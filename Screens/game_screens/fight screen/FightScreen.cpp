#include "FightScreen.h"

void FightScreen::open(Player *player, Mob *mob, std::vector<Mob *> &allMobs, int mobIndex)
{
    Blur backgroundBlur(background->getSize(), 2);
    backgroundSprite = backgroundBlur.apply(background->getTexture());

    loadVisualElements(player, mob);
    manifest();
    float closingTime = 0;

    while (true)
    {
        clock->restart().asSeconds();

        allHPBars[0].update(mob->getHp());
        allHPBars[1].update(player->getHp());

        FightHolder& fightHolder = FightHolder::getInstance();
        if (fightHolder.isPlayerMove)
        {
            enemyAttackClock.restart().asSeconds();

            for (auto& button : allButtons) button->update();
        }
        else if (mob->getHp() > 0)
        {
            updateEnemyAttack(player, mob);
        }

        sf::Event event = {};
        while (window->pollEvent(event)) {}

        if (mob->getHp() <= 0)
        {
            closingTime += endFightClock.restart().asSeconds();
            if (closingTime >= 1.5)
            {
                close(mob, allMobs, mobIndex);
                return;
            }
        }
        else endFightClock.restart().asSeconds();

        EffectsHolders::Inventory::getInstance().update();

        window->clear();
        window->draw(backgroundSprite);
        window->draw(fightBackground);
        for (auto& button : allButtons) window->draw(*button);
        for (auto& bar : allHPBars) window->draw(bar);
        for (auto& icon : allFightersIcons) window->draw(icon);
        window->draw(EffectsHolders::Inventory::getInstance());
        window->display();
    }
}

void FightScreen::updateEnemyAttack(Player* player, Mob* mob)
{
    if (enemyAttackTime == 0) for (auto& button : allButtons) button->forceHoverShutdown();

    enemyAttackTime += enemyAttackClock.restart().asSeconds();

    if (enemyAttackTime >= 1)
    {
        FightHolder& fightHolder = FightHolder::getInstance();
        fightHolder.attackPlayer(player, mob, window);

        enemyAttackTime = 0;
    }
}

void FightScreen::loadVisualElements(Player *player, Mob *mob)
{
    allButtons.clear();
    allHPBars.clear();
    allFightersIcons.clear();

    TextureHolder& textureHolder = TextureHolder::getInstance();

    /* Задний фон */
    textureHolder.loadFromFile("../GUI/FIGHT_GUI/Background/fightBackground.png", "fightBackground");
    sf::Texture *texture = textureHolder.getResource("fightBackground");
    fightBackground.setTexture(*texture);
    fightBackground.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                          (float) window->getSize().y / 1080));
    fightBackground.setPosition(sf::Vector2f(464 * (float) window->getSize().x / 1920,
                                             108 * (float) window->getSize().y / 1080));

    /* Бары здоровья */
    FIGHT_GUI::HPBar enemyBar(window, "HPEnemyBarHP", mob->getHp(), sf::Vector2f(704, 523));
    allHPBars.push_back(enemyBar);

    FIGHT_GUI::HPBar playerBar(window, "HPPlayerBarHP", player->getMaxHp(), sf::Vector2f(1008, 523));
    playerBar.update(player->getHp());
    allHPBars.push_back(playerBar);

    /* Кнопки */
    auto weaponButton = new FIGHT_GUI::WeaponButton(window, player, mob, player->inventory.inv[4], sf::Vector2f(952, 635));
    auto hotBarButton1 = new FIGHT_GUI::HotBarButton(window, player, mob, player->inventory.inv[5], sf::Vector2f(1024, 635));
    auto hotBarButton2 = new FIGHT_GUI::HotBarButton(window, player, mob, player->inventory.inv[6], sf::Vector2f(1096, 635));
    auto hotBarButton3 = new FIGHT_GUI::HotBarButton(window, player, mob, player->inventory.inv[7], sf::Vector2f(1168, 635));
    allButtons.push_back(weaponButton);
    allButtons.push_back(hotBarButton1);
    allButtons.push_back(hotBarButton2);
    allButtons.push_back(hotBarButton3);


    /* Иконки сражающихся */
    FIGHT_GUI::FighterIcon icon1(window, mob, sf::Vector2f(740, 403));
    FIGHT_GUI::FighterIcon icon2(window, player, sf::Vector2f(1044, 403));
    allFightersIcons.push_back(icon1);
    allFightersIcons.push_back(icon2);
}

void FightScreen::manifest()
{
    textureForAnimator.clear();
    textureForAnimator.draw(backgroundSprite);
    textureForAnimator.draw(fightBackground);
    for (auto& button : allButtons) textureForAnimator.draw(*button);
    for (auto& bar : allHPBars) textureForAnimator.draw(bar);
    for (auto& icon : allFightersIcons) textureForAnimator.draw(icon);
    textureForAnimator.display();

    Animator& animator = Animator::getInstance();
    animator.manifest(window, clock, background, &textureForAnimator);
}

void FightScreen::unManifest()
{
    textureForAnimator.clear();
    textureForAnimator.draw(backgroundSprite);
    textureForAnimator.draw(fightBackground);
    for (auto& button : allButtons) textureForAnimator.draw(*button);
    for (auto& bar : allHPBars) textureForAnimator.draw(bar);
    for (auto& icon : allFightersIcons) textureForAnimator.draw(icon);
    textureForAnimator.display();

    Animator& animator = Animator::getInstance();
    animator.unManifest(window, clock, background, &textureForAnimator);
}

void FightScreen::close(Mob *mob, std::vector<Mob *> &allMobs, int mobIndex)
{
    /* Выставляем начальные условия для следующего боя */
    FightHolder::getInstance().isPlayerMove = true;

    /* Очищаем пулл эффектов FightScreen'а */
    EffectsHolders::Inventory::getInstance().clear();

    /* Добавляем в пулл эффектов карты эфект смерти моба и удаляем его*/
    EffectsHolders::Map::getInstance().createEffect("mob death", mob->getPosition(), window);
    allMobs.erase(allMobs.begin() + mobIndex);
    delete mob;

    /* Плавно закрываем экран */
    unManifest();
}

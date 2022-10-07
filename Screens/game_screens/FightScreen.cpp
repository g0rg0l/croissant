#include "FightScreen.h"

void FightScreen::open(Player *player, Mob *mob, std::vector<Mob *> &allMobs, int mobIndex)
{
    Blur backgroundBlur(background->getSize(), 2);
    sf::Sprite backgroundSprite(backgroundBlur.apply(background->getTexture()));

    loadVisualElements(player, mob);

    while (true)
    {
        clock->restart().asSeconds();

        allHPBars[0].update(mob->getHp());
        allHPBars[1].update(player->getHp());

        for (auto& button : allButtons) button->update();

        sf::Event event = {};
        while (window->pollEvent(event)) {}

        if (mob->getHp() <= 0)
        {
            allMobs.erase(allMobs.begin() + mobIndex);

            return;
        }

        window->clear();
        window->draw(backgroundSprite);
        window->draw(fightBackground);
        for (auto& button : allButtons) window->draw(*button);
        for (auto& bar : allHPBars) window->draw(bar);
        for (auto& icon : allFightersIcons) window->draw(icon);
        window->display();
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
    fightBackground.setPosition(sf::Vector2f(544 * (float) window->getSize().x / 1920,
                                             220 * (float) window->getSize().y / 1080));

    /* Бары здоровья */
    FIGHT_GUI::HPBar enemyBar(window, "HPEnemyBarHP", mob->getHp(), sf::Vector2f(704, 411));
    allHPBars.push_back(enemyBar);

    FIGHT_GUI::HPBar playerBar(window, "HPPlayerBarHP", player->getMaxHp(), sf::Vector2f(1008, 411));
    allHPBars.push_back(playerBar);

    /* Кнопки */
    auto weaponButton = new FIGHT_GUI::WeaponButton(window, player, mob, player->inventory.inv[4], sf::Vector2f(952, 523));
    auto hotBarButton1 = new FIGHT_GUI::HotBarButton(window, player, mob, player->inventory.inv[5], sf::Vector2f(1024, 523));
    auto hotBarButton2 = new FIGHT_GUI::HotBarButton(window, player, mob, player->inventory.inv[6], sf::Vector2f(1096, 523));
    auto hotBarButton3 = new FIGHT_GUI::HotBarButton(window, player, mob, player->inventory.inv[7], sf::Vector2f(1168, 523));
    allButtons.push_back(weaponButton);
    allButtons.push_back(hotBarButton1);
    allButtons.push_back(hotBarButton2);
    allButtons.push_back(hotBarButton3);


    /* Иконки сражающихся */
    FIGHT_GUI::FighterIcon icon1(window, mob, sf::Vector2f(740, 291));
    FIGHT_GUI::FighterIcon icon2(window, player, sf::Vector2f(1044, 291));
    allFightersIcons.push_back(icon1);
    allFightersIcons.push_back(icon2);
}

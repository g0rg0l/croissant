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

        for (auto& button : allFightMenuButtons) button.hoverUpdate(sf::Mouse::getPosition());

        sf::Event event = {};
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::MouseButtonPressed:
                    for (auto& button : allFightMenuButtons)
                    {
                        if (button.isHovered && !button.isLocked)
                        {
                            /* Выполняем команду кнопки */
                            button.func();

                            /* Проверяем, не умер ли моб */
                            if (mob->getHp() <= 0)
                            {
                                allMobs.erase(allMobs.begin() + mobIndex);
                                return;
                            }

                            /* Блокируем кнопку, на которую только что нажали */
                            button.lock();

                            /* Атака моба */
                            player->takeDamage(10);

                            break;
                        }
                    }
                    break;

                case sf::Event::MouseButtonReleased:
                    for (auto& button : allFightMenuButtons) button.unlock();
                    break;

                default:
                    break;
            }
        }

        window->clear();
        window->draw(backgroundSprite);
        window->draw(fightBackground);
        for (auto& button : allFightMenuButtons) window->draw(button);
        for (auto& bar : allHPBars) window->draw(bar);
        for (auto& icon : allFightersIcons) window->draw(icon);
        window->display();
    }
}

void FightScreen::loadVisualElements(Player *player, Mob *mob)
{
    allHPBars.clear();
    allFightMenuButtons.clear();
    allFightersIcons.clear();

    TextureHolder& textureHolder = TextureHolder::getInstance();

    /* Задний фон */
    textureHolder.loadFromFile("../GUI/FIGHT_GUI/Background/fightBackground.png", "fightBackground");
    sf::Texture *texture = textureHolder.getResource("fightBackground");
    fightBackground.setTexture(*texture);
    fightBackground.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                          (float) window->getSize().y / 1080));
    fightBackground.setPosition(sf::Vector2f(706 * (float) window->getSize().x / 1920,
                                             292 * (float) window->getSize().y / 1080));

    /* Бары здоровья */
    FIGHT_GUI::HPBar enemyBar(window, "HPEnemyBarHP", mob->getHp(), sf::Vector2f(778, 517));
    allHPBars.push_back(enemyBar);

    FIGHT_GUI::HPBar playerBar(window, "HPPlayerBarHP", player->getMaxHp(), sf::Vector2f(982, 517));
    allHPBars.push_back(playerBar);

    /* Кнопки */
    FIGHT_GUI::AttackButton button1(window, player, mob, player->inventory.inv[4], sf::Vector2f(778, 660));
    FIGHT_GUI::AttackButton button2(window, player, mob, player->inventory.inv[5], sf::Vector2f(874, 660));
    FIGHT_GUI::AttackButton button3(window, player, mob, player->inventory.inv[6], sf::Vector2f(982, 660));
    FIGHT_GUI::AttackButton button4(window, player, mob, player->inventory.inv[7], sf::Vector2f(1078, 660));
    allFightMenuButtons.push_back(button1);
    allFightMenuButtons.push_back(button2);
    allFightMenuButtons.push_back(button3);
    allFightMenuButtons.push_back(button4);

    /* Иконки сражающихся */
    FIGHT_GUI::FighterIcon icon1(window, mob, sf::Vector2f(814, 400));
    FIGHT_GUI::FighterIcon icon2(window, player, sf::Vector2f(1018, 400));
    allFightersIcons.push_back(icon1);
    allFightersIcons.push_back(icon2);
}

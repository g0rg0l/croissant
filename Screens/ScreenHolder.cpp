#include "ScreenHolder.h"

ScreenHolder::ScreenHolder(sf::RenderWindow* window, sf::RenderTexture* renderTexture, sf::Clock* clock)
    : window(window), background(renderTexture), clock(clock)
{
    if (window)
    {
        loadPauseMenuElements();
    }
}

/////////////////////////////////// Пауза ///////////////////////////////////
void ScreenHolder::openPauseMenu()
{
    Blur backgroundBlur(background->getSize(), 2);
    sf::Sprite backgroundSprite(backgroundBlur.apply(background->getTexture()));

    while (true)
    {
        clock->restart().asSeconds();
        sf::Event event = {};

        while (window->pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) return;
        }

        window->clear();
        window->draw(backgroundSprite);
        for (auto& element : allPauseMenuElements) window->draw(element);

        sf::Text pauseText;
        sf::Font pauseTextFont;
        pauseTextFont.loadFromFile("../Screens/First School.ttf");
        pauseText.setFont(pauseTextFont);
        pauseText.setString("Paused now");
        pauseText.setCharacterSize(48);
        pauseText.setFillColor(sf::Color::Black);
        pauseText.setPosition((float) window->getSize().x / 4 + 350, (float) window->getSize().y / 5);
        window->draw(pauseText);
        window->display();
    }
}

void ScreenHolder::loadPauseMenuElements()
{
    sf::RectangleShape pauseBackground(sf::Vector2f((float) background->getSize().x / 2, (float) background->getSize().y / 4));
    pauseBackground.setFillColor(sf::Color::Red);
    pauseBackground.setPosition((float) window->getSize().x / 4, (float) window->getSize().y / 8);
    allPauseMenuElements.push_back(pauseBackground);
}

/////////////////////////////////// Меню боя ///////////////////////////////////
void ScreenHolder::openFightMenu(Player* player, Mob* mob, std::vector<Mob*>& allMobs, int mobIndex)
{
    Blur backgroundBlur(background->getSize(), 2);
    sf::Sprite backgroundSprite(backgroundBlur.apply(background->getTexture()));

    loadFightMenuElements(player, mob);

    while (true)
    {
        clock->restart().asSeconds();

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

            allHPBars[0].update(mob->getHp());
            allHPBars[1].update(player->getHp());

            for (auto& button : allFightMenuButtons) button.hoverUpdate(sf::Mouse::getPosition());
        }

        window->clear();
        window->draw(backgroundSprite);
        window->draw(fightBackground);
        for (auto& button : allFightMenuButtons) window->draw(button);
        for (auto& bar : allHPBars) window->draw(bar);
        for (auto& icon : allFightersIconFrames) window->draw(icon);
        window->display();
    }
}

void ScreenHolder::loadFightMenuElements(Player* player, Mob* mob)
{
    allHPBars.clear();
    allFightMenuButtons.clear();
    allFightersIconFrames.clear();

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

    FIGHT_GUI::HPBar playerBar(window, "HPPlayerBarHP", player->getHp(), sf::Vector2f(982, 517));
    allHPBars.push_back(playerBar);

    /* Кнопки */
    FIGHT_GUI::AttackButton button1(window, player, mob, "icon_sword", sf::Vector2f(778, 660));
    FIGHT_GUI::AttackButton button2(window, player, mob, "icon_axe", sf::Vector2f(874, 660));
    FIGHT_GUI::AttackButton button3(window, player, mob, "icon_wand", sf::Vector2f(982, 660));
    FIGHT_GUI::AttackButton button4(window, player, mob, "icon_bow", sf::Vector2f(1078, 660));
    allFightMenuButtons.push_back(button1);
    allFightMenuButtons.push_back(button2);
    allFightMenuButtons.push_back(button3);
    allFightMenuButtons.push_back(button4);

    /* Иконки сражающихся */
    FIGHT_GUI::FightersIconFrame icon1(window, mob, sf::Vector2f(814, 400));
    FIGHT_GUI::FightersIconFrame icon2(window, player, sf::Vector2f(1018, 400));
    allFightersIconFrames.push_back(icon1);
    allFightersIconFrames.push_back(icon2);
}


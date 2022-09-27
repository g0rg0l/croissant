#include "ScreenHolder.h"

ScreenHolder::ScreenHolder(sf::RenderWindow* window,
                           sf::RenderTexture* renderTexture,
                           sf::Clock* clock
) : window(window), background(renderTexture), clock(clock)
{
    if (window)
    {
        loadPauseMenuElements();
        loadFightMenuElements();
    }
}

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

void ScreenHolder::openFightMenu(Player* player, Mob* mob, std::vector<Mob*>& allMobs, int mobIndex)
{
    Blur backgroundBlur(background->getSize(), 2);
    sf::Sprite backgroundSprite(backgroundBlur.apply(background->getTexture()));

    loadHpBars(player, mob);

    bool keyWasPressed = false;
    bool clicking;
    while (true)
    {
        clock->restart().asSeconds();

        sf::Event event = {};
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::MouseButtonPressed:
                    clicking = true;
                    break;

                case sf::Event::MouseButtonReleased:
                    clicking = false;
                    break;

                default:
                    break;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
            {
                if (!keyWasPressed)
                {
                    mob->takeDamage(10);

                    if (mob->getHp() <= 0)
                    {
                        allMobs.erase(allMobs.begin() + mobIndex);
                        allHPBars.clear();
                        return;
                    }

                    keyWasPressed = true;
                }
            }
            else keyWasPressed = false;

            for(auto& button : allFightMenuButtons)
            {
                button.update(sf::Mouse::getPosition(*window), clicking);
            }
            allHPBars[0].update(mob->getHp());
            allHPBars[1].update(player->getHp());
        }

        window->clear();
        window->draw(backgroundSprite);
        window->draw(fightBackground);
        for (auto& button : allFightMenuButtons) window->draw(button);
        for (auto& bar : allHPBars) window->draw(bar);
        window->display();
    }
}

void ScreenHolder::loadFightMenuElements()
{

    TextureHolder& textureHolder = TextureHolder::getInstance();

    /* Задний фон */
    textureHolder.loadFromFile("../GUI/FIGHT_GUI/Background/fightBackground.png", "fightBackground");
    sf::Texture *texture = textureHolder.getResource("fightBackground");
    fightBackground.setTexture(*texture);
    fightBackground.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                                 (float) window->getSize().y / 1080));
    fightBackground.setPosition(sf::Vector2f(706 * (float) window->getSize().x / 1920,
                                             292 * (float) window->getSize().y / 1080));

    /* Иконки сражающихся */


    /* Кнопки */
    FIGHT_GUI::AttackButton button(window, "button");
    allFightMenuButtons.push_back(button);
}

void ScreenHolder::loadHpBars(Player* player, Mob* mob)
{
    FIGHT_GUI::HPBar enemyBar(window, "HPEnemyBarHP", mob->getHp(), sf::Vector2f(778, 517));
    allHPBars.push_back(enemyBar);

    FIGHT_GUI::HPBar playerBar(window, "HPPlayerBarHP", player->getHp(), sf::Vector2f(982, 517));
    allHPBars.push_back(playerBar);
}



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
        bool lock_click = false;
        while (window->pollEvent(event))
        {
            for(auto& button : allPauseButtons)
            {
                button.update(sf::Mouse::getPosition(*window));
            }

            switch (event.type)
            {
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left && !lock_click)
                    {
                        for(auto& button : allPauseButtons)
                        {
                            button.update(sf::Mouse::getPosition(*window), true);
                        }
                        lock_click = true;
                    }
                    break;

                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        lock_click = false;
                    }
                    break;

                default:
                    break;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) return;
        }

        window->clear();
        window->draw(backgroundSprite);
        for (auto& element : allPauseMenuElements) window->draw(element);
        for(auto& button : allPauseButtons) window->draw(button);

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

    GUI::Button button1("button");
    allPauseButtons.push_back(button1);

    GUI::Button button2("button", sf::Vector2f(100, 0));
    allPauseButtons.push_back(button2);
}

void ScreenHolder::openFightMenu(Player* player, Mob* mob, std::vector<Mob*>& allMobs, int mobIndex)
{
    Blur backgroundBlur(background->getSize(), 2);
    sf::Sprite backgroundSprite(backgroundBlur.apply(background->getTexture()));

    bool keyWasPressed = false;
    while (true)
    {
        clock->restart().asSeconds();

        sf::Event event = {};
        bool lock_click = false;
        while (window->pollEvent(event))
        {
            for(auto& button : allFightMenuButtons)
            {
                button.update(sf::Mouse::getPosition(*window));
            }

            switch (event.type)
            {
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left && !lock_click)
                    {
                        for(auto& button : allFightMenuButtons)
                        {
                            button.update(sf::Mouse::getPosition(*window), true);
                        }
                        lock_click = true;
                    }
                    break;

                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        lock_click = false;
                    }
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
                        return;
                    }

                    keyWasPressed = true;
                }
            }
            else keyWasPressed = false;
        }

        window->clear();
        window->draw(backgroundSprite);
        for (auto& element : allFightMenuElements) window->draw(element);
        for (auto& button : allFightMenuButtons) window->draw(button);
        window->display();
    }
}

void ScreenHolder::loadFightMenuElements()
{
    sf::RectangleShape fightBackground(sf::Vector2f((float) background->getSize().x * 1/2, (float) background->getSize().y * 1/2));
    fightBackground.setFillColor(sf::Color::Blue);
    fightBackground.setPosition((float) window->getSize().x * 1/4, (float) window->getSize().y * 1/4);
    allFightMenuElements.push_back(fightBackground);

    GUI::Button button("button");
    allFightMenuButtons.push_back(button);
}



#include "FightScreen.h"

FightScreen::FightScreen(unsigned int windowWidth, unsigned int windowHeight, float viewScale)
{
    mainWindowWidth = windowWidth;
    mainWindowHeight = windowHeight;
    mainViewScale = viewScale;
}

void FightScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (isFighting)
    {
        sf::Vector2f backgroundShapeSize((float) mainWindowWidth / mainViewScale * 3/4,
                                         (float) mainWindowHeight / mainViewScale * 3/4);

        sf::RectangleShape backgroundShape(backgroundShapeSize);
        backgroundShape.setFillColor(sf::Color::Blue);
        backgroundShape.setPosition(sf::Vector2f(
                player->getPosition().x + player->getSprite().getGlobalBounds().width / 2 - backgroundShapeSize.x / 2,
                player->getPosition().y + player->getSprite().getGlobalBounds().height / 2 - backgroundShapeSize.y / 2
                ));
//        backgroundShape.setPosition((sf::Vector2f(-24.383, 204.921)));
//        sf::Font font;
//        font.loadFromFile("../Screens/arial.ttf");
//
//        sf::Text playerName;
//        playerName.setFont(font);
//        playerName.setString(std::to_string(player->getHp()));
//        playerName.setFillColor(sf::Color::Blue);
//        playerName.setCharacterSize(8);
//        playerName.setPosition(sf::Vector2f(44, 244));
//
//        sf::Text mobName;
//        mobName.setFont(font);
//        mobName.setString(std::to_string(mob->getHp()));
//        mobName.setFillColor(sf::Color::Red);
//        mobName.setCharacterSize(8);
//        mobName.setPosition(sf::Vector2f(100, 244));

        target.draw(backgroundShape, states);
//        target.draw(playerName, states);
//        target.draw(mobName, states);
    }
}

void FightScreen::enableFight(Player &PLAYER, Mob &MOB, int newId)
{
    isFighting = true;

    player = &PLAYER;
    mob = &MOB;
    mobIndex = newId;
}

void FightScreen::updateFight(std::vector<Mob> &allMobs)
{
    if (isFighting)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        {
            if (!keyWasPressed)
            {
                mob->getDamage(10);

                if (mob->getHp() <= 0)
                {
                    allMobs.erase(allMobs.begin() + mobIndex);
                    disableFight();
                }

                keyWasPressed = true;
            }
        }
        else keyWasPressed = false;
    }
}

void FightScreen::disableFight()
{
    isFighting = false;

    mob = nullptr;
    player = nullptr;
    mobIndex = -1;
}
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
//        sf::Vector2f backgroundShapeSize((float) mainWindowWidth / mainViewScale * 3/4,
//                                         (float) mainWindowHeight / mainViewScale * 3/4);
//
//        sf::RectangleShape backgroundShape(backgroundShapeSize);
//        backgroundShape.setFillColor(sf::Color::Blue);
//        backgroundShape.setPosition(sf::Vector2f(
//                player->getPosition().x + player->getSprite().getGlobalBounds().width / 2 - backgroundShapeSize.x / 2,
//                player->getPosition().y + player->getSprite().getGlobalBounds().height / 2 - backgroundShapeSize.y / 2
//                ));

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

//        target.draw(backgroundShape, states);
//        target.draw(playerName, states);
//        target.draw(mobName, states);

        for (auto& sprite : screenElements)
        {
            target.draw(sprite, states);
        }
    }
}

void FightScreen::enableFight(Player &PLAYER, Mob &MOB, int newId)
{
    isFighting = true;

    player = &PLAYER;
    mob = &MOB;
    mobIndex = newId;

    // тут будем вызывать функцию, которая будет перезаписывать вектор элементов окна файтинга
    loadFightScreenElements();
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

    screenElements.clear();
}

void FightScreen::loadFightScreenElements()
{
    /* Получение TextureHolde'а и добавление/получение всех текстур для элементов */
    TextureHolder& textureHolder = TextureHolder::getInstance();

    textureHolder.loadFromFile("../Screens/blue.png", "fightScreenBackground"); // Задний фон

    /* Задний фон */
    sf::Sprite background;

    sf::Texture *texture = textureHolder.getResource("fightScreenBackground");
    sf::Vector2u backgroundTextureSizes = texture->getSize();
    background.setTexture(*texture);


    background.setPosition(sf::Vector2f(
            player->getPosition().x + player->getSprite().getGlobalBounds().width / 2 - (float) backgroundTextureSizes.x / 2,
            player->getPosition().y + player->getSprite().getGlobalBounds().height / 2 - (float) backgroundTextureSizes.y / 2
    ));

    screenElements.push_back(background);
}
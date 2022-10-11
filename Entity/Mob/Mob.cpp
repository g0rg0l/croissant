#include "Mob.h"

/////////////////////////////////// Конструкторы и деконструкторы ///////////////////////////////////
Mob::Mob(const std::string&  name, sf::Vector2f position, sf::Vector2f sizes, const std::string& textureHolderKey, sf::RenderWindow* window)
    : name(name), sizes(sizes), textureHolderKey(textureHolderKey), window(window)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();
    textureHolder.loadFromFile("../Entity/Mob/" + textureHolderKey + "/src/" +
        textureHolderKey + ".png", textureHolderKey);

    sf::Texture *texture = textureHolder.getResource(textureHolderKey);
    sprite.setTexture(*texture);
    textureFramesCount = (int) (sprite.getGlobalBounds().width / sizes.x);
    sprite.setTextureRect(sf::IntRect(0, 0, sizes.x, sizes.y));

    sprite.setScale(sf::Vector2f(
            (float) window->getSize().x / 1920,
            (float) window->getSize().y / 1080));

    sprite.setPosition(
            position.x * (float) window->getSize().x / 1920,
            position.y * (float) window->getSize().y / 1080);
}

/////////////////////////////////// Отрисовка ///////////////////////////////////
void Mob::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

/////////////////////////////////// Взаимодействие с игроком ///////////////////////////////////
bool Mob::isSeePlayer(Player* player, const std::vector<sf::FloatRect> &allWallBounds)
{
    sf::FloatRect playerBounds = player->getSprite().getGlobalBounds();
    sf::FloatRect mobBounds = sprite.getGlobalBounds();

    sf::Vector2f mobCenterPoint = sf::Vector2f(mobBounds.left + mobBounds.width / 2, mobBounds.top + mobBounds.height / 2);

    sf::Vector2f playerPoint1 = {playerBounds.left + playerBounds.width/4, playerBounds.top + playerBounds.height/4};
    sf::Vector2f playerPoint2 = {playerBounds.left + 3*playerBounds.width/4, playerBounds.top + playerBounds.height/4};
    sf::Vector2f playerPoint3 = {playerBounds.left + 3*playerBounds.width/4, playerBounds.top + 3*playerBounds.height/4};
    sf::Vector2f playerPoint4 = {playerBounds.left + playerBounds.width/4, playerBounds.top + 3*playerBounds.height/4};
    
    sf::Vector2f mobPoint1 = {mobBounds.left + mobBounds.width/4, mobBounds.top + mobBounds.width/4};
    sf::Vector2f mobPoint2 = {mobBounds.left + 3*mobBounds.width/4, mobBounds.top + mobBounds.height/4};
    sf::Vector2f mobPoint3 = {mobBounds.left + 3*mobBounds.width/4, mobBounds.top + 3*mobBounds.height/4};
    sf::Vector2f mobPoint4 = {mobBounds.left + mobBounds.width/4, mobBounds.top + 3*mobBounds.height/4};

    bool point1InVis = sqrt(pow(playerPoint1.x - mobCenterPoint.x, 2) + pow(playerPoint1.y - mobCenterPoint.y, 2)) <= visibilityDistance;
    bool point2InVis = sqrt(pow(playerPoint2.x - mobCenterPoint.x, 2) + pow(playerPoint2.y - mobCenterPoint.y, 2)) <= visibilityDistance;
    bool point3InVis = sqrt(pow(playerPoint3.x - mobCenterPoint.x, 2) + pow(playerPoint3.y - mobCenterPoint.y, 2)) <= visibilityDistance;
    bool point4InVis = sqrt(pow(playerPoint4.x - mobCenterPoint.x, 2) + pow(playerPoint4.y - mobCenterPoint.y, 2)) <= visibilityDistance;

    /* Проверка на то, входит ли игрок в зону видимости противника */
    if (point1InVis || point2InVis || point3InVis || point4InVis)
    {
        /* Проверка на то, не мешают ли взглядам моба стены */
        sf::Vector2f line1[] = {playerPoint1, mobPoint1};
        sf::Vector2f line2[] = {playerPoint2, mobPoint2};
        sf::Vector2f line3[] = {playerPoint3, mobPoint3};
        sf::Vector2f line4[] = {playerPoint4, mobPoint4};

        bool Q1 = false, Q2 = false, Q3 = false, Q4 = false;
        for(auto &wallBounds : allWallBounds)
        {
            sf::Vector2f rectangle[] = {
                    sf::Vector2f(wallBounds.left, wallBounds.top),
                    sf::Vector2f(wallBounds.left + wallBounds.width, wallBounds.top),
                    sf::Vector2f(wallBounds.left + wallBounds.width, wallBounds.top + wallBounds.height),
                    sf::Vector2f(wallBounds.left, wallBounds.top + wallBounds.height)
            };

            if (lineCrossingRectangle(line1, rectangle) && point1InVis) Q1 = true;
            if (lineCrossingRectangle(line2, rectangle) && point2InVis) Q2 = true;
            if (lineCrossingRectangle(line3, rectangle) && point3InVis) Q3 = true;
            if (lineCrossingRectangle(line4, rectangle) && point4InVis) Q4 = true;
        }

        if ((point1InVis && !Q1) || (point2InVis && !Q2) || (point3InVis && !Q3) || (point4InVis && !Q4))
        {
            return true;
        }
        else return false;
    }
    else return false;
}

void Mob::updateSprite()
{
    float dt = 7.5 * animationClock.restart().asSeconds();

    if ((int) currentSpriteFrame < (int) (currentSpriteFrame + dt))
    {
        sprite.setTextureRect(sf::IntRect(((int) currentSpriteFrame) * sizes.x, 0, sizes.x, sizes.y));
    }
    currentSpriteFrame += dt;

    if ((int ) currentSpriteFrame > textureFramesCount - 1) currentSpriteFrame = 0;
}

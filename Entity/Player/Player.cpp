#include "Player.h"


/////////////////////////////////// Конструкторы и деконструкторы ///////////////////////////////////
Player::Player(float SPEED)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();
    textureHolder.loadFromFile("../Entity/Player/images/player.png", "player");

    sf::Texture *texture = textureHolder.getResource("player");
    sprite.setTexture(*texture);

    speed = SPEED;
    sprite.setPosition(sf::Vector2f(128, 128));

    inventory = Inventory();
}

/////////////////////////////////// Отрисовка ///////////////////////////////////
void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

/////////////////////////////////// Перемещение ///////////////////////////////////
void Player::move(float dt, const std::vector<sf::FloatRect>& wallBounds, sf::View *view) // Передвижение игрока
{
    resetMoveOptions(); // Обнуляем вектор скорости
    checkMove(dt); // Считываем управление и вычисляем вектор скорости
    checkWallCollision(wallBounds); // Проверяем коллизию со стенами
    sprite.move(velocity); // Передвигаем спрайт

    view->setCenter(
            sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 2,
            sprite.getGlobalBounds().top + sprite.getGlobalBounds().height / 2
            );
    setPosition(sprite.getPosition()); // Запоминаем координаты объекта Player
}

void Player::checkWallCollision(const std::vector<sf::FloatRect>& allWallBounds) // Проверка коллизии со стенами
{
    sf::FloatRect playerBounds = sprite.getGlobalBounds();
    sf::FloatRect nextPos(
            playerBounds.left + velocity.x,
            playerBounds.top + velocity.y,
            playerBounds.width,
            playerBounds.height
            );

    for(auto wallBounds : allWallBounds)

        if (wallBounds.intersects(nextPos))
        {
            // Bottom collision
            if (playerBounds.top < wallBounds.top
                && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
                && playerBounds.left < wallBounds.left + wallBounds.width
                && playerBounds.left + playerBounds.width > wallBounds.left)
            {
                velocity.y = 0.f;
                sprite.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
            }
                // Top collision
            else if (playerBounds.top > wallBounds.top
                     && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
                     && playerBounds.left < wallBounds.left + wallBounds.width
                     && playerBounds.left + playerBounds.width > wallBounds.left)
            {
                velocity.y = 0.f;
                sprite.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
            }
                // Right collision
            else if (playerBounds.left < wallBounds.left
                     && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
                     && playerBounds.top < wallBounds.top + wallBounds.height
                     && playerBounds.top + playerBounds.height > wallBounds.top)
            {
                velocity.x = 0.f;
                sprite.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
            }
                // Left collision
            else if (playerBounds.left > wallBounds.left
                     && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
                     && playerBounds.top < wallBounds.top + wallBounds.height
                     && playerBounds.top + playerBounds.height > wallBounds.top)
            {
                velocity.x = 0.f;
                sprite.setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
            }
        }
}

void Player::checkMove(float dt) // Считывание управления и вычисление вектора скорости
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        velocity = sf::Vector2f(velocity.x, velocity.y - speed * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        velocity = sf::Vector2f(velocity.x, velocity.y + speed * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity = sf::Vector2f(velocity.x - speed * dt, velocity.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        velocity = sf::Vector2f(velocity.x + speed * dt, velocity.y);
    }

    if (velocity.x != 0 && velocity.y != 0) velocity *= 0.707f; // Нормирование диагонали
}

void Player::resetMoveOptions() // Обнуление вектора скорости
{
    velocity = sf::Vector2f(0, 0);
}

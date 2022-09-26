#include "GUI.h"

using namespace GUI;

/////////////////////////////////// Button ///////////////////////////////////
Button::Button(const std::string& fileName, sf::Vector2f position)
    : fileName(fileName)
{
    sprite.setPosition(position);

    TextureHolder& textureHolder = TextureHolder::getInstance();
    textureHolder.loadFromFile("../GUI/Button/" + fileName + "_normal" + ".png", fileName + "_normal");
    textureHolder.loadFromFile("../GUI/Button/" + fileName + "_hovered" + ".png", fileName + "_hovered");
    textureHolder.loadFromFile("../GUI/Button/" + fileName + "_clicked" + ".png", fileName + "_clicked");
    sf::Texture *texture = textureHolder.getResource(fileName + "_normal");
    sprite.setTexture(*texture);
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {target.draw(sprite, states);}

void Button::setStatus(const std::string& status)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();
    sf::Texture* texture = textureHolder.getResource(fileName + status);
    sprite.setTexture(*texture);
}

void Button::update(sf::Vector2i mousePosition, bool clicked)
{
    /* Этот метод будет запускаться всякий раз, когда игрок двигает мышкой в окне, где есть кнопка.
     * Нужно проверять, навели ли мышь на кнопку и была ли она нажата
     * */
    if (sprite.getGlobalBounds().contains((float) mousePosition.x, (float) mousePosition.y))
    {
        setStatus("_hovered");
        if (clicked) setStatus("_clicked");
    }
    else setStatus("_normal");
}



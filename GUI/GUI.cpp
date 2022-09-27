#include "GUI.h"

using namespace FIGHT_GUI;

/////////////////////////////////// AttackButton ///////////////////////////////////
AttackButton::AttackButton(sf::RenderWindow* window, const std::string& fileName, sf::Vector2f position)
    : fileName(fileName), window(window)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();
    textureHolder.loadFromFile("../GUI/FIGHT_GUI/AttackButton/" + fileName + "_normal" + ".png", fileName + "_normal");
    textureHolder.loadFromFile("../GUI/FIGHT_GUI/AttackButton/" + fileName + "_hovered" + ".png", fileName + "_hovered");
    textureHolder.loadFromFile("../GUI/FIGHT_GUI/AttackButton/" + fileName + "_clicked" + ".png", fileName + "_clicked");
    sf::Texture *texture = textureHolder.getResource(fileName + "_normal");
    sprite.setTexture(*texture);
    sprite.setScale(sf::Vector2f(
            (float) window->getSize().x / 1920,
            (float) window->getSize().y / 1080
    ));
    sprite.setPosition(position);

}

void AttackButton::draw(sf::RenderTarget &target, sf::RenderStates states) const {target.draw(sprite, states);}

void AttackButton::setStatus(const std::string& status)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();
    sf::Texture* texture = textureHolder.getResource(fileName + status);
    sprite.setTexture(*texture);
}

void AttackButton::update(sf::Vector2i mousePosition, bool clicked)
{
    if (sprite.getGlobalBounds().contains((float) mousePosition.x, (float) mousePosition.y))
    {
        if (clicked)
        {
            if (!wasClicked)
            {
                setStatus("_clicked");
                wasClicked = true;

                /* Выполняем функцию */
                std::cout << "clicked" << std::endl;
            }
        }
        else
        {
            setStatus("_hovered");
            wasClicked = false;
        }
    }
    else setStatus("_normal");
}

/////////////////////////////////// HPBar ///////////////////////////////////
HPBar::HPBar(sf::RenderWindow* window,const std::string &fileName, int maxHP, sf::Vector2f position)
    : maxHP(maxHP), window(window)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();

    textureHolder.loadFromFile("../GUI/FIGHT_GUI/HPBar/HPBarFrame.png", "HPBarFrame");
    sf::Texture *frameTexture = textureHolder.getResource("HPBarFrame");
    frameSprite.setTexture(*frameTexture);
    frameSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                             (float) window->getSize().y / 1080));
    frameSprite.setPosition(position.x * (float) window->getSize().x / 1920,
                            position.y * (float) window->getSize().y / 1080);

    textureHolder.loadFromFile("../GUI/FIGHT_GUI/HPBar/" + fileName + ".png", fileName);
    sf::Texture *HPTexture = textureHolder.getResource(fileName);
    HPSprite.setTexture(*HPTexture);
    HPSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                      (float) window->getSize().y / 1080));
    HPSprite.setPosition(position.x * (float) window->getSize().x / 1920,
                            position.y * (float) window->getSize().y / 1080);
}

void HPBar::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(HPSprite, states);
    target.draw(frameSprite, states);
}

void HPBar::update(int hp)
{
    HPSprite.setScale(sf::Vector2f((float) hp / (float) maxHP * (float) window->getSize().x / 1920, (float) window->getSize().y / 1080));
}

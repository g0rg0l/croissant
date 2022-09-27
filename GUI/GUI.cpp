#include "GUI.h"

using namespace FIGHT_GUI;

/////////////////////////////////// AttackButton ///////////////////////////////////
void AttackButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(iconSprite, states);
    if (isHovered) target.draw(frameSprite_hovered, states);
    else target.draw(frameSprite_normal, states);
}

AttackButton::AttackButton(sf::RenderWindow *window, Player *player, Mob* mob, const std::string &iconFileName, sf::Vector2f position)
    : window(window), player(player), mob(mob)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();

    textureHolder.loadFromFile("../GUI/FIGHT_GUI/AttackButton/frame_normal.png", "fightButtonFrame_normal");
    textureHolder.loadFromFile("../GUI/FIGHT_GUI/AttackButton/frame_hovered.png", "fightButtonFrame_hovered");
    sf::Texture* frameNormal = textureHolder.getResource("fightButtonFrame_normal");
    sf::Texture* frameHovered = textureHolder.getResource("fightButtonFrame_hovered");
    frameSprite_normal.setTexture(*frameNormal);
    frameSprite_hovered.setTexture(*frameHovered);
    frameSprite_normal.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                      (float) window->getSize().y / 1080));
    frameSprite_hovered.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                      (float) window->getSize().y / 1080));
    frameSprite_normal.setPosition(position.x * (float) window->getSize().x / 1920,
                            position.y * (float) window->getSize().y / 1080);
    frameSprite_hovered.setPosition(position.x * (float) window->getSize().x / 1920,
                            position.y * (float) window->getSize().y / 1080);

    textureHolder.loadFromFile("../GUI/FIGHT_GUI/AttackButton/" + iconFileName + ".png", "fightButton" + iconFileName);
    sf::Texture* icon = textureHolder.getResource("fightButton" + iconFileName);
    iconSprite.setTexture(*icon);
    iconSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                             (float) window->getSize().y / 1080));
    iconSprite.setPosition(position.x * (float) window->getSize().x / 1920,
                                    position.y * (float) window->getSize().y / 1080);

}

void AttackButton::hoverUpdate(sf::Vector2i mousePosition)
{
    isHovered = iconSprite.getGlobalBounds().contains((float) mousePosition.x, (float) mousePosition.y);
}

void AttackButton::func()
{
    mob->takeDamage(10);
}


/////////////////////////////////// HPBar ///////////////////////////////////
HPBar::HPBar(sf::RenderWindow* window, const std::string &HPFileName, int maxHP, sf::Vector2f position)
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

    textureHolder.loadFromFile("../GUI/FIGHT_GUI/HPBar/" + HPFileName + ".png", HPFileName);
    sf::Texture *HPTexture = textureHolder.getResource(HPFileName);
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

/////////////////////////////////// FightersIconFrame ///////////////////////////////////
FightersIconFrame::FightersIconFrame(sf::RenderWindow *window, Mob* mob, sf::Vector2f position)
    : window(window), mob(mob), player(nullptr)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();

    textureHolder.loadFromFile("../GUI/FIGHT_GUI/FightersIcon/fightersIconFrame.png",
                               "fightersIconFrame");
    sf::Texture *frameTexture = textureHolder.getResource("fightersIconFrame");
    frameSprite.setTexture(*frameTexture);
    frameSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                      (float) window->getSize().y / 1080));
    frameSprite.setPosition(position.x * (float) window->getSize().x / 1920,
                            position.y * (float) window->getSize().y / 1080);

    textureHolder.loadFromFile("../GUI/FIGHT_GUI/FightersIcon/" + mob->getName() + "FightersIcon.png",
                               mob->getName() + "FightersIcon");
    sf::Texture *icon = textureHolder.getResource(mob->getName() + "FightersIcon");
    iconSprite.setTexture(*icon);
    iconSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                     (float) window->getSize().y / 1080));
    iconSprite.setPosition(position.x * (float) window->getSize().x / 1920,
                           position.y * (float) window->getSize().y / 1080);
}

FightersIconFrame::FightersIconFrame(sf::RenderWindow *window, Player* player, sf::Vector2f position)
        : window(window), mob(nullptr), player(player)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();

    textureHolder.loadFromFile("../GUI/FIGHT_GUI/FightersIcon/fightersIconFrame.png",
                               "fightersIconFrame");
    sf::Texture *frameTexture = textureHolder.getResource("fightersIconFrame");
    frameSprite.setTexture(*frameTexture);
    frameSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                      (float) window->getSize().y / 1080));
    frameSprite.setPosition(position.x * (float) window->getSize().x / 1920,
                            position.y * (float) window->getSize().y / 1080);

    textureHolder.loadFromFile("../GUI/FIGHT_GUI/FightersIcon/playerFightersIcon.png",
                               "playerFightersIcon");
    sf::Texture *icon = textureHolder.getResource("playerFightersIcon");
    iconSprite.setTexture(*icon);
    iconSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                     (float) window->getSize().y / 1080));
    iconSprite.setPosition(position.x * (float) window->getSize().x / 1920,
                           position.y * (float) window->getSize().y / 1080);
}

void FightersIconFrame::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(iconSprite, states);
    target.draw(frameSprite, states);
}

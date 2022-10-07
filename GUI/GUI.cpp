#include "GUI.h"

using namespace FIGHT_GUI;
using namespace INVENTORY_GUI;

/////////////////////////////////// AttackButton ///////////////////////////////////
void AttackButton::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (isHovered) target.draw(backgroundSpriteHovered, states);
    else target.draw(backgroundSpriteNormal, states);

    target.draw(itemSprite, states);
}

AttackButton::AttackButton(sf::RenderWindow *window, Player *player, Mob* mob, Item* item, sf::Vector2f position)
    : window(window), player(player), mob(mob), item(item)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();

    textureHolder.loadFromFile("../GUI/FIGHT_GUI/AttackButton/background_normal.png",
                               "fight_background_normal");
    sf::Texture *backgroundNormalTexture = textureHolder.getResource("fight_background_normal");
    backgroundSpriteNormal.setTexture(*backgroundNormalTexture);
    backgroundSpriteNormal.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                           (float) window->getSize().y / 1080));
    backgroundSpriteNormal.setPosition(position.x * (float) window->getSize().x / 1920,
                                 position.y * (float) window->getSize().y / 1080);


    textureHolder.loadFromFile("../GUI/FIGHT_GUI/AttackButton/background_hovered.png",
                               "fight_background_hovered");
    sf::Texture *backgroundHoveredTexture = textureHolder.getResource("fight_background_hovered");
    backgroundSpriteHovered.setTexture(*backgroundHoveredTexture);
    backgroundSpriteHovered.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                                 (float) window->getSize().y / 1080));
    backgroundSpriteHovered.setPosition(position.x * (float) window->getSize().x / 1920,
                                       position.y * (float) window->getSize().y / 1080);

    if (item)
    {
        textureHolder.loadFromFile("../Items/icons/" + item->getName() + ".png",
                                   item->getName());
        sf::Texture *itemTexture = textureHolder.getResource(item->getName());
        itemSprite.setTexture(*itemTexture);

        itemSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                         (float) window->getSize().y / 1080));

        sf::Vector2f centeredItemPosition = {
                backgroundSpriteNormal.getGlobalBounds().left + (backgroundSpriteNormal.getGlobalBounds().width - itemSprite.getGlobalBounds().width) / 2,
                backgroundSpriteNormal.getGlobalBounds().top + (backgroundSpriteNormal.getGlobalBounds().height - itemSprite.getGlobalBounds().height) / 2
        };

        itemSprite.setPosition(centeredItemPosition);
    }

}

void AttackButton::hoverUpdate(sf::Vector2i mousePosition)
{
    isHovered = isHovered ? backgroundSpriteHovered.getGlobalBounds().contains((float) mousePosition.x, (float) mousePosition.y)
            : backgroundSpriteNormal.getGlobalBounds().contains((float) mousePosition.x, (float) mousePosition.y);
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


/////////////////////////////////// FighterIcon ///////////////////////////////////
FighterIcon::FighterIcon(sf::RenderWindow *window, Mob* mob, sf::Vector2f position)
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
                               mob->getName() + "FighterIcon");
    sf::Texture *icon = textureHolder.getResource(mob->getName() + "FighterIcon");
    iconSprite.setTexture(*icon);
    iconSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                     (float) window->getSize().y / 1080));
    iconSprite.setPosition(position.x * (float) window->getSize().x / 1920,
                           position.y * (float) window->getSize().y / 1080);
}

FighterIcon::FighterIcon(sf::RenderWindow *window, Player* player, sf::Vector2f position)
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

void FighterIcon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(iconSprite, states);
    target.draw(frameSprite, states);
}


/////////////////////////////////// EquipmentIcon ///////////////////////////////////
INVENTORY_GUI::EquipmentIcon::EquipmentIcon(sf::RenderWindow *window, Item *item, sf::Vector2f position)
    : UniversalIcon(window, item)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();

    textureHolder.loadFromFile("../GUI/INVENTORY_GUI/Equipment/inventoryEquipment.png",
                               "inventoryEquipmentIcon");
    sf::Texture *backgroundTexture = textureHolder.getResource("inventoryEquipmentIcon");
    backgroundSprite.setTexture(*backgroundTexture);
    backgroundSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                      (float) window->getSize().y / 1080));
    backgroundSprite.setPosition(position.x * (float) window->getSize().x / 1920,
                            position.y * (float) window->getSize().y / 1080);

    if (item)
    {
        textureHolder.loadFromFile("../Items/icons/" + item->getName() + ".png",
                                   item->getName());
        sf::Texture *itemTexture = textureHolder.getResource(item->getName());
        itemSprite.setTexture(*itemTexture);
        itemSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                         (float) window->getSize().y / 1080));
        sf::Vector2f centeredItemPosition = {
                backgroundSprite.getGlobalBounds().left + (backgroundSprite.getGlobalBounds().width - itemSprite.getGlobalBounds().width) / 2,
                5 + backgroundSprite.getGlobalBounds().top + (backgroundSprite.getGlobalBounds().height - itemSprite.getGlobalBounds().height) / 2
        };

        itemSprite.setPosition(centeredItemPosition);
    }
}

void INVENTORY_GUI::EquipmentIcon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(backgroundSprite, states);
    if (item) target.draw(itemSprite, states);
}


/////////////////////////////////// PlayerIcon ///////////////////////////////////
INVENTORY_GUI::PlayerIcon::PlayerIcon(sf::RenderWindow *window, Player *player, sf::Vector2f position)
    : window(window), player(player)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();

    textureHolder.loadFromFile("../GUI/INVENTORY_GUI/PlayerIcon/inventoryPlayerIconFrame.png",
                               "inventoryPlayerIconFrame");
    sf::Texture *frameTexture = textureHolder.getResource("inventoryPlayerIconFrame");
    frameSprite.setTexture(*frameTexture);
    frameSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                           (float) window->getSize().y / 1080));
    frameSprite.setPosition(position.x * (float) window->getSize().x / 1920,
                                 position.y * (float) window->getSize().y / 1080);

    textureHolder.loadFromFile("../GUI/INVENTORY_GUI/PlayerIcon/inventoryPlayerIcon.png",
                               "inventoryPlayerIcon");
    sf::Texture *iconTexture = textureHolder.getResource("inventoryPlayerIcon");
    playerIconSprite.setTexture(*iconTexture);
    playerIconSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                      (float) window->getSize().y / 1080));

    sf::Vector2f centeredIconPosition = {
            frameSprite.getGlobalBounds().left + (frameSprite.getGlobalBounds().width - playerIconSprite.getGlobalBounds().width) / 2,
            frameSprite.getGlobalBounds().top + (frameSprite.getGlobalBounds().height - playerIconSprite.getGlobalBounds().height) / 2
    };
    playerIconSprite.setPosition(centeredIconPosition);
}

void INVENTORY_GUI::PlayerIcon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(frameSprite, states);
    target.draw(playerIconSprite, states);
}


/////////////////////////////////// HotBarIcon ///////////////////////////////////
INVENTORY_GUI::HotBarIcon::HotBarIcon(sf::RenderWindow *window, Item *item, sf::Vector2f position)
    : UniversalIcon(window, item)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();

    textureHolder.loadFromFile("../GUI/INVENTORY_GUI/HotBar/inventoryHotBar.png",
                               "inventoryHotBar");
    sf::Texture *backgroundTexture = textureHolder.getResource("inventoryHotBar");
    backgroundSprite.setTexture(*backgroundTexture);
    backgroundSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                           (float) window->getSize().y / 1080));
    backgroundSprite.setPosition(position.x * (float) window->getSize().x / 1920,
                                 position.y * (float) window->getSize().y / 1080);

    if (item)
    {
        textureHolder.loadFromFile("../Items/icons/" + item->getName() + ".png",
                                   item->getName());
        sf::Texture *itemTexture = textureHolder.getResource(item->getName());
        itemSprite.setTexture(*itemTexture);

        itemSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                         (float) window->getSize().y / 1080));

        sf::Vector2f centeredItemPosition = {
                backgroundSprite.getGlobalBounds().left + (backgroundSprite.getGlobalBounds().width - itemSprite.getGlobalBounds().width) / 2,
                backgroundSprite.getGlobalBounds().top + (backgroundSprite.getGlobalBounds().height - itemSprite.getGlobalBounds().height) / 2
        };

        itemSprite.setPosition(centeredItemPosition);
    }
}

void INVENTORY_GUI::HotBarIcon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(backgroundSprite, states);
    if (item) target.draw(itemSprite, states);
}


/////////////////////////////////// InventoryIcon ///////////////////////////////////
INVENTORY_GUI::InventoryIcon::InventoryIcon(sf::RenderWindow *window, Item *item, sf::Vector2f position)
        : UniversalIcon(window, item)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();

    textureHolder.loadFromFile("../GUI/INVENTORY_GUI/Inventory/inventoryInventory.png",
                               "inventoryInventory");
    sf::Texture *backgroundTexture = textureHolder.getResource("inventoryInventory");
    backgroundSprite.setTexture(*backgroundTexture);
    backgroundSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                           (float) window->getSize().y / 1080));
    backgroundSprite.setPosition(position.x * (float) window->getSize().x / 1920,
                                 position.y * (float) window->getSize().y / 1080);

    if (item)
    {
        textureHolder.loadFromFile("../Items/icons/" + item->getName() + ".png",
                                   item->getName());
        sf::Texture *itemTexture = textureHolder.getResource(item->getName());
        itemSprite.setTexture(*itemTexture);

        itemSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                         (float) window->getSize().y / 1080));

        sf::Vector2f centeredItemPosition = {
                backgroundSprite.getGlobalBounds().left + (backgroundSprite.getGlobalBounds().width - itemSprite.getGlobalBounds().width) / 2,
                backgroundSprite.getGlobalBounds().top + (backgroundSprite.getGlobalBounds().height - itemSprite.getGlobalBounds().height) / 2
        };

        itemSprite.setPosition(centeredItemPosition);
    }
}

void INVENTORY_GUI::InventoryIcon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(backgroundSprite, states);
    if (item) target.draw(itemSprite, states);
}


INVENTORY_GUI::WeaponIcon::WeaponIcon(sf::RenderWindow *window, Item *item, sf::Vector2f position)
        : UniversalIcon(window, item)
{
    TextureHolder& textureHolder = TextureHolder::getInstance();

    textureHolder.loadFromFile("../GUI/INVENTORY_GUI/WeaponIcon/inventoryWeaponIcon.png",
                               "inventoryWeaponIcon");
    sf::Texture *backgroundTexture = textureHolder.getResource("inventoryWeaponIcon");
    backgroundSprite.setTexture(*backgroundTexture);
    backgroundSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                           (float) window->getSize().y / 1080));
    backgroundSprite.setPosition(position.x * (float) window->getSize().x / 1920,
                                 position.y * (float) window->getSize().y / 1080);

    if (item)
    {
        textureHolder.loadFromFile("../Items/icons/" + item->getName() + ".png",
                                   item->getName());
        sf::Texture *itemTexture = textureHolder.getResource(item->getName());
        itemSprite.setTexture(*itemTexture);

        itemSprite.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                         (float) window->getSize().y / 1080));

        sf::Vector2f centeredItemPosition = {
                backgroundSprite.getGlobalBounds().left + (backgroundSprite.getGlobalBounds().width - itemSprite.getGlobalBounds().width) / 2,
                backgroundSprite.getGlobalBounds().top + (backgroundSprite.getGlobalBounds().height - itemSprite.getGlobalBounds().height) / 2
        };

        itemSprite.setPosition(centeredItemPosition);
    }
}

void INVENTORY_GUI::WeaponIcon::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(backgroundSprite, states);
    if (item) target.draw(itemSprite, states);
}

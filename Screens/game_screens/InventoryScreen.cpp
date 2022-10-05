#include "InventoryScreen.h"

void InventoryScreen::open(Player* player)
{
    Blur backgroundBlur(background->getSize(), 2);
    sf::Sprite backgroundSprite(backgroundBlur.apply(background->getTexture()));

    loadVisualElements(player);
    swapHolder.loadIcons(&player->inventory, allInventoryIcons, allHotBarIcons, allEquipmentIcons);

    while (true)
    {
        clock->restart().asSeconds();
        sf::Event event = {};

        for (auto& bar : allPlayerBars) bar.update(player->getHp());

        while (window->pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                swapHolder.breakSwap();
                return;
            }
        }

        swapHolder.update();
        if (swapHolder.needToReloadVisualElements)
        {
            loadVisualElements(player);
            swapHolder.loadIcons(&player->inventory, allInventoryIcons, allHotBarIcons, allEquipmentIcons);
            swapHolder.needToReloadVisualElements = false;
        }

        window->clear();
        window->draw(backgroundSprite);

        window->draw(inventoryBackground);
        for (auto& icon : allEquipmentIcons) window->draw(icon);
        for (auto& icon : allPlayerIcons) window->draw(icon);
        for (auto& bar : allPlayerBars) window->draw(bar);
        for (auto& icon : allHotBarIcons) window->draw(icon);
        for (auto& icon : allInventoryIcons) window->draw(icon);
        window->draw(swapHolder);

        window->display();
    }
}

void InventoryScreen::loadVisualElements(Player* player)
{
    allEquipmentIcons.clear();
    allPlayerIcons.clear();
    allPlayerBars.clear();
    allHotBarIcons.clear();
    allInventoryIcons.clear();

    TextureHolder& textureHolder = TextureHolder::getInstance();

    /* Задний фон */
    textureHolder.loadFromFile("../GUI/INVENTORY_GUI/Background/inventoryBackground.png", "inventoryBackground");
    sf::Texture *texture = textureHolder.getResource("inventoryBackground");
    inventoryBackground.setTexture(*texture);
    inventoryBackground.setScale(sf::Vector2f((float) window->getSize().x / 1920,
                                          (float) window->getSize().y / 1080));
    inventoryBackground.setPosition(sf::Vector2f(688 * (float) window->getSize().x / 1920,
                                             276 * (float) window->getSize().y / 1080));

    /* Иконки снаряжения */
    INVENTORY_GUI::EquipmentIcon helmetIcon(window, player->inventory.inv[0], sf::Vector2f(742, 334));
    INVENTORY_GUI::EquipmentIcon leggingsIcon(window, player->inventory.inv[1], sf::Vector2f(896, 334));
    INVENTORY_GUI::EquipmentIcon chestPlateIcon(window, player->inventory.inv[2], sf::Vector2f(742, 403));
    INVENTORY_GUI::EquipmentIcon bootsIcon(window, player->inventory.inv[3], sf::Vector2f(896, 403));
    allEquipmentIcons.push_back(helmetIcon);
    allEquipmentIcons.push_back(leggingsIcon);
    allEquipmentIcons.push_back(chestPlateIcon);
    allEquipmentIcons.push_back(bootsIcon);

    /* Иконка игрока */
    INVENTORY_GUI::PlayerIcon playerIcon(window, player, sf::Vector2f(806, 493));
    allPlayerIcons.push_back(playerIcon);

    /* Бар здоровья игрока */
    FIGHT_GUI::HPBar playerBar(window, "HPPlayerBarHP", player->getMaxHp(), sf::Vector2f(774, 616));
    allPlayerBars.push_back(playerBar);

    /* Хот бар */
    INVENTORY_GUI::HotBarIcon hotBarIcon1(window, player->inventory.inv[4], sf::Vector2f(742, 699));
    INVENTORY_GUI::HotBarIcon hotBarIcon2(window, player->inventory.inv[5], sf::Vector2f(869, 699));
    INVENTORY_GUI::HotBarIcon hotBarIcon3(window, player->inventory.inv[6], sf::Vector2f(996, 699));
    INVENTORY_GUI::HotBarIcon hotBarIcon4(window, player->inventory.inv[7], sf::Vector2f(1123, 699));
    allHotBarIcons.push_back(hotBarIcon1);
    allHotBarIcons.push_back(hotBarIcon2);
    allHotBarIcons.push_back(hotBarIcon3);
    allHotBarIcons.push_back(hotBarIcon4);

    /* Основной инвентарь */
    INVENTORY_GUI::InventoryIcon icon1(window, player->inventory.inv[8], sf::Vector2f(981, 330));
    INVENTORY_GUI::InventoryIcon icon2(window, player->inventory.inv[9], sf::Vector2f(1052, 330));
    INVENTORY_GUI::InventoryIcon icon3(window, player->inventory.inv[10], sf::Vector2f(1123, 330));
    INVENTORY_GUI::InventoryIcon icon4(window, player->inventory.inv[11], sf::Vector2f(981, 399));
    INVENTORY_GUI::InventoryIcon icon5(window, player->inventory.inv[12], sf::Vector2f(1052, 399));
    INVENTORY_GUI::InventoryIcon icon6(window, player->inventory.inv[13], sf::Vector2f(1123, 399));
    INVENTORY_GUI::InventoryIcon icon7(window, player->inventory.inv[14], sf::Vector2f(981, 468));
    INVENTORY_GUI::InventoryIcon icon8(window, player->inventory.inv[15], sf::Vector2f(1052, 468));
    INVENTORY_GUI::InventoryIcon icon9(window, player->inventory.inv[16], sf::Vector2f(1123, 468));
    INVENTORY_GUI::InventoryIcon icon10(window, player->inventory.inv[17], sf::Vector2f(981, 537));
    INVENTORY_GUI::InventoryIcon icon11(window, player->inventory.inv[18], sf::Vector2f(1052, 537));
    INVENTORY_GUI::InventoryIcon icon12(window, player->inventory.inv[19], sf::Vector2f(1123, 537));
    INVENTORY_GUI::InventoryIcon icon13(window, player->inventory.inv[20], sf::Vector2f(981, 606));
    INVENTORY_GUI::InventoryIcon icon14(window, player->inventory.inv[21], sf::Vector2f(1052, 606));
    INVENTORY_GUI::InventoryIcon icon15(window, player->inventory.inv[22], sf::Vector2f(1123, 606));
    allInventoryIcons.push_back(icon1);
    allInventoryIcons.push_back(icon2);
    allInventoryIcons.push_back(icon3);
    allInventoryIcons.push_back(icon4);
    allInventoryIcons.push_back(icon5);
    allInventoryIcons.push_back(icon6);
    allInventoryIcons.push_back(icon7);
    allInventoryIcons.push_back(icon8);
    allInventoryIcons.push_back(icon9);
    allInventoryIcons.push_back(icon10);
    allInventoryIcons.push_back(icon11);
    allInventoryIcons.push_back(icon12);
    allInventoryIcons.push_back(icon13);
    allInventoryIcons.push_back(icon14);
    allInventoryIcons.push_back(icon15);
}

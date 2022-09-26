#include "TileMap.h"

#include "rapidxml/rapidxml_utils.hpp"
#include <iostream>
#include <cstring>
#include <sstream>

/////////////////////////////////// Конструктор ///////////////////////////////////
TileMap::TileMap(int LEVEL)
{
    level = LEVEL;

    TextureHolder& textureHolder = TextureHolder::getInstance();
    if (level == 1)
    {
        textureHolder.loadFromFile("../Levels/images/level_1_tileSet.png", "mapTileSet1");
    }
}

/////////////////////////////////// Отрисовка ///////////////////////////////////
void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    TextureHolder& textureHolder = TextureHolder::getInstance();
    sf::Texture *texture;

    if (level == 1)
    {
        texture = textureHolder.getResource("mapTileSet1");
    }

    target.draw(vertexArray, texture);
}

/////////////////////////////////// Загрузка карты ///////////////////////////////////
bool TileMap::load(std::vector<int> tiles)
{
    int width = mapSizes.x;
    int height = mapSizes.y;

    vertexArray = sf::VertexArray(sf::Quads, width * height * 4);

    TextureHolder& textureHolder = TextureHolder::getInstance();
    sf::Texture *mapTexture = textureHolder.getResource("mapTileSet1");

    countOfTilesInImageX = mapTexture->getSize().x / tileSizes.x;
    countOfTilesInImageY = mapTexture->getSize().y / tileSizes.y;

    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            int id = tiles[i + j * width];

            if (id > 0)
            {
                /* Загрузка карты через VertexArray */
                sf::Vertex* quad = &vertexArray[(i + j * width) * 4];

                quad[0].position = sf::Vector2f(i * tileSizes.x, j * tileSizes.y);
                quad[1].position = sf::Vector2f( (i + 1) * tileSizes.x, j * tileSizes.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSizes.x, (j + 1) * tileSizes.y);
                quad[3].position = sf::Vector2f(i * tileSizes.x, (j + 1) * tileSizes.y);

                sf::Vector2i texLeftTop(
                        ((id - 1) % countOfTilesInImageX) * tileSizes.x,
                        ((id - 1 - abs(countOfTilesInImageX - countOfTilesInImageY)) / countOfTilesInImageY) * tileSizes.y
                );

                quad[0].texCoords = sf::Vector2f(texLeftTop.x, texLeftTop.y);
                quad[1].texCoords = sf::Vector2f(texLeftTop.x + tileSizes.x, texLeftTop.y);
                quad[2].texCoords = sf::Vector2f(texLeftTop.x + tileSizes.x, texLeftTop.y + tileSizes.y);
                quad[3].texCoords = sf::Vector2f(texLeftTop.x, texLeftTop.y + tileSizes.y);

                /* Загрузка GlobalBouds стен на карте */
                if (std::find(std::begin(wallIds), std::end(wallIds), id) != std::end(wallIds))
                {
                    wallBounds.push_back(sf::FloatRect(quad[0].position.x, quad[0].position.y, tileSizes.x, tileSizes.y));
                }
            }


        }
    return true;
}

void TileMap::readMapFromFile()
{
    /* Получение map */
    std::ifstream mapFile("../Levels/maps/level_1.tmx");
    rapidxml::xml_document<> mapDoc;

    std::vector<char> mapBuffer((std::istreambuf_iterator<char>(mapFile)), std::istreambuf_iterator<char>());
    mapBuffer.push_back('\0');
    mapDoc.parse<0>(&mapBuffer[0]);

    rapidxml::xml_node<> *curNode = mapDoc.first_node("map")->first_node("layer")->first_node("data");
    std::string mapData = curNode->value();

    std::vector<int> ids;
    std::stringstream ss(mapData);
    int id;
    char ch;

    while(ss >> id)
    {
        if(ss >> ch)
            ids.push_back(id);
        else
            ids.push_back(id);
    }

    /* Получение objects */
    std::ifstream objectsFile("../Levels/maps/level_1.tsx");
    rapidxml::xml_document<> objectsDoc;

    std::vector<char> ObjectsBuffer((std::istreambuf_iterator<char>(objectsFile)), std::istreambuf_iterator<char>());
    ObjectsBuffer.push_back('\0');
    objectsDoc.parse<0>(&ObjectsBuffer[0]);

    curNode = objectsDoc.first_node("tileset")->first_node("tile");

    while(curNode)
    {
        if (0 == strcmp(curNode->first_attribute("class")->value(), "wall"))
        {
            wallIds.push_back(atoi(curNode->first_attribute("id")->value()) + 1);
        }

        curNode = curNode->next_sibling();
    }

    /* Получение артибутов карты */
    curNode = mapDoc.first_node("map");

    rapidxml::xml_attribute<> *width = curNode->first_attribute("width");
    rapidxml::xml_attribute<> *height = curNode->first_attribute("height");
    rapidxml::xml_attribute<> *tileWidth = curNode->first_attribute("tilewidth");
    rapidxml::xml_attribute<> *tileHeight = curNode->first_attribute("tileheight");
    /* Присвоение атрибутов */
    map = ids;
    mapSizes = sf::Vector2i(atoi(width->value()), atoi(height->value()));
    tileSizes = sf::Vector2i(atoi(tileWidth->value()), atoi(tileHeight->value()));
}

/////////////////////////////////// Общая функция загрузки карты ///////////////////////////////////
void TileMap::buildMap()
{
    readMapFromFile();
    load(map);
}

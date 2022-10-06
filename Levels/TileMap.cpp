#include "TileMap.h"

TileMap::TileMap()
{
    TextureHolder& textureHolder = TextureHolder::getInstance();
    textureHolder.loadFromFile("../Levels/images/map_level_1.png", "map_level_1");
}

void TileMap::loadMap(int level, sf::RenderWindow* window)
{
    this->level = level;
    this->window = window;

    loadLevelIds("level_" + std::to_string(level));
    loadVertexArray("level_" + std::to_string(level));
}

void TileMap::loadLevelIds(const std::string &level)
{
    /* Удаление предыдущей карты */
    map.clear();
    wallIds.clear();
    textureCoordinates.clear();
    wallBounds.clear();

    /* Загрузка id всех тайлов карты */
    std::ifstream mapFile("../Levels/maps/" + level + ".tmx");
    rapidxml::xml_document<> mapDoc;

    std::vector<char> mapBuffer((std::istreambuf_iterator<char>(mapFile)), std::istreambuf_iterator<char>());
    mapBuffer.push_back('\0');
    mapDoc.parse<0>(&mapBuffer[0]);

    rapidxml::xml_node<> *curNode = mapDoc.first_node("map")->first_node("layer")->first_node("data");
    std::string mapData = curNode->value();

    std::stringstream ss_(mapData);
    int id_;
    char ch_;

    while(ss_ >> id_)
    {
        if(ss_ >> ch_)
            map.push_back(id_ - 1);
        else
            map.push_back(id_ - 1);
    }

    /* Загрузка id всех стен карты */
    std::ifstream objectsFile("../Levels/maps/level_1.tsx");
    rapidxml::xml_document<> objectsDoc;

    std::vector<char> ObjectsBuffer((std::istreambuf_iterator<char>(objectsFile)), std::istreambuf_iterator<char>());
    ObjectsBuffer.push_back('\0');
    objectsDoc.parse<0>(&ObjectsBuffer[0]);

    curNode = objectsDoc.first_node("tileset")->first_node("tile");

    while(curNode)
    {
        /* Загрузка id стен */
        if (curNode->first_attribute("class"))
        {
            if (0 == strcmp(curNode->first_attribute("class")->value(), "wall"))
            {
                wallIds.push_back(atoi(curNode->first_attribute("id")->value()));
            }
        }

        /* Загрузка текстурных координат */
        int id = atoi(curNode->first_attribute("id")->value());

        rapidxml::xml_node<> *childNode = curNode->first_node("properties")->first_node("property");
        int left = atoi(childNode->first_attribute("value")->value());
        childNode = childNode->next_sibling();
        int top = atoi(childNode->first_attribute("value")->value());

        textureCoordinates[id] = {left, top};

        curNode = curNode->next_sibling();
    }

    /* Получение артибутов карты */
    curNode = mapDoc.first_node("map");

    rapidxml::xml_attribute<> *width = curNode->first_attribute("width");
    rapidxml::xml_attribute<> *height = curNode->first_attribute("height");
    rapidxml::xml_attribute<> *tileWidth = curNode->first_attribute("tilewidth");
    rapidxml::xml_attribute<> *tileHeight = curNode->first_attribute("tileheight");

    mapSizes = {atoi(width->value()), atoi(height->value())};
    tileSizes = {atoi(tileWidth->value()), atoi(tileHeight->value())};
}

void TileMap::loadVertexArray(const std::string &level)
{
    vertexArray = sf::VertexArray(sf::Quads, mapSizes.x * mapSizes.y * 4);

    for (unsigned int i = 0; i < mapSizes.x; ++i)
    {
        for (unsigned int j = 0; j < mapSizes.y; ++j)
        {
            int id = map[i + j * mapSizes.x];

            /* Координаты тек. вертекса */
            sf::Vertex* quad = &vertexArray[(i + j * mapSizes.x) * 4];

            quad[0].position = sf::Vector2f(i * tileSizes.x * window->getSize().x / 1920, j * tileSizes.y * window->getSize().y / 1080);
            quad[1].position = sf::Vector2f( (i + 1) * tileSizes.x * window->getSize().x / 1920, j * tileSizes.y * window->getSize().y / 1080);
            quad[2].position = sf::Vector2f((i + 1) * tileSizes.x * window->getSize().x / 1920, (j + 1) * tileSizes.y * window->getSize().y / 1080);
            quad[3].position = sf::Vector2f(i * tileSizes.x * window->getSize().x / 1920, (j + 1) * tileSizes.y * window->getSize().y / 1080);

            /* Текстурные координаты */
            sf::Vector2i texLeftTop = textureCoordinates[id];

            quad[0].texCoords = sf::Vector2f(texLeftTop.x, texLeftTop.y);
            quad[1].texCoords = sf::Vector2f(texLeftTop.x + tileSizes.x, texLeftTop.y);
            quad[2].texCoords = sf::Vector2f(texLeftTop.x + tileSizes.x, texLeftTop.y + tileSizes.y);
            quad[3].texCoords = sf::Vector2f(texLeftTop.x, texLeftTop.y + tileSizes.y);

            /* Заполнение вектора Bounds'ов всех стен на карте */
            if (std::find(std::begin(wallIds), std::end(wallIds), id) != std::end(wallIds))
            {
                wallBounds.push_back(sf::FloatRect(
                        quad[0].position.x,
                        quad[0].position.y,
                        tileSizes.x * window->getSize().x / 1920,
                        tileSizes.y * window->getSize().y / 1080)
                );
            }
        }
    }
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    TextureHolder& textureHolder = TextureHolder::getInstance();
    sf::Texture *texture = textureHolder.getResource("map_level_" + std::to_string(level));

    target.draw(vertexArray, texture);
}

#ifndef CROISSANT_TILEMAP_H
#define CROISSANT_TILEMAP_H

#include "SFML/Graphics.hpp"

#include "../Resources/ResourceHolder.h"

class TileMap : public sf::Drawable
{

public:
    explicit TileMap(int LEVEL);

    void buildMap();

    std::vector<sf::FloatRect> getWallBounds() {return wallBounds;}

private:
    int level;
    sf::VertexArray vertexArray;

    int countOfTilesInImageX;
    int countOfTilesInImageY;

    sf::Vector2i mapSizes;
    sf::Vector2i tileSizes;
    std::vector<int> map;

    std::vector<int> wallIds;
    std::vector<sf::FloatRect> wallBounds;

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void readMapFromFile();
    bool load(std::vector<int> tiles);

};


#endif //CROISSANT_TILEMAP_H

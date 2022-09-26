#ifndef CROISSANT_TILEMAP_H
#define CROISSANT_TILEMAP_H

#include "SFML/Graphics.hpp"

#include "../Resources/ResourceHolder.h"

class TileMap : public sf::Drawable
{

public:
    /////////////////////////////////// Конструктор ///////////////////////////////////
    explicit TileMap(int LEVEL);

    /////////////////////////////////// Общая функция загрузки карты ///////////////////////////////////
    void buildMap();

    /////////////////////////////////// Доступные атрибуты ///////////////////////////////////
    std::vector<sf::FloatRect> wallBounds; // Вектор Bounds всех стен на карте

private:
    int level; // Текущий уровень (локация)
    sf::VertexArray vertexArray; // Массив вертексов карты

    int countOfTilesInImageX; // Ширина тайлсета в тайлах
    int countOfTilesInImageY; // Высота тайлсета в тайлах

    sf::Vector2i mapSizes; // Размер карты в тайлах
    sf::Vector2i tileSizes; // Размер тайлов в пикселях
    std::vector<int> map; // Вектор id всех тайлов на карте

    std::vector<int> wallIds; // Вектор id всех стен на карте

private:
    /////////////////////////////////// Отрисовка ///////////////////////////////////
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    /////////////////////////////////// Парсинг .tmx и .tsx файлов локаций ///////////////////////////////////
    void readMapFromFile();

    /////////////////////////////////// Загрузка карты ///////////////////////////////////
    bool load(std::vector<int> tiles);

};


#endif //CROISSANT_TILEMAP_H

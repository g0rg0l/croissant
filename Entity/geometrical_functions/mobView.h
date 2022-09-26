#ifndef Roguelike_MOBVIEW_H
#define Roguelike_MOBVIEW_H

#include "SFML/Graphics.hpp"

/////////////////////////////* Векторное произведение векторов *//////////////////////////////////////////
float vectorProduct(float x1, float y1, float x2, float y2);

/////////////////////////////* Пересечение отрезков *//////////////////////////////////////////
bool linesCrossing(sf::Vector2f firstLine[], sf::Vector2f secondLine[]);

/////////////////////////////* Пересечение отрезка и прямоугольника *//////////////////////////////////////////
bool lineCrossingRectangle(sf::Vector2f line[], sf::Vector2f rectangle[]);

#endif //Roguelike_MOBVIEW_H

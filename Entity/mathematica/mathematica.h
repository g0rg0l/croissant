#ifndef Roguelike_MOBVIEW_H
#define Roguelike_MOBVIEW_H

#include "SFML/Graphics.hpp"

/* ----------------------------- mob view ----------------------------- */

float vectorProduct(float x1, float y1, float x2, float y2);

bool linesCrossing(sf::Vector2f firstLine[], sf::Vector2f secondLine[]);

bool lineCrossingRectangle(sf::Vector2f line[], sf::Vector2f rectangle[]);


/* ----------------------------- random functions ----------------------------- */

double getRandomDamageMultiplier(double from, double to);


#endif //Roguelike_MOBVIEW_H

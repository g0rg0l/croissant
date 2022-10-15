#include "mathematica.h"

/////////////////////////////* Векторное произведение векторов *//////////////////////////////////////////
float vectorProduct(float x1, float y1, float x2, float y2)
{
    return x1 * y2 - x2 * y1;
}

/////////////////////////////* Пересечение отрезков *//////////////////////////////////////////
bool linesCrossing(sf::Vector2f firstLine[], sf::Vector2f secondLine[])
{
    float x1 = firstLine[0].x;
    float y1 = firstLine[0].y;
    float x2 = firstLine[1].x;
    float y2 = firstLine[1].y;

    float x3 = secondLine[0].x;
    float y3 = secondLine[0].y;
    float x4 = secondLine[1].x;
    float y4 = secondLine[1].y;

    float v1 = vectorProduct(x4 - x3, y4 - y3, x1 - x3, y1 - y3);
    float v2 = vectorProduct(x4 - x3, y4 - y3, x2 - x3, y2 - y3);
    float v3 = vectorProduct(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
    float v4 = vectorProduct(x2 - x1, y2 - y1, x4 - x1, y4 - y1);

    return (v1 * v2 < 0 && v3 * v4 < 0);
}

/////////////////////////////* Пересечение отрезка и прямоугольника *//////////////////////////////////////////
bool lineCrossingRectangle(sf::Vector2f line[], sf::Vector2f rectangle[])
{
    sf::Vector2f line1[] = {rectangle[0], rectangle[1]};
    sf::Vector2f line2[] = {rectangle[1], rectangle[2]};
    sf::Vector2f line3[] = {rectangle[2], rectangle[3]};
    sf::Vector2f line4[] = {rectangle[3], rectangle[0]};

    /* Если хотя бы одна прямая прямоугольника пересекается с линией */
    if (linesCrossing(line, line1) ||
    linesCrossing(line, line2) ||
    linesCrossing(line, line3) ||
    linesCrossing(line, line4))
    {
        return true;
    }
    return false;
}
#include "mathematica.h"

double getRandomDamageMultiplier(double from, double to)
{
    int iMin = (int) (from * 100);
    int iMax = (int) (to * 100);
    int iMultiplier = iMin + (rand() % (iMax - iMin + 1));

    return (double) iMultiplier / 100;
}
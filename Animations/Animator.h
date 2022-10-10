#ifndef ENEMY1_H_ANIMATOR_H
#define ENEMY1_H_ANIMATOR_H

#include "SFML/Graphics.hpp"

class Animator
{
private:
    Animator() = default;
    ~Animator() = default;

public:
    static Animator& getInstance();

public:
    void manifest(sf::RenderWindow* window, sf::Clock* clock, sf::RenderTexture* background,  sf::RenderTexture* textureToManifest);
    void unManifest(sf::RenderWindow* window, sf::Clock* clock, sf::RenderTexture* background,  sf::RenderTexture* textureToManifest);
};


#endif //ENEMY1_H_ANIMATOR_H

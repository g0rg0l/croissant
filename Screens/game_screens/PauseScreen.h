#ifndef ENEMY1_H_PAUSESCREEN_H
#define ENEMY1_H_PAUSESCREEN_H

#include "SFML/Graphics.hpp"
#include "../dynamic_blur.hpp"

class PauseScreen
{

public:
    explicit PauseScreen(sf::RenderWindow* window,
            sf::RenderTexture* renderTexture,
            sf::Clock* clock)
    : window(window), background(renderTexture), clock(clock) { }

public:
    void open();
    void loadVisualElements();

private:
    sf::RenderWindow* window;
    sf::RenderTexture* background;
    sf::Clock* clock;

};


#endif //ENEMY1_H_PAUSESCREEN_H

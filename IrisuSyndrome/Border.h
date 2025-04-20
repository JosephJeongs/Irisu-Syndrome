#ifndef BORDER_H
#define BORDER_H

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

class Border {
public:
    Border(b2World* world, float length, float height, float x, float y);  // Constructor
    void draw(sf::RenderWindow& window);  // Draw

    b2Body* body;

private:
};

#endif 
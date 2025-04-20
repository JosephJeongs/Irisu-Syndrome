#ifndef BULLET_H
#define BULLET_H

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet(b2World* world, float x, float y);  // Constructor
    void draw(sf::RenderWindow& window);  // Draw

    b2Body* body;  

private:
};

#endif 
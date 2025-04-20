#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include "Bullet.h" 
#include "BulletContactListener.h"
#include "Border.h"

int main() {
    int windowHeight = sf::VideoMode::getDesktopMode().height - 80, windowWidth = 3 * (windowHeight / 2) ;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Irisu Syndrome", sf::Style::Titlebar | sf::Style::Close);
    window.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width - windowWidth) / 2, (sf::VideoMode::getDesktopMode().height - windowHeight) / 2 - 40));
    window.setFramerateLimit(60);

    b2Vec2 gravity(0.0f, 9.81f);
    b2World world(gravity);

    sf::Texture texture;
    if (!texture.loadFromFile("DoNotIgnoreHer.png")) {return -1;}

    sf::Sprite irisu(texture);
    irisu.setScale(0.444f, 0.444f);

    sf::FloatRect irisuBounds = irisu.getLocalBounds();
    irisu.setOrigin(irisuBounds.width / 2.f, irisuBounds.height / 2.f);
    irisu.setPosition(windowWidth / 2.f, windowHeight / 2.f);

    //BulletContactListener contactListener;
    //world.SetContactListener(&contactListener);

    std::vector<Bullet*> bullets;

    //sf::Clock clock;

    bool focusedWindow = true;
    Border floor(&world, 10.f, 0.5f, 25, 25);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    float x = event.mouseButton.x / 30.f; 
                    float y = event.mouseButton.y / 30.f;

                    bullets.push_back(new Bullet(&world, x, y));
                }
            }
            else if (event.type == sf::Event::LostFocus) {
                focusedWindow = false;
            }
            else if (event.type == sf::Event::GainedFocus) {
                focusedWindow = true;
            }
        }

        world.Step(1.0f / 60.0f, 8, 4); 
        window.clear();
        if (!focusedWindow) {
            window.draw(irisu);
        }
        else {
            floor.draw(window);
            for (Bullet* bullet : bullets) {
                bullet->draw(window);
            }
        }
        
        window.display();
    }

    for (Bullet* bullet : bullets) {
        delete bullet; 
    }

    return 0;
}

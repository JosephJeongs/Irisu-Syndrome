#include "Border.h"

Border::Border(b2World* world, float width, float height, float x, float y) {
    b2BodyDef borderDef;
    borderDef.type = b2_staticBody;
    borderDef.position.Set(x, y);

    body = world->CreateBody(&borderDef);

    b2PolygonShape borderShape;
    borderShape.SetAsBox(width, height);

    b2FixtureDef borderFixture;
    borderFixture.shape = &borderShape;
    borderFixture.density = 10.0f;
    borderFixture.friction = 1.0f;
    borderFixture.restitution = 0.0f;

    body->CreateFixture(&borderFixture);
}

void Border::draw(sf::RenderWindow& window) {
    sf::RectangleShape border(sf::Vector2f(29.f, 29.f));
    border.setFillColor(sf::Color(255, 255, 255));

    b2Vec2 position = body->GetPosition();

    border.setPosition(position.x * 30.f, position.y * 30.f);

    window.draw(border);
}
#include "Bullet.h"

Bullet::Bullet(b2World* world, float x, float y) {
    b2BodyDef bulletDef;
    bulletDef.type = b2_dynamicBody;
    bulletDef.position.Set(x, y);

    body = world->CreateBody(&bulletDef);

    b2PolygonShape bulletShape;
    bulletShape.SetAsBox(0.5f, 0.5f);

    b2FixtureDef bulletFixture;
    bulletFixture.shape = &bulletShape; 
    bulletFixture.density = 1.0f;
    bulletFixture.friction = 1.0f;
    bulletFixture.restitution = 0.0f;

    body->CreateFixture(&bulletFixture);

    b2Vec2 bulletVelocity(0.0f, -10.0f);
    body->SetLinearVelocity(bulletVelocity);
}

void Bullet::draw(sf::RenderWindow& window) {
    sf::RectangleShape bullet(sf::Vector2f(30.f, 30.f));
    bullet.setFillColor(sf::Color(255, 255, 255, 150));

    b2Vec2 position = body->GetPosition();

    bullet.setPosition(position.x * 29.5f, position.y * 29.5f);

    window.draw(bullet);
}
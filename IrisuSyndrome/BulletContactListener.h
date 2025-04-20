// BulletContactListener.h
#ifndef BULLET_CONTACT_LISTENER_H
#define BULLET_CONTACT_LISTENER_H

#include <box2d/box2d.h>

class BulletContactListener : public b2ContactListener {
public:
    BulletContactListener() {}

    void BeginContact(b2Contact* contact) override {
        b2Body* bodyA = contact->GetFixtureA()->GetBody();
        b2Body* bodyB = contact->GetFixtureB()->GetBody();

        if (bodyA && bodyB) {
            ApplyTorqueToBody(bodyA);
            ApplyTorqueToBody(bodyB);
        }
    }

    void EndContact(b2Contact* contact) override {
    }

    void ApplyTorqueToBody(b2Body* body) {
        float torque = 100.0f; // Adjust this value to control the rotation speed
        body->ApplyTorque(torque, true); // Apply torque to rotate the body
    }
};

#endif 

//
// Created by Jacopo Gasparetto on 13/09/21.
//

#include "Verlet/Particle.h"

// ---- SETTERS ----
void Particle::setInitialVelocity(const sf::Vector2f &v) {
    m_oldPos = getPosition() + v;
}

// ---- GETTERS ----
sf::Time Particle::getElapsedTime() {
    return m_clock.getElapsedTime();
}


// ---- LOOP METHODS ----

void Particle::loop() {

    m_velocity = getPosition() - m_oldPos;
    m_oldPos = sf::Vector2f{ getPosition() };
    m_velocity.y += Physics::gravity;
    move(m_velocity);
}

void Particle::bounce(const sf::Window &w) {

    auto pos = getPosition();
    auto size = static_cast<sf::Vector2f>(w.getSize());

    if (pos.x > size.x - Particle::radius * 2.0f) {
        pos.x = size.x - Particle::radius * 2.0f;
        m_oldPos.x = (pos.x + m_velocity.x) * Physics::bounce;
        setPosition(pos);
    } else if (pos.x <  Particle::radius * 2.0f) {
        pos.x = Particle::radius * 2.0f;
        m_oldPos.x = (pos.x + m_velocity.x) * Physics::bounce;
        setPosition(pos);
    }

    if (pos.y > size.y - Particle::radius * 2.0f) {
        pos.y = size.y - Particle::radius * 2.0f;
        m_oldPos.y = (pos.y + m_velocity.y) * Physics::bounce;
        setPosition(pos);
    } else if (pos.y < Particle::radius * 2.0f) {
        pos.y = Particle::radius * 2.0f;
        m_oldPos.y = (pos.y + m_velocity.y) * Physics::bounce;
        setPosition(pos);
    }
}





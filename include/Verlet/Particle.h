//
// Created by Jacopo Gasparetto on 13/09/21.
//

#ifndef VERLET_PARTICLE_H
#define VERLET_PARTICLE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "constants.h"

class Particle : public sf::CircleShape {
public:
    static constexpr float radius = 5.0f;

private:
    sf::Vector2f m_oldPos;
    sf::Vector2f m_velocity;
    sf::Clock m_clock{};
    bool m_isConstraint{};

public:
    Particle() {
        init();
    }

    explicit Particle(const sf::Vector2f &position) {
        setPosition(position);
        init();
    }

    void init();

//    ~Particle() override {
//        std::cout << "Destroy!\n";
//    }

    void setInitialVelocity(const sf::Vector2f &v);

    sf::Time getElapsedTime();

    void loop();

    void bounce(const sf::Window &w);

    void setConstraint();

    bool isConstraint() const;

};


#endif //VERLET_PARTICLE_H

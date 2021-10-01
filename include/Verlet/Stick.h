//
// Created by Jacopo Gasparetto on 19/09/21.
//

#ifndef VERLET_STICK_H
#define VERLET_STICK_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "Verlet/VectorMath.h"
#include "Verlet/Particle.h"

class App;

class Stick : public sf::Drawable, public sf::Transformable {

private:
    const float m_length;
    Particle &m_p1;
    Particle &m_p2;
    sf::VertexArray m_vertices{ sf::Quads, 4};
    float thickness = 2.0f;

    bool m_isActive = true;

public:
    Stick(Particle &p1, Particle &p2);

    void updateStick();

    friend class App;

    bool isActive() const;

    void deactivate();

private:
    void updateVertices();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //VERLET_STICK_H

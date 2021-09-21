//
// Created by Jacopo Gasparetto on 19/09/21.
//

#ifndef VERLET_STICK_H
#define VERLET_STICK_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

class Stick : public sf::Drawable, public sf::Transformable {

private:
    sf::Vector2f m_p1;
    sf::Vector2f m_p2;
    sf::VertexArray m_vertices{ sf::Quads, 4};
    float thickness = 2.0f;
public:
    Stick(const sf::Vector2f &p1, const sf::Vector2f &p2) : m_p1(p1), m_p2(p2) {
        auto direction = p2 - p1;
        direction /= std::sqrt(direction.x * direction.x + direction.y * direction.y);
        direction = sf::Vector2f(-direction.y, direction.x); // Perpendicular direction

        auto offset = thickness * 0.5f * direction;
        m_vertices[0].position = p1 + offset;
        m_vertices[1].position = p2 + offset;
        m_vertices[2].position = p2 - offset;
        m_vertices[3].position = p1 - offset;

        for (int i = 0; i < 4; i++)
            m_vertices[i].color = sf::Color::White;
    }

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //VERLET_STICK_H

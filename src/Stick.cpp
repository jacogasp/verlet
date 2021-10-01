//
// Created by Jacopo Gasparetto on 19/09/21.
//

#include "Verlet/Stick.h"

Stick::Stick(Particle &p1, Particle &p2) :
        m_p1(p1), m_p2(p2),
        m_length(vm::distance2f(p1.getPosition(), p2.getPosition())) {

    for (int i = 0; i < 4; i++)
        m_vertices[i].color = sf::Color::White;

    updateVertices();
}

void Stick::updateStick() {

    if (!m_isActive) return;

    auto v1{ m_p1.getPosition() };
    auto v2{ m_p2.getPosition() };

    float dist = vm::distance2f(v1, v2);
    float percent = 0.5f * (m_length - dist) / dist;

    auto d = v2 - v1;

    float offsetX = d.x * percent;
    float offsetY = d.y * percent;

    v1.x -= offsetX;
    v1.y -= offsetY;
    v2.x += offsetX;
    v2.y += offsetY;

    if (!m_p1.isConstraint())
        m_p1.setPosition(v1);
    if (!m_p2.isConstraint())
        m_p2.setPosition(v2);

    updateVertices();
}

bool Stick::isActive() const {
    return m_isActive;
}

void Stick::deactivate() {
    m_isActive = false;
}

void Stick::updateVertices() {

    auto d = m_p2.getPosition() - m_p1.getPosition();

    d /= std::sqrt(d.x * d.x + d.y * d.y);
    d = sf::Vector2f(-d.y, d.x); // Perpendicular d

    auto offset = thickness * 0.5f * d;
    auto r = sf::Vector2f{Particle::radius, Particle::radius};

    m_vertices[0].position = m_p1.getPosition() + offset + r;
    m_vertices[1].position = m_p2.getPosition() + offset + r;
    m_vertices[2].position = m_p2.getPosition() - offset + r;
    m_vertices[3].position = m_p1.getPosition() - offset + r;
}

void Stick::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_vertices, states);
}

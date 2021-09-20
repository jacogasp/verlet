//
// Created by Jacopo Gasparetto on 19/09/21.
//

#ifndef VERLET_STICK_H
#define VERLET_STICK_H

#include <SFML/Graphics.hpp>

class Stick : public sf::Vertex{
private:
    sf::Vector2f &m_p1;
    sf::Vector2f &m_p2;
    sf::Vertex m_line[2];

public:
    Stick(sf::Vector2f &p1, sf::Vector2f &p2) : m_p1(p1), m_p2(p2) {}

};


#endif //VERLET_STICK_H

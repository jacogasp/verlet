//
// Created by Jacopo Gasparetto on 19/09/21.
//

#include "Verlet/Stick.h"


void Stick::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(m_vertices, states);
}

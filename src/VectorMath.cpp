//
// Created by Jacopo Gasparetto on 23/09/21.
//

#include "Verlet/VectorMath.h"

namespace vm {
    float distance2f(const sf::Vector2f &p1, const sf::Vector2f &p2) {
        auto d = p2 - p1;
        return std::sqrt(d.x * d.x + d.y * d.y);
    }
}
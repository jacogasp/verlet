//
// Created by Jacopo Gasparetto on 13/09/21.
//

#include "Verlet/App.h"

void App::onEvent() {
    switch (m_event.type) {

        case sf::Event::Closed:
            m_window.close();
            break;

        case sf::Event::MouseMoved: {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                cut(sf::Mouse::getPosition(m_window));
        }
            break;

        case sf::Event::KeyPressed: {
            if (m_event.key.code == sf::Keyboard::Key::R)
                reset();
        }
            break;

        default:;
    }
}

void App::cut(const sf::Vector2i &mousePos) {

    BoundingBox bb{ mousePos.x - Physics::cutSize,
                    mousePos.y - Physics::cutSize,
                    mousePos.x + Physics::cutSize,
                    mousePos.y + Physics::cutSize
    };

    std::vector<QuadTreeDataPoint<Stick> *> result;
    m_quadTree.query(bb, result);

    for (auto &s: result)
        s->data->deactivate();

}
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

        default:;
    }
}

void App::cut(const sf::Vector2i &mousePos) {

    float boxSize = 10.f;
    BoundingBox bb{ mousePos.x - boxSize, mousePos.y - boxSize, mousePos.x + boxSize, mousePos.y + boxSize };

    std::vector<QuadTreeDataPoint<Stick> *> result;
    m_quadTree.query(bb, result);

    for (auto &s: result)
        s->data->deactivate();

}
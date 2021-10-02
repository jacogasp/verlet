//
// Created by Jacopo Gasparetto on 13/09/21.
//

#include "Verlet/App.h"

void App::onRender() {
    m_window.clear();

    for (auto &p : m_particles)
        m_window.draw(p);

    std::vector<QuadTreeDataPoint<Stick>*> sticks;
    m_quadTree.query(m_boundingBox, sticks);


    for (auto &s : sticks) {
        auto _s = s->data;
        if (!_s->isActive()) continue;
        m_window.draw(*_s);
    }

    m_window.draw(m_gui);

    m_window.display();
}
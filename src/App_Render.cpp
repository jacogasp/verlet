//
// Created by Jacopo Gasparetto on 13/09/21.
//

#include "Verlet/App.h"

void App::onRender() {
    m_window.clear();

    for (auto &p : m_particles)
        m_window.draw(p);

    m_window.display();
}
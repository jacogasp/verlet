//
// Created by Jacopo Gasparetto on 13/09/21.
//

#include "Verlet/App.h"

void App::onLoop() {

    if (m_particles.empty()) return;

    for (auto it = m_particles.begin(); it != m_particles.end(); ++it) {
        if (it->getElapsedTime().asSeconds() < 5.0f) {
            it->loop();
            it->bounce(m_window);
        } else {
            m_particles.erase(it--);
        }
    }

}
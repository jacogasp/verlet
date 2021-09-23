//
// Created by Jacopo Gasparetto on 13/09/21.
//

#include "Verlet/App.h"

void App::updateParticles() {
    if (m_particles.empty()) return;

    for (auto &p : m_particles) {
        if (p.isConstraint()) continue;
        p.loop();
//        p.bounce(m_window);
    }
}

void App::updateSticks() {
    if (m_sticks.empty()) return;

    for (auto &s : m_sticks) {
        s.updateStick();
    }
}

void App::onLoop() {
    updateParticles();
    for (int i = 0; i < Simulation::NUM_OF_ITERATIONS; ++i) {
        updateSticks();
    }
}
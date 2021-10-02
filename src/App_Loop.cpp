//
// Created by Jacopo Gasparetto on 13/09/21.
//

#include "Verlet/App.h"

void App::updateParticles() {
    if (m_particles.empty()) return;

    for (auto &p : m_particles) {
        if (p.isConstraint()) continue;
        if (p.getPosition().y > Resolution::HEIGHT + 30.f) continue;
        p.loop();
//        p.bounce(m_window);
    }
}

void App::updateSticks() {
    if (m_sticks.empty()) return;

    for (int i = 0; i < Simulation::NUM_OF_ITERATIONS; ++i) {
        for (auto &s: m_sticks) {
            if (s.m_p1.getPosition().y > Resolution::HEIGHT + 30.f && s.m_p2.getPosition().y > Resolution::HEIGHT + 30.f)
                continue;

            s.updateStick();
        }
    }
}

void App::updateQuadTree() {
    // Recreate quadTree from scratch
    m_quadTree = QuadTree<Stick>(m_boundingBox);
    for (auto &s : m_sticks)
        addStickToQuadTree(s);
}

void App::onLoop() {
    updateParticles();
    updateSticks();
    updateQuadTree();
}
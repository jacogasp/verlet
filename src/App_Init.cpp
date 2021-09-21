#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
//
// Created by Jacopo Gasparetto on 13/09/21.
//

#include "Verlet/App.h"


void App::initParticles(bool bRandomVelocity) {
    std::default_random_engine generator;
    generator.seed(Physics::randomSeed);
    std::uniform_real_distribution<float> distribution(-1, 1);

    int nRows = static_cast<int>(sqrt(Simulation::NUM_OF_PARTICLES));
    int nCols = nRows;

    sf::Vector2f offset;

    offset.x = (getWidth() - Resolution::PADDING) / static_cast<float>(nCols);
    offset.y = (getHeight() - Resolution::PADDING) / static_cast<float>(nRows);

    m_particles.resize(Simulation::NUM_OF_PARTICLES);

    for (int i = 0; i < Simulation::NUM_OF_PARTICLES; ++i) {

        auto x = static_cast<float>(i % nCols) * offset.x + Resolution::PADDING;
        auto y = static_cast<float>(i / nRows) * offset.y + Resolution::PADDING;

        m_particles.at(i).setPosition(x, y);

        sf::Vector2f velocity = bRandomVelocity ? sf::Vector2f{
                distribution(generator) * Physics::maxInitialVelocity,
                distribution(generator) * Physics::maxInitialVelocity
        } : sf::Vector2f();

        m_particles.at(i).setInitialVelocity(velocity);
    }

    offset.x = Particle::radius;
    offset.y = Particle::radius;

    for (int r = 0; r < nRows; r++) {
        for (int c = 0; c < nCols; c++) {
            // Horizontal
            if (c < nCols - 1)
                m_sticks.emplace_back(m_particles[c + nCols * r].getPosition() + offset,
                                      m_particles[c + nCols * r + 1].getPosition() + offset);
            // Vertical
            if (r < nRows - 1)
                m_sticks.emplace_back(m_particles[c + nCols * r].getPosition() + offset,
                                      m_particles[c + nCols * r + nRows].getPosition() + offset);
        }
    }
}


bool App::onInit() {

    m_window.setVerticalSyncEnabled(true);
    initParticles(false);

    return true;
}


#pragma clang diagnostic pop
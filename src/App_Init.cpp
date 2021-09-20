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

    int nRows =  static_cast<int>(sqrt(Simulation::NUM_OF_PARTICLES));
    int nCols = nRows;

    float offsetX = (getWidth() - Resolution::PADDING) / static_cast<float>(nCols);
    float offsetY = (getHeight() - Resolution::PADDING) / static_cast<float>(nRows);

    for (int i = 0; i < Simulation::NUM_OF_PARTICLES; ++i) {
        m_particles.emplace_back();

        auto x = static_cast<float>(i % nCols) * offsetX + Resolution::PADDING;
        auto y = static_cast<float>(i / nRows) * offsetY + Resolution::PADDING;

        m_particles.back().setPosition(x, y);

        // m_particles.back().setPosition(getWidth() / 2.0f, getHeight() / 2.0f);

        sf::Vector2f velocity = bRandomVelocity ? sf::Vector2f {
                distribution(generator) * Physics::maxInitialVelocity,
                distribution(generator) * Physics::maxInitialVelocity
        } : sf::Vector2f();

        m_particles.back().setInitialVelocity(velocity);
    }
}


bool App::onInit() {

    m_window.setVerticalSyncEnabled(true);
    initParticles(false);

    return true;
}


#pragma clang diagnostic pop
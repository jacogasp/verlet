#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
//
// Created by Jacopo Gasparetto on 13/09/21.
//

#include "Verlet/App.h"


void App::addStickToQuadTree(Stick &stick) {

    auto pos = (stick.m_p1.getPosition() + stick.m_p2.getPosition()) * 0.5f;

    QuadTreeDataPoint<Stick> data { pos.x, pos.y, &stick };
    m_quadTree.insert(data);
}


void App::initParticles(bool bRandomVelocity) {
    std::default_random_engine generator;
    generator.seed(Physics::randomSeed);
    std::uniform_real_distribution<float> distribution(-1, 1);

    int nRows = static_cast<int>(sqrt(Simulation::NUM_OF_PARTICLES));
    int nCols = nRows;

    m_particles.resize(Simulation::NUM_OF_PARTICLES);
    auto offsetX = 0.5f * (getWidth() - Resolution::GRID_SPACING * nCols -  2.0f * Resolution::PADDING);
    auto offsetY = 0.5f * (getHeight() - Resolution::GRID_SPACING * nRows -  2.0f * Resolution::PADDING);

    for (auto &p : m_particles) {
        static int i = 0;
        auto x = (i % nCols) * Resolution::GRID_SPACING + offsetX;
        auto y = (i++ / nRows) * Resolution::GRID_SPACING + offsetY;

        p.setPosition(x, y);

        sf::Vector2f velocity = bRandomVelocity ? sf::Vector2f{
                distribution(generator) * Physics::maxInitialVelocity,
                distribution(generator) * Physics::maxInitialVelocity
        } : sf::Vector2f();

        p.setInitialVelocity(velocity);
    }

    // Set constraints
    m_particles[0].setConstraint();
    m_particles[nCols - 1].setConstraint();

    // Create sticks
    for (int r = 0; r < nRows; r++) {
        for (int c = 0; c < nCols; c++) {

            // Horizontal
            if (c < nCols - 1)
                m_sticks.emplace_back(m_particles[c + nCols * r],m_particles[c + nCols * r + 1]);
            // Vertical
            if (r < nRows - 1)
                m_sticks.emplace_back(m_particles[c + nCols * r],m_particles[c + nCols * r + nRows]);
        }
    }


    for (auto &s : m_sticks)
        addStickToQuadTree(s);
}


bool App::onInit() {

    m_window.setVerticalSyncEnabled(true);
    initParticles(false);

    return true;
}


#pragma clang diagnostic pop
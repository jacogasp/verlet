//
// Created by Jacopo Gasparetto on 13/09/21.
//

#ifndef VERLET_CONSTANTS_H
#define VERLET_CONSTANTS_H

namespace Physics {
    constexpr float gravity = 9.81f * 0.01;
    constexpr float bounce = 0.99f;         // 1 = rigid body
    constexpr float maxInitialVelocity = 42.0f;
    constexpr int randomSeed = 666;
    constexpr float wind = 0.1f;
}


namespace Resolution {
    constexpr int WIDTH = 1024;
    constexpr int HEIGHT = 800;
    constexpr int PADDING = 5;
    constexpr int GRID_SPACING = 20;
}

namespace Simulation {
    constexpr int NUM_OF_PARTICLES = 1024;
    constexpr int NUM_OF_ITERATIONS = 5;
}

#endif //VERLET_CONSTANTS_H
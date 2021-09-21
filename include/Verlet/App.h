//
// Created by Jacopo Gasparetto on 12/09/21.
//

#ifndef VERLET_APP_H
#define VERLET_APP_H

#include <SFML/Graphics.hpp>
#include <algorithm>
#include <vector>
#include <random>
#include <cmath>

#include "Particle.h"
#include "Stick.h"

class App {

private:
    sf::Event m_event{};
    sf::RenderWindow m_window;

    std::vector<Particle> m_particles;
    std::vector<Stick> m_sticks;

public:

    App() : m_window(sf::VideoMode(Resolution::WIDTH, Resolution::HEIGHT), "Window") {};

public:

    int onExecute();

private:

    bool onInit();

    void onEvent();

    void onLoop();

    void onRender();

    void onCleanup();

private:

    float getWidth() const;

    float getHeight() const;

private:

    void initParticles(bool bRandomVelocity = false);

};


#endif //VERLET_APP_H

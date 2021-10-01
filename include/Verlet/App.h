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

#include "QuadTree.h"
#include "Particle.h"
#include "Stick.h"

class App {

private:
    BoundingBox boundingBox{ 0.0f, 0.0f, Resolution::WIDTH, Resolution::HEIGHT };

    sf::Event m_event{};
    sf::RenderWindow m_window;

    std::vector<Particle> m_particles;
    std::vector<Stick> m_sticks;
    QuadTree<Stick> m_quadTree;

public:

    App() : m_window(sf::VideoMode(Resolution::WIDTH, Resolution::HEIGHT), "Window"),
            m_quadTree{ boundingBox } {};

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

    void addStickToQuadTree(Stick &stick);

    void initParticles(bool bRandomVelocity = false);

    void updateParticles();

    void updateSticks();

    void updateQuadTree();

    // Events
private:

    void cut(const sf::Vector2i &mousePos);

};


#endif //VERLET_APP_H

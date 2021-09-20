//
// Created by Jacopo Gasparetto on 12/09/21.
//

#include "Verlet/App.h"
int App::onExecute() {
    if (!onInit())
        return -1;

    while(m_window.isOpen()) {
        while (m_window.pollEvent(m_event)) {
            onEvent();
        }

        onLoop();
        onRender();
    }

    onCleanup();

    return 0;
}

float App::getWidth() const {
    return static_cast<float>(m_window.getSize().x);
}

float App::getHeight() const {
    return static_cast<float>(m_window.getSize().y);
}

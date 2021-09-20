//
// Created by Jacopo Gasparetto on 13/09/21.
//

#include "Verlet/App.h"

void App::onEvent() {
    if (m_event.type == sf::Event::Closed)
        m_window.close();
}
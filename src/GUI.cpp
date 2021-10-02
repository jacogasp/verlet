//
// Created by Jacopo Gasparetto on 02/10/21.
//

#include "Verlet/GUI.h"

GUI::GUI() {
    m_font.loadFromFile("../resources/Mulish-Regular.ttf");

    m_textReset.setFont(m_font);
    m_textReset.setString("Press R to reset");
    m_textReset.setCharacterSize(24);
    m_textReset.setFillColor(sf::Color::White);
}

void GUI::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_textReset);
}

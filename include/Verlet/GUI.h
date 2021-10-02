//
// Created by Jacopo Gasparetto on 02/10/21.
//

#ifndef VERLET_GUI_H
#define VERLET_GUI_H

#include <SFML/Graphics.hpp>

class GUI : public sf::Drawable {
private:
    sf::Font m_font;
    sf::Text m_textReset;

public:
    GUI();

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //VERLET_GUI_H

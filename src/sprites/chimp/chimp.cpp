#include "chimp.hpp"
#include <string>
#include <SFML/Graphics.hpp>

#include <iostream>

Chimp::Chimp(std::string texture_file) {
    m_move_speed = 9.0;
    m_dizzy = 0;

    sf::Image image;
    image.loadFromFile(texture_file);
    image.createMaskFromColor(sf::Color::Red);

    m_sprite_texture.loadFromImage(image);
    m_sprite.setTexture(m_sprite_texture);
}

sf::FloatRect Chimp::get_rect() {
    return m_sprite.getGlobalBounds();
}

void Chimp::update(sf::RenderWindow* window) {
    if (m_dizzy) {
        spin();
    } else {
        walk(window->getSize().x);
    }

    window->draw(m_sprite);
}

void Chimp::walk(float right_bounds) {
    float new_position = m_sprite.getPosition().x + m_move_speed;
    
    float chimp_width = m_sprite.getGlobalBounds().width;

    if (new_position >= right_bounds - chimp_width) {
        m_move_speed = m_move_speed * -1;
        new_position = m_sprite.getPosition().x + m_move_speed;
    } else if (new_position <= 0) {
        m_move_speed = m_move_speed * -1;
        new_position = m_sprite.getPosition().x + m_move_speed;
    }

    m_sprite.setPosition(new_position, 0);
}

void Chimp::spin() {

}

void Chimp::punched() {
    
}
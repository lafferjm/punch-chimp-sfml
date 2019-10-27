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


    float x_origin = m_sprite.getLocalBounds().width / 2;
    float y_origin = m_sprite.getLocalBounds().height / 2;
    m_sprite.setOrigin(x_origin, y_origin);

    m_sprite.setPosition(x_origin, y_origin);
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
    
    float chimp_width = m_sprite.getLocalBounds().width / 2;

    if (new_position >= right_bounds - chimp_width) {
        m_move_speed = m_move_speed * -1;
        new_position = m_sprite.getPosition().x + m_move_speed;
    } else if (new_position <= 0) {
        m_move_speed = m_move_speed * -1;
        new_position = m_sprite.getPosition().x + m_move_speed;
    }

    m_sprite.setPosition(new_position, m_sprite.getLocalBounds().height / 2);
}

void Chimp::spin() {
    m_dizzy = m_dizzy + 12;

    if (m_dizzy >= 360) {
        m_dizzy = 0;
    }

    m_sprite.setRotation(m_dizzy);
}

void Chimp::punched() {
    if (!m_dizzy) {
        m_dizzy =  1;
    }
}
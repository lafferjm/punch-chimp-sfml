#include <string>
#include <SFML/Graphics.hpp>
#include "fist.hpp"
#include "../chimp/chimp.hpp"


Fist::Fist(std::string texture_file) {
    m_punching = false;
    sf::Image image;
    image.loadFromFile(texture_file);
    image.createMaskFromColor(sf::Color::Black);

    m_sprite_texture.loadFromImage(image);
    m_sprite.setTexture(m_sprite_texture);

    m_punch_buffer.loadFromFile("resources/sounds/punch.wav");
    m_punch_sound.setBuffer(m_punch_buffer);

    m_whiff_buffer.loadFromFile("resources/sounds/whiff.wav");
    m_whiff_sound.setBuffer(m_whiff_buffer);
}

void Fist::update(sf::RenderWindow* window) {
    sf::Mouse mouse;
    m_sprite.setPosition((sf::Vector2f)mouse.getPosition((*window)));

    if (m_punching) {
        m_sprite.move(5, 10);
    }

    window->draw(m_sprite);
}

void Fist::punch(Chimp* target) {
    if (!m_punching) {
        m_punching = true;
        if (m_sprite.getGlobalBounds().intersects(target->get_rect())) {
            m_punch_sound.play();
            target->punched();
        } else {
            m_whiff_sound.play();
        }
    }
}

void Fist::unpunch() {
    m_punching = false;
}

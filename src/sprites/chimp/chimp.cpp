#include "chimp.hpp"
#include <string>
#include <SFML/Graphics.hpp>

Chimp::Chimp(std::string texture_file) {
    m_move_speed = 9;
    m_dizzy = 0;

    sf::Image image;
    image.loadFromFile(texture_file);
    image.createMaskFromColor(sf::Color::Red);

    m_sprite_texture.loadFromImage(image);
    m_sprite.setTexture(m_sprite_texture);
}

void Chimp::update(sf::RenderWindow* window) {

}

void Chimp::walk() {

}

void Chimp::spin() {

}

void Chimp::punched() {
    
}
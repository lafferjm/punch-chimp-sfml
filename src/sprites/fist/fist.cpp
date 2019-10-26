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
}

void Fist::update(sf::RenderWindow* window) {
    sf::Mouse mouse;
    m_sprite.setPosition((sf::Vector2f)mouse.getPosition((*window)));

    window->draw(m_sprite);
}

void Fist::punch(Chimp* target) {
    
}

void Fist::unpunch() {
    m_punching = false;
}

#include "fist.hpp"
#include <SFML/Graphics.hpp>

Fist::Fist(std::string texture_file) {
    m_punching = false;
    sf::Image image;
    image.loadFromFile(texture_file);
    image.createMaskFromColor(sf::Color::Black);

    m_sprite_texture.loadFromImage(image);
    m_sprite.setTexture(m_sprite_texture);
}

void Fist::update(sf::RenderWindow* window) {
    window->draw(m_sprite);
}

bool Fist::punch(sf::Sprite* target) {
    return false;
}

void Fist::unpunch() {
    m_punching = false;
}

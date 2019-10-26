#ifndef __FIST_HPP__
#define __FIST_HPP__

#include <SFML/Graphics.hpp>

class Fist {
    public:
        Fist(std::string);
        void update(sf::RenderWindow*);
        bool punch(sf::Sprite*);
        void unpunch();

    private:
        bool m_punching;
        sf::Sprite m_sprite;
        sf::Texture m_sprite_texture;
};

#endif

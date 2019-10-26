#ifndef __FIST_HPP__
#define __FIST_HPP__

#include <string>
#include <SFML/Graphics.hpp>
#include "../chimp/chimp.hpp"

class Fist {
    public:
        Fist(std::string);
        void update(sf::RenderWindow*);
        void punch(Chimp*);
        void unpunch();

    private:
        bool m_punching;
        sf::Sprite m_sprite;
        sf::Texture m_sprite_texture;
};

#endif

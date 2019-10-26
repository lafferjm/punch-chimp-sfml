#ifndef __CHIMP_H__
#define __CHIMP_H__

#include <string>
#include <SFML/Graphics.hpp>

class Chimp {
    public:
        Chimp(std::string);
        void update(sf::RenderWindow*);
    private:
        int m_move_speed;
        int m_dizzy;

        sf::Texture m_sprite_texture;
        sf::Sprite m_sprite;

        void walk();
        void spin();
        void punched();
};

#endif

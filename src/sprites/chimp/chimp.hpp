#ifndef __CHIMP_H__
#define __CHIMP_H__

#include <string>
#include <SFML/Graphics.hpp>

class Chimp {
    public:
        Chimp(std::string);
        void update(sf::RenderWindow*);
        sf::FloatRect get_rect();
    private:
        float m_move_speed;
        int m_dizzy;

        sf::Texture m_sprite_texture;
        sf::Sprite m_sprite;

        void walk(float);
        void spin();
        void punched();
};

#endif

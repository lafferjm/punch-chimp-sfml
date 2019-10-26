#ifndef __FIST_HPP__
#define __FIST_HPP__

#include <SFML/Graphics.hpp>

class Fist {
    public:
        Fist(std::string);
        void update();
        bool punch(sf::Sprite*);
        void unpunch();

    private:
        bool m_punching = false;
        sf::Sprite sprite;
};

#endif

#include <SFML/Graphics.hpp>

int main(int argc, char** argv) {
    sf::RenderWindow window(sf::VideoMode(468, 60), "Monkey Fever");
    window.setMouseCursorVisible(false);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        window.display();
    }   

    return 0;
}

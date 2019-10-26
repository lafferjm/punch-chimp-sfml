#include <SFML/Graphics.hpp>

sf::Text setupText(sf::Font* font, std::string text_content, sf::Vector2f position) {
    font->loadFromFile("resources/fonts/freesansbold.ttf");

    sf::Text text;
    text.setFont(*font);
    text.setString(text_content);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, 0);
    text.setPosition(position);

    return text;
}

int main(int argc, char** argv) {
    sf::RenderWindow window(sf::VideoMode(468, 60), "Monkey Fever");
    window.setMouseCursorVisible(false);

    sf::Font font;
    sf::Text text;
    text = setupText(&font, "Pummel The Chimp, And Win $$$",
        sf::Vector2f(window.getSize().x / 2 , 0));


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.draw(text);

        window.display();
    }   

    return 0;
}

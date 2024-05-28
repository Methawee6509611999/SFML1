#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!",sf::Style::Default,settings);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(100,100);
    
    while (window.isOpen())
    {
    //-------------------------------update--------------------------------------
        sf::Event event;
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        shape.setPosition(static_cast<sf::Vector2f>(mousePos));
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                shape.setFillColor(sf::Color::Red);
            }
            else {
                shape.setFillColor(sf::Color::Green);
            }
                
        }
        
    //-------------------------------update--------------------------------------


    //-------------------------------draw--------------------------------------
        window.clear();
        window.draw(shape);
        window.display();
    //-------------------------------draw--------------------------------------
    }

    return 0;
}
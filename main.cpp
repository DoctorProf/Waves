
#include <iostream>
#include "SFML/Graphics.hpp"

import Cell;

using namespace sf;

int main() 
{
    RenderWindow window(VideoMode(1920, 1080), "Waves", sf::Style::Default); 

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        window.clear(Color::White);
        window.display();
    }
}
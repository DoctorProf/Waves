
#include <iostream>
#include "SFML/Graphics.hpp"

import Block;
import Data;

using namespace sf;

int main() 
{
    double countBlock = 100.0f;

    RenderWindow window(VideoMode(1920, 1080), "Waves", sf::Style::Default); 
    window.setVerticalSyncEnabled(true);

    std::vector<Block> wave = data::generateWave(countBlock, window);


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

        window.clear(Color::Black);

        data::drawWave(wave, window);

        window.display();
    }
}
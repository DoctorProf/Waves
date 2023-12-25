
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

    Clock logic;
    Time timePerFrame = seconds(1.0f / 60.0f);
    Time accumulate = Time::Zero;

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
        accumulate += logic.restart();
        while (accumulate >= timePerFrame)
        {
            accumulate -= timePerFrame;
            data::moveWave(wave);
        }

        window.clear(Color::Black);

        data::drawWave(wave, window);

        window.display();
    }
}
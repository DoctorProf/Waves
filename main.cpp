
#include <iostream>
#include "SFML/Graphics.hpp"

import Block;
import Data;

using namespace sf;

int main() 
{
    double countBlock = 1000.0f;

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
            if (event.type == Event::MouseButtonPressed &&  event.mouseButton.button == Mouse::Button::Left) 
            {
                sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                //Vector2i mouseCoor = Mouse::getPosition(window);
                data::clickOnWave(mousePosition.x, mousePosition.y, wave);
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::R) 
            {
                wave.clear();
                wave = data::generateWave(countBlock, window);
            }
        }
        accumulate += logic.restart();
        while (accumulate >= timePerFrame)
        {
            accumulate -= timePerFrame;
            data::moveWave(wave);
        }

        window.clear(Color::Color(127, 127, 127));

        data::drawWave(wave, window);

        window.display();
    }
}
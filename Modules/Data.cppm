module;
#include <iostream>
#include "SFML/Graphics.hpp"
import Block;
using namespace sf;
export module Data;

namespace data
{
    export std::vector<Block> generateWave(double countBlock, RenderWindow& window)
    {
        std::vector<Block> wave;
        for (int i = 0; i < countBlock; i++)
        {
            double heightBlock = window.getSize().y / countBlock > 1 ? window.getSize().y / countBlock : 3;
            double widthBlock = window.getSize().x / countBlock;
            wave.push_back(Block(heightBlock, widthBlock, widthBlock * i, window.getSize().y / 2.0f - heightBlock / 2.0f));
        }
        wave[0].setVerticalSpeed(-10);
        return wave;
    }
    export void drawWave(std::vector<Block>& wave, RenderWindow& window)
    {
        for (int i = 0; i < wave.size(); i++)
        {
            wave[i].draw(window);
        }
    }
    export void moveWave(std::vector<Block>& wave)
    {
        for (int i = 0; i < wave.size(); i++)
        {
            double speedBlock = wave[i].getVerticalSpeed();;
            double verticalPos = wave[i].getVerticalPosition();

            if (wave.size() < 2) return;

            if (i == 0)
            {
                double verticalPosRight = wave[i + 1].getVerticalPosition();
                double averageHeight = (verticalPos + verticalPosRight) / 2;
                double difference = verticalPos - averageHeight;
                wave[i].setVerticalSpeed(speedBlock - 0.1 * difference);
            }
            else if (i == wave.size() - 1)
            {
                double verticalPosLeft = wave[i - 1].getVerticalPosition();
                double averageHeight = (verticalPos + verticalPosLeft) / 2;
                double difference = verticalPos - averageHeight;
                wave[i].setVerticalSpeed(speedBlock - 0.1 * difference);
            }
            else
            {
                double verticalPosLeft = wave[i - 1].getVerticalPosition();
                double verticalPosRight = wave[i + 1].getVerticalPosition();
                double averageHeight = (verticalPosLeft + verticalPosRight) / 2;
                double difference = verticalPos - averageHeight;
                wave[i].setVerticalSpeed(speedBlock - 0.1 * difference);
            }
        }

        for (int i = 0; i < wave.size(); i++)
        {
            wave[i].move();
        }
    }
}


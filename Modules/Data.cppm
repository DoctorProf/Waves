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
            double heightBlock = window.getSize().y / countBlock > 10 ? window.getSize().y / countBlock : 10;
            double widthBlock = window.getSize().x / countBlock;
            wave.push_back(Block(heightBlock, widthBlock, widthBlock * i, window.getSize().y / 2.0f - heightBlock / 2.0f));
        }
        wave[0].setFixed(true);
        wave[countBlock - 1].setFixed(true);
        for (int i = countBlock * 0.2; i < countBlock * 0.3; i++) 
        {
            wave[i].setMass(2);
        }
        for (int i = countBlock * 0.5; i < countBlock * 0.7; i++)
        {
            wave[i].setMass(4);
        }
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
            if (wave.size() < 2) return;
            if (wave[i].getFixed()) continue;

            double speedBlock = wave[i].getVerticalSpeed();
            double massBlock = wave[i].getMass();
            double verticalPos = wave[i].getVerticalPosition();
            double verticalPosRight = i + 1 < wave.size() ? wave[i + 1].getVerticalPosition() : wave[i].getVerticalPosition();
            double verticalPosLeft = i - 1 > -1 ? wave[i - 1].getVerticalPosition() : wave[i].getVerticalPosition();

            double averageHeight = (verticalPosLeft + verticalPosRight) / 2;
            double difference = verticalPos - averageHeight;
            wave[i].setVerticalSpeed(speedBlock - 0.1 * difference / massBlock);
        }

        for (int i = 0; i < wave.size(); i++)
        {
            wave[i].move();
        }
    }
    export void clickOnWave(double x, double y, std::vector<Block>& wave)
    {
        for (int i = 0; i < wave.size(); i++) 
        {
            if (wave[i].clickOnBlock(x, y) && !wave[i].getFixed()) wave[i].setVerticalSpeed(-10 / wave[i].getMass());
        }
    }
}
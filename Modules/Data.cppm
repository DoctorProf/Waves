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
        std::vector <Block> wave;
        wave.resize(countBlock);

        for (int i = 0; i < countBlock; i++)
        {
            double heightBlock = window.getSize().y / countBlock > 1 ? window.getSize().y / countBlock : 1;
            double widthBlock = window.getSize().x / countBlock;
            wave.push_back(Block(heightBlock, widthBlock, widthBlock * i, window.getSize().y / 2.0f - heightBlock / 2.0f));
        }

        return wave;
	}
    export void drawWave(std::vector<Block> wave, RenderWindow& window) 
    {
        for (int i = 0; i < wave.size(); i++)
        {
            wave[i].draw(window);
        }
    }
}


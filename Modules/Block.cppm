module;
#include <iostream>
#include "SFML/Graphics.hpp"
using namespace sf;
export module Block;

export class Block
{
private:
	RectangleShape block;
public:
	Block();
	Block(double height, double width, double x, double y);
	void draw(RenderWindow& window);
	RectangleShape getBlock();
};

Block::Block() 
{

}
Block::Block(double height, double width, double x, double y)
{
	this->block.setFillColor(Color::Color(127, 127, 127));
	this->block.setSize(Vector2f(width, height));
	this->block.setPosition(Vector2f(x, y));
}

void Block::draw(RenderWindow& window)
{
	window.draw(this->block);
}
RectangleShape Block::getBlock()
{
	return this->block;
}
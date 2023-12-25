module;
#include <iostream>
#include "SFML/Graphics.hpp"
using namespace sf;
export module Block;

export class Block
{
private:
	RectangleShape block;
	double verticalSpeed;
public:
	Block();
	Block(double height, double width, double x, double y);
	void draw(RenderWindow& window);
	void move();
	void setVerticalSpeed(double verticalSpeed);
	double getVerticalSpeed();
	double getVerticalPosition();
	void setVerticalPosition(double verticalPosition);

};

Block::Block() 
{

}
Block::Block(double height, double width, double x, double y)
{
	this->block.setFillColor(Color::Color(127, 127, 127));
	this->block.setSize(Vector2f(width, height));
	this->block.setPosition(Vector2f(x, y));
	this->verticalSpeed = 0;
}

void Block::draw(RenderWindow& window)
{
	window.draw(this->block);
}
void Block::move() 
{
	double blockX = this->block.getPosition().x;
	double blockY = this->block.getPosition().y;
	this->block.setPosition(Vector2f(blockX, blockY + this->verticalSpeed));
}
void Block::setVerticalSpeed(double verticalSpeed)
{
	this->verticalSpeed = verticalSpeed;
}
double Block::getVerticalSpeed()
{
	return this->verticalSpeed;
}
double Block::getVerticalPosition() 
{
	return this->block.getPosition().y;
}
void Block::setVerticalPosition(double verticalPosition) 
{
	this->block.setPosition(Vector2f(this->block.getPosition().x, verticalPosition));
}
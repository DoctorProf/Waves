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
	double mass;
	bool fixed;
public:
	Block();
	Block(double height, double width, double x, double y, double mass = 1);
	void draw(RenderWindow& window);
	void move();
	void setVerticalSpeed(double verticalSpeed);
	double getVerticalSpeed();
	double getVerticalPosition();
	void setVerticalPosition(double verticalPosition);
	double getMass();
	void setMass(double mass);
	bool clickOnBlock(double x, double y);
	void setFixed(bool fixed);
	bool getFixed();
};

Block::Block() 
{

}
Block::Block(double height, double width, double x, double y, double mass)
{
	this->block.setSize(Vector2f(width, height));
	this->block.setPosition(Vector2f(x, y));
	this->verticalSpeed = 0;
	this->mass = mass;
	this->fixed = false;
}

void Block::draw(RenderWindow& window)
{
	this->block.setFillColor(this->fixed ? Color::Red : Color::Color(255 / mass, 255 / mass, 255 / mass));
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
double Block::getMass()
{
	return this->mass;
}
void Block::setMass(double mass) 
{
	this->mass = mass;
}
bool Block::clickOnBlock(double x, double y) 
{
	double blockPosX = this->block.getPosition().x;
	double blockPosY = this->block.getPosition().y;
	return (x > blockPosX && x < blockPosX + this->block.getSize().x) &&
		   (y > blockPosY && y < blockPosY + this->block.getSize().y);
}
void Block::setFixed(bool fixed)
{
	this->fixed = fixed;
}
bool Block::getFixed()
{
	return this->fixed;
}
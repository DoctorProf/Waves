module;
#include <iostream>
#include "SFML/Graphics.hpp"
export module Cell;

export class Cell 
{
private:
	sf::RectangleShape cell;
public:
	Cell();
	void draw(sf::RenderWindow& window);

};

Cell::Cell() {

}

void Cell::draw(sf::RenderWindow& window) {
	window.draw(this->cell)
}
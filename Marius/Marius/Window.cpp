#include "Window.h"

void Window::init() {
	this->setSize(sf::Vector2u(640, 480));
	this->setTitle("Marius");
}
void Window::update(sf::CircleShape shape) {
	this->clear();
	this->draw(shape);
	this->display();
}
void Window::setLng(int newLng) {
	this->lng = newLng;
}
void Window::setLarg(int newLarg) {
	this->larg = newLarg;
}
int Window::getLarg() {
	return this->larg;
}
int Window::getLng() {
	return this->lng;
}


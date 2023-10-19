#include "rect.hpp"

// Constructor
Rect::Rect(sf::Vector2f position, sf::Vector2f size, sf::Color color, float xVelocity, float yVelocity)
{
	m_position = position;
	m_size = size;
	m_color = color;
	m_xVelocity = xVelocity;
	m_yVelocity = yVelocity;

	m_shape.setPosition(m_position);
	m_shape.setSize(m_size);
	m_shape.setFillColor(m_color);
}

// Setters
void Rect::setXVelocity(float xVelocity)
{
	m_xVelocity = xVelocity;
}

void Rect::setYVelocity(float yVelocity)
{
	m_yVelocity = yVelocity;
}

// Getters
float Rect::getXVelocity()
{
	return m_xVelocity;
}

float Rect::getYVelocity()
{
	return m_yVelocity;
}

// Update
void Rect::update()
{
	m_position.x += m_xVelocity;
	m_position.y += m_yVelocity;

	m_shape.setPosition(m_position);
}

// Get shape
sf::RectangleShape Rect::getShape()
{
	return m_shape;
}

// Draw
void Rect::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
}

#ifndef RECT_HPP
#define RECT_HPP

#pragma once

#include <SFML/Graphics.hpp>
#include <random>

class Rect {
private:
    sf::RectangleShape m_shape;
    sf::Vector2f m_position;
    sf::Vector2f m_size;
    sf::Color m_color;
    float m_xVelocity{};
    float m_yVelocity{};

public:
    Rect(sf::Vector2f position, sf::Vector2f size, sf::Color color, float xVelocity, float yVelocity);
    void update();
    void draw(sf::RenderWindow& window);
    void setXVelocity(float xVelocity);
    void setYVelocity(float yVelocity);
    float getXVelocity();
    float getYVelocity();
    sf::RectangleShape getShape();

};

#endif // RECT_HPP

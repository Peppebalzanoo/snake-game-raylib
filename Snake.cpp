#include "Snake.hpp"

void Snake::setPosition(const Position pos)
{
    head_position = pos;
}

/* ************************************************** */
void Snake::setDirection(const Position dir)
{
    head_direction = dir;
}

/* ************************************************** */
Position &Snake::getPosition()
{
    return head_position;
}

const Position &Snake::getPosition() const
{
    return head_position;
}

/* ************************************************** */
Position &Snake::getDirection()
{
    return head_direction;
}

const Position &Snake::getDirection() const
{
    return head_direction;
}

/* ************************************************** */
std::vector<Position> &Snake::getBody()
{
    return body;
}

const std::vector<Position> &Snake::getBody() const
{
    return body;
}
#include "Position.hpp"

Position::Position(int x, int y) : x(x), y(y) {}

/* ************************************************** */
int &Position::getX()
{
    return x;
}

const int &Position::getX() const
{
    return x;
}

/* ************************************************** */
int &Position::getY()
{
    return y;
}

const int &Position::getY() const
{
    return y;
}
/* ************************************************** */

bool Position::operator==(const Position &other) const
{
    return x == other.x && y == other.y;
}

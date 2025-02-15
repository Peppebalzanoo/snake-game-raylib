#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Position.hpp"
#include <vector>

class Snake
{
private:
    /* ************************************************** */
    Position head_position;
    Position head_direction;
    std::vector<Position> body;

    /* ************************************************** */

public:
    /* ************************************************** */
    Snake() = default;

    /* ************************************************** */
    void setPosition(const Position pos);
    
    void setDirection(const Position dir);

    /* *********************** */
    Position &getPosition();
    const Position &getPosition() const;

    /* *********************** */
    Position &getDirection();
    const Position &getDirection() const;

    /* *********************** */
    std::vector<Position> &getBody();
    const std::vector<Position> &getBody() const;
    /* ************************************************** */
};

#endif
#ifndef GAME_HPP
#define GAME_HPP

#include "Snake.hpp"

#include "raylib.h"

#include <iostream>
#include <algorithm>

class GameModel
{

public:
    /* ************************************************** */
    static constexpr int GRID_SIZE = 20; // The size of the grid (GRID_SIZExGRID_SIZE)
    static constexpr int CELL_SIZE = 35; // The size of each cell

    /* ************************************************** */

private:
    /* ************************************************** */
    float apple_spawn_timer = 0.0f;          // Timer to track apple spawning
    const float APPLE_SPAWN_INTERVAL = 2.0f; // Generates an apple every APPLE_SPAWN_INTERVAL seconds
    const float APPLE_SPAWN_LIMIT = 30;      // Limit for the number of apples on the screen
    const int APPLE_SPAWN_INIT = 5;

    /* *********************** */
    std::vector<Position> apples; // Vector to store apple positions

    Snake snake; // The snake object

    /* *********************** */
    enum class Direction
    {
        Up,
        Down,
        Left,
        Right
    };

    /* *********************** */
    Position convertDirectionToPosition(Direction dir); // Converts the snake's direction to a position change

    /* *********************** */
    void checkIsEatingApple(); // Checks if the snake is eating an apple

    /* *********************** */
    bool areAllInLine(); // Checks if all segments of the snake are aligned

    void checkIsCollided(); // Checks if the snake has collided with itself or the walls

    /* *********************** */
    void updateSnakeBodyPosition(); // Updates the positions of the snake's body

    /* *********************** */
    void wrapAround(Position &pos); // Wraps the snake around the grid when it goes off the edges

    /* ************************************************** */

public:
    /* ************************************************** */
    GameModel(); // Constructor to initialize the game model

    /* *********************** */
    std::vector<Position> &getApples(); // Returns a reference to the list of apples

    Snake &getSnake(); // Returns a reference to the snake object

    /* *********************** */
    void initGame(); // Initializes the game, setting up the grid, snake, and apples

    /* *********************** */
    Position getNewRandomPosition(); // Generates a new random position for the apple

    Position getNewRandomDirection(); // Generates a new random direction for the snake

    void generateInitRandomApples(); // Generates the initial random apples for the game

    /* *********************** */
    void updateSnakeDirection(); // Updates the direction the snake is moving

    void updateSnakePosition(); // Updates the position of the snake

    void updateAppleSpawning(); // Manages the spawning of apples based on the timer

    /* ************************************************** */
};

#endif

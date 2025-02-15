#include "GameModel.hpp"

GameModel::GameModel()
{
    initGame(); // Initializes the game when an instance of GameModel is created
}

/* ************************************************** */
std::vector<Position> &GameModel::getApples()
{
    return apples; // Returns a reference to the list of apples
}

/* ************************************************** */
Snake &GameModel::getSnake()
{
    return snake; // Returns a reference to the snake object
}

/* ************************************************** */
void GameModel::initGame()
{
    snake.getBody().clear(); // Clears the snake's body
    apples.clear();          // Clears the apples list

    snake.setPosition(getNewRandomPosition());      // Sets the snake's starting position
    snake.getBody().push_back(snake.getPosition()); // Adds the head of the snake to the body

    snake.setDirection(getNewRandomDirection()); // Sets the snake's random initial direction

    generateInitRandomApples(); // Generates the initial apples for the game
}

/* ************************************************** */
Position GameModel::getNewRandomPosition()
{
    int random_x = (GetRandomValue(0, GRID_SIZE - 2)); // Random X coordinate within the grid
    int random_y = (GetRandomValue(0, GRID_SIZE - 2)); // Random Y coordinate within the grid
    return Position(random_x, random_y);               // Returns the random position as a Position object
}

/* ************************************************** */
Position GameModel::getNewRandomDirection()
{
    int random_int_dir = GetRandomValue(0, 3);                                 // Randomly selects a direction
    return convertDirectionToPosition(static_cast<Direction>(random_int_dir)); // Converts direction to position change
}

/* ************************************************** */
void GameModel::generateInitRandomApples()
{
    for (size_t i = 0; i < APPLE_SPAWN_INIT; i++) // Generates random apples initially
    {
        Position pos = getNewRandomPosition();
        auto iter = std::find(apples.begin(), apples.end(), pos);

        if (iter == apples.end())
        {
            apples.push_back(pos); // Adds a new apple to the apples list
        }
    }
}

/* ************************************************** */
void GameModel::updateSnakeDirection()
{
    Position &dir = snake.getDirection(); // Gets the current direction of the snake

    if (IsKeyPressed(KEY_UP))
    {
        dir.getY() = -1; // Sets the Y direction to move up
        dir.getX() = 0;  // Sets the X direction to 0
    }
    if (IsKeyPressed(KEY_DOWN))
    {
        dir.getY() = +1; // Sets the Y direction to move down
        dir.getX() = 0;  // Sets the X direction to 0
    }
    if (IsKeyPressed(KEY_LEFT))
    {
        dir.getX() = -1; // Sets the X direction to move left
        dir.getY() = 0;  // Sets the Y direction to 0
    }
    if (IsKeyPressed(KEY_RIGHT))
    {
        dir.getX() = +1; // Sets the X direction to move right
        dir.getY() = 0;  // Sets the Y direction to 0
    }
}

/* ************************************************** */
void GameModel::updateSnakePosition()
{
    Position &pos = snake.getPosition();  // Gets the current position of the snake
    Position &dir = snake.getDirection(); // Gets the current direction of the snake

    pos.getX() += dir.getX(); // Updates the X position of the snake
    pos.getY() += dir.getY(); // Updates the Y position of the snake

    wrapAround(pos); // Wraps the snake around the grid if it goes off the edges

    checkIsEatingApple(); // Checks if the snake has eaten an apple

    checkIsCollided(); // Checks if the snake has collided with itself

    updateSnakeBodyPosition(); // Updates the body of the snake based on its new position
}

/* ************************************************** */
void GameModel::updateAppleSpawning()
{
    apple_spawn_timer += GetFrameTime(); // GetFrameTime() from Raylib returns the time passed since the last frame

    if (apple_spawn_timer >= APPLE_SPAWN_INTERVAL) // Checks if it's time to spawn a new apple
    {
        apple_spawn_timer = 0.0f; // Resets the timer

        if (apples.size() < APPLE_SPAWN_LIMIT) // Limits the number of apples on the screen
        {
            apples.push_back(getNewRandomPosition()); // Adds a new apple to the apples list
        }
    }
}

/* ************************************************** */
Position GameModel::convertDirectionToPosition(Direction dir)
{
    switch (dir)
    {
    case Direction::Up:
        return Position(0, -1); // Moves up (decreases Y)
    case Direction::Down:
        return Position(0, 1); // Moves down (increases Y)
    case Direction::Left:
        return Position(-1, 0); // Moves left (decreases X)
    case Direction::Right:
        return Position(1, 0); // Moves right (increases X)
    }
    return Position(0, 0); // Default case (this should never happen)
}

/* ************************************************** */
bool GameModel::areAllInLine()
{
    bool same_x = true;
    bool same_y = true;
    int x = snake.getBody().at(0).getX(); // Gets the X position of the first body segment
    int y = snake.getBody().at(0).getY(); // Gets the Y position of the first body segment

    for (size_t i = 1; i < snake.getBody().size(); i++) // Iterates through the body segments
    {
        if (snake.getBody().at(i).getX() != x)
        {
            same_x = false; // If X positions are not the same, sets same_x to false
        }
        if (snake.getBody().at(i).getY() != y)
        {
            same_y = false; // If Y positions are not the same, sets same_y to false
        }
    }
    return same_x || same_y; // Returns true if all segments are in a line (either horizontally or vertically)
}

/* ************************************************** */
void GameModel::checkIsEatingApple()
{
    for (size_t i = 0; i < apples.size(); i++) // Iterates through all apples
    {
        if (snake.getPosition().getX() == apples.at(i).getX() && // Checks if snake's head position matches an apple's position
            snake.getPosition().getY() == apples.at(i).getY())
        {
            apples.erase(apples.begin() + i);               // Removes the apple from the list
            snake.getBody().push_back(snake.getPosition()); // Adds a new body segment to the snake
        }
    }
}

/* ************************************************** */
void GameModel::checkIsCollided()
{
    if (snake.getBody().size() > 1 && !areAllInLine()) // Checks if the snake has collided with itself
    {
        for (size_t i = 1; i < snake.getBody().size(); i++) // Iterates through the body
        {
            if (snake.getBody().at(0).getX() == snake.getBody().at(i).getX() &&
                snake.getBody().at(0).getY() == snake.getBody().at(i).getY())
            {
                initGame(); // Restarts the game if there is a collision
            }
        }
    }
}

/* ************************************************** */
void GameModel::updateSnakeBodyPosition()
{
    for (size_t i = snake.getBody().size() - 1; i > 0; --i) // Iterates through the body segments starting from the tail
    {
        snake.getBody().at(i) = snake.getBody().at(i - 1); // Moves each segment to the next position
    }
    snake.getBody().at(0) = snake.getPosition(); // Updates the head of the snake to its new position
}

/* ************************************************** */
void GameModel::wrapAround(Position &pos)
{
    // Ensures the snake wraps around the grid when it goes off the edges
    pos.getX() = (pos.getX() + GRID_SIZE - 1) % (GRID_SIZE - 1);
    pos.getY() = (pos.getY() + GRID_SIZE - 1) % (GRID_SIZE - 1);
}

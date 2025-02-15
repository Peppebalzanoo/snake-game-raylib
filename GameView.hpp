#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP

#include "GameModel.hpp"

class GameView
{

private:
    /* ************************************************** */
    GameModel &game_model; // Reference to the game model that holds game data

    const int GRID_SIZE = GameModel::GRID_SIZE; // The size of the grid from the game model
    const int CELL_SIZE = GameModel::CELL_SIZE; // The size of each cell in the grid

    const int offset_x = CELL_SIZE; // Horizontal offset for positioning
    const int offset_y = CELL_SIZE; // Vertical offset for positioning

    const int screenWidth = GRID_SIZE * CELL_SIZE + offset_x;  // Screen width based on grid size and cell size
    const int screenHeight = GRID_SIZE * CELL_SIZE + offset_y; // Screen height based on grid size and cell size
    /* ************************************************** */

private:
    /* ************************************************** */
    void drawRows(); // Draws the rows on the game grid

    /* *********************** */
    void drawColumns(); // Draws the columns on the game grid

    /* *********************** */
    void drawApples(); // Draws the apples on the game grid

    /* *********************** */
    void drawSnake(); // Draws the snake on the game grid

    /* ************************************************** */

public:
    /* ************************************************** */
    GameView(GameModel &model); // Constructor that initializes the game view with a reference to the game model

    /* *********************** */
    void render(); // Renders the entire game view (grid, apples, and snake)

    /* ************************************************** */
};

#endif

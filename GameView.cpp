#include "GameView.hpp"

GameView::GameView(GameModel &model) : game_model(model)
{
    InitWindow(screenWidth, screenHeight, "Raylib Snake Example"); // Initializes the game window with the specified width, height, and title
    SetTargetFPS(15);                                              // Sets the target frames per second
}

/* ************************************************** */

void GameView::drawRows()
{
    // Loops through all the rows and draws the horizontal lines on the grid
    for (int row = 0; row <= GRID_SIZE; row++)
    {
        int start_x = offset_x;
        int start_y = row * CELL_SIZE + offset_y;

        if (row == 0) // Draws the first row line in green
        {
            DrawLine(start_x, start_y, GRID_SIZE * CELL_SIZE, start_y, GREEN);
        }
        else if (row == GRID_SIZE) // Draws the last row line in green
        {
            start_y = start_y - offset_y;
            DrawLine(start_x, start_y, GRID_SIZE * CELL_SIZE, start_y, GREEN);
        }
        else // Draws other rows in light gray
        {
            DrawLine(start_x, start_y, GRID_SIZE * CELL_SIZE, start_y, LIGHTGRAY);
        }
    }
}

/* ************************************************** */

void GameView::drawColumns()
{
    // Loops through all the columns and draws the vertical lines on the grid
    for (int col = 0; col <= GRID_SIZE; col++)
    {
        int start_x = col * CELL_SIZE + offset_x;
        int start_y = offset_y;

        if (col == 0) // Draws the first column line in green
        {
            DrawLine(start_x, start_y, start_x, GRID_SIZE * CELL_SIZE, GREEN);
        }
        else if (col == GRID_SIZE) // Draws the last column line in green
        {
            start_x = start_x - offset_x;
            DrawLine(start_x, start_y, start_x, GRID_SIZE * CELL_SIZE, GREEN);
        }
        else // Draws other columns in light gray
        {
            DrawLine(start_x, start_y, start_x, GRID_SIZE * CELL_SIZE, LIGHTGRAY);
        }
    }
}

/* ************************************************** */

void GameView::drawApples()
{
    // Loops through all apples and draws them as red circles
    for (const auto &pos_apple : game_model.getApples())
    {
        DrawCircle(
            pos_apple.getX() * CELL_SIZE + (CELL_SIZE / 2) + offset_x, // X position adjusted for center
            pos_apple.getY() * CELL_SIZE + (CELL_SIZE / 2) + offset_y, // Y position adjusted for center
            CELL_SIZE / 2,                                             // Apple radius
            RED);                                                      // Color of the apple
    }
}

/* ************************************************** */

void GameView::drawSnake()
{
    const std::vector<Position> &body = game_model.getSnake().getBody();
    
    int head_pos_x = (body.at(0).getX() * CELL_SIZE) + offset_x;
    int head_pos_y = (body.at(0).getY() * CELL_SIZE) + offset_y;
    DrawRectangle(head_pos_x, head_pos_y, CELL_SIZE, CELL_SIZE, DARKGREEN); // Draws head of snake as a dark-blue rectangle

    for (size_t i = 1; i < body.size(); i++)
    {
        int pos_x = (body.at(i).getX() * CELL_SIZE) + offset_x;
        int pos_y = (body.at(i).getY() * CELL_SIZE) + offset_y;
        DrawRectangle(pos_x, pos_y, CELL_SIZE, CELL_SIZE, GREEN); // Draws each snake segment as a blue rectangle
    }
}

/* ************************************************** */

void GameView::render()
{
    drawRows();    // Draws the rows on the grid
    drawColumns(); // Draws the columns on the grid
    drawApples();  // Draws the apples on the grid
    drawSnake();   // Draws the snake on the grid
}

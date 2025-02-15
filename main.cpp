#include "GameController.hpp"

int main()
{

    GameModel model;
    GameView view(model);
    GameController controller(model, view);

    // Loop principale
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        controller.updateModel();

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);

        controller.updateView();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();
    return 0;
}

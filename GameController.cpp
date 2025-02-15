#include "GameController.hpp"

GameController::GameController(GameModel &model_ref, GameView &view_ref) : model(model_ref), view(view_ref) {};

/* ************************************************** */

void GameController::updateModel()
{
    model.updateSnakePosition();
    model.updateSnakeDirection();
    model.updateAppleSpawning();
}

/* ************************************************** */

void GameController::updateView()
{
    view.render();
}
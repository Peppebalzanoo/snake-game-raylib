#ifndef GAMECONTROLLER_HPP

#define GAMECONTROLLER_HPP

#include "GameModel.hpp"
#include "GameView.hpp"

class GameController
{
private:
    /* ************************************************** */
    GameModel &model;
    GameView &view;
    /* ************************************************** */

public:
    /* ************************************************** */
    GameController(GameModel &model_ref, GameView &view_ref);

    /* *********************** */
    void updateModel();

    void updateView();
    /* ************************************************** */
};

#endif

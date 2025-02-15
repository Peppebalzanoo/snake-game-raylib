# Snake Game in C++ with Raylib

This repository contains a simple implementation of the classic Snake game for educational purposes using the C++ language and the Raylib graphics library. The project follows the **MVC (Model-View-Controller)** design pattern to organize the code and ensure maintainability and separation of concerns.

## Requirements

To compile and run the game, make sure you have installed:

- A C++ compiler compatible with C++11 or later (e.g., g++, clang++)
- The [Raylib](https://www.raylib.com/) library installed on your system

## Installation and Compilation

1. Clone the repository:

   ```sh
   git clone https://github.com/Peppebalzanoo/snake-game-raylib.git
   ```

2. Compile the project (a `build.sh` file is available containing the following command to facilitate compilation and execution):

   ```sh
   g++ main.cpp Position.cpp Snake.cpp GameView.cpp GameModel.cpp GameController.cpp -o snake -lraylib && ./snake
   ```

3. Run the game:

   ```sh
   ./snake
   ```
   
## Controls

- **Arrow Up**: Move the snake up
- **Arrow Down**: Move the snake down
- **Arrow Left**: Move the snake left
- **Arrow Right**: Move the snake right
- **ESC**: Exit the game


<img src="https://github.com/user-attachments/assets/dfa55945-2f34-441e-b3f7-bf35b856b81b" alt="Screenshot 2025-02-15 154518" width="40%" height="40%">


## Code Structure

The code is organized following the **MVC (Model-View-Controller)** design pattern:

- `GameController.hpp/GameController.cpp` → Manages the game's control logic (Controller)
- `GameModel.hpp/GameModel.cpp` → Defines data structures and game logic (Model)
- `GameView.hpp/GameView.cpp` → Handles the game's graphical rendering (View)
- `main.cpp` → Contains the main game code

## Dependencies

If you don't have Raylib installed, you can download and compile it by following the instructions on the official website: [https://www.raylib.com/](https://www.raylib.com/)

On Debian-based systems, you can install it with:

```sh
sudo apt install libraylib-dev
```

## Contributions

Bug reports, suggestions, or improvements are welcome. Feel free to open an issue or submit a pull request!

## License

This project is released under the MIT license. See the `LICENSE` file for more details.

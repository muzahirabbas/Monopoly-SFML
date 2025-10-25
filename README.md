# Monopoly++

This is a C++ implementation of the classic board game Monopoly, built using the SFML multimedia library.

## Description

This project is a 2-4 player Monopoly game with a graphical user interface. It includes features like buying and selling properties, building houses and hotels, paying rent, and drawing Chance and Community Chest cards. The game ends when all but one player goes bankrupt.

## Features

*   2-4 player local multiplayer
*   Graphical board and player tokens
*   Dice rolling animation
*   Property management (buying, selling, mortgaging)
*   Chance and Community Chest cards
*   Jail and Go spaces
*   Bankruptcy detection

## Screenshots

*(This section would ideally contain screenshots of the game in action. The following are placeholder image names from the `resources` directory that could be used.)*

*   `resources/main.png` - The main game board.
*   `resources/Dice.png` - The dice used in the game.
*   `resources/p1.png`, `resources/p2.png`, `resources/p3.png`, `resources/p4.png` - The player tokens.

## Getting Started

### Prerequisites

*   A C++ compiler (like g++)
*   SFML library (https://www.sfml-dev.org/)
*   OpenAL32

### Installation

1.  Clone the repository:
    ```
    git clone https://github.com/your-username/Monopoly-SFML.git
    ```
2.  Compile the project using your preferred C++ compiler, making sure to link the SFML and OpenAL32 libraries. For example, using g++:
    ```
    g++ "Monopoly Project/code.cpp" -o Monopoly.exe -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lopenal32
    ```
3.  Run the executable:
    ```
    ./Monopoly.exe
    ```

## How to Play

1.  Launch the game.
2.  Select the number of players (2-4).
3.  Each player takes a turn to roll the dice and move their token around the board.
4.  When a player lands on an unowned property, they can choose to buy it.
5.  If a player lands on a property owned by another player, they must pay rent.
6.  Players can build houses and hotels on their properties to increase the rent.
7.  The game ends when only one player is left who has not gone bankrupt.

## Built With

*   [C++](https://isocpp.org/)
*   [SFML](https://www.sfml-dev.org/) - Simple and Fast Multimedia Library

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

*   The developers of the SFML library.
*   The creators of the original Monopoly board game.

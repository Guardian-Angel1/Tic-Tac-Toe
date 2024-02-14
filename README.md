markdown

# Tic-Tac-Toe Game with AI

## Introduction
This Tic-Tac-Toe implementation in C++ features two modes of gameplay against an AI: one using the Minimax algorithm and another enhanced with Alpha-Beta Pruning. Designed to showcase different AI strategies in a classic game, this project also includes performance analysis features, such as move generation counts and execution time measurement, allowing players to compare the efficiency and speed of both algorithms.

## Requirements
- C++ Compiler (GCC or any compatible C++11 compiler)
- Basic knowledge of C++, terminals, or command prompts

## Installation
1. **Clone the repository or download the source code:**

git clone https://github.com/Guardian-Angel1/Tic-Tac-Toe-.git

markdown

or directly download `TTT.cpp` if available.

2. **Navigate to the project directory:**

cd path/to/Tic-Tac-Toe

markdown


3. **Compile the source code:**

g++ -o TicTacToe TTT.cpp

shell


## Usage
To play the game, execute the compiled program:

./TicTacToe

markdown


Upon launch, you will be prompted to:
- Choose your symbol (X or O).
- Decide who plays first.
- Select the algorithm: Minimax or Minimax with Alpha-Beta Pruning.
- Set the maximum depth for the algorithm (for adjusting difficulty).

Enter your moves as prompted by entering the row and column numbers.

## Features
- **Two AI Modes:** Choose between classic Minimax or the optimized Minimax with Alpha-Beta Pruning.
- **Performance Analysis:** After each game, the application reports the total number of positions evaluated and the total time taken, enabling a comparative analysis of the two algorithms in terms of efficiency and speed.
- **Customizable Difficulty:** Through the maximum depth setting, players can adjust the AI's foresight, making the game as easy or as challenging as desired.
- **Win/Tie Detection:** The game accurately detects and announces wins, losses, or ties.

## Algorithms Description
- **Minimax:** A brute-force search algorithm that explores all possible moves in the game to find the best move for the AI. It evaluates the game state from the perspective of maximizing the AI's chances of winning while minimizing the opponent's chances.
- **Minimax with Alpha-Beta Pruning:** An optimized version of Minimax that significantly reduces the number of nodes evaluated in the search tree, using two values, alpha and beta, to prune branches that cannot influence the final decision.

## Contributing
Contributions are welcome to enhance the game's AI, improve performance, or add new features. To contribute:
1. Fork the repository.
2. Create a feature branch: `git checkout -b new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin new-feature`
5. Submit a pull request.

## License
This project is open-sourced under [License Name]. For more details, see the LICENSE fil

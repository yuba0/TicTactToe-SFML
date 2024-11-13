#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>

const int WINDOW_SIZE = 600;
const int GRID_SIZE = 3;
const int CELL_SIZE = WINDOW_SIZE / GRID_SIZE;

std::array<std::array<char, GRID_SIZE>, GRID_SIZE> board;
char currentPlayer = 'X';

void resetBoard() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

bool checkWinner(char player) {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Tic Tac Toe");

    // Charger la police
    sf::Font font;
    if (!font.loadFromFile("OpenSans-Regular.ttf")) {  // Assure-toi que le chemin correspond au fichier ajouté
        std::cerr << "Erreur : impossible de charger la police de caractères.\n";
        return -1;
    }

    resetBoard();
    bool gameWon = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::MouseButtonPressed && !gameWon) {
                int x = event.mouseButton.x / CELL_SIZE;
                int y = event.mouseButton.y / CELL_SIZE;

                if (x < GRID_SIZE && y < GRID_SIZE && board[y][x] == ' ') {
                    board[y][x] = currentPlayer;
                    if (checkWinner(currentPlayer)) {
                        gameWon = true;
                        std::cout << "Joueur " << currentPlayer << " a gagné !" << std::endl;
                    } else {
                        switchPlayer();
                    }
                }
            }
        }

        window.clear(sf::Color::White);

        for (int i = 1; i < GRID_SIZE; i++) {
            sf::RectangleShape line(sf::Vector2f(WINDOW_SIZE, 2));
            line.setPosition(0, i * CELL_SIZE);
            line.setFillColor(sf::Color::Black);
            window.draw(line);

            line.setSize(sf::Vector2f(2, WINDOW_SIZE));
            line.setPosition(i * CELL_SIZE, 0);
            window.draw(line);
        }

        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (board[i][j] != ' ') {
                    sf::Text text;
                    text.setFont(font);
                    text.setString(board[i][j]);
                    text.setCharacterSize(CELL_SIZE - 20);
                    text.setFillColor(sf::Color::Black);
                    text.setPosition(j * CELL_SIZE + 10, i * CELL_SIZE - 10);
                    window.draw(text);
                }
            }
        }

        window.display();
    }

    return 0;
}

#include "GameBoard.h"

GameBoard::GameBoard()
{
	for (size_t i = 0; i < boardSizeY; i++) {
		for (size_t j = 0; j < boardSizeX; j++) {
			if (i == 0 || i == (boardSizeY - 1)) {
				m_board[i][j] = '#';
				std::cout << m_board[i][j];
			}
			else if (j == 0 || j == (boardSizeX - 1)) {
				m_board[i][j] = '#';
				std::cout << m_board[i][j];
			}
			else {
				m_board[i][j] = ' ';
				std::cout << m_board[i][j];
			}
		}
		std::cout << std::endl;
	}
}

void GameBoard::drawSnake(Snake* snake)
{
	for (auto it : snake->m_wholeSnake) {
		m_board[it.y][it.x] = 'O';
	}
}

void GameBoard::cleanBoardFromSnake(Snake* snake)
{
	for (auto it : snake->m_wholeSnake) {
		GameBoard::clearSymbol(it.x, it.y);
	}
}

void GameBoard::clearSymbol(int x, int y)
{
	if (m_board[y][x] != '#') {
		m_board[y][x] = ' ';
	}
}

void GameBoard::updateBoard()
{
	system("cls");
	for (int i = 0; i < boardSizeY; i++) {
		for (int j = 0; j < boardSizeX; j++) {
			std::cout << m_board[i][j];
		}
		std::cout << std::endl;
	}
}

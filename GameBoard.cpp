#include "GameBoard.h"

GameBoard::GameBoard()
{
	for (size_t i = 0; i < m_boardSizeY; i++) {
		for (size_t j = 0; j < m_boardSizeX; j++) {
			if (i == 0 || i == (m_boardSizeY - 1)) {
				m_board[i][j] = wallSymbol;
				std::cout << m_board[i][j];
			}
			else if (j == 0 || j == (m_boardSizeX - 1)) {
				m_board[i][j] = wallSymbol;
				std::cout << m_board[i][j];
			}
			else {
				m_board[i][j] = voidSymbol;
				std::cout << m_board[i][j];
			}
		}
		std::cout << std::endl;
	}
}

void GameBoard::drawSnake(Snake snake)
{
	for (auto it : snake.wholeSnake) {
		m_board[it.y][it.x] = snakeSymbol;
	}
}

void GameBoard::cleanBoardFromSnake(Snake snake)
{
	for (auto it : snake.wholeSnake) {
		GameBoard::clearSymbol(it.x, it.y);
	}
}

void GameBoard::drawFruite(Fruite fruite)
{
	m_board[fruite.getY()][fruite.getX()] = fruiteSymbol;
}

void GameBoard::clearSymbol(int x, int y)
{
	if (m_board[y][x] != wallSymbol) {
		m_board[y][x] = voidSymbol;
	}
}

void GameBoard::updateBoard()
{
	system("cls");
	for (int i = 0; i < m_boardSizeY; i++) {
		for (int j = 0; j < m_boardSizeX; j++) {
			std::cout << m_board[i][j];
		}
		std::cout << std::endl;
	}
}

void GameBoard::showGameOver()
{
	system("cls");
	for (int i = 0; i < m_gameOverStringSizeY; i++) {
		for (int j = 0; j < m_gameOverStringSizeX; j++) {
			std::cout << m_gameOverString[i][j];
		}
		std::cout << std::endl;
	}
}

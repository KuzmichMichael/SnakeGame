#include "GameBoard.h"
#include "GameRules.h"

GameBoard::GameBoard()
{
	for (size_t i = 0; i < m_boardSizeY; i++) {
		for (size_t j = 0; j < m_boardSizeX; j++) {
			if (i == 0 || i == (m_boardSizeY - 1)) {
				m_board[i][j] = GameRules::wallSymbol;
				std::cout << m_board[i][j];
			}
			else if (j == 0 || j == (m_boardSizeX - 1)) {
				m_board[i][j] = GameRules::wallSymbol;
				std::cout << m_board[i][j];
			}
			else {
				m_board[i][j] = GameRules::voidSymbol;
				std::cout << m_board[i][j];
			}
		}
		std::cout << std::endl;
	}
}

void GameBoard::drawSnake()
{
	if (snake->wholeSnake.empty()) {
		exit;
	}

	for (auto it : snake->wholeSnake) {
		m_board[it.y][it.x] = GameRules::snakeSymbol;
	}
}

void GameBoard::cleanBoardFromSnake()
{
	if (snake->wholeSnake.empty()) {
		exit;
	}

	for (auto it : snake->wholeSnake) {
		GameBoard::clearSymbol(it.x, it.y);
	}
}

void GameBoard::drawFruite()
{
	m_board[fruite->getY()][fruite->getX()] = GameRules::fruiteSymbol;
}

void GameBoard::clearSymbol(int x, int y)
{
	if (m_board[y][x] != GameRules::wallSymbol) {
		m_board[y][x] = GameRules::voidSymbol;
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

void GameBoard::attachSnake(Snake *attachedSnake)
{
	snake = attachedSnake;
}

void GameBoard::attachFruite(Fruite* attachedFruite)
{
	fruite = attachedFruite;
}

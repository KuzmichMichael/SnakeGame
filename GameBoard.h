#pragma once
#include <iostream>
#include "Snake.h"
#include "Fruite.h"

class GameBoard
{
public:
	GameBoard();
	~GameBoard() = default;

	static void clearSymbol(int x, int y);
	void updateBoard();
	void showGameOver();
	void attachSnake(Snake *attachedSnake);
	void attachFruite(Fruite* attachedFruite);

	void drawSnake();
	void cleanBoardFromSnake();

	void drawFruite();

	friend class Snake;
	friend class Fruite;

private:
	static constexpr const int m_boardSizeX = 60;
	static constexpr const int m_boardSizeY = 30;

	static constexpr const int m_gameOverStringSizeX = 60;
	static constexpr const int m_gameOverStringSizeY = 10;

	static char m_board[m_boardSizeY][m_boardSizeX];
	static char m_gameOverString[m_gameOverStringSizeY][m_gameOverStringSizeX];

	Snake* snake;
	Fruite* fruite;
};


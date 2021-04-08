#pragma once
#include <iostream>
#include "Snake.h"
#include "Fruite.h"

class GameBoard
{
public:
	static constexpr const char snakeSymbol = 'O';
	static constexpr const char wallSymbol = '#';
	static constexpr const char voidSymbol = ' ';
	static constexpr const char fruiteSymbol = '@';

	GameBoard();
	~GameBoard() = default;

	static void clearSymbol(int x, int y);
	void updateBoard();
	void showGameOver();

	void drawSnake(Snake snake);
	void cleanBoardFromSnake(Snake snake);

	void drawFruite(Fruite fruite);

	friend class Snake;
	friend class Fruite;

private:
	static constexpr const int m_boardSizeX = 60;
	static constexpr const int m_boardSizeY = 30;

	static constexpr const int m_gameOverStringSizeX = 60;
	static constexpr const int m_gameOverStringSizeY = 10;

	static char m_board[m_boardSizeY][m_boardSizeX];
	static char m_gameOverString[m_gameOverStringSizeY][m_gameOverStringSizeX];
};


#pragma once
#include <iostream>
#include "Snake.h"

class GameBoard
{
public:
	static constexpr const int boardSizeX = 60;
	static constexpr const int boardSizeY = 30;

	GameBoard();
	~GameBoard() = default;

	static void clearSymbol(int x, int y);
	void updateBoard();
	void drawSnake(Snake* snake);
	void cleanBoardFromSnake(Snake* snake);

	friend class Snake;
	friend class Fruit;

private:
	static char m_board[boardSizeY][boardSizeX];
};


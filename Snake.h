#pragma once
#include <vector>
#include <conio.h>
#include <iostream>

class Snake
{
private:
	enum class Direction
	{
		UP,
		DOWN,
		RIGHT,
		LEFT,
		NONE
	};

	struct Cell
	{
		int x;
		int y;
		Direction curDirection;
		Direction prevDirection;
	};

	void changeDirection(char key);
	void moveCell(Cell* cell);

	double m_speed;
	int m_size;

public:
	Snake();
	~Snake() = default;

	void moveSnake();
	void addCell();
	std::vector<Cell> wholeSnake;

};



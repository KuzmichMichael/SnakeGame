#pragma once
#include <vector>

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

	void changeDirection(Snake* snake, char key);
	void moveCell(Cell* cell);

public:
	Snake();
	~Snake() = default;

	void moveSnake(Snake* snake);
	void addCell(Snake* snake);

	std::vector<Cell> wholeSnake;
	double speed;
	int size;
};



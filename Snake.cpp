#include "Snake.h"
#include "GameBoard.h"
#include <conio.h>


Snake::Snake()
{
	Cell head;
	head.x = GameBoard::boardSizeX / 2;
	head.y = GameBoard::boardSizeY / 2;
	head.curDirection = Direction::RIGHT;
	head.prevDirection = Direction::UP;
	wholeSnake.push_back(head);
	
	addCell(this);

	speed = 0;
	size = 2;
}

void Snake::addCell(Snake* snake)
{
	if (snake->wholeSnake.empty()) {
		return;
	}
	Cell cell;
	cell.curDirection = snake->wholeSnake.back().prevDirection;
	cell.prevDirection = Direction::NONE;
	
	switch (cell.curDirection)
	{
	case(Direction::UP):
		cell.x = snake->wholeSnake.back().x;
		cell.y = snake->wholeSnake.back().y - 1;
		break;

	case(Direction::DOWN):
		cell.x = snake->wholeSnake.back().x;
		cell.y = snake->wholeSnake.back().y + 1;
		break;

	case(Direction::RIGHT):
		cell.x = snake->wholeSnake.back().x - 1;
		cell.y = snake->wholeSnake.back().y;
		break;

	case(Direction::LEFT):
		cell.x = snake->wholeSnake.back().x + 1;
		cell.y = snake->wholeSnake.back().y;
		break;

	default:
		break;
	}

	snake->wholeSnake.push_back(cell);
	size++;
}

void Snake::moveSnake(Snake* snake)
{
	if (snake->wholeSnake.empty()) {
		return;
	}

	if (_kbhit()) {
		changeDirection(snake, _getch());
	}
	
	//change every cell direction
	for (auto it = snake->wholeSnake.begin(); it != snake->wholeSnake.end() - 1; it++) {

		(*(it + 1)).prevDirection = (*(it + 1)).curDirection;
		(*(it + 1)).curDirection = (*it).curDirection;

	}


	//move every cell
	for (auto it = snake->wholeSnake.begin(); it != snake->wholeSnake.end(); it++) {
		moveCell(&(*it));
	}
}

void Snake::moveCell(Cell* cell)
{
	switch (cell->curDirection)
	{
	case(Direction::UP):
		cell->y -= 1;
		break;

	case(Direction::DOWN):
		cell->y += 1;
		break;

	case(Direction::RIGHT):
		cell->x += 1;
		break;

	case(Direction::LEFT):
		cell->x -= 1;
		break;

	default:
		break;
	}
}


void Snake::changeDirection(Snake* snake, char key)
{
	if (snake->wholeSnake.empty()) {
		return;
	}

	switch (key)
	{
	case 'w':
		if (snake->wholeSnake.front().curDirection == Direction::DOWN) {
			break;
		}
		snake->wholeSnake.front().prevDirection = wholeSnake.front().curDirection;
		snake->wholeSnake.front().curDirection = Direction::UP;
		break;

	case 's':
		if (snake->wholeSnake.front().curDirection == Direction::UP) {
			break;
		}
		snake->wholeSnake.front().prevDirection = wholeSnake.front().curDirection;
		snake->wholeSnake.front().curDirection = Direction::DOWN;
		break;			
						
	case 'a':		
		if (snake->wholeSnake.front().curDirection == Direction::RIGHT) {
			break;
		}
		snake->wholeSnake.front().prevDirection = wholeSnake.front().curDirection;
		snake->wholeSnake.front().curDirection = Direction::LEFT;
		break;			
						
	case 'd':	
		if (snake->wholeSnake.front().curDirection == Direction::LEFT) {
			break;
		}
		snake->wholeSnake.front().prevDirection = wholeSnake.front().curDirection;
		snake->wholeSnake.front().curDirection = Direction::RIGHT;
		break;

	default:
		break;
	}
}



#include "Snake.h"
#include "GameBoard.h"



Snake::Snake()
{
	Cell head;
	head.x = GameBoard::boardSizeX / 2;
	head.y = GameBoard::boardSizeY / 2;
	head.curDirection = Direction::RIGHT;
	head.prevDirection = Direction::RIGHT;
	wholeSnake.push_back(head);


	m_speed = 0;
	m_size = 2;
}

void Snake::addCell()
{
	if (wholeSnake.empty()) {
		return;
	}
	Cell cell;
	cell.curDirection = wholeSnake.back().prevDirection;
	cell.prevDirection = Direction::RIGHT;
	
	switch (cell.curDirection)
	{
	case(Direction::UP):
		cell.x = wholeSnake.back().x;
		cell.y = wholeSnake.back().y + 1;
		break;

	case(Direction::DOWN):
		cell.x = wholeSnake.back().x;
		cell.y = wholeSnake.back().y - 1;
		break;

	case(Direction::RIGHT):
		cell.x = wholeSnake.back().x - 1;
		cell.y = wholeSnake.back().y;
		break;

	case(Direction::LEFT):
		cell.x = wholeSnake.back().x + 1;
		cell.y = wholeSnake.back().y;
		break;

	default:
		break;
	}

	wholeSnake.push_back(cell);
	//change every cell direction
	for (auto it = wholeSnake.begin(); it != wholeSnake.end(); it++) {
		std::cout <<(*it).x << " " << (*it).y << " : ";
	}

	std::cout << std::endl;
	m_size++;
}

void Snake::moveSnake()
{
	if (wholeSnake.empty()) {
		return;
	}

	if (_kbhit()) {
		changeDirection(_getch());
	}

	//move every cell
	for (auto it = wholeSnake.begin(); it != wholeSnake.end(); it++) {
		moveCell(&(*it));
	}
	
	//change every cell direction
	for (auto it = wholeSnake.rbegin(); it != wholeSnake.rend() - 1; it++) {

		(*(it + 1)).prevDirection = (*(it + 1)).curDirection;
		(*it).curDirection = (*(it + 1)).curDirection;

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


void Snake::changeDirection(char key)
{
	if (wholeSnake.empty()) {
		return;
	}

	switch (key)
	{
	case 'w':
		if (wholeSnake.front().curDirection == Direction::DOWN) {
			break;
		}
		wholeSnake.front().prevDirection = wholeSnake.front().curDirection;
		wholeSnake.front().curDirection = Direction::UP;
		break;

	case 's':
		if (wholeSnake.front().curDirection == Direction::UP) {
			break;
		}
		wholeSnake.front().prevDirection = wholeSnake.front().curDirection;
		wholeSnake.front().curDirection = Direction::DOWN;
		break;			
						
	case 'a':		
		if (wholeSnake.front().curDirection == Direction::RIGHT) {
			break;
		}
		wholeSnake.front().prevDirection = wholeSnake.front().curDirection;
		wholeSnake.front().curDirection = Direction::LEFT;
		break;			
						
	case 'd':	
		if (wholeSnake.front().curDirection == Direction::LEFT) {
			break;
		}
		wholeSnake.front().prevDirection = wholeSnake.front().curDirection;
		wholeSnake.front().curDirection = Direction::RIGHT;
		break;

	default:
		break;
	}
}



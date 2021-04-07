#include "Snake.h"
#include "GameBoard.h"



Snake::Snake()
{
	Cell head;
	head.x = GameBoard::boardSizeX / 2;
	head.y = GameBoard::boardSizeY / 2;
	head.curDirection = Direction::RIGHT;
	head.prevDirection = Direction::RIGHT;
	m_wholeSnake.push_back(head);


	m_speed = 0;
	m_size = 2;
}

void Snake::addCell()
{
	if (m_wholeSnake.empty()) {
		return;
	}
	Cell cell;
	cell.curDirection = m_wholeSnake.back().prevDirection;
	cell.prevDirection = Direction::NONE;
	
	switch (cell.curDirection)
	{
	case(Direction::UP):
		cell.x = m_wholeSnake.back().x;
		cell.y = m_wholeSnake.back().y + 1;
		break;

	case(Direction::DOWN):
		cell.x = m_wholeSnake.back().x;
		cell.y = m_wholeSnake.back().y - 1;
		break;

	case(Direction::RIGHT):
		cell.x = m_wholeSnake.back().x - 1;
		cell.y = m_wholeSnake.back().y;
		break;

	case(Direction::LEFT):
		cell.x = m_wholeSnake.back().x + 1;
		cell.y = m_wholeSnake.back().y;
		break;

	default:
		break;
	}

	m_wholeSnake.push_back(cell);
	//change every cell direction
	for (auto it = m_wholeSnake.begin(); it != m_wholeSnake.end(); it++) {
		std::cout <<(*it).x << " " << (*it).y << " : ";
	}

	std::cout << std::endl;
	m_size++;
}

void Snake::moveSnake()
{
	if (m_wholeSnake.empty()) {
		return;
	}

	if (_kbhit()) {
		changeDirection(_getch());
	}
	
	//change every cell direction
	for (auto it = m_wholeSnake.rbegin(); it != m_wholeSnake.rend() - 1; it++) {

		(*(it + 1)).prevDirection = (*(it + 1)).curDirection;
		(*it).curDirection = (*(it + 1)).curDirection;

	}

	//move every cell
	for (auto it = m_wholeSnake.begin(); it != m_wholeSnake.end(); it++) {
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


void Snake::changeDirection(char key)
{
	if (m_wholeSnake.empty()) {
		return;
	}

	switch (key)
	{
	case 'w':
		if (m_wholeSnake.front().curDirection == Direction::DOWN) {
			break;
		}
		m_wholeSnake.front().prevDirection = m_wholeSnake.front().curDirection;
		m_wholeSnake.front().curDirection = Direction::UP;
		break;

	case 's':
		if (m_wholeSnake.front().curDirection == Direction::UP) {
			break;
		}
		m_wholeSnake.front().prevDirection = m_wholeSnake.front().curDirection;
		m_wholeSnake.front().curDirection = Direction::DOWN;
		break;			
						
	case 'a':		
		if (m_wholeSnake.front().curDirection == Direction::RIGHT) {
			break;
		}
		m_wholeSnake.front().prevDirection = m_wholeSnake.front().curDirection;
		m_wholeSnake.front().curDirection = Direction::LEFT;
		break;			
						
	case 'd':	
		if (m_wholeSnake.front().curDirection == Direction::LEFT) {
			break;
		}
		m_wholeSnake.front().prevDirection = m_wholeSnake.front().curDirection;
		m_wholeSnake.front().curDirection = Direction::RIGHT;
		break;

	default:
		break;
	}
}



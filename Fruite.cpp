#include "Fruite.h"
#include "GameBoard.h"

Fruite::Fruite()
{
	m_x = 0;
	m_y = 0;
	addFruit();
}

void Fruite::addFruit()
{
	do {
		m_x = rand() % (GameBoard::m_boardSizeX + 1);
		m_y = rand() % (GameBoard::m_boardSizeY + 1);
	}
	while (GameBoard::m_board[m_y][m_x] != ' ');
}

const int Fruite::getX() const
{
	return m_x;
}

const int Fruite::getY() const
{
	return m_y;
}

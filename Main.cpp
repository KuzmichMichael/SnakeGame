#include "GameBoard.h"
#include "Fruite.h"
#include "Snake.h"
#include <chrono>
#include <thread>

char GameBoard::m_board[boardSizeY][boardSizeX]{};

int main() {
	GameBoard board;
	Snake snake;

	std::chrono::milliseconds delayMS(100);
	int i = 0;
	while (true)
	{
		if (i == 5) {
			snake.addCell();
			i = 0;
		}
		snake.moveSnake();
		board.drawSnake(&snake);
		board.updateBoard();
		board.cleanBoardFromSnake(&snake);
		std::this_thread::sleep_for(delayMS);
		i++;
	}
}
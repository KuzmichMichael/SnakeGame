#include "GameBoard.h"
#include "Fruite.h"
#include "Snake.h"
#include <chrono>
#include <thread>

char GameBoard::m_board[boardSizeY][boardSizeX]{};

int main() {
	GameBoard board;
	Snake snake;

	std::chrono::milliseconds delayMS(1000);
	int i = 0;
	while (true)
	{
		snake.addCell();
		//snake->moveSnake(snake);
		//board.drawSnake(snake);
		//board.updateBoard();
		//board.cleanBoardFromSnake(snake);
		std::this_thread::sleep_for(delayMS);
		i++;
	}
}
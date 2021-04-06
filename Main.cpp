#include "GameBoard.h"
#include "Fruite.h"
#include "Snake.h"
#include <chrono>
#include <thread>

char GameBoard::m_board[boardSizeY][boardSizeX]{};

int main() {
	GameBoard board;
	Snake* snake = new Snake();

	std::chrono::milliseconds delayMS(1);
	int i = 0;
	while (true)
	{
		if (i == 15) {
			snake->addCell(snake);
			i = 0;
		}
		snake->moveSnake(snake);
		board.drawSnake(snake);
		board.updateBoard();
		board.cleanBoardFromSnake(snake);
		std::this_thread::sleep_for(delayMS);
		i++;
	}
}
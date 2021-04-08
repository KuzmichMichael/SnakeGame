#pragma once
#include <ctime>
#include <cstdlib>

class Fruite
{
public:
	Fruite();
	~Fruite() = default;

	void addFruit();
	const int getX() const;
	const int getY() const;

private:
	int m_x;
	int m_y;
};


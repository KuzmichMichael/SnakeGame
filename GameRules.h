#pragma once
class GameRules
{
public:
	GameRules() = default;
	virtual ~GameRules() = default;

	static constexpr const char snakeSymbol = 'O';
	static constexpr const char wallSymbol = '#';
	static constexpr const char voidSymbol = ' ';
	static constexpr const char fruiteSymbol = '@';
};


#pragma once
#define HEIGHT_MAP_8 8
#define WIDTH_MAP_8 8
#include"SFML/Graphics.hpp"
class Map8
{
	sf::String map_8[HEIGHT_MAP_8] = {
		"bbbbbbbb",
		"bbbbbbbb",
		"bbbbbbbb",
		"bbbbbbbb",
		"bbbbbbbb",
		"bbbbbbbb",    /// Сделать связный список карт и функцию получения этих карт для функции DrawMap
		"bbbbbbbb",
		"bbbbbbbb",
	};
	const int MinesSquare = 10;
	const int SizeBlocks = 8;
};


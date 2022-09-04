#pragma once
#define MAX_HEIGHT  30
#define MAX_WIDTH 30
#include"SFML/Graphics.hpp"
#include<list>
#include<vector>
#include"Map8.h"


/*

	�������� ����� � �������.

   b - ������������ �������
   m - ����
   o - ������� � ������ ����
   d - ������� � ������ ���
   t - ������� � ������ ���
   f - ������� � ������ ������ 
   v - ������� � ������ ����
*/





class Game
{
	
	sf::String **map{};  
	
	 int MinesSquare{};
	 int SizeSquare{};
	std::vector<sf::Vector2u> Mines;
	int SizePNG{};

public:
	Game();
	Game(int size);
	void DrawMap(sf::RenderWindow &wnd, sf::Sprite &BasedSquare, sf::Sprite &SquareOne,
		sf::Sprite &SquareTwo, sf::Sprite &SquareThree, sf::Sprite &SquareFour, sf::Sprite &SquareFive) const;

	void ChangeMap(sf::Vector2i pos);
	void CreateMines();
    void RepeatCheck();
	~Game();
};


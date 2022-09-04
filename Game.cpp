#include "Game.h"
#include<random>
#include<iostream>

Game::Game() {
	this->MinesSquare = NULL;
	this->SizeSquare = NULL;
	this->map = NULL;
}

Game::Game(int size) {
	if (size == 8) {
		this->MinesSquare = 10;
		this->SizeSquare = 8;
		this->SizePNG = 64;
		this->map = new sf::String*[size];
		for (int i = 0; i < SizeSquare; i++) {
			map[i] = new sf::String[size];
		}

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				map[i][j] = 'b';
			}
		}
	}
	else if (size == 16) {
		this->MinesSquare = 40;
		this->SizeSquare = 16;
		this->SizePNG = 32;
		this->map = new sf::String * [size];
		for (int i = 0; i < SizeSquare; i++) {
			map[i] = new sf::String[size];
		}

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				map[i][j] = 'b';
			}
		}
	}
	

}

Game::~Game() {
	delete[] map; /// Проверить memory leak!!!
}

void Game::DrawMap(sf::RenderWindow &window, sf::Sprite &BasedSquare, sf::Sprite &SquareOne,
	sf::Sprite &SquareTwo, sf::Sprite &SquareThree, sf::Sprite &SquareFour, sf::Sprite &SquareFive) const {

	window.clear();
	for (int i = 0; i < SizeSquare; i++) {
		for (int j = 0; j < SizeSquare; j++) {
			if (this->map[i][j] == 'b' || this->map[i][j] == 'm') {
				BasedSquare.setTextureRect(sf::IntRect(0, 0, SizePNG, SizePNG));
				window.draw(BasedSquare);
				BasedSquare.setPosition(j * SizePNG, i * SizePNG);
			}
			else if (this->map[i][j] == 'o') {
				SquareOne.setTextureRect(sf::IntRect(0, 0, SizePNG, SizePNG));
				SquareOne.setPosition(j * SizePNG, i * SizePNG);
				window.draw(SquareOne);
			}
			else if (this->map[i][j] == 'd') {
				SquareTwo.setTextureRect(sf::IntRect(0, 0, 64, 64));
				SquareTwo.setPosition(j * 64, i * 64);
				window.draw(SquareTwo);
			}
			else if (this->map[i][j] == 't') {
				SquareThree.setTextureRect(sf::IntRect(0, 0, 64, 64));
				SquareThree.setPosition(j * 64, i * 64);
				window.draw(SquareThree);
			}
			else if (this->map[i][j] == 'f') {
				SquareFour.setTextureRect(sf::IntRect(0, 0, 64, 64));
				SquareFour.setPosition(j * 64, i * 64);
				window.draw(SquareFour);
			}
			else if (this->map[i][j] == 'v') {
				SquareFive.setTextureRect(sf::IntRect(0, 0, 64, 64));
				SquareFive.setPosition(j * 64, i * 64);
				window.draw(SquareFive);
			}

		}
	}
	window.display(); 

}

void Game::ChangeMap(sf::Vector2i pos) {
	int x = pos.x / SizePNG; /// Придумать зависимость от размера картинки 
	int y = pos.y / SizePNG;
	this->map[y][x] = 'o';

	for (int i = 0; i < this->MinesSquare; i++) {
		this->map[Mines[i].y][Mines[i].x] = 'm';
	}

}

void Game::RepeatCheck() {
	for (int i = 0; i < Mines.size(); i++) { // Проверка чтобы мины не накладывались друг на друга

	}
}

void Game::CreateMines() {

	srand(time(NULL));

	sf::Vector2u PositionMines;  // Создаю случайные мины на карте

	for (int i = 0; i < this->MinesSquare; i++) {
		PositionMines.x = rand() % SizeSquare;
		PositionMines.y = rand() % SizeSquare;
		this->Mines.push_back(PositionMines);
	}

	RepeatCheck();

	for (int i = 0; i < this->MinesSquare; i++) {
		this->map[Mines[i].y][Mines[i].x] = 'm';
	}
}
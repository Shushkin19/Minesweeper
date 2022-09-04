#include"SFML/Graphics.hpp"
#include<iostream>
#include"Game.h"


using namespace sf;

int main() {

	RenderWindow window(sf::VideoMode(1220,980), "Mines");

	
//////////////////////////////////// КВАДРАТ ДЛЯ КАРТЫ /////////////////////////
	/*mp.GetSprite("blsqr64.png"); /// пока не работает*/
	
	Game gm(16);
	gm.CreateMines();
	sf::Image img;
	img.loadFromFile("blsqr64.png"); /// добавить картинки на 32 и 16
	sf::Texture txtr;
	txtr.loadFromImage(img);
	sf::Sprite spr;
	spr.setTexture(txtr);

	
	Image img1;
	img1.loadFromFile("one_blsqr64.png");
	Texture txtr1;
	txtr1.loadFromImage(img1);
	Sprite spr1;
	spr1.setTexture(txtr1);


//////////////////////////////////////////////////////////////////////////////////////
	std::vector<sf::String> vec;

				sf::Vector2i cor;

	Vector2i pos; // переменная для координат мыши

	while (window.isOpen()) {
		
			Event event;
		
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		
		
		};
		//pos = Mouse::getPosition(window);

		gm.DrawMap(window, spr, spr1, spr, spr, spr, spr);

		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (sf::IntRect(0, 0, 512, 512).contains(sf::Mouse::getPosition(window))) {



				pos = Mouse::getPosition(window);
				//std::cout << pos.x << " - " << pos.y << std::endl;
				gm.ChangeMap(pos);
				//cor = mp.GetNumSquare(pos);
				//std::cout << cor.x << " - " << cor.y << std::endl;
				//mp.map_8[cor.y][cor.x] = 'h';
				static int c = 0;
				std::cout << "click! - " << c << std::endl;
				c++;
				sleep(milliseconds(300));
			}
		}

	}



	return  0;
}
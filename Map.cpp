#include "Map.h"




Map::Map() {

	TileMap = new sf::String[HEIGHT_MAP] {
		"000000000000000000000000000000",
        "00                          00",
        "00                          00",
        "00  11  11  111111  11  11  00",
        "00  11  11  111111  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  112211  11  11  00",
        "00  11  11  112211  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11          11  11  00",
        "00  11  11          11  11  00",
        "00          11  11         h00",
        "00          11  11          00",
        "0011  1111          1111  1100",
        "0022  1111          1111  2200",
        "00 h        11h 11          00",
        "00          111111          00",
        "00  11  11  111111  11  11  00",
        "00  11  11  11 h11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  11  11  11  11  11  11  00",
        "00  1111111111111111111111  00",
        "00  11  11          11  11  00",
        "00  11  11   1111   11  11  00",
        "00           1  1           00",
        "00           1  1           00",
        "000000000000000000000000000000",
    };
	map_texture.loadFromFile("assets/wall/2.png");//загрузка текстуры карты
	map_texture.setSmooth(true);//включение сглаживания вроде как пиксели убирать должно
	map_sprite.setTexture(map_texture);//создания спрайта для карты


}


//разрушение стенки от выстрела
void Map::break_wall(const int& i, const int& j)
{
	TileMap[i][j] = ' ';
}

//получение тайлика карты
const char Map::get_tile(const int& i, const int& j)
{
	return TileMap[i][j];
}

//рисовалка карты
void Map::draw(sf::RenderWindow& window)
{
	for (int i(0); i < HEIGHT_MAP; i++)
		for (int j(0); j < WIDTH_MAP; j++) {
			switch (TileMap[i][j]) {
			case '1':
				map_sprite.setTextureRect(sf::IntRect(0, 0, 24, 24));
				break;

			case ' ':
				map_sprite.setTextureRect(sf::IntRect(72, 0, 24, 24));
				break;

			case '0':
				map_sprite.setTextureRect(sf::IntRect(24, 0, 24, 24));
				break;

			case '2':
				map_sprite.setTextureRect(sf::IntRect(48, 0, 24, 24));
				break;
			case 'h':
                map_sprite.setTextureRect(sf::IntRect(96, 0, 24, 24));
                break;
			}
			map_sprite.setPosition(j * 24, i * 24);
			window.draw(map_sprite);
		}
}

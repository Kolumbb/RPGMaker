#include "stdafx.h"
#include "Entity.h"

Entity::Entity(float pos_x, float pos_y){
	this->position = sf::Vector2f(pos_x, pos_y);
	/*switch (entity_type) {
		case PLAYER: {
			this->textureSheet.loadFromFile();
		}break;
		case ENEMY: {
			this->textureSheet.loadFromFile();
		}break;
		default: {
			this->textureSheet.loadFromFile();
			MessageBox(HWND(), L"Sorry, we couldn't find your texture sheet, please check the file location", L"Error", MB_ICONWARNING);
		}
	}*/

		
}

Entity::~Entity(){
	std::cout << "Enetity Deleted\n";

}



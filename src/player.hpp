#pragma once

#include <vector>
#include <string>
#include "item.hpp"

class Item;

class Player
{
public:
	Player() = default;
	~Player() = default;
	
	// Position
	int x;
	int y;
	size_t floor;

	//Attributes
	std::string name;
	int health;
	int mana;
	std::vector<Item> inventory;
};

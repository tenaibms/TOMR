#pragma once

#include "player.hpp"
#include <string>
#include <functional>

class Player;

class Item
{
private:
	std::function<void(Player &)> callback;
public:
	Item(std::string display_name, std::function<void(Player &)> function);
	~Item() = default;
	void Interact(Player & player);	
	std::string display_name;	
};

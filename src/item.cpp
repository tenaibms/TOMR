#include "item.hpp"
#include "player.hpp"
#include <string>
#include <functional>

Item::Item(std::string display_name, std::function<void(Player &)> function)
{
	this->display_name = display_name;
	callback = function;
}
void Item::Interact(Player & player)
{
	if(callback)
		callback(player);
}

#include "window.hpp"
#include "player.hpp"
#include "item.hpp"

#define WINDOW_WIDTH 80
#define WINDOW_HEIGHT 24

int main()
{
	Player player;

	Item juice("juice", [](Player & player){ player.health = 10; });

	player.inventory.push_back(juice);

	player.inventory[0].Interact(player);

	printf("%d\n", player.health);
  
  printf("\e[1;1H\e[2J");
	
  Window window(24, 80);

  window.Draw();
  window.Print();
}

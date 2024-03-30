#pragma once
#include <functional>
#include <string>
#include "player.hpp"

class Tile
{
private:
  std::function<void(Player & player)> callback;
public:
  Tile(std::string name, char character, std::function<void(Player & player)>);
  ~Tile() = default;
  char character;
  void interact();
};

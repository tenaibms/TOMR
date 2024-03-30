#pragma once
#include <stddef.h>
#include <vector>

struct Layer
{
public:
	Layer(size_t z_index);
	~Layer() = default;
	char data[24][80];
	size_t z_index;
};

class Window
{
private:
  char window_buffer[24][80];
	std::vector<Layer> layers;
	
  void RegisterLayers();
	void ClearBuffer();
public:
	Window(size_t window_width, size_t window_height);
  ~Window() = default;

  size_t window_height = 24;
	size_t window_width = 80;
	
	void Draw();
	void Print(); 
};

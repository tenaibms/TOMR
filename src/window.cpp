#include <stddef.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <format>

#include "window.hpp"
#include "layers.hpp"
#include "player.hpp"

Layer::Layer(size_t z_index)
{
	this->z_index = z_index;
}

Window::Window(size_t window_height, size_t window_width)
{
	this->window_height = window_height;
	this->window_width = window_width;

  RegisterLayers();
}

void Window::ClearBuffer()
{
	for(size_t i = 0; i < 24; i++)
	{
		for(size_t j = 0; j < 80; j++)
		{
			window_buffer[i][j] = ' ';
		}
	}
}

void Window::Draw(Player & player)
{
  ClearBuffer();
 
	std::sort(layers.begin(), layers.end(), [](Layer a, Layer b){
		return a.z_index > b.z_index;		
	});

	for(size_t i = 0; i < layers.size(); i++) {
		Layer layer = layers[i];
		
		for(size_t q = 0; q < 24; q++) {
			for(size_t p = 0; p < 80; p++) {
				if(layer.data[q][p] > 0) {
					window_buffer[q][p] = layer.data[q][p];
				}
			}
		}
	}   
}

void Window::Print()
{
  std::string window_string;
  for (size_t i = 0; i < window_height; i++) {
    for (size_t j = 0; j < window_width; j++ ) {
      window_string += std::format("\033[{};{}H{}", i+1, j+1, std::string(1, window_buffer[i][j])); 
    }
  }
  puts(window_string.c_str());
}

void Window::RegisterLayers()
{
  layers.push_back(Layers::DrawBorder(this));  
}

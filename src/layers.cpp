#include "window.hpp"
#include "layers.hpp"

Layer Layers::DrawBorder(Window* window)
{
  Layer layer(10);

  struct { 
    char corner = '+'; 
    char vertical = '|'; 
    char horizontal = '-'; 
    char blank = 0; 
  } DrawingCharacters;

  for (size_t i = 0; i < window->window_height; i++) {
    for (size_t j = 0; j < window->window_width; j++ ) {
      //checks if current position is a corner
      if (
        (i == 0 && j == 0) ||
        (i == window->window_height - 1 && j == window->window_width - 1) ||
        (i == 0 && j == window->window_width - 1) ||
        (i == window->window_height - 1 && j == 0)
      )
        layer.data[i][j] = DrawingCharacters.corner;
      else if (i == 0 || i == window->window_height - 1)
        layer.data[i][j] = DrawingCharacters.horizontal;
      else if (j == 0 || j == window->window_width - 1)
        layer.data[i][j] = DrawingCharacters.vertical;
      else
        layer.data[i][j] = DrawingCharacters.blank;
    }
  }

  return layer;
}



#include "Color.hpp"

namespace Tolik
{
Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
  e[0] = r;
  e[1] = g;
  e[2] = b;
  e[3] = a;
}
Color::Color(uint8_t r, uint8_t g, uint8_t b)
{
  e[0] = r;
  e[1] = g;
  e[2] = b;
  e[3] = 255;
}
Color::Color(uint32_t rgba)
{
  e[0] = rgba & 0x000000FF;
  e[1] = (rgba & 0x0000FF00) >> 8;
  e[2] = (rgba & 0x00FF0000) >> 16;
  e[3] = (rgba & 0xFF000000) >> 24;
}
Color::Color()
{
  e[0] = 255;
  e[1] = 255;
  e[2] = 255;
  e[3] = 255;
}
}
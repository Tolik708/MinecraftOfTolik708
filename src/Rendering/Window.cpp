#include "Window.hpp"

#include "Header.hpp"

#include "Debug.hpp"
#include "RenderAPI.hpp"
#include "DefinesAndConstants.hpp"

namespace Tolik
{
void Window::Init(bool *running, Debug *debug)
{
  m_debug = debug;
  m_running = running;
  SDL_CALL(m_debug, SDL_Init(SDL_INIT_EVERYTHING) == 0);
  SDL_CALL(m_debug, m_window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, renderAPI->GetSDLFlags()));
}
}
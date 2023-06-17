#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Window.hpp"
#include "Game.hpp"


namespace Tolik
{
class Application
{
public:
  Application();
  void Run();

private:
  bool m_running = false;
  Window m_window;
  Game m_game;
};
}

#endif
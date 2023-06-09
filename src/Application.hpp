#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Debug.hpp"
#include "Window.hpp"
#include "Database.hpp"
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
  Debug m_debug;
  Window m_window;
  Database m_database;
  Game m_game;
};
}

#endif
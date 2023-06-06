#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Debug.hpp"
#include "RenderAPI.hpp"
#include "RenderAPIOpenGL.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
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
  RenderAPI *m_api; // Window class owns it. Do not delete it here!!!
  Window m_window;
  Renderer m_renderer;
  Game m_game;
};
}

#endif
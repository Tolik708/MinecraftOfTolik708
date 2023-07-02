#include "Application.hpp"

#include "Header.hpp"

#include "State.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Game.hpp"

namespace Tolik
{
class RendererGL;

Application::Application()
  : m_window(&m_running),
  m_game(new StateDeps(&m_game, m_window.GetRenderer()))
{}

void Application::Run()
{
  m_running = true;
  while(m_running)
  {
    m_window.ListenToEvents();
    m_game.Update();
  }
}
}

#include "Application.hpp"

#include "Header.hpp"

#include "Utils.hpp"
#include "State.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Game.hpp"

namespace Tolik
{
class RendererGL;

Application::Application()
  : m_window(&m_running, &m_debug),
  m_database(&m_debug, Identity<RendererGL>()),
  m_game(new StateDeps(&m_debug, &m_game, m_window.GetRenderer()))
{

}

void Application::Run()
{
  m_running = true;
  while(m_running)
  {
    m_window.GetRenderer()->StartFrame();
    m_window.ListenToEvents();
    m_game.Update();
    m_window.GetRenderer()->EndFrame();
  }
}
}

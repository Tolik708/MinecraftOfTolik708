#include "Application.hpp"

#include "Header.hpp"

#include "State.hpp"
#include "RenderAPI.hpp"
#include "RenderAPIOpenGL.hpp"
#include "Window.hpp"
#include "Renderer.hpp"
#include "Game.hpp"

namespace Tolik
{
Application::Application()
{
  m_api = new RenderAPIOpenGL(); // Here we decide what RenderAPI we will use
  m_api->Init(&m_debug);
  m_window.Init(&m_running, &m_debug, m_api); //From now it will own RenderAPI
  m_renderer.Init(m_api, &m_debug, &m_window);
  m_game.Init(new StateDeps(&m_debug, &m_game, &m_renderer));
}

void Application::Run()
{
  m_running = true;
  while(m_running)
  {
    m_renderer.StartFrame();
    m_window.ListenToEvents();
    m_game.Update();
    m_renderer.EndFrame();
  }
}
}

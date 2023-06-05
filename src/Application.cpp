#include "Application.hpp"

#include "Header.hpp"

#include "State.hpp"

namespace Tolik
{
Application::Application()
{
  m_window.Init(&m_running);
  m_state = new GameState([this](State *newState) { ChangeState(newState); }, m_debug);
}

void Application::Run()
{
  m_running = true;
  while(m_running)
  {
    m_satate.Update();
  }
  Quit();
}

void Application::Quit()
{
  m_state.Quit();
  m_window.Quit();
}
}

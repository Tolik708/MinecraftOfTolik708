#include "Application.hpp"

#include "Header.hpp"

#include "RenderAPIOpenGL.hpp"

namespace Tolik
{
void Application::Init()
{
  SDL_CALL((&m_debug), SDL_Init(SDL_INIT_EVERYTHING) == 0);
}

void Application::Run()
{
  m_running = true;
  while(m_running)
  {
    
  }
  Quit();
}

void Application::Quit()
{
  
}
}

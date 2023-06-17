#include "Window.hpp"

#include "Header.hpp"

#include "Vec2.hpp"
#include "Debug.hpp"
#include "Renderer.hpp"
#include "RendererGL.hpp"

namespace Tolik
{
Window::~Window()
{
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

Window::Window(bool *running)
  : m_running(running),
  m_renderer(new RendererGL()) // Here we decide what render API we will use
{
  SDL_CALL(SDL_Init(SDL_INIT_EVERYTHING) == 0);
  SDL_CALL(m_window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, m_renderer->GetSDLWindowFlags()));
  SDL_GetWindowSize(m_window, &m_width, &m_height);

  m_renderer->SetWindow(this);
}

void Window::ListenToEvents()
{
  SDL_Event event;
  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
    case SDL_QUIT:
      *m_running = false;
      break;
    case SDL_WINDOWEVENT:
      switch(event.window.type)
      {
        case SDL_WINDOWEVENT_RESIZED:
          SDL_GetWindowSize(m_window, &m_width, &m_height);
          m_renderer->UpdateDrawbleSize();
          break;
      }
      break;
    default:
      Debug::GetLogger("main").Warning("Unhandlet SDL_Event: @0", event.type);
      break;
    }
  }
}
}
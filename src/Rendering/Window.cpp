#include "Window.hpp"

#include "Header.hpp"

#include "Debug.hpp"
#include "Renderer.hpp"
#include "RendererGL.hpp"

namespace Tolik
{
Window::~Window()
{
  delete m_renderer;
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

void Window::Init(bool *running, Debug *debug)
{
  m_debug = debug;
  m_running = running;

  m_renderer = new RendererGL(m_debug); // Here we decide what renderer will be used

  SDL_CALL(m_debug, SDL_Init(SDL_INIT_EVERYTHING) == 0);
  SDL_CALL(m_debug, m_window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, m_renderer->GetSDLWindowFlags()));
  
  m_renderer->Init(this);
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
    default:
      m_debug->Warning("Unhandlet SDL_Event: @0", event.type);
    }
  }
}
}
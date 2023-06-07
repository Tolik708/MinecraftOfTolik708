#include "RendererOpenGL.hpp"

#include "Header.hpp"

#include "Window.hpp"
#include "Debug.hpp"

namespace Tolik
{
RendererOpenGL::RendererOpenGL(Debug *debug)
{
  m_debug = debug;

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}

void RendererOpenGL::Init(Window *window)
{
  m_window = window;
  SDL_CALL(m_debug, (m_context = SDL_GL_CreateContext(m_window->GetWindow())) != NULL);
  GL_CALL(m_debug, gladLoadGLLoader(SDL_GL_GetProcAddress));

  GL_CALL(m_debug, glClearColor(0.2, 0.2, 0.2, 1));
}

void RendererOpenGL::StartFrame()
{
  GL_CALL(m_debug, glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT));
}

void RendererOpenGL::EndFrame()
{
  SDL_GL_SwapWindow(m_window->GetWindow());
}

uint32_t RendererOpenGL::GetSDLWindowFlags()
{
  return SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
}
}
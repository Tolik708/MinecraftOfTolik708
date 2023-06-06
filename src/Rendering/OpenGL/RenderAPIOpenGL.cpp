#include "RenderAPIOpenGL.hpp"

#include "Header.hpp"

#include "Debug.hpp"

namespace Tolik
{
void RenderAPIOpenGL::Init(Debug *debug)
{
  m_debug = debug;
  SetAttributes();
}
uint32_t RenderAPIOpenGL::GetSDLWindowFlags()
{
  return SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;
}

void RenderAPIOpenGL::Load()
{
  GL_CALL(m_debug, gladLoadGLLoader(SDL_GL_GetProcAddress));
}

void RenderAPIOpenGL::SetAttributes()
{
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}

void RenderAPIOpenGL::Clear()
{
  GL_CALL(m_debug, glClearColor(0.2, 0.2, 0.2, 1));
  GL_CALL(m_debug, glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}
void RenderAPIOpenGL::CreateContext(void *context, void *data)
{
  SDL_CALL(m_debug, (context = SDL_GL_CreateContext(reinterpret_cast<SDL_Window*>(data))) != nullptr);
}
void RenderAPIOpenGL::DestroyContext(void *context)
{
  SDL_GL_DeleteContext(reinterpret_cast<SDL_GLContext*>(context));
}
void RenderAPIOpenGL::SwapBuffers(void *data)
{
  SDL_GL_SwapWindow(reinterpret_cast<SDL_Window*>(data));
}
void RenderAPIOpenGL::Viewport(int x, int y, uint32_t width, uint32_t height)
{
  GL_CALL(m_debug, glViewport(x, y, width, height));
}
}
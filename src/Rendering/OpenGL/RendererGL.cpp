#include "RendererGL.hpp"

#include "Header.hpp"

#include "Database.hpp"
#include "Window.hpp"
#include "Debug.hpp"
#include "ShaderGL.hpp"
#include "MeshGL.hpp"

namespace Tolik
{
RendererGL::RendererGL(Debug *debug)
  : m_debug(debug)
{
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}

void RendererGL::SetWindow(Window *window)
{
  m_window = window;
  SDL_CALL(m_debug, (m_context = SDL_GL_CreateContext(m_window->GetWindow())) != NULL);
  GL_CALL(m_debug, gladLoadGLLoader(SDL_GL_GetProcAddress));

  GL_CALL(m_debug, glClearColor(0.2, 0.2, 0.2, 1));
  GL_CALL(m_debug, glViewport(0, 0, m_width, m_height));
}

void RendererGL::StartFrame()
{
  GL_CALL(m_debug, glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT));
}

void RendererGL::Render(void *mesh)
{
  MeshGL *convertedMesh = reinterpret_cast<MeshGL*>(mesh);
  m_database->GetMeshTypeData<ShaderGL>(convertedMesh->GetMeshType()).Use();
  convertedMesh->Draw();
}

void *RendererGL::CreateMesh(std::vector<Vertex> verts, std::vector<uint32_t> inds, MeshType meshType)
{
  return new MeshGL(verts, inds, m_database->GetMeshTypeData<BufferLayoutGL>(meshType), meshType);
}

void RendererGL::EndFrame()
{
  SDL_GL_SwapWindow(m_window->GetWindow());
}

uint32_t RendererGL::GetSDLWindowFlags()
{
  return SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
}

void RendererGL::UpdateDrawbleSize()
{
  SDL_GL_GetDrawableSize(m_window->GetWindow(), &m_width, &m_height);
}
}
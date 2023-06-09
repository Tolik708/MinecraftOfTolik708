#include "RendererGL.hpp"

#include "Header.hpp"

#include "DefinesAndConstants.hpp"
#include "Vec2.hpp"
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

void RendererGL::Init(Window *window)
{
  m_window = window;
  SDL_CALL(m_debug, (m_context = SDL_GL_CreateContext(m_window->GetWindow())) != NULL);
  GL_CALL(m_debug, gladLoadGLLoader(SDL_GL_GetProcAddress));

  m_meshTypeData = new MeshTypeDataGL(m_debug);

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
  (*m_meshTypeData)[convertedMesh->GetMeshType()].shader->Use();
  convertedMesh->Draw();
}

void *RendererGL::CreateMesh(std::vector<Vertex> verts, std::vector<uint32_t> inds, MeshType meshType)
{
  return new MeshGL(verts, inds, *(*m_meshTypeData)[static_cast<uint32_t>(meshType)].layout, static_cast<uint32_t>(meshType));
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

MeshTypeDataGL::MeshTypeDataGL(Debug *debug)
  : m_debug(debug), 
  data
  {
    MeshTypeDataElementGL(new ShaderGL("res\\Shaders\\ChunkShader.vert", "res\\Shaders\\ChunkShader.frag", m_debug), new BufferLayoutGL(GL_FLOAT, 3, GL_FALSE))
  }
{}
const MeshTypeDataElementGL &MeshTypeDataGL::operator[](uint32_t meshType) const
{
  int index = meshType - 1;
  if(index >= static_cast<int>(data.size()) || index < 0)
  {
    m_debug->Error("Invalid mesh type to acces MeshTypeDataGl: @0", meshType);
    return data[0];
  }
  return data[index];
}
}
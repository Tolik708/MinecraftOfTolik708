#include "RendererGL.hpp"

#include "Header.hpp"

#include "Window.hpp"
#include "Camera.hpp"
#include "Debug.hpp"
#include "ShaderGL.hpp"
#include "MeshGL.hpp"

namespace Tolik
{
RendererGL::RendererGL()
{
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}

RendererGL::~RendererGL()
{
  delete resources;
}

void RendererGL::SetWindow(Window *window)
{
  m_window = window;
  SDL_CALL((m_context = SDL_GL_CreateContext(m_window->GetWindow())) != NULL);
  GL_CALL(gladLoadGLLoader(SDL_GL_GetProcAddress));

  UpdateDrawbleSize();
  resources = new ResourceManagerGL();
  GL_CALL(glClearColor(0.2, 0.2, 0.2, 1));
  GL_CALL(glViewport(0, 0, m_width, m_height));
}

void RendererGL::StartFrame(const Camera &camera)
{
  GL_CALL(glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT));

  // I decided that fully hardcoded values will be fine
  // Meight be I'll add common uniform setter in the future
  resources->GetShader(MeshType::Chunk).SetUniform<4>("u_view", 1, GL_FALSE, &camera.GetViewMatrix()[0][0]);
}

void RendererGL::Render(void *mesh)
{
  MeshGL *convertedMesh = reinterpret_cast<MeshGL*>(mesh);
  resources->GetShader(convertedMesh->GetMeshType()).Use();
  convertedMesh->Draw();
}

void *RendererGL::CreateMesh(const std::vector<Vertex> &verts, const std::vector<uint32_t> &inds, MeshType meshType)
{
  return new MeshGL(verts, inds, resources->GetLayout(meshType), meshType);
}

void RendererGL::Debug(void *data)
{
  
}

void RendererGL::EndFrame()
{
  SDL_GL_SwapWindow(m_window->GetWindow());
}

uint32_t RendererGL::GetSDLWindowFlags() const
{
  return SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
}

void RendererGL::UpdateDrawbleSize()
{
  SDL_GL_GetDrawableSize(m_window->GetWindow(), &m_width, &m_height);
}
}
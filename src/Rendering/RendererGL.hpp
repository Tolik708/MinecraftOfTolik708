#ifndef RENDERER_GL_HPP
#define RENDERER_GL_HPP

#include "Header.hpp"
#include "Renderer.hpp"

namespace Tolik
{
class Debug;
class Window;

class RendererGL : public Renderer
{
public:
  RendererGL(Debug *debug);
  virtual void Init(Window *window) override;

  virtual void StartFrame() override;
  virtual void Render(void *mesh) override;
  virtual void *CreateMesh(std::vector<Vertex> verts, std::vector<uint32_t> inds) override;
  virtual void EndFrame() override;

  virtual uint32_t GetSDLWindowFlags() override;
private:
  Debug *m_debug;
  Window *m_window;
  SDL_GLContext m_context;
};
}

#endif
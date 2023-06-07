#ifndef RENDERER_OPENGL_HPP
#define RENDERER_OPENGL_HPP

#include "Header.hpp"
#include "Renderer.hpp"

namespace Tolik
{
class Debug;
class Window;

class RendererOpenGL : public Renderer
{
public:
  RendererOpenGL(Debug *debug);
  virtual void Init(Window *window) override;

  virtual void StartFrame() override;
  virtual void Render() override {}
  virtual void *CreateMesh() override { return nullptr; }
  virtual void EndFrame() override;

  virtual uint32_t GetSDLWindowFlags() override;
private:
  Debug *m_debug;
  Window *m_window;
  SDL_GLContext m_context;
};
}

#endif
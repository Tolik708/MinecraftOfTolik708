#ifndef RENDERER_GL_HPP
#define RENDERER_GL_HPP

#include "Header.hpp"

#include "Renderer.hpp"
#include "ResourceManagerGL.hpp"

namespace Tolik
{
class Camera;
class Window;

class RendererGL : public Renderer
{
public:
  RendererGL();
  ~RendererGL();
  virtual void SetWindow(Window *window) override;

  virtual void StartFrame(const Camera &camera) override;
  virtual void Render(void *mesh) override;
  virtual void *CreateMesh(const std::vector<Vertex> &verts, const std::vector<uint32_t> &inds, MeshType type) override;
  virtual void Debug(void *data) override;
  virtual void EndFrame() override;

  virtual uint32_t GetSDLWindowFlags() const override;
  virtual void UpdateDrawbleSize() override;
  
private:
  Window *m_window;
  SDL_GLContext m_context;
  ResourceManagerGL *resources;
};
}

#endif
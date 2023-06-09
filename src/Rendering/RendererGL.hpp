#ifndef RENDERER_GL_HPP
#define RENDERER_GL_HPP

#include "Header.hpp"

#include "Renderer.hpp"
#include "ShaderGL.hpp"
#include "MeshGL.hpp"

namespace Tolik
{
class Vec2;
class Debug;
class Window;

struct MeshTypeDataElementGL
{
  MeshTypeDataElementGL(ShaderGL *newShader, BufferLayoutGL *newLayout) : shader(newShader), layout(newLayout) {}
  ~MeshTypeDataElementGL() { delete shader; delete layout; }

  ShaderGL *shader;
  BufferLayoutGL *layout;
};

class MeshTypeDataGL
{
public:
  MeshTypeDataGL(Debug *debug);
  const MeshTypeDataElementGL &operator[](uint32_t index) const;
  
private:
  Debug *m_debug;
  const std::array<MeshTypeDataElementGL, 1> data;
};

class RendererGL : public Renderer
{
public:
  RendererGL(Debug *debug);
  virtual void Init(Window *window) override;

  virtual void StartFrame() override;
  virtual void Render(void *mesh) override;
  virtual void *CreateMesh(std::vector<Vertex> verts, std::vector<uint32_t> inds, MeshType type) override;
  virtual void EndFrame() override;

  virtual uint32_t GetSDLWindowFlags() override;
  virtual void UpdateDrawbleSize() override;
private:
  Debug *m_debug;
  Window *m_window;
  SDL_GLContext m_context;
  MeshTypeDataGL *m_meshTypeData;
};
}

#endif
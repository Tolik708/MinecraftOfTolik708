#ifndef RENDERER__HPP
#define RENDERER__HPP

#include "Header.hpp"
#include "Vec3.hpp"

namespace Tolik
{
class Window;

struct Vertex
{
  float x, y, z;
};

class Renderer
{
public:
  virtual ~Renderer() = default;

  virtual void StartFrame() = 0;
  virtual void Render(void *mesh) = 0;
  virtual void *CreateMesh(std::vector<Vertex> verts, std::vector<uint32_t> inds) = 0;
  virtual void EndFrame() = 0;

  virtual void Init(Window *window) = 0;
  virtual uint32_t GetSDLWindowFlags() = 0;
};
}

#endif
#ifndef RENDERER__HPP
#define RENDERER__HPP

#include "Header.hpp"

#include "Vec3.hpp"

namespace Tolik
{
class Window;
class Camera;

struct Vertex
{
  float x, y, z;
};

/*
 * MeshType is enum that determins what shader and other stuff we will use in creating and rendering mesh
*/
enum class MeshType : uint32_t
{
  Chunk = 0
};

enum class RenderAPIType : char
{
  OpenGL
};

class Renderer
{
public:
  virtual ~Renderer() = default;

  virtual void StartFrame(const Camera &camera) = 0;
  virtual void Render(void *mesh) = 0;
  virtual void *CreateMesh(const std::vector<Vertex> &verts, const std::vector<uint32_t> &inds, MeshType type) = 0;
  virtual void Debug(void *data) = 0;
  virtual void EndFrame() = 0;

  virtual void SetWindow(Window *window) = 0;
  virtual uint32_t GetSDLWindowFlags() const = 0;
  virtual void UpdateDrawbleSize() = 0;

  inline int GetWidth() const { return m_width; }
  inline int GetHeight() const { return m_height; }

protected:
  int m_width, m_height;
};
}

#endif
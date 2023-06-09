#ifndef RENDERER__HPP
#define RENDERER__HPP

#include "Header.hpp"

#include "Vec3.hpp"

namespace Tolik
{
class Window;
class Database;

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

class Renderer
{
public:
  virtual ~Renderer() = default;

  virtual void StartFrame() = 0;
  virtual void Render(void *mesh) = 0;
  virtual void *CreateMesh(std::vector<Vertex> verts, std::vector<uint32_t> inds, MeshType type) = 0;
  virtual void EndFrame() = 0;

  virtual void SetWindow(Window *window) = 0;
  virtual uint32_t GetSDLWindowFlags() = 0;
  virtual void UpdateDrawbleSize() = 0;

  inline int GetWidth() { return m_width; }
  inline int GetHeight() { return m_height; }
  void InjectDatabase(Database *database) { m_database = database; }

protected:
  int m_width, m_height;
  Database *m_database;
};
}

#endif
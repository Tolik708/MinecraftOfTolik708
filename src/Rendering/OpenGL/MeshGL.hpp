#ifndef MESH_GL_HPP
#define MESH_GL_HPP

#include "Header.hpp"

#include "Renderer.hpp"
#include "BuffersGL.hpp"
#include "VAOGL.hpp"

namespace Tolik
{
class Debug;

class MeshGL
{
public:
  MeshGL(const std::vector<Vertex> &verts, const std::vector<uint32_t> &inds, const BufferLayoutGL &layout, MeshType meshType, Debug *debug);
  
  void Draw();
  inline MeshType GetMeshType() const { return m_meshType; }

private:
  Debug *m_debug;
  MeshType m_meshType;
  VAOGL m_vao;
  VBOGL m_vbo;
  EBOGL m_ebo;
};
}


#endif
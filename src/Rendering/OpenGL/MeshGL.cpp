#include "MeshGL.hpp"

#include "Header.hpp"

#include "BuffersGL.hpp"
#include "VAOGL.hpp"

namespace Tolik
{
MeshGL::MeshGL(const std::vector<Vertex> &verts, const std::vector<uint32_t> &inds, const BufferLayoutGL &layout, MeshType meshType)
  : m_meshType(meshType)
{
  m_vbo.BufferData(verts);
  m_ebo.BufferData(inds);
  m_vao.AddVBO(m_vbo, layout);
  m_vao.AddEBO(m_ebo);
}

void MeshGL::Draw()
{
  m_vao.Bind();
  glDrawElements(GL_TRIANGLES, m_ebo.GetCount(), GL_UNSIGNED_INT, 0);
}
}
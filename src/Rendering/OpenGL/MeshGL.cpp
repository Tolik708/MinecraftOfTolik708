#include "MeshGL.hpp"

#include "Header.hpp"

#include "BuffersGL.hpp"
#include "VAOGL.hpp"
#include "Debug.hpp"

namespace Tolik
{
MeshGL::MeshGL(const std::vector<Vertex> &verts, const std::vector<uint32_t> &inds, const BufferLayoutGL &layout, MeshType meshType, Debug *debug)
  : m_debug(debug),
  m_meshType(meshType),
  m_vao(m_debug),
  m_vbo(m_debug),
  m_ebo(m_debug)
{
  m_vbo.BufferData(verts);
  m_ebo.BufferData(inds);
  m_vao.AddVBO(m_vbo, layout);
  m_vao.AddEBO(m_ebo);
}

MeshGL::~MeshGL()
{
  m_vao.Delete();
  m_vbo.Delete();
  m_ebo.Delete();
}

void MeshGL::Draw()
{
  m_vao.Bind();
  GL_CALL(m_debug, glDrawElements(GL_TRIANGLES, m_ebo.GetCount(), GL_UNSIGNED_INT, 0));
}
}
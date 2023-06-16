#include "BuffersGL.hpp"

#include "Header.hpp"

#include "Renderer.hpp"

namespace Tolik
{
void VBOGL::BufferData(const std::vector<Vertex> &verts) const
{
  Bind();
  GL_CALL(m_debug, glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(Vertex), &verts[0], GL_STATIC_DRAW));
}


void EBOGL::BufferData(const std::vector<uint32_t> &inds)
{
  Bind();
  GL_CALL(m_debug, glBufferData(GL_ELEMENT_ARRAY_BUFFER, inds.size() * sizeof(uint32_t), &inds[0], GL_STATIC_DRAW));
  m_count = inds.size();
}
}
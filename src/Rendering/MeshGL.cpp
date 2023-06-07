#include "MeshGL.hpp"

#include "Header.hpp"
#include "DefinesAndConstants.hpp"

namespace Tolik
{
uint32_t BufferLayoutElementGL::GetSizeOfTypeGL(uint32_t type)
{
  switch (type)
  {
  case GL_FLOAT:
    return sizeof(float);
  case GL_UNSIGNED_INT:
    return sizeof(uint32_t);
  case GL_BYTE:
    return sizeof(char);
  }

  std::cerr << "No such GL type" << std::endl;
  return 4; //hoping that we will hit
}

void BufferLayoutGL::AddBufferLayoutElement(uint32_t type, char size, char normalized)
{
  m_layoutElements.push_back(BufferLayoutElementGL(type, size, normalized, m_stride));
  m_stride += BufferLayoutElementGL::GetSizeOfTypeGL(type) * size;
}


void VBOGL::BufferData(const std::vector<Vertex> &verts) const
{
  Bind();
  glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(Vertex), &verts[0], GL_STATIC_DRAW);
}


void EBOGL::BufferData(const std::vector<uint32_t> &inds)
{
  Bind();
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, inds.size() * sizeof(uint32_t), &inds[0], GL_STATIC_DRAW);
  m_count = inds.size();
}


void VAOGL::AddVBO(const VBOGL &vbo, const BufferLayoutGL &layout)
{
  Bind();
  vbo.Bind();
  const std::vector<BufferLayoutElementGL> &elements = layout.GetLayoutElements();

  for(uint32_t i = 0; i < elements.size(); i++)
  {
    glVertexAttribPointer(i, elements[i].size, elements[i].type, elements[i].normalized, layout.GetStride(), reinterpret_cast<void*>(static_cast<intptr_t>(elements[i].offset)));
    glEnableVertexAttribArray(i);
  }
}

void VAOGL::AddEBO(const EBOGL &ebo)
{
  Bind();
  ebo.Bind();
}

MeshGL::MeshGL(const std::vector<Vertex> &verts, const std::vector<uint32_t> &inds)
{
  m_vbo.BufferData(verts);
  m_ebo.BufferData(inds);
  BufferLayoutGL layout;
  layout.AddBufferLayoutElement(GL_FLOAT, 3, GL_FALSE);
  m_vao.AddVBO(m_vbo, layout);
  m_vao.AddEBO(m_ebo);
}

void MeshGL::Draw()
{
  m_vao.Bind();
  glDrawElements(GL_TRIANGLES, m_ebo.GetCount(), GL_UNSIGNED_INT, 0);
}
}
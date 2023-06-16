#include "VAOGL.hpp"

#include "Header.hpp"

#include "BuffersGL.hpp"

namespace Tolik
{
std::size_t BufferLayoutElementGL::GetSizeOfTypeGL(uint32_t type)
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

void VAOGL::AddVBO(const VBOGL &vbo, const BufferLayoutGL &layout)
{
  Bind();
  vbo.Bind();
  const std::vector<BufferLayoutElementGL> &elements = layout.GetLayoutElements();

  for(std::size_t i = 0; i < elements.size(); i++)
  {
    GL_CALL(m_debug, glVertexAttribPointer(i, elements[i].size, elements[i].type, elements[i].normalized, layout.GetStride(), reinterpret_cast<void*>(static_cast<intptr_t>(elements[i].offset))));
    GL_CALL(m_debug, glEnableVertexAttribArray(i));
  }
}

void VAOGL::AddEBO(const EBOGL &ebo)
{
  Bind();
  ebo.Bind();
}
}
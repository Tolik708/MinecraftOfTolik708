#include "BuffersOpenGL.hpp"

#include "Header.hpp"

namespace Tolik
{
void VBOOpenGL::SetData(const void *data, uint32_t size)
{
  Bind();
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void IBOOpenGL::SetData(const uint32_t *data, uint32_t count)
{
  Bind();
  m_count = count;
  glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint32_t), data, GL_STATIC_DRAW);
}
}
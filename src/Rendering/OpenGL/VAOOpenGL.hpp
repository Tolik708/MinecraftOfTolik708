#ifndef VAO_OPENGL_HPP
#define VAO_OPENGL_HPP

#include "Header.hpp"

namespace Tolik
{
class VAOOpenGL
{
public:
  VAOOpenGL() { glGenVertexArrays(1, &ID); }
  
  void Bind() { glBindVertexAarray(ID); }
  void Unbind() { glBindVertexAarray(0); }
  void AddBuffer(const VBOOpenGL &vbo);
  void AddLayoutToLastBuffer(uint32_t count, uint32_t type, char normalized);

private:
  uint32_t m_lastBuffer;
};
}

#endif
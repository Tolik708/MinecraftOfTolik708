#ifndef BUFFERS_OPENGL_HPP
#define BUFFERS_OPENGL_HPP

#include "Header.hpp"

namespace Tolik
{
class VBOOpenGL
{
public:
  VBOOpenGL() { glGenBuffers(1, &ID); }
  ~VBOOpenGL() { glDeleteBuffers(1, &ID); }
  
  void Bind() { glBindBuffer(GL_ARRAY_BUFFER, ID); }
  void Unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
  
  virtual void SetData(const void *data, uint32_t size);

private:
  uint32_t ID;
};

class IBOOpenGL
{
public:
  IBOOpenGL() { glGenBuffers(1, &ID); }
  IBOOpenGL(const uint32_t *data, uint32_t count) { glGenBuffers(1, &ID); SetData(data, count); }
  ~IBOOpenGL() { glDeleteBuffers(1, &ID); }

  void Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID); }
  void Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
  uint32_t GetCount() const { return m_count; }
  
  virtual void SetData(const uint32_t *data, uint32_t count);

private:
  uint32_t ID;
  uint32_t m_count;
};
}

#endif
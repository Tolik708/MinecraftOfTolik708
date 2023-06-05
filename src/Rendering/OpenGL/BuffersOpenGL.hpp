#ifndef BUFFERS_OPENGL_HPP
#define BUFFERS_OPENGL_HPP

#include "Header.hpp"

namespace Tolik
{
class VBOOpenGL
{
public:
  VBOOpenGL() { glGenBuffers(1, &m_rendererID); }
  ~VBOOpenGL() { glDeleteBuffers(1, &m_rendererID); }
  
  void Bind() { glBindBuffer(GL_ARRAY_BUFFER, m_rendererID); }
  void Unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
  
  virtual void SetData(const void *data, uint32_t size);

private:
  uint32_t m_rendererID;
};

class IBOOpenGL
{
public:
  IBOOpenGL() { glGenBuffers(1, &m_rendererID); }
  IBOOpenGL(const uint32_t *data, uint32_t count) { glGenBuffers(1, &m_rendererID); SetData(data, count); }
  ~IBOOpenGL() { glDeleteBuffers(1, &m_rendererID); }

  void Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID); }
  void Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
  uint32_t GetCount() const { return m_count; }
  
  virtual void SetData(const uint32_t *data, uint32_t count);

private:
  uint32_t m_rendererID;
  uint32_t m_count;
};
}

#endif
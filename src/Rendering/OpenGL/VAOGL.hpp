#ifndef VAO_GL_HPP
#define VAO_GL_HPP

#include "Header.hpp"

#include "Debug.hpp"

namespace Tolik
{
class VBOGL;
class EBOGL;

struct BufferLayoutElementGL
{
  static std::size_t GetSizeOfTypeGL(uint32_t type);

  BufferLayoutElementGL(uint32_t newType, char newSize, char newNormalized, char newOffset) { type = newType; size = newSize; normalized = newNormalized; offset = newOffset; }

  uint32_t type = GL_FLOAT;
  char size = 3;
  char normalized = 0;
  char offset = 0; // hope that one vertex won't be larger then 255 bytes
};


class BufferLayoutGL
{
public:
  BufferLayoutGL() = default;
  template<typename... Args> BufferLayoutGL(uint32_t type, char size, char normalized, Args... args) { AddBufferLayoutElement(type, size, normalized); Iterate(args...); }

  template<typename... Args> void Iterate(uint32_t type, char size, char normalized, Args... args) { AddBufferLayoutElement(type, size, normalized); Iterate(args...); }
  inline void Iterate() {}
  void AddBufferLayoutElement(uint32_t type, char size, char normalized);
  inline std::size_t GetStride() const { return m_stride; }
  inline const std::vector<BufferLayoutElementGL> &GetLayoutElements() const { return m_layoutElements; }

private:
  std::vector<BufferLayoutElementGL> m_layoutElements;
  std::size_t m_stride = 0;
};


class VAOGL
{
public:
  VAOGL(Debug *debug) { GL_CALL(m_debug, glGenVertexArrays(1, &m_id)); }
  ~VAOGL() { GL_CALL(m_debug, glDeleteVertexArrays(1, &m_id)); }

  inline void Bind() { GL_CALL(m_debug, glBindVertexArray(m_id)); }
  inline void Unbind() { GL_CALL(m_debug, glBindVertexArray(0)); }

  void AddVBO(const VBOGL &vbo, const BufferLayoutGL &layout);
  void AddEBO(const EBOGL &ebo);

private:
  uint32_t m_id;
  Debug *m_debug;
};
}

#endif
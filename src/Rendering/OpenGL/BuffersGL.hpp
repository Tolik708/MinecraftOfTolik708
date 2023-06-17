#ifndef BUFFERS_GL_HPP
#define BUFFERS_GL_HPP

#include "Header.hpp"

#include "Debug.hpp"

namespace Tolik
{
struct Vertex;

class VBOGL
{
public:
  VBOGL() { GL_CALL(glGenBuffers(1, &m_id)); }
  inline void Delete() const { GL_CALL(glDeleteBuffers(1, &m_id)); }

  inline void Bind() const { GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_id)); }
  inline void Unbind() const { GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0)); }

  void BufferData(const std::vector<Vertex> &verts) const;

private:
  uint32_t m_id;
};


class EBOGL
{
public:
  EBOGL() { GL_CALL(glGenBuffers(1, &m_id)); }
  inline void Delete() const { GL_CALL(glDeleteBuffers(1, &m_id)); }

  inline void Bind() const { GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id)); }
  inline void Unbind() const { GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0)); }

  void BufferData(const std::vector<uint32_t> &inds);
  inline std::size_t GetCount() { return m_count; }

private:
  uint32_t m_id;
  std::size_t m_count;
};
}

#endif
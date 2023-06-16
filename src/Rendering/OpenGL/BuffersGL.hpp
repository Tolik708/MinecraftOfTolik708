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
  VBOGL(Debug *debug) : m_debug(debug) { GL_CALL(m_debug, glGenBuffers(1, &m_id)); }
  inline void Delete() const { glDeleteBuffers(1, &m_id); }

  inline void Bind() const { GL_CALL(m_debug, glBindBuffer(GL_ARRAY_BUFFER, m_id)); }
  inline void Unbind() const { GL_CALL(m_debug, glBindBuffer(GL_ARRAY_BUFFER, 0)); }

  void BufferData(const std::vector<Vertex> &verts) const;

private:
  uint32_t m_id;
  Debug *m_debug;
};


class EBOGL
{
public:
  EBOGL(Debug *debug) : m_debug(debug) { GL_CALL(m_debug, glGenBuffers(1, &m_id)); }
  inline void Delete() const { glDeleteBuffers(1, &m_id); }

  inline void Bind() const { GL_CALL(m_debug, glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id)); }
  inline void Unbind() const { GL_CALL(m_debug, glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0)); }

  void BufferData(const std::vector<uint32_t> &inds);
  inline std::size_t GetCount() { return m_count; }

private:
  uint32_t m_id;
  std::size_t m_count;
  Debug *m_debug;
};
}

#endif
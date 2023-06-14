#ifndef BUFFERS_GL_HPP
#define BUFFERS_GL_HPP

#include "Header.hpp"

namespace Tolik
{
struct Vertex;

class VBOGL
{
public:
  VBOGL() { glGenBuffers(1, &m_id); }
  VBOGL(VBOGL &&move) { m_id = std::move(move.m_id); move.m_id = 0; }
  ~VBOGL() { glDeleteBuffers(1, &m_id); }

  inline void Bind() const { glBindBuffer(GL_ARRAY_BUFFER, m_id); }
  inline void Unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

  void BufferData(const std::vector<Vertex> &verts) const;

private:
  uint32_t m_id;
};


class EBOGL
{
public:
  EBOGL() { glGenBuffers(1, &m_id); }
  EBOGL(EBOGL &&move) { m_id = std::move(move.m_id); m_count = std::move(move.m_count); move.m_id = 0; move.m_count = 0; }
  ~EBOGL() { glDeleteBuffers(1, &m_id); }

  inline void Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id); }
  inline void Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

  void BufferData(const std::vector<uint32_t> &inds);
  inline std::size_t GetCount() { return m_count; }

private:
  uint32_t m_id;
  std::size_t m_count;
};
}

#endif
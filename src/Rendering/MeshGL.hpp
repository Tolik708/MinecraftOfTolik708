#ifndef MESH_GL_HPP
#define MESH_GL_HPP

#include "Header.hpp"

#include "DefinesAndConstants.hpp"
#include "Renderer.hpp"

namespace Tolik
{
class ShaderGL;
  
class VBOGL
{
public:
  VBOGL() { glGenBuffers(1, &m_id); }
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
  ~EBOGL() { glDeleteBuffers(1, &m_id); }

  inline void Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id); }
  inline void Unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

  void BufferData(const std::vector<uint32_t> &inds);
  inline uint32_t GetCount() { return m_count; }

private:
  uint32_t m_id;
  uint32_t m_count;
};


struct BufferLayoutElementGL
{
  static uint32_t GetSizeOfTypeGL(uint32_t type);

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
  void Iterate() {}
  void AddBufferLayoutElement(uint32_t type, char size, char normalized);
  inline uint32_t GetStride() const { return m_stride; }
  inline const std::vector<BufferLayoutElementGL> &GetLayoutElements() const { return m_layoutElements; }

private:
  std::vector<BufferLayoutElementGL> m_layoutElements;
  uint32_t m_stride = 0;
};


class VAOGL
{
public:
  VAOGL() { glGenVertexArrays(1, &m_id); }
  ~VAOGL() { glDeleteVertexArrays(1, &m_id); }

  inline void Bind() { glBindVertexArray(m_id); }
  inline void Unbind() { glBindVertexArray(0); }

  void AddVBO(const VBOGL &vbo, const BufferLayoutGL &layout);
  void AddEBO(const EBOGL &ebo);

private:
  uint32_t m_id;
};


class MeshGL
{
public:
  MeshGL(const std::vector<Vertex> &verts, const std::vector<uint32_t> &inds, const BufferLayoutGL &layout, uint32_t meshType);
  void Draw();
  inline uint32_t GetMeshType() const { return m_meshType; }

private:
  uint32_t m_meshType;
  VAOGL m_vao;
  VBOGL m_vbo;
  EBOGL m_ebo;
};
}


#endif
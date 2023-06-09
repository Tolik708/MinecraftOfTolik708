#include "Database.hpp"

#include "VAOGL.hpp"
#include "ShaderGL.hpp"

namespace Tolik
{
Database::Database(Debug *debug, Identity<RendererGL> type)
  : m_debug(debug),
  m_meshTypeData
  {
    MeshTypeIndexes(int{1, 1})
  },
  m_shaders
  {
    ShaderGL("res\\Shaders\\ChunkShader.vert", "res\\Shaders\\ChunkShader.frag", m_debug)
  },
  m_layouts
  {
    BufferLayoutGL(GL_FLOAT, 3, GL_FALSE)
  }
{}
}

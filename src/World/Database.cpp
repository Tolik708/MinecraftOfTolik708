#include "Database.hpp"

#include "Header.hpp"

#include "VAOGL.hpp"
#include "ShaderGL.hpp"

namespace Tolik
{
Database::Database(Debug *debug, Identity<RendererGL> type)
  : m_debug(debug),
  m_meshTypeData
  {
    {1, 1}
  },
  m_data1
  {
    VariantDatabase<ShaderGL>(ShaderGL("res\\Shaders\\ChunkShader.vert", "res\\Shaders\\ChunkShader.frag", m_debug))
  },
  m_data2
  {
    VariantDatabase<BufferLayoutGL>(BufferLayoutGL(GL_FLOAT, 3, GL_FALSE))
  }
{}
}

#include "ResourceManagerGL.hpp"

#include "ShaderGL.hpp"
#include "Renderer.hpp"

namespace Tolik
{
ResourceManagerGL::ResourceManagerGL(Debug *debug)
  : m_indexes
  {
    { MeshType::Chunk, {0, 0} }
  },
  m_shaders
  {
    ShaderGL("res\\Shaders\\ChunkShader.vert", "res\\Shaders\\ChunkShader.frag", debug)
  },
  m_layouts
  {
    BufferLayoutGL(GL_FLOAT, 3, GL_FALSE)
  }
{}
}
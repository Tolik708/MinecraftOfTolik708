#include "ResourceManagerGL.hpp"

#include "ShaderGL.hpp"
#include "Renderer.hpp"

namespace Tolik
{
ResourceManagerGL::ResourceManagerGL()
  : m_indexes
  {
    { MeshType::Chunk, {0, 0} }
  },
  m_shaders
  {
    ShaderGL("res\\Shaders\\ChunkShader.vert", "res\\Shaders\\ChunkShader.frag")
  },
  m_layouts
  {
    BufferLayoutGL(GL_FLOAT, 3, GL_FALSE)
  }
{}

ResourceManagerGL::~ResourceManagerGL()
{
  for(uint32_t i = 0; i < m_shaders.size(); i++)
    m_shaders[i].Delete();
}
}
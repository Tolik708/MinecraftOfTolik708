#ifndef RESOURCE_MANAGER_GL_HPP
#define RESOURCE_MANAGER_GL_HPP

#include "Header.hpp"

#include "ShaderGL.hpp"
#include "VAOGL.hpp"
#include "Renderer.hpp"

namespace Tolik
{
class Debug;

class ResourceManagerGL
{
public:
  ResourceManagerGL(Debug *debug);
  ~ResourceManagerGL();
  const ShaderGL &GetShader(MeshType meshType) { return m_shaders[m_indexes[meshType][0]]; }
  const BufferLayoutGL &GetLayout(MeshType meshType) { return m_layouts[m_indexes[meshType][1]]; }

private:
  std::unordered_map<MeshType, std::array<uint32_t, 2>> m_indexes;
  std::vector<ShaderGL> m_shaders;
  std::vector<BufferLayoutGL> m_layouts;
};
}

#endif
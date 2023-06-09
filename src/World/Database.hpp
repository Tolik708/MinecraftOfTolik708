#ifndef DATABSE_HPP
#define DATABSE_HPP

#include "Header.hpp"

#include "Utils.hpp"
#include "Renderer.hpp"

namespace Tolik
{
class Debug;
class RendererGL;

union MeshTypeIndexes
{
  MeshTypeIndexes(int newPadding[2]) : padding(newPadding) {}
  struct
  {
    int shaderIndex;
    int layouIndex;
  };
  int padding[2];
};

class Database
{
public:
  Database(Debug *debug, Identity<RendererGL> type);
  template<typename T> inline const T &GetMeshTypeData(MeshType meshType);

private:
  Debug *m_debug;

  const std::array<MeshTypeIndexes, 1> m_meshTypeData;
  const std::array<void*, 1> m_shaders;
  const std::array<void*, 1> m_layouts;
};

template <typename T> inline const T &Database::GetMeshTypeData(MeshType meshType)
{
  switch(HeshType<T>())
  {
    case HeshType<ShaderGL>():
      return reinterpret_cast<T>(m_shaders[m_meshTypeData[static_cast<std::size_t>(meshType)].shaderIndex]);
    case HeshType<BufferLayoutGL>():
      return reinterpret_cast<T>(m_layouts[m_meshTypeData[static_cast<std::size_t>(meshType)].layoutIndex]);
  }
}
}

#endif
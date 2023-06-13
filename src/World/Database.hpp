#ifndef DATABSE_HPP
#define DATABSE_HPP

#include "Header.hpp"

#include "Utils.hpp"
#include "Renderer.hpp"

#include "ShaderGL.hpp"
#include "VAOGL.hpp"

namespace Tolik
{
class Debug;
class RendererGL;

// I can't use std::variant for 2 reasons. 1 - I am on c++11, 2 - it also saves current type, when this implementation doesn't
template<typename... Types> class VariantDatabase
{
public:
  template<typename T, std::enable_if_t<IsIn<T, Types...>::value, bool> = true>
  VariantDatabase(T &&t) { new(&buffer) T(std::move(t)); }

  ~VariantDatabase();

  template<typename T, std::enable_if_t<IsIn<T, Types...>::value, bool> = true>
  inline const T &Get() { return reinterpret_cast<const T*>(&buffer); }

private:
  typename std::aligned_union<0, Types...>::type buffer;
};

template<typename... Types> VariantDatabase<Types...>::~VariantDatabase()
{
  switch(Renderer::currenAPIType)
  {
    case RenderAPIType::OpenGL:
      DestroyAt(reinterpret_cast<const typename GetTypeInPlace<0, Types...>::type*>(&buffer));
  }
}

class Database
{
public:
  Database(Debug *debug, Identity<RendererGL> type);
  template<typename T> inline const T &GetMeshTypeData(MeshType meshType);

private:
  Debug *m_debug;

  // Very important to set API's one after another like GL then Vulkan in every container

  const std::array<int[2], 1> m_meshTypeData;
  const std::array<VariantDatabase<ShaderGL>, 1> m_data1;
  const std::array<VariantDatabase<BufferLayoutGL>, 1> m_data2;
};

template <typename T> inline const T &Database::GetMeshTypeData(MeshType meshType)
{
  switch(HeshType<T>())
  {
    case HeshType<ShaderGL>():
      return m_data1[m_meshTypeData[static_cast<std::size_t>(meshType)][0]].Get<T>();
    case HeshType<BufferLayoutGL>():
      return m_data2[m_meshTypeData[static_cast<std::size_t>(meshType)][1]].Get<T>();
  }
}
}

#endif
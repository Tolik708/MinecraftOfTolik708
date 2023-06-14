#ifndef SHADER_GL_HPP
#define SHADER_GL_HPP

#include "Header.hpp"

#include "FileReader.hpp"

namespace Tolik
{
class Debug;

class ShaderGL
{
public:
  ShaderGL(const std::string &vertexShaderPath, const std::string &fragmentShaderPath, Debug *debug);
  ShaderGL(ShaderGL &&move) { m_id = std::move(move.m_id); move.m_id = 0; }
  ~ShaderGL() { glDeleteProgram(m_id); }

  inline void Use() const { glUseProgram(m_id); }

private:
  void CheckForErrors(uint32_t shader, uint32_t error, Debug *debug) const;

  uint32_t m_id;
};
}

#endif
#ifndef SHADER_GL_HPP
#define SHADER_GL_HPP

#include "Header.hpp"

#include "FileReader.hpp"
#include "Debug.hpp"

namespace Tolik
{
class Debug;

class ShaderGL
{
public:
  ShaderGL(const std::string &vertexShaderPath, const std::string &fragmentShaderPath);
  inline void Delete() const { GL_CALL(glDeleteProgram(m_id)); }

  inline void Use() const { GL_CALL(glUseProgram(m_id)); }

private:
  uint32_t m_id;
};
}

#endif
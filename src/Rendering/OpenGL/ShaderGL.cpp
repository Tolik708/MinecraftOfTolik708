#include "ShaderGL.hpp"

#include "Header.hpp"

#include "FileReader.hpp"
#include "Debug.hpp"

namespace Tolik
{
ShaderGL::ShaderGL(const std::string &vertexShaderPath, const std::string &fragmentShaderPath, Debug *debug)
  : m_debug(debug)
{
  std::string vertexSource, fragmentSource;
  FileReader::ReadTxtFile(vertexShaderPath, vertexSource);
  FileReader::ReadTxtFile(fragmentShaderPath,fragmentSource);

  int succes = 0;
  uint32_t vertexShader, fragmentShader;
  const char *vertexChar = vertexSource.c_str();
  const char *fragmentChar = fragmentSource.c_str();

  GL_CALL(m_debug, vertexShader = glCreateShader(GL_VERTEX_SHADER));
  GL_CALL(m_debug, glShaderSource(vertexShader, 1, &vertexChar, NULL));
  GL_CALL(m_debug, glCompileShader(vertexShader));
  GL_CALL(m_debug, glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &succes));
  if(!succes)
  {
    char buffer[512];
    GL_CALL(m_debug, glGetShaderInfoLog(vertexShader, 512, NULL, buffer));
    m_debug->Error("Error in compiling/linking shader: @0", buffer);
  }

  GL_CALL(m_debug, fragmentShader = glCreateShader(GL_FRAGMENT_SHADER));
  GL_CALL(m_debug, glShaderSource(fragmentShader, 1, &fragmentChar, NULL));
  GL_CALL(m_debug, glCompileShader(fragmentShader));
  GL_CALL(m_debug, glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &succes));
  if(!succes)
  {
    char buffer[512];
    GL_CALL(m_debug, glGetShaderInfoLog(fragmentShader, 512, NULL, buffer));
    m_debug->Error("Error in compiling/linking shader: @0", buffer);
  }

  GL_CALL(m_debug, m_id = glCreateProgram());
  GL_CALL(m_debug, glAttachShader(m_id, vertexShader));
  GL_CALL(m_debug, glAttachShader(m_id, fragmentShader));
  GL_CALL(m_debug, glLinkProgram(m_id));
  GL_CALL(m_debug, glGetProgramiv(m_id, GL_LINK_STATUS, &succes));
  if(!succes)
  {
    char buffer[512];
    GL_CALL(m_debug, glGetProgramInfoLog(m_id, 512, NULL, buffer));
    m_debug->Error("Error in compiling/linking shader: @0", buffer);
  }

  GL_CALL(m_debug, glDeleteShader(vertexShader));
  GL_CALL(m_debug, glDeleteShader(fragmentShader));
}
}
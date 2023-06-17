#include "ShaderGL.hpp"

#include "Header.hpp"

#include "FileReader.hpp"
#include "Debug.hpp"

namespace Tolik
{
ShaderGL::ShaderGL(const std::string &vertexShaderPath, const std::string &fragmentShaderPath)
{
  std::string vertexSource, fragmentSource;
  FileReader::ReadTxtFile(vertexShaderPath, vertexSource);
  FileReader::ReadTxtFile(fragmentShaderPath,fragmentSource);

  int succes = 0;
  uint32_t vertexShader, fragmentShader;
  const char *vertexChar = vertexSource.c_str();
  const char *fragmentChar = fragmentSource.c_str();

  GL_CALL(vertexShader = glCreateShader(GL_VERTEX_SHADER));
  GL_CALL(glShaderSource(vertexShader, 1, &vertexChar, NULL));
  GL_CALL(glCompileShader(vertexShader));
  GL_CALL(glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &succes));
  if(!succes)
  {
    char buffer[512];
    GL_CALL(glGetShaderInfoLog(vertexShader, 512, NULL, buffer));
    Debug::GetLogger("main").Error("Error in compiling shader: @0", buffer);
  }

  GL_CALL( fragmentShader = glCreateShader(GL_FRAGMENT_SHADER));
  GL_CALL( glShaderSource(fragmentShader, 1, &fragmentChar, NULL));
  GL_CALL( glCompileShader(fragmentShader));
  GL_CALL( glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &succes));
  if(!succes)
  {
    char buffer[512];
    GL_CALL(glGetShaderInfoLog(fragmentShader, 512, NULL, buffer));
    Debug::GetLogger("main").Error("Error in compiling shader: @0", buffer);
  }

  GL_CALL(m_id = glCreateProgram());
  GL_CALL(glAttachShader(m_id, vertexShader));
  GL_CALL(glAttachShader(m_id, fragmentShader));
  GL_CALL(glLinkProgram(m_id));
  GL_CALL(glGetProgramiv(m_id, GL_LINK_STATUS, &succes));
  if(!succes)
  {
    char buffer[512];
    GL_CALL(glGetProgramInfoLog(m_id, 512, NULL, buffer));
    Debug::GetLogger("main").Error("Error in linking shader: @0", buffer);
  }

  GL_CALL(glDeleteShader(vertexShader));
  GL_CALL(glDeleteShader(fragmentShader));
}
}
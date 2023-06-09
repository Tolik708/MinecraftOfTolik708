#include "ShaderGL.hpp"

#include "Header.hpp"

#include "FileReader.hpp"
#include "Debug.hpp"

namespace Tolik
{
ShaderGL::ShaderGL(const std::string &vertexShaderPath, const std::string &fragmentShaderPath, Debug *debug)
{
  std::string vertexSource, fragmentSource;
  FileReader::ReadTxtFile(vertexShaderPath, vertexSource);
  FileReader::ReadTxtFile(fragmentShaderPath,fragmentSource);

  uint32_t vertexShader, fragmentShader;
  const char *vertexChar = vertexSource.c_str(), *fragmentChar = fragmentSource.c_str();

  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexChar, NULL);
  glCompileShader(vertexShader);
  CheckForErrors(vertexShader, GL_COMPILE_STATUS, debug);
  
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentChar, NULL);
  glCompileShader(fragmentShader);
  CheckForErrors(fragmentShader, GL_COMPILE_STATUS, debug);
  m_id = glCreateProgram();
  glAttachShader(m_id, vertexShader);
  glAttachShader(m_id, fragmentShader);
  glLinkProgram(m_id);
  CheckForErrors(m_id, GL_LINK_STATUS, debug);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void ShaderGL::CheckForErrors(uint32_t shader, uint32_t status, Debug *debug) const
{
  int succes;
  glGetShaderiv(shader, status, &succes);
  if(!succes)
  {
    char buffer[512];
    glGetShaderInfoLog(shader, 512, NULL, buffer);
    debug->Error("Error in compilinh/linking shader: @0", buffer);
  }
}
}
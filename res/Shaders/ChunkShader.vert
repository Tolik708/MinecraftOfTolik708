#version 410 core

layout (location = 0) in vec3 inPosition;

void main()
{
  gl_Position = vec4(inPosition.x, inPosition.y, inPosition.z, 1);
}
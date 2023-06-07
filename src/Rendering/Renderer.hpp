#ifndef RENDERER__HPP
#define RENDERER__HPP

#include "Header.hpp"

namespace Tolik
{
class Window;

class Renderer
{
public:
  virtual ~Renderer() = default;

  virtual void StartFrame() = 0;
  virtual void Render() = 0;
  virtual void *CreateMesh() = 0;
  virtual void EndFrame() = 0;

  virtual void Init(Window *window) = 0;
  virtual uint32_t GetSDLWindowFlags() = 0;
};
}

#endif
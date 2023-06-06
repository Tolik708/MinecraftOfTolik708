#ifndef RENDER_API_HPP
#define RENDER_API_HPP

#include "Header.hpp"

namespace Tolik
{
class Debug;

class RenderAPI
{
public:
  virtual ~RenderAPI() = default;

  virtual void Init(Debug *debug) = 0;
  virtual uint32_t GetSDLWindowFlags() = 0;
  virtual void Load() = 0;
  virtual void Clear() = 0;
  virtual void DestroyContext(void *context) = 0;
  virtual void CreateContext(void *context, void *data) = 0;
  virtual void SwapBuffers(void *data) = 0;
  virtual void Viewport(int x, int y, uint32_t width, uint32_t height) = 0;

protected:
  Debug *m_debug;
};
}

#endif
#ifndef RENDER_API_OPENGL_HPP
#define RENDER_API_OPENGL_HPP

#include "Header.hpp"

#include "RenderAPI.hpp"

namespace Tolik
{
class RenderAPIOpenGL : public RenderAPI
{
public:
  virtual void Init(Debug *debug) override;
  virtual uint32_t GetSDLWindowFlags() override;
  virtual void Load() override;
  virtual void Clear() override;
  virtual void CreateContext(void *context, void *data) override;
  virtual void DestroyContext(void *context) override;
  virtual void SwapBuffers(void *data) override;
  virtual void Viewport(int x, int y, uint32_t width, uint32_t height) override;

private:
  void SetAttributes();
};
}

#endif
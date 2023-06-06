#ifndef RENDERER_HPP
#define RENDERER_HPP

namespace Tolik
{
class Debug;
class RenderAPI;
class Window;

class Renderer
{
public:
  ~Renderer();
  void Init(RenderAPI *renderAPI, Debug *debug, Window *window);
  const RenderAPI &GetAPI() { return  *m_api; } 

  void StartFrame();
  void EndFrame();
private:
  RenderAPI *m_api;
  Debug *m_debug;
  Window *m_window;
  void *context;
};
}

#endif
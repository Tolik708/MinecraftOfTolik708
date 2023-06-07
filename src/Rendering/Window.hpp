#ifndef WINDOW_HPP
#define WINDOW_HPP

class SDL_Window;

namespace Tolik
{
class Debug;
class Renderer;

class Window
{
public:
  ~Window();
  void Init(bool *running, Debug *debug);
  void ListenToEvents();
  inline SDL_Window *GetWindow() { return m_window; }
  inline Renderer *GetRenderer() { return m_renderer; }

private:
  bool *m_running;
  Debug *m_debug;
  SDL_Window *m_window;
  Renderer *m_renderer;
};
}

#endif
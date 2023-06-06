#ifndef WINDOW_HPP
#define WINDOW_HPP

class SDL_Window;

namespace Tolik
{
class Debug;
class RenderAPI;

class Window
{
public:
  ~Window();
  void Init(bool *running, Debug *debug, RenderAPI *renderAPI);
  void ListenToEvents();
  inline SDL_Window *GetWindow() { return m_window; }

private:
  bool *m_running;
  SDL_Window *m_window;
  Debug *m_debug;
  RenderAPI *m_api;
};
}

#endif
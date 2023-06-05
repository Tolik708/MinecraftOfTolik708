#ifndef WINDOW_HPP
#define WINDOW_HPP

namespace Tolik
{
class SDL_Window;
class Debug;

class Window
{
public:
  void Init(bool *running, Debug *debug);

private:
  bool *m_running;
  SDL_Window *m_window;
  Debug *m_debug;
}
}

#endif
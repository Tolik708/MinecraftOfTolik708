#ifndef WINDOW_HPP
#define WINDOW_HPP

namespace Tolik
{
class SDL_Window;

class Window
{
public:
  Window(bool *running);

private:
  bool *m_running;
  SDL_Window *m_window;
}
}

#endif
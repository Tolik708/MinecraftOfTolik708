#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Debug.hpp"
#include "Window.hpp"

namespace Tolik
{
class State;

class Application
{
public:
  Application();
  void Run();

private:
  void Quit();
  inline void ChangeState(State *newState) { delete m_state; m_state = newState; }

  bool m_running = false;
  State *m_state;
  Debug m_debug;
  Window m_window;
};
}

#endif
#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Debug.hpp"

namespace Tolik
{
class Event;

class Application
{
  friend class EventHandler;
public:
  Application() { Init(); }
  void Init();
  void Run();
  void Quit();

private:
  bool m_running = false;
  Debug m_debug;
  
};
}

#endif
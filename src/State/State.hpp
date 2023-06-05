#ifndef STATE_HPP
#define STATE_HPP

namespace Tolik
{
class Debug;
class Renderer;

struct StateDeps
{
  Debug *debug;
  std::function<void(State*)> ChangeState;
  Renderer *renderer;
};

class State
{
public:
  virtual void Update() = 0;
};
}

#endif
#ifndef STATE_HPP
#define STATE_HPP

namespace Tolik
{
class Debug;
class Renderer;
class Context;

struct StateDeps
{
  Debug *debug;
  Context *context;
  Renderer *renderer;
};

class State
{
public:
  virtual void Update() = 0;
};
}

#endif
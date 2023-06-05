#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "Application.hpp"
#include "State.hpp"

namespace Tolik
{
class Debug;

class GameState : public State
{
public:
  GameState(StateDeps newDeps) { deps = newDeps; }

  virtual void Update() override;

private:
  void Render();

  StateDeps *deps;
}
}

#endif
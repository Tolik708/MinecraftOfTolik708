#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "State.hpp"

union SDL_Event;

namespace Tolik
{
class Debug;

class GameState : public State
{
public:
  GameState(StateDeps *newDeps);

  virtual void Update() override;

private:
  void Render();

  StateDeps *deps;

  static int EventFilter(void *userdata, SDL_Event *event);
};
}

#endif
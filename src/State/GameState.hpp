#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "State.hpp"

union SDL_Event;

namespace Tolik
{
class Debug;
class Player;

class GameState : public State
{
public:
  GameState(StateDeps *newDeps);

  virtual void Init() override;
  virtual void Update() override;

private:
  StateDeps *deps;
  void *m_mesh;
  Player *player;

  static int EventFilter(void *userdata, SDL_Event *event);
};
}

#endif
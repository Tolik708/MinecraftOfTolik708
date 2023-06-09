#ifndef STATE_HPP
#define STATE_HPP

namespace Tolik
{
class Debug;
class Renderer;
class Game;

struct StateDeps
{
  StateDeps(Game *newGame, Renderer *newRenderer) : game(newGame), renderer(newRenderer) {}
  Game *game;
  Renderer *renderer;
};

class State
{
public:
  virtual ~State() = default;

  virtual void Init() = 0;
  virtual void Update() = 0;
};
}

#endif
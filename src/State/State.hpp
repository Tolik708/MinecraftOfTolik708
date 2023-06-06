#ifndef STATE_HPP
#define STATE_HPP

namespace Tolik
{
class Debug;
class Renderer;
class Game;

struct StateDeps
{
  StateDeps(Debug *newDebug, Game *newGame, Renderer *newRenderer) : debug(newDebug), game(newGame), renderer(newRenderer) {}
  Debug *debug;
  Game *game;
  Renderer *renderer;
};

class State
{
public:
  virtual ~State() = default;
  virtual void Update() = 0;
};
}

#endif
#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "Header.hpp"

#include "State.hpp"
#include "GameState.hpp"

namespace Tolik
{
class Game
{
  friend class Application;
public:
  ~Game() { delete m_state; delete latestState; }

  template<typename T, std::enable_if_t<std::is_base_of<State, T>::value, bool> = true>
  inline void ChangeState(T *newState) { delete latestState; latestState = newState; }

private:
  void Init(StateDeps *deps);
  void Update();

  State *m_state = nullptr;
  State *latestState = nullptr;
};
}

#endif
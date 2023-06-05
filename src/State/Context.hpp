#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "Header.hpp"

#include "State.hpp"
#include "GameState.hpp"

namespace Tolik
{
class Context
{
public:
  template<typename T, std::enable_if<std::is_base_of<State, T>::value>> inline void ChangeState(StateDeps *deps) { delete m_state; newState = new T(deps); }
  void EndOfStateUpdate();

private:
  inline void Update() { m_state->Update(); }

  State *m_state = nullptr;
  State *newState = nullptr;
};
}

#endif
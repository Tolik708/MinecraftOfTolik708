#include "Game.hpp"

#include "State.hpp"

namespace Tolik
{
Game::Game(StateDeps *deps)
  : m_state(new GameState(deps)) // Here we dicide entry state of a game
{
  m_state->Init();
}

void Game::Update()
{
  m_state->Update();

  if(pendingState == nullptr)
    return;
  
  delete m_state; 
  m_state = pendingState;
  pendingState = nullptr;
  m_state->Init();
}
}
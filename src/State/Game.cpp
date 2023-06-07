#include "Game.hpp"

#include "State.hpp"

namespace Tolik
{
void Game::Init(StateDeps *deps)
{
  m_state = new GameState(deps); // Here we dicide entry state of a game
  m_state->Init();
}

void Game::Update()
{
  m_state->Update();
  if(latestState == nullptr)
    return;
  delete m_state; 
  m_state = latestState;
  latestState = nullptr;
  m_state->Init();
}
}
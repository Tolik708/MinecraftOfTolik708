#include "GameState.hpp"

namespace Tolik
{
void GameState::Update()
{
  Render();
  deps->context->EndOfStateUpdate();
}
void GameState::Render()
{
  
}
}
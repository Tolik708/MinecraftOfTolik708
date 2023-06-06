#include "GameState.hpp"

#include "Header.hpp"

namespace Tolik
{
GameState::GameState(StateDeps *newDeps)
{
  deps = newDeps;
  SDL_SetEventFilter(&EventFilter, nullptr);
}

void GameState::Update()
{

  
  Render();
}
void GameState::Render()
{
  
}
int GameState::EventFilter(void *userdata, SDL_Event *event)
{
  switch(event->type)
  {
  case SDL_KEYDOWN:
  case SDL_KEYUP:
  case SDL_MOUSEBUTTONDOWN:
  case SDL_MOUSEBUTTONUP:
  case SDL_MOUSEMOTION:
  case SDL_MOUSEWHEEL:
    return 0;
  default:
    return 1;
  }
}
}
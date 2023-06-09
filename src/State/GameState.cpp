#include "GameState.hpp"

#include "Header.hpp"

#include "Renderer.hpp"

namespace Tolik
{
GameState::GameState(StateDeps *newDeps)
{
  deps = newDeps;
}

void GameState::Init()
{
  SDL_SetEventFilter(&EventFilter, nullptr);

  std::vector<Vertex> verts = { { 0, 0, 0 },   { 0, 0.5, 0 },   { 0.5, 0.5, 0 },   { 0.5, 0, 0 } };
  std::vector<uint32_t> inds = { 0, 1, 2, 0, 2, 3 };
  m_mesh = deps->renderer->CreateMesh(verts, inds, MeshType::Chunk);
}

void GameState::Update()
{
  deps->renderer->Render(m_mesh);
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
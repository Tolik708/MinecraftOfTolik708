#include "GameState.hpp"

#include "Header.hpp"

#include "Debug.hpp"
#include "Renderer.hpp"
#include "Player.hpp"

namespace Tolik
{
GameState::GameState(StateDeps *newDeps)
{
  deps = newDeps;
}

void GameState::Init()
{
  SDL_SetEventFilter(&EventFilter, nullptr);

  std::vector<Vertex> verts = { { 0, 0, -1 },   { 0, 0.5, -1 },   { 0.5, 0.5, -1 },   { 0.5, 0, -1 } };
  std::vector<uint32_t> inds = { 0, 1, 2, 0, 2, 3 };
  m_mesh = deps->renderer->CreateMesh(verts, inds, MeshType::Chunk);

  player = new Player();
}

void GameState::Update()
{
  deps->renderer->StartFrame(player->GetCamera());
  deps->renderer->Render(m_mesh);

  deps->renderer->EndFrame();
}
int GameState::EventFilter(void *userdata, SDL_Event *event)
{
  Player *player = reinterpret_cast<Player*>(userdata);
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
#include "Renderer.hpp"

#include "RenderAPI.hpp"
#include "Window.hpp"

namespace Tolik
{
Renderer::~Renderer()
{
  m_api->DestroyContext(context);
}

void Renderer::Init(RenderAPI *renderAPI, Debug *debug, Window *window)
{
  m_debug = debug;
  m_api = renderAPI;
  m_window = window;

  m_api->CreateContext(context, m_window->GetWindow());
  m_api->Load();
}

void Renderer::StartFrame()
{
  m_api->Clear();
}

void Renderer::Render()
{
  
}

void Renderer::EndFrame()
{
  m_api->SwapBuffers(m_window->GetWindow());
}
}
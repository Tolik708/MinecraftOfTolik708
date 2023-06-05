#include "Context.hpp"

void Tolik::Context::EndOfStateUpdate()
{
  if(newState != nullptr) 
  {
    delete m_state; 
    m_state = newState; 
    newState = nullptr;
  }
}
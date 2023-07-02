#include "UserInput.hpp"

#include "Debug.hpp"

namespace Tolik
{
void UserInput::Update()
{
  
}

void UserInput::SetKeyDown(uint16_t keyCode)
{
  #ifndef BUILD
  if(keyCode > 321)
  {
    Debug::GetLogger("Invalid keyCode with number @0", keyCode);
    return;
  }
  #endif
  m_keys[keyCode] = 2;
}

void UserInput::SetKeyUp(uint16_t keyCode)
{
  #ifndef BUILD
  if(keyCode > 321)
  {
    Debug::GetLogger("Invalid keyCode with number @0", keyCode);
    return;
  }
  #endif
  m_keys[keyCode] = 3;
}
}
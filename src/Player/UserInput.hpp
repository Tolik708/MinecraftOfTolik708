#ifndef USER_INPUT_HPP
#define USER_INPUT_HPP

#include "Header.hpp"

#include "Vec2.hpp"

namespace Tolik
{
enum class InputAxisType : uint8_t
{
  MouseWheel, MouseDelta, MousePosition, InputAxis
};

class UserInput
{
public:
  void Update();

  void SetKeyDown(uint16_t keyCode);
  void SetKeyUp(uint16_t keyCode);

  bool GetKey(uint16_t keyCode);
  bool GetKeyDown(uint16_t keyCode);
  bool GetKeyUp(uint16_t keyCode);
  const Vec2 &GetAxis(InputAxisType type);

private:
  char m_keys[512]; // used 512. 0 - not pressed, 1 - pressed, 2 - pressed and down, 3 - pressed and up
  Vec2 m_axses[4]; //0 - mouse wheel, 1 - mouse delta, 2 - mouse position, 3 - input axeses
};
}

#endif
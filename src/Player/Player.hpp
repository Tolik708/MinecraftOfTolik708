#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Camera.hpp"

namespace Tolik
{
class UserInput;

class Player
{
public:
  Player(UserInput *input) : m_input(input) {}

  inline const Camera &GetCamera() const { return camera; }
  inline Camera &GetCamera() { return camera; }

private:
  Camera camera;
  UserInput *m_input;
};
}


#endif
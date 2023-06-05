#include "Ray.hpp"

namespace Tolik
{
Ray::Ray(const vec3 &origin, const vec3 &direction)
{
  this->origin = origin;
  this->direction = direction;
}

void Ray::SetDirection(const vec3 &direction)
{
  if (direction.SqrMagnitude() != 1)
    this->direction = direction.Normalized();
  else
    this->direction = direction;
}
void Ray::SetOrigin(const vec3 &origin)
{
  this->origin = origin;
}
}
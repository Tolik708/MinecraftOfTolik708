#include "Ray.hpp"

namespace Tolik
{
Ray::Ray(const Vec3 &origin, const Vec3 &direction)
{
  this->origin = origin;
  this->direction = direction;
}

void Ray::SetDirection(const Vec3 &direction)
{
  if (direction.SqrMagnitude() != 1)
    this->direction = direction.Normalized();
  else
    this->direction = direction;
}
void Ray::SetOrigin(const Vec3 &origin)
{
  this->origin = origin;
}
}
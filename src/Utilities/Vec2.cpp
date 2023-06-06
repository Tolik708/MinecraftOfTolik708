#include "Vec2.hpp"

namespace Tolik
{
void Vec2::ClampMagnitude(float maxMagnitude, float minMagnitude)
{
  float sqrMagnitude = SqrMagnitude();
  if (sqrMagnitude > maxMagnitude * maxMagnitude)
  {
    Normalize();
    x *= maxMagnitude;
    y *= maxMagnitude;
  }
  else if (sqrMagnitude < minMagnitude * minMagnitude)
  {
    Normalize();
    x *= minMagnitude;
    y *= minMagnitude;
  }
}
Vec2 Vec2::Normalized() const
{
  float inverseMagnitude = 1 / Magnitude();
  return Vec2(x * inverseMagnitude, y * inverseMagnitude);
}
void Vec2::Normalize()
{
  float inverseMagnitude = 1 / Magnitude();
  x *= inverseMagnitude;
  y *= inverseMagnitude;
}

Vec2 Vec2::ClampMagnitude(const Vec2 &vector, float maxMagnitude, float minMagnitude)
{
  float sqrMagnitude = vector.SqrMagnitude();
  if (sqrMagnitude > maxMagnitude * maxMagnitude)
    return vector.Normalized() * maxMagnitude;
  else if (sqrMagnitude < minMagnitude * minMagnitude)
    return vector.Normalized() * minMagnitude;
  return vector;
}

const Vec2 Vec2::right = Vec2(1, 0);
const Vec2 Vec2::left =  Vec2(-1, 0);
const Vec2 Vec2::up =    Vec2(0, 1);
const Vec2 Vec2::down =  Vec2(0, -1);
const Vec2 Vec2::one =   Vec2(1, 1);
const Vec2 Vec2::zero =  Vec2(0, 0);
const Vec2 Vec2::min =   Vec2(std::numeric_limits<float>::min(), std::numeric_limits<float>::min());
const Vec2 Vec2::max =   Vec2(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
}
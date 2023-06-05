#include "Vec2.hpp"

namespace Tolik
{
void vec2::ClampMagnitude(float maxMagnitude, float minMagnitude)
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
vec2 vec2::Normalized() const
{
  float inverseMagnitude = 1 / Magnitude();
  return vec2(x * inverseMagnitude, y * inverseMagnitude);
}
void vec2::Normalize()
{
  float inverseMagnitude = 1 / Magnitude();
  x *= inverseMagnitude;
  y *= inverseMagnitude;
}

vec2 vec2::ClampMagnitude(const vec2 &vector, float maxMagnitude, float minMagnitude)
{
  float sqrMagnitude = vector.SqrMagnitude();
  if (sqrMagnitude > maxMagnitude * maxMagnitude)
    return vector.Normalized() * maxMagnitude;
  else if (sqrMagnitude < minMagnitude * minMagnitude)
    return vector.Normalized() * minMagnitude;
  return vector;
}

const vec2 vec2::right = vec2(1, 0);
const vec2 vec2::left =  vec2(-1, 0);
const vec2 vec2::up =    vec2(0, 1);
const vec2 vec2::down =  vec2(0, -1);
const vec2 vec2::one =   vec2(1, 1);
const vec2 vec2::zero =  vec2(0, 0);
const vec2 vec2::min =   vec2(std::numeric_limits<float>::min(), std::numeric_limits<float>::min());
const vec2 vec2::max =   vec2(std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
}
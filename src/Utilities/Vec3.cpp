#include "Vec3.hpp"

namespace Tolik
{
vec3 vec3::Normalized() const 
{
  float inverseMagnitude = 1 / Magnitude();
  return vec3(x * inverseMagnitude, y * inverseMagnitude, z * inverseMagnitude);
}
void vec3::Normalize()
{
  float inverseMagnitude = 1 / Magnitude();
  x *= inverseMagnitude;
  y *= inverseMagnitude;
  z *= inverseMagnitude;
}
void vec3::ClampMagnitude(float maxMagnitude, float minMagnitude)
{
  float sqrMagnitude = SqrMagnitude();
  if (sqrMagnitude > maxMagnitude * maxMagnitude)
  {
    Normalize();
    x *= maxMagnitude;
    y *= maxMagnitude;
    z *= maxMagnitude;
  }
  else if (sqrMagnitude < minMagnitude * minMagnitude)
  {
    Normalize();
    x *= minMagnitude;
    y *= minMagnitude;
    z *= minMagnitude;
  }
}

vec3 vec3::ClampMagnitude(const vec3 &vector, float maxMagnitude, float minMagnitude)
{
  float sqrMagnitude = vector.SqrMagnitude();
  if (sqrMagnitude > maxMagnitude * maxMagnitude)
    return vector.Normalized() * maxMagnitude;
  else if (sqrMagnitude < minMagnitude * minMagnitude)
    return vector.Normalized() * minMagnitude;
  return vector;
}

const vec3 vec3::right = vec3(1, 0, 0);
const vec3 vec3::left = vec3(-1, 0, 0);
const vec3 vec3::up = vec3(0, 1, 0);
const vec3 vec3::down = vec3(0, -1, 0);
const vec3 vec3::forward = vec3(0, 0, 1);
const vec3 vec3::backward = vec3(0, 0, -1);
const vec3 vec3::one = vec3(1, 1, 1);
const vec3 vec3::zero = vec3();
}
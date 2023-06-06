#include "Vec3.hpp"

namespace Tolik
{
Vec3 Vec3::Normalized() const 
{
  float inverseMagnitude = 1 / Magnitude();
  return Vec3(x * inverseMagnitude, y * inverseMagnitude, z * inverseMagnitude);
}
void Vec3::Normalize()
{
  float inverseMagnitude = 1 / Magnitude();
  x *= inverseMagnitude;
  y *= inverseMagnitude;
  z *= inverseMagnitude;
}
void Vec3::ClampMagnitude(float maxMagnitude, float minMagnitude)
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

Vec3 Vec3::ClampMagnitude(const Vec3 &vector, float maxMagnitude, float minMagnitude)
{
  float sqrMagnitude = vector.SqrMagnitude();
  if (sqrMagnitude > maxMagnitude * maxMagnitude)
    return vector.Normalized() * maxMagnitude;
  else if (sqrMagnitude < minMagnitude * minMagnitude)
    return vector.Normalized() * minMagnitude;
  return vector;
}

const Vec3 Vec3::right = Vec3(1, 0, 0);
const Vec3 Vec3::left = Vec3(-1, 0, 0);
const Vec3 Vec3::up = Vec3(0, 1, 0);
const Vec3 Vec3::down = Vec3(0, -1, 0);
const Vec3 Vec3::forward = Vec3(0, 0, 1);
const Vec3 Vec3::backward = Vec3(0, 0, -1);
const Vec3 Vec3::one = Vec3(1, 1, 1);
const Vec3 Vec3::zero = Vec3();
}
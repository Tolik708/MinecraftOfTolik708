#ifndef RAY
#define RAY

#include "Vec3.hpp"

namespace Tolik
{
class Ray
{
private:
  Vec3 origin;
  Vec3 direction;
public:
  Ray(const Vec3 &origin, const Vec3 &direction);

  inline void SetOrigin(const Vec3 &origin);
  inline void SetDirection(const Vec3 &direction);
  inline Vec3 GetOrigin() const { return origin; }
  inline Vec3 GetDirection() const { return direction; }
  inline Vec3 Calculate(float t) const { return origin + (direction * t); }
};
}

#endif    
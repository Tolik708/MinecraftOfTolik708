#ifndef RAY
#define RAY

#include "vec3.hpp"

namespace Tolik
{
class Ray
{
private:
  vec3 origin;
  vec3 direction;
public:
  Ray(const vec3 &origin, const vec3 &direction);

  inline void SetOrigin(const vec3 &origin);
  inline void SetDirection(const vec3 &direction);
  inline vec3 GetOrigin() const { return origin; }
  inline vec3 GetDirection() const { return direction; }
  inline vec3 Calculate(float t) const { return origin + (direction * t); }
};
}

#endif    
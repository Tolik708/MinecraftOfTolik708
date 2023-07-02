#ifndef VEC3
#define VEC3

#include "Header.hpp"

namespace Tolik
{
struct Vec3
{
  union
  {
    struct
    {
      float x;
      float y;
      float z;
    };
    float padding[3] = { 0 };
  };

  Vec3(float newX, float newY, float newZ) { x = newX; y = newY; z = newZ; }
  Vec3(float xyz) { x = xyz; y = xyz; z = xyz; }
  Vec3() {}

  inline float SqrMagnitude() const { return (x * x) + (y * y) + (z * z); }
  inline float Magnitude() const { return sqrt(SqrMagnitude()); }
  inline void Round() { x = round(x); y = round(y); z = round(z); }
  inline Vec3 Abs() { return Vec3(abs(x), abs(y), abs(z)); }
  inline void MakeAbsolute() { x = abs(x); y = abs(y); z = abs(z); }
  #ifdef GLM_SETUP_INCLUDED
  inline glm::vec3 ToGlm() const { return glm::vec3(x, y, z); }
  #endif
  void ClampMagnitude(float minMagnitude, float maxMagnitude);
  Vec3 Normalized() const;
  void Normalize();

  inline float &operator[](int i) { return padding[i]; }
  inline float operator[](int i) const { return padding[i]; }
  inline Vec3 operator+(const Vec3 &vector) const { return Vec3(x + vector.x, y + vector.y, z + vector.z); }
  inline Vec3 operator-(const Vec3 &vector) const { return Vec3(x - vector.x, y - vector.y, z - vector.z); }
  inline Vec3 operator*(const Vec3 &vector) const { return Vec3(x * vector.x, y * vector.y, z * vector.z); }
  inline Vec3 operator/(const Vec3 &vector) const { return Vec3(x / vector.x, y / vector.y, z / vector.z); }
  inline Vec3 operator+(float num) const { return Vec3(x + num, y + num, z + num); }
  inline Vec3 operator-(float num) const { return Vec3(x - num, y - num, z - num); }
  inline Vec3 operator*(float num) const { return Vec3(x * num, y * num, z * num); }
  inline Vec3 operator/(float num) const { return Vec3(x / num, y / num, z / num); }
  inline const Vec3 &operator+=(const Vec3 &vector) { x += vector.x; y += vector.y; z += vector.z; return *this; }
  inline const Vec3 &operator-=(const Vec3 &vector) { x -= vector.x; y -= vector.y; z -= vector.z; return *this; }
  inline const Vec3 &operator*=(const Vec3 &vector) { x *= vector.x; y *= vector.y; z *= vector.z; return *this; }
  inline const Vec3 &operator/=(const Vec3 &vector) { x /= vector.x; y /= vector.y; z /= vector.z; return *this; }
  inline const Vec3 &operator+=(float num) { x += num; y += num; z += num; return *this; }
  inline const Vec3 &operator-=(float num) { x -= num; y -= num; z -= num; return *this; }
  inline const Vec3 &operator*=(float num) { x *= num; y *= num; z *= num; return *this; }
  inline const Vec3 &operator/=(float num) { x /= num; y /= num; z /= num; return *this; }
  inline Vec3 operator-() const { return Vec3(-x, -y, -z); }
  inline friend std::ostream& operator<<(std::ostream& os, Vec3 const& self) { return os << self.x << ' ' << self.y << ' ' << self.z; }
  
  inline static Vec3 Lerp(const Vec3 &a, const Vec3 &b, float t) { return a * (1 - t) + (b * t); }
  inline static float Dot(const Vec3 &a, const Vec3 &b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
  inline static Vec3 Min(const Vec3 &a, const Vec3 &b) { return Vec3(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z)); } //smallest from 2 vectors
  inline static Vec3 Max(const Vec3 &a, const Vec3 &b) { return Vec3(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z)); } //biggest from 2 vectors
  inline static Vec3 Round(const Vec3 &vector) { return Vec3(round(vector.x), round(vector.y), round(vector.z)); }
  inline static Vec3 Cross(const Vec3 &a, const Vec3 &b) { return Vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }
  inline static Vec3 Abs(const Vec3 &vector) { return Vec3(abs(vector.x), abs(vector.y), abs(vector.z)); }
  #ifdef GLM_SETUP_INCLUDED
  inline static glm::vec3 ToGlm(const Vec3 &vector) { return glm::vec3(vector.x, vector.y, vector.z); }
  #endif
  static Vec3 ClampMagnitude(const Vec3 &vector, float maxMagnitude, float minMagnitude);

  static const Vec3 right;
  static const Vec3 up;
  static const Vec3 left;
  static const Vec3 down;
  static const Vec3 forward;
  static const Vec3 backward;
  static const Vec3 one;
  static const Vec3 zero;
  static const Vec3 min;
  static const Vec3 max;
};

inline Vec3 operator+(float num, const Vec3 &vector) { return vector + num; }
inline Vec3 operator*(float num, const Vec3 &vector) { return vector * num; }
}

#endif
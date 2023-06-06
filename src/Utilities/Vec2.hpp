#ifndef VEC2
#define VEC2

#include "Header.hpp"

namespace Tolik
{
struct Vec2
{
  Vec2(float newX, float newY) { x = newX; y = newY; }
  Vec2(float newXY) { x = newXY; y = newXY; }
  Vec2() {}

  union
  {
    struct
    {
      float x;
      float y;
    };
    float padding[2] = { 0 };
  };

  inline float SqrMagnitude() const { return (x * x) + (y * y); }
  inline float Magnitude() const { return sqrt(SqrMagnitude()); }
  void ClampMagnitude(float minMagnitude, float maxMagnitude);
  inline void Round() { x = round(x); y = round(y); }
  Vec2 Normalized() const;
  void Normalize();

  inline float& operator[](int i) { return padding[i]; }
  inline float operator[](int i) const { return padding[i]; }
  inline Vec2 operator+(const Vec2 &vector) const { return Vec2(x + vector[0], y + vector[1]); }
  inline Vec2 operator-(const Vec2 &vector) const { return Vec2(x - vector[0], y - vector[1]); }
  inline Vec2 operator*(const Vec2 &vector) const { return Vec2(x * vector[0], y * vector[1]); }
  inline Vec2 operator/(const Vec2 &vector) const { return Vec2(x / vector[0], y / vector[1]); }
  inline Vec2 operator+(float num) const { return Vec2(x + num, y + num); }
  inline Vec2 operator-(float num) const { return Vec2(x - num, y - num); }
  inline Vec2 operator*(float num) const { return Vec2(x * num, y * num); }
  inline Vec2 operator/(float num) const { return Vec2(x / num, y / num); }
  inline Vec2 operator-() const { return Vec2(-x, -y); }
  inline friend std::ostream& operator<<(std::ostream& os, Vec2 const& self) { return os << "Vec3 " << self[0] << ' ' << self[1]; }
  
  inline static Vec2 Lerp(const Vec2 &a, const Vec2 &b, float t) { return a * (1 - t) + (b * t); }
  inline static float Dot(const Vec2 &a, const Vec2 &b) { return a[0] * b[0] + a[1] * b[1]; }
  inline static Vec2 Min(const Vec2 &a, const Vec2 &b) { return Vec2(std::min(a[0], b[0]), std::min(a[1], b[1])); } //smallest from 2 vectors
  inline static Vec2 Max(const Vec2 &a, const Vec2 &b) { return Vec2(std::max(a[0], b[0]), std::max(a[1], b[1])); } //biggest from 2 vectors
  inline static Vec2 Round(const Vec2 &vector) { return Vec2(round(vector[0]), round(vector[1])); }
  static Vec2 ClampMagnitude(const Vec2 &vector, float maxMagnitude, float minMagnitude);

  static const Vec2 right;
  static const Vec2 up;
  static const Vec2 left;
  static const Vec2 down;
  static const Vec2 one;
  static const Vec2 zero;
  static const Vec2 min;
  static const Vec2 max;
};

inline Vec2 operator+(float num, const Vec2 &vector) { return vector + num; }
inline Vec2 operator*(float num, const Vec2 &vector) { return vector * num; }
}

#endif
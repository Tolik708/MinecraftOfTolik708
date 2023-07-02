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
  inline void Abs() { x = abs(x); y = abs(y); }
  inline void MakeAbsolute() { x = abs(x); y = abs(y); } 
  Vec2 Normalized() const;
  void Normalize();

  inline float& operator[](int i) { return padding[i]; }
  inline float operator[](int i) const { return padding[i]; }
  inline Vec2 operator+(const Vec2 &vector) const { return Vec2(x + vector.x, y + vector.y); }
  inline Vec2 operator-(const Vec2 &vector) const { return Vec2(x - vector.x, y - vector.y); }
  inline Vec2 operator*(const Vec2 &vector) const { return Vec2(x * vector.x, y * vector.y); }
  inline Vec2 operator/(const Vec2 &vector) const { return Vec2(x / vector.x, y / vector.y); }
  inline Vec2 operator+(float num) const { return Vec2(x + num, y + num); }
  inline Vec2 operator-(float num) const { return Vec2(x - num, y - num); }
  inline Vec2 operator*(float num) const { return Vec2(x * num, y * num); }
  inline Vec2 operator/(float num) const { return Vec2(x / num, y / num); }
  inline Vec2 operator-() const { return Vec2(-x, -y); }
  inline friend std::ostream& operator<<(std::ostream& os, const Vec2 &self) { return os << "Vec3 " << self.x << ' ' << self.y; }
  
  inline static Vec2 Lerp(const Vec2 &a, const Vec2 &b, float t) { return a * (1 - t) + (b * t); }
  inline static float Dot(const Vec2 &a, const Vec2 &b) { return a.x * b.x + a.y * b.y; }
  inline static Vec2 Min(const Vec2 &a, const Vec2 &b) { return Vec2(std::min(a.x, b.x), std::min(a.y, b.y)); } //smallest from 2 vectors
  inline static Vec2 Max(const Vec2 &a, const Vec2 &b) { return Vec2(std::max(a.x, b.x), std::max(a.y, b.y)); } //biggest from 2 vectors
  inline static Vec2 Round(const Vec2 &vector) { return Vec2(round(vector.x), round(vector.y)); }
  inline static Vec2 Abs(const Vec2 &vector) { return Vec2(abs(vector.x), abs(vector.y)); }
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
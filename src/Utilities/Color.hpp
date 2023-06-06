#ifndef COLOR
#define COLOR

#define DIV255 0.0039215f

#include "Header.hpp"
#include "Vec3.hpp"

namespace Tolik
{
struct Color32
{
  Color32(uint8_t newR, uint8_t newG, uint8_t newB, uint8_t newA) { r = newR; g = newG; b = newB; a = newA; }
  Color32(uint8_t newR, uint8_t newG, uint8_t newB) { r = newR; g = newG; b = newB; }
  Color32(uint32_t rgba) { r = rgba & 0x000000FF; g = (rgba & 0x0000FF00) >> 8; b = (rgba & 0x00FF0000) >> 16; a = (rgba & 0xFF000000) >> 24; }
  Color32() {}

  union
  {
    struct { uint8_t r, g, b, a; };
    uint8_t padding[4] = { 255 };
  };
  

  inline Color32 operator+(const Color32 &color) const { return Color32(r + color.a, g + color.g, b + color.b, a + color.a); }
  inline Color32 operator-(const Color32 &color) const { return Color32(r - color.a, g - color.g, b - color.b, a - color.a); }
  inline Color32 operator*(const Color32 &color) const { return Color32(r * color.a, g * color.g, b * color.b, a * color.a); }
  inline Color32 operator/(const Color32 &color) const { return Color32(r / color.a, g / color.g, b / color.b, a / color.a); }
  inline Color32 operator+(float num) const { return Color32(r + num, g + num, b + num, a + num); }
  inline Color32 operator-(float num) const { return Color32(r - num, g - num, b - num, a - num); }
  inline Color32 operator*(float num) const { return Color32(r * num, g * num, b * num, a * num); }
  inline Color32 operator/(float num) const { return Color32(r / num, g / num, b / num, a / num); }

  inline uint8_t operator[](int i) const { return padding[i]; }
  inline uint8_t& operator[](int i) { return padding[i]; }

  inline uint32_t toUint32() const { return reinterpret_cast<uint32_t>(padding); }
  inline Vec3 toUnitColor32() const { return Vec3(r * DIV255, g * DIV255, b * DIV255); }

  inline static uint32_t toUint32(const Color32 &color) { return reinterpret_cast<uint32_t>(color.padding); }
  inline static Vec3 toUnitColor32(const Color32 &color) { return Vec3(color[0] * DIV255, color[1] * DIV255, color[2] * DIV255); }
  inline static Color32 unitToColor32(float r, float g, float b, float a) { return Color32(255 * r, 255 * g, 255 * b, 255 * a); }
  inline static Color32 unitToColor32(float r, float g, float b) { return Color32(255 * r, 255 * g, 255 * b); }
  inline static Color32 unitToColor32(const Vec3 &vector) { return Color32(255 * vector.x, 255 * vector.y, 255 * vector.z); }
  inline static Color32 Lerp(const Color32 &a, const Color32 &b, float t) { return a * (1 - t) + (b * t); }
};

inline Color32 operator+(float num, const Color32 &color) { return color + num; }
inline Color32 operator*(float num, const Color32 &color) { return color * num; }
}

#endif
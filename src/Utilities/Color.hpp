#ifndef COLOR
#define COLOR

#define DIV255 0.0039215f

#include "Header.hpp"
#include "Vec3.hpp"

namespace Tolik
{
struct Color
{
  uint8_t e[4];
  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
  Color(uint8_t r, uint8_t g, uint8_t b);
  Color(uint32_t rgba);
  Color();

  inline uint8_t& r() { return e[0]; }
  inline uint8_t& g() { return e[1]; }
  inline uint8_t& b() { return e[2]; }
  inline uint8_t& a() { return e[3]; }
  inline uint8_t r() const { return e[0]; }
  inline uint8_t g() const { return e[1]; }
  inline uint8_t b() const { return e[2]; }
  inline uint8_t a() const { return e[3]; }

  inline Color operator+(const Color &color) const { return Color(e[0] + color[0], e[1] + color[1], e[2] + color[2], e[3] + color[3]); }
  inline Color operator-(const Color &color) const { return Color(e[0] - color[0], e[1] - color[1], e[2] - color[2], e[3] - color[3]); }
  inline Color operator*(const Color &color) const { return Color(e[0] * color[0], e[1] * color[1], e[2] * color[2], e[3] * color[3]); }
  inline Color operator/(const Color &color) const { return Color(e[0] / color[0], e[1] / color[1], e[2] / color[2], e[3] / color[3]); }
  inline Color operator+(float num) const { return Color(e[0] + num, e[1] + num, e[2] + num, e[3] + num); }
  inline Color operator-(float num) const { return Color(e[0] - num, e[1] - num, e[2] - num, e[3] - num); }
  inline Color operator*(float num) const { return Color(e[0] * num, e[1] * num, e[2] * num, e[3] * num); }
  inline Color operator/(float num) const { return Color(e[0] / num, e[1] / num, e[2] / num, e[3] / num); }

  inline uint8_t operator[](int i) const { return e[i]; }
  inline uint8_t& operator[](int i) { return e[i]; }

  inline uint32_t toUint32() const { return *(uint32_t*)&e; }
  inline vec3 toUnitColor() const { return vec3(e[0] * DIV255, e[1] * DIV255, e[2] * DIV255); }

  inline static uint32_t toUint32(const Color &color) { return *(uint32_t*)&color.e; }
  inline static vec3 toUnitColor(const Color &color) { return vec3(color[0] * DIV255, color[1] * DIV255, color[2] * DIV255); }
  inline static Color unitToColor(float r, float g, float b, float a) { return Color(255 * r, 255 * g, 255 * b, 255 * a); }
  inline static Color unitToColor(float r, float g, float b) { return Color(255 * r, 255 * g, 255 * b); }
  inline static Color unitToColor(const vec3 &vector) { return Color(255 * vector.x(), 255 * vector.y(), 255 * vector.z()); }
  inline static Color Lerp(const Color &a, const Color &b, float t) { return a * (1 - t) + (b * t); }
};

inline Color operator+(float num, const Color &color) { return color + num; }
inline Color operator-(float num, const Color &color) { return color - num; }
inline Color operator*(float num, const Color &color) { return color * num; }
inline Color operator/(float num, const Color &color) { return color / num; }
}

#endif
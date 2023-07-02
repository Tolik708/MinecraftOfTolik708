#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Header.hpp"

#include "Vec3.hpp"

namespace Tolik
{
class Camera
{
public:
  Camera() { UpdateVectors(); }
  Camera(const Vec3 &newPosition) : position(newPosition) { UpdateVectors(); }

  Vec3 position = Vec3::zero;

  inline void SetRotation(const Vec3 &rotation) { m_rotation = rotation; UpdateVectors(); }
  inline void Rotate(const Vec3 &deltaRotation) { m_rotation += deltaRotation; UpdateVectors(); }
  inline const Vec3 &GetRotation() const { return m_rotation; }
  inline glm::mat4 GetViewMatrix() const { return glm::lookAt(position.ToGlm(), (position + m_front).ToGlm(), m_up.ToGlm()); }

private:
  Vec3 m_up;
  Vec3 m_right;
  Vec3 m_front;
  Vec3 m_rotation = Vec3::zero;

  void UpdateVectors();
};
}

#endif
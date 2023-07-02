#include "Camera.hpp"

#include "Header.hpp"

#include "Vec3.hpp"
#include "Utils.hpp"

namespace Tolik
{
void Camera::UpdateVectors()
{
  const float cosOfPitch = cos(DegreesToRadians(m_rotation.x));
  m_front.x = cos(DegreesToRadians(m_rotation.y)) * cosOfPitch;
  m_front.y = sin(DegreesToRadians(m_rotation.x));
  m_front.z = sin(DegreesToRadians(m_rotation.z)) * cosOfPitch;
  m_front.Normalize();

  m_right = Vec3::Cross(m_front, Constants::WorldUp).Normalized();
  m_up = Vec3::Cross(m_front, m_right).Normalized();
}
}
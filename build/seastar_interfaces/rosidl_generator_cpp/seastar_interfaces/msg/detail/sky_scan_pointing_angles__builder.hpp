// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from seastar_interfaces:msg/SkyScanPointingAngles.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_POINTING_ANGLES__BUILDER_HPP_
#define SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_POINTING_ANGLES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "seastar_interfaces/msg/detail/sky_scan_pointing_angles__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace seastar_interfaces
{

namespace msg
{

namespace builder
{

class Init_SkyScanPointingAngles_stokes_angle
{
public:
  explicit Init_SkyScanPointingAngles_stokes_angle(::seastar_interfaces::msg::SkyScanPointingAngles & msg)
  : msg_(msg)
  {}
  ::seastar_interfaces::msg::SkyScanPointingAngles stokes_angle(::seastar_interfaces::msg::SkyScanPointingAngles::_stokes_angle_type arg)
  {
    msg_.stokes_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::seastar_interfaces::msg::SkyScanPointingAngles msg_;
};

class Init_SkyScanPointingAngles_elevation
{
public:
  explicit Init_SkyScanPointingAngles_elevation(::seastar_interfaces::msg::SkyScanPointingAngles & msg)
  : msg_(msg)
  {}
  Init_SkyScanPointingAngles_stokes_angle elevation(::seastar_interfaces::msg::SkyScanPointingAngles::_elevation_type arg)
  {
    msg_.elevation = std::move(arg);
    return Init_SkyScanPointingAngles_stokes_angle(msg_);
  }

private:
  ::seastar_interfaces::msg::SkyScanPointingAngles msg_;
};

class Init_SkyScanPointingAngles_azimuth
{
public:
  Init_SkyScanPointingAngles_azimuth()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SkyScanPointingAngles_elevation azimuth(::seastar_interfaces::msg::SkyScanPointingAngles::_azimuth_type arg)
  {
    msg_.azimuth = std::move(arg);
    return Init_SkyScanPointingAngles_elevation(msg_);
  }

private:
  ::seastar_interfaces::msg::SkyScanPointingAngles msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::seastar_interfaces::msg::SkyScanPointingAngles>()
{
  return seastar_interfaces::msg::builder::Init_SkyScanPointingAngles_azimuth();
}

}  // namespace seastar_interfaces

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_POINTING_ANGLES__BUILDER_HPP_

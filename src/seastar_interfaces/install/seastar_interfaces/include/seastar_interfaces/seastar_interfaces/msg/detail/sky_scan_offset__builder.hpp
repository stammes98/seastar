// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from seastar_interfaces:msg/SkyScanOffset.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__BUILDER_HPP_
#define SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "seastar_interfaces/msg/detail/sky_scan_offset__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace seastar_interfaces
{

namespace msg
{

namespace builder
{

class Init_SkyScanOffset_stokes_angle_offset
{
public:
  explicit Init_SkyScanOffset_stokes_angle_offset(::seastar_interfaces::msg::SkyScanOffset & msg)
  : msg_(msg)
  {}
  ::seastar_interfaces::msg::SkyScanOffset stokes_angle_offset(::seastar_interfaces::msg::SkyScanOffset::_stokes_angle_offset_type arg)
  {
    msg_.stokes_angle_offset = std::move(arg);
    return std::move(msg_);
  }

private:
  ::seastar_interfaces::msg::SkyScanOffset msg_;
};

class Init_SkyScanOffset_elevation_offset
{
public:
  explicit Init_SkyScanOffset_elevation_offset(::seastar_interfaces::msg::SkyScanOffset & msg)
  : msg_(msg)
  {}
  Init_SkyScanOffset_stokes_angle_offset elevation_offset(::seastar_interfaces::msg::SkyScanOffset::_elevation_offset_type arg)
  {
    msg_.elevation_offset = std::move(arg);
    return Init_SkyScanOffset_stokes_angle_offset(msg_);
  }

private:
  ::seastar_interfaces::msg::SkyScanOffset msg_;
};

class Init_SkyScanOffset_azimuth_offset
{
public:
  Init_SkyScanOffset_azimuth_offset()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SkyScanOffset_elevation_offset azimuth_offset(::seastar_interfaces::msg::SkyScanOffset::_azimuth_offset_type arg)
  {
    msg_.azimuth_offset = std::move(arg);
    return Init_SkyScanOffset_elevation_offset(msg_);
  }

private:
  ::seastar_interfaces::msg::SkyScanOffset msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::seastar_interfaces::msg::SkyScanOffset>()
{
  return seastar_interfaces::msg::builder::Init_SkyScanOffset_azimuth_offset();
}

}  // namespace seastar_interfaces

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__BUILDER_HPP_

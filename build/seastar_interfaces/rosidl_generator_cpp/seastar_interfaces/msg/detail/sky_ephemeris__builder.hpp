// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from seastar_interfaces:msg/SkyEphemeris.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__SKY_EPHEMERIS__BUILDER_HPP_
#define SEASTAR_INTERFACES__MSG__DETAIL__SKY_EPHEMERIS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "seastar_interfaces/msg/detail/sky_ephemeris__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace seastar_interfaces
{

namespace msg
{

namespace builder
{

class Init_SkyEphemeris_elevation
{
public:
  explicit Init_SkyEphemeris_elevation(::seastar_interfaces::msg::SkyEphemeris & msg)
  : msg_(msg)
  {}
  ::seastar_interfaces::msg::SkyEphemeris elevation(::seastar_interfaces::msg::SkyEphemeris::_elevation_type arg)
  {
    msg_.elevation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::seastar_interfaces::msg::SkyEphemeris msg_;
};

class Init_SkyEphemeris_azimuth
{
public:
  Init_SkyEphemeris_azimuth()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SkyEphemeris_elevation azimuth(::seastar_interfaces::msg::SkyEphemeris::_azimuth_type arg)
  {
    msg_.azimuth = std::move(arg);
    return Init_SkyEphemeris_elevation(msg_);
  }

private:
  ::seastar_interfaces::msg::SkyEphemeris msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::seastar_interfaces::msg::SkyEphemeris>()
{
  return seastar_interfaces::msg::builder::Init_SkyEphemeris_azimuth();
}

}  // namespace seastar_interfaces

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__SKY_EPHEMERIS__BUILDER_HPP_

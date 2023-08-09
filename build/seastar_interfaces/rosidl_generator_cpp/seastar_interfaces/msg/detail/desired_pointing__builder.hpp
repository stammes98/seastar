// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from seastar_interfaces:msg/DesiredPointing.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__DESIRED_POINTING__BUILDER_HPP_
#define SEASTAR_INTERFACES__MSG__DETAIL__DESIRED_POINTING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "seastar_interfaces/msg/detail/desired_pointing__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace seastar_interfaces
{

namespace msg
{

namespace builder
{

class Init_DesiredPointing_polarization
{
public:
  explicit Init_DesiredPointing_polarization(::seastar_interfaces::msg::DesiredPointing & msg)
  : msg_(msg)
  {}
  ::seastar_interfaces::msg::DesiredPointing polarization(::seastar_interfaces::msg::DesiredPointing::_polarization_type arg)
  {
    msg_.polarization = std::move(arg);
    return std::move(msg_);
  }

private:
  ::seastar_interfaces::msg::DesiredPointing msg_;
};

class Init_DesiredPointing_altitude
{
public:
  explicit Init_DesiredPointing_altitude(::seastar_interfaces::msg::DesiredPointing & msg)
  : msg_(msg)
  {}
  Init_DesiredPointing_polarization altitude(::seastar_interfaces::msg::DesiredPointing::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return Init_DesiredPointing_polarization(msg_);
  }

private:
  ::seastar_interfaces::msg::DesiredPointing msg_;
};

class Init_DesiredPointing_azimuth
{
public:
  Init_DesiredPointing_azimuth()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DesiredPointing_altitude azimuth(::seastar_interfaces::msg::DesiredPointing::_azimuth_type arg)
  {
    msg_.azimuth = std::move(arg);
    return Init_DesiredPointing_altitude(msg_);
  }

private:
  ::seastar_interfaces::msg::DesiredPointing msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::seastar_interfaces::msg::DesiredPointing>()
{
  return seastar_interfaces::msg::builder::Init_DesiredPointing_azimuth();
}

}  // namespace seastar_interfaces

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__DESIRED_POINTING__BUILDER_HPP_

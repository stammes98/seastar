// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from seastar_interfaces:srv/PointMotors.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__SRV__DETAIL__POINT_MOTORS__BUILDER_HPP_
#define SEASTAR_INTERFACES__SRV__DETAIL__POINT_MOTORS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "seastar_interfaces/srv/detail/point_motors__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace seastar_interfaces
{

namespace srv
{

namespace builder
{

class Init_PointMotors_Request_input_state
{
public:
  explicit Init_PointMotors_Request_input_state(::seastar_interfaces::srv::PointMotors_Request & msg)
  : msg_(msg)
  {}
  ::seastar_interfaces::srv::PointMotors_Request input_state(::seastar_interfaces::srv::PointMotors_Request::_input_state_type arg)
  {
    msg_.input_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::seastar_interfaces::srv::PointMotors_Request msg_;
};

class Init_PointMotors_Request_point
{
public:
  Init_PointMotors_Request_point()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PointMotors_Request_input_state point(::seastar_interfaces::srv::PointMotors_Request::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_PointMotors_Request_input_state(msg_);
  }

private:
  ::seastar_interfaces::srv::PointMotors_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::seastar_interfaces::srv::PointMotors_Request>()
{
  return seastar_interfaces::srv::builder::Init_PointMotors_Request_point();
}

}  // namespace seastar_interfaces


namespace seastar_interfaces
{

namespace srv
{

namespace builder
{

class Init_PointMotors_Response_command
{
public:
  Init_PointMotors_Response_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::seastar_interfaces::srv::PointMotors_Response command(::seastar_interfaces::srv::PointMotors_Response::_command_type arg)
  {
    msg_.command = std::move(arg);
    return std::move(msg_);
  }

private:
  ::seastar_interfaces::srv::PointMotors_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::seastar_interfaces::srv::PointMotors_Response>()
{
  return seastar_interfaces::srv::builder::Init_PointMotors_Response_command();
}

}  // namespace seastar_interfaces

#endif  // SEASTAR_INTERFACES__SRV__DETAIL__POINT_MOTORS__BUILDER_HPP_

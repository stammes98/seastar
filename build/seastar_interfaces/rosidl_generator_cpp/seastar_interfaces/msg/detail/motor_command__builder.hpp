// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from seastar_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_
#define SEASTAR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "seastar_interfaces/msg/detail/motor_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace seastar_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorCommand_q3
{
public:
  explicit Init_MotorCommand_q3(::seastar_interfaces::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  ::seastar_interfaces::msg::MotorCommand q3(::seastar_interfaces::msg::MotorCommand::_q3_type arg)
  {
    msg_.q3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::seastar_interfaces::msg::MotorCommand msg_;
};

class Init_MotorCommand_q2
{
public:
  explicit Init_MotorCommand_q2(::seastar_interfaces::msg::MotorCommand & msg)
  : msg_(msg)
  {}
  Init_MotorCommand_q3 q2(::seastar_interfaces::msg::MotorCommand::_q2_type arg)
  {
    msg_.q2 = std::move(arg);
    return Init_MotorCommand_q3(msg_);
  }

private:
  ::seastar_interfaces::msg::MotorCommand msg_;
};

class Init_MotorCommand_q1
{
public:
  Init_MotorCommand_q1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorCommand_q2 q1(::seastar_interfaces::msg::MotorCommand::_q1_type arg)
  {
    msg_.q1 = std::move(arg);
    return Init_MotorCommand_q2(msg_);
  }

private:
  ::seastar_interfaces::msg::MotorCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::seastar_interfaces::msg::MotorCommand>()
{
  return seastar_interfaces::msg::builder::Init_MotorCommand_q1();
}

}  // namespace seastar_interfaces

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__BUILDER_HPP_

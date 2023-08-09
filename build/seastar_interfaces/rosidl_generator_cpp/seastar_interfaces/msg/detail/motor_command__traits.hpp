// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from seastar_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_
#define SEASTAR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "seastar_interfaces/msg/detail/motor_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace seastar_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: q1
  {
    out << "q1: ";
    rosidl_generator_traits::value_to_yaml(msg.q1, out);
    out << ", ";
  }

  // member: q2
  {
    out << "q2: ";
    rosidl_generator_traits::value_to_yaml(msg.q2, out);
    out << ", ";
  }

  // member: q3
  {
    out << "q3: ";
    rosidl_generator_traits::value_to_yaml(msg.q3, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: q1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q1: ";
    rosidl_generator_traits::value_to_yaml(msg.q1, out);
    out << "\n";
  }

  // member: q2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q2: ";
    rosidl_generator_traits::value_to_yaml(msg.q2, out);
    out << "\n";
  }

  // member: q3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q3: ";
    rosidl_generator_traits::value_to_yaml(msg.q3, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace seastar_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use seastar_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const seastar_interfaces::msg::MotorCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  seastar_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use seastar_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const seastar_interfaces::msg::MotorCommand & msg)
{
  return seastar_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<seastar_interfaces::msg::MotorCommand>()
{
  return "seastar_interfaces::msg::MotorCommand";
}

template<>
inline const char * name<seastar_interfaces::msg::MotorCommand>()
{
  return "seastar_interfaces/msg/MotorCommand";
}

template<>
struct has_fixed_size<seastar_interfaces::msg::MotorCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<seastar_interfaces::msg::MotorCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<seastar_interfaces::msg::MotorCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__TRAITS_HPP_

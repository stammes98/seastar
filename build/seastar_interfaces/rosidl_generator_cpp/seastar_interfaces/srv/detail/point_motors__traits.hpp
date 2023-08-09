// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from seastar_interfaces:srv/PointMotors.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__SRV__DETAIL__POINT_MOTORS__TRAITS_HPP_
#define SEASTAR_INTERFACES__SRV__DETAIL__POINT_MOTORS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "seastar_interfaces/srv/detail/point_motors__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'point'
#include "seastar_interfaces/msg/detail/desired_pointing__traits.hpp"
// Member 'input_state'
#include "seastar_interfaces/msg/detail/motor_command__traits.hpp"

namespace seastar_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PointMotors_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: point
  {
    out << "point: ";
    to_flow_style_yaml(msg.point, out);
    out << ", ";
  }

  // member: input_state
  {
    out << "input_state: ";
    to_flow_style_yaml(msg.input_state, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PointMotors_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "point:\n";
    to_block_style_yaml(msg.point, out, indentation + 2);
  }

  // member: input_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_state:\n";
    to_block_style_yaml(msg.input_state, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PointMotors_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace seastar_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use seastar_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const seastar_interfaces::srv::PointMotors_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  seastar_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use seastar_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const seastar_interfaces::srv::PointMotors_Request & msg)
{
  return seastar_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<seastar_interfaces::srv::PointMotors_Request>()
{
  return "seastar_interfaces::srv::PointMotors_Request";
}

template<>
inline const char * name<seastar_interfaces::srv::PointMotors_Request>()
{
  return "seastar_interfaces/srv/PointMotors_Request";
}

template<>
struct has_fixed_size<seastar_interfaces::srv::PointMotors_Request>
  : std::integral_constant<bool, has_fixed_size<seastar_interfaces::msg::DesiredPointing>::value && has_fixed_size<seastar_interfaces::msg::MotorCommand>::value> {};

template<>
struct has_bounded_size<seastar_interfaces::srv::PointMotors_Request>
  : std::integral_constant<bool, has_bounded_size<seastar_interfaces::msg::DesiredPointing>::value && has_bounded_size<seastar_interfaces::msg::MotorCommand>::value> {};

template<>
struct is_message<seastar_interfaces::srv::PointMotors_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'command'
// already included above
// #include "seastar_interfaces/msg/detail/motor_command__traits.hpp"

namespace seastar_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const PointMotors_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: command
  {
    out << "command: ";
    to_flow_style_yaml(msg.command, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PointMotors_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command:\n";
    to_block_style_yaml(msg.command, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PointMotors_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace seastar_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use seastar_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const seastar_interfaces::srv::PointMotors_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  seastar_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use seastar_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const seastar_interfaces::srv::PointMotors_Response & msg)
{
  return seastar_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<seastar_interfaces::srv::PointMotors_Response>()
{
  return "seastar_interfaces::srv::PointMotors_Response";
}

template<>
inline const char * name<seastar_interfaces::srv::PointMotors_Response>()
{
  return "seastar_interfaces/srv/PointMotors_Response";
}

template<>
struct has_fixed_size<seastar_interfaces::srv::PointMotors_Response>
  : std::integral_constant<bool, has_fixed_size<seastar_interfaces::msg::MotorCommand>::value> {};

template<>
struct has_bounded_size<seastar_interfaces::srv::PointMotors_Response>
  : std::integral_constant<bool, has_bounded_size<seastar_interfaces::msg::MotorCommand>::value> {};

template<>
struct is_message<seastar_interfaces::srv::PointMotors_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<seastar_interfaces::srv::PointMotors>()
{
  return "seastar_interfaces::srv::PointMotors";
}

template<>
inline const char * name<seastar_interfaces::srv::PointMotors>()
{
  return "seastar_interfaces/srv/PointMotors";
}

template<>
struct has_fixed_size<seastar_interfaces::srv::PointMotors>
  : std::integral_constant<
    bool,
    has_fixed_size<seastar_interfaces::srv::PointMotors_Request>::value &&
    has_fixed_size<seastar_interfaces::srv::PointMotors_Response>::value
  >
{
};

template<>
struct has_bounded_size<seastar_interfaces::srv::PointMotors>
  : std::integral_constant<
    bool,
    has_bounded_size<seastar_interfaces::srv::PointMotors_Request>::value &&
    has_bounded_size<seastar_interfaces::srv::PointMotors_Response>::value
  >
{
};

template<>
struct is_service<seastar_interfaces::srv::PointMotors>
  : std::true_type
{
};

template<>
struct is_service_request<seastar_interfaces::srv::PointMotors_Request>
  : std::true_type
{
};

template<>
struct is_service_response<seastar_interfaces::srv::PointMotors_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SEASTAR_INTERFACES__SRV__DETAIL__POINT_MOTORS__TRAITS_HPP_

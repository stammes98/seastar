// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from seastar_interfaces:msg/DesiredPointing.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__DESIRED_POINTING__TRAITS_HPP_
#define SEASTAR_INTERFACES__MSG__DETAIL__DESIRED_POINTING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "seastar_interfaces/msg/detail/desired_pointing__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace seastar_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const DesiredPointing & msg,
  std::ostream & out)
{
  out << "{";
  // member: azimuth
  {
    out << "azimuth: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth, out);
    out << ", ";
  }

  // member: altitude
  {
    out << "altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude, out);
    out << ", ";
  }

  // member: polarization
  {
    out << "polarization: ";
    rosidl_generator_traits::value_to_yaml(msg.polarization, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DesiredPointing & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: azimuth
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "azimuth: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth, out);
    out << "\n";
  }

  // member: altitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude, out);
    out << "\n";
  }

  // member: polarization
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "polarization: ";
    rosidl_generator_traits::value_to_yaml(msg.polarization, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DesiredPointing & msg, bool use_flow_style = false)
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
  const seastar_interfaces::msg::DesiredPointing & msg,
  std::ostream & out, size_t indentation = 0)
{
  seastar_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use seastar_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const seastar_interfaces::msg::DesiredPointing & msg)
{
  return seastar_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<seastar_interfaces::msg::DesiredPointing>()
{
  return "seastar_interfaces::msg::DesiredPointing";
}

template<>
inline const char * name<seastar_interfaces::msg::DesiredPointing>()
{
  return "seastar_interfaces/msg/DesiredPointing";
}

template<>
struct has_fixed_size<seastar_interfaces::msg::DesiredPointing>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<seastar_interfaces::msg::DesiredPointing>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<seastar_interfaces::msg::DesiredPointing>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__DESIRED_POINTING__TRAITS_HPP_

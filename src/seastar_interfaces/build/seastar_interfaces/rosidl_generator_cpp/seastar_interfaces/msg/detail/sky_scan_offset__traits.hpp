// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from seastar_interfaces:msg/SkyScanOffset.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__TRAITS_HPP_
#define SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "seastar_interfaces/msg/detail/sky_scan_offset__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace seastar_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SkyScanOffset & msg,
  std::ostream & out)
{
  out << "{";
  // member: azimuth_offset
  {
    out << "azimuth_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth_offset, out);
    out << ", ";
  }

  // member: elevation_offset
  {
    out << "elevation_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.elevation_offset, out);
    out << ", ";
  }

  // member: stokes_angle_offset
  {
    out << "stokes_angle_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.stokes_angle_offset, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SkyScanOffset & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: azimuth_offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "azimuth_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth_offset, out);
    out << "\n";
  }

  // member: elevation_offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "elevation_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.elevation_offset, out);
    out << "\n";
  }

  // member: stokes_angle_offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stokes_angle_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.stokes_angle_offset, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SkyScanOffset & msg, bool use_flow_style = false)
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
  const seastar_interfaces::msg::SkyScanOffset & msg,
  std::ostream & out, size_t indentation = 0)
{
  seastar_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use seastar_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const seastar_interfaces::msg::SkyScanOffset & msg)
{
  return seastar_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<seastar_interfaces::msg::SkyScanOffset>()
{
  return "seastar_interfaces::msg::SkyScanOffset";
}

template<>
inline const char * name<seastar_interfaces::msg::SkyScanOffset>()
{
  return "seastar_interfaces/msg/SkyScanOffset";
}

template<>
struct has_fixed_size<seastar_interfaces::msg::SkyScanOffset>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<seastar_interfaces::msg::SkyScanOffset>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<seastar_interfaces::msg::SkyScanOffset>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__TRAITS_HPP_

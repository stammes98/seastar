// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from seastar_interfaces:msg/SkyEphemeris.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__SKY_EPHEMERIS__TRAITS_HPP_
#define SEASTAR_INTERFACES__MSG__DETAIL__SKY_EPHEMERIS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "seastar_interfaces/msg/detail/sky_ephemeris__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace seastar_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SkyEphemeris & msg,
  std::ostream & out)
{
  out << "{";
  // member: azimuth
  {
    out << "azimuth: ";
    rosidl_generator_traits::value_to_yaml(msg.azimuth, out);
    out << ", ";
  }

  // member: elevation
  {
    out << "elevation: ";
    rosidl_generator_traits::value_to_yaml(msg.elevation, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SkyEphemeris & msg,
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

  // member: elevation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "elevation: ";
    rosidl_generator_traits::value_to_yaml(msg.elevation, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SkyEphemeris & msg, bool use_flow_style = false)
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
  const seastar_interfaces::msg::SkyEphemeris & msg,
  std::ostream & out, size_t indentation = 0)
{
  seastar_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use seastar_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const seastar_interfaces::msg::SkyEphemeris & msg)
{
  return seastar_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<seastar_interfaces::msg::SkyEphemeris>()
{
  return "seastar_interfaces::msg::SkyEphemeris";
}

template<>
inline const char * name<seastar_interfaces::msg::SkyEphemeris>()
{
  return "seastar_interfaces/msg/SkyEphemeris";
}

template<>
struct has_fixed_size<seastar_interfaces::msg::SkyEphemeris>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<seastar_interfaces::msg::SkyEphemeris>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<seastar_interfaces::msg::SkyEphemeris>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__SKY_EPHEMERIS__TRAITS_HPP_

// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from seastar_interfaces:msg/DesiredPointing.idl
// generated code does not contain a copyright notice
#include "seastar_interfaces/msg/detail/desired_pointing__rosidl_typesupport_fastrtps_cpp.hpp"
#include "seastar_interfaces/msg/detail/desired_pointing__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace seastar_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_seastar_interfaces
cdr_serialize(
  const seastar_interfaces::msg::DesiredPointing & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: azimuth
  cdr << ros_message.azimuth;
  // Member: altitude
  cdr << ros_message.altitude;
  // Member: polarization
  cdr << ros_message.polarization;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_seastar_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  seastar_interfaces::msg::DesiredPointing & ros_message)
{
  // Member: azimuth
  cdr >> ros_message.azimuth;

  // Member: altitude
  cdr >> ros_message.altitude;

  // Member: polarization
  cdr >> ros_message.polarization;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_seastar_interfaces
get_serialized_size(
  const seastar_interfaces::msg::DesiredPointing & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: azimuth
  {
    size_t item_size = sizeof(ros_message.azimuth);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: altitude
  {
    size_t item_size = sizeof(ros_message.altitude);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: polarization
  {
    size_t item_size = sizeof(ros_message.polarization);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_seastar_interfaces
max_serialized_size_DesiredPointing(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: azimuth
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: altitude
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: polarization
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _DesiredPointing__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const seastar_interfaces::msg::DesiredPointing *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DesiredPointing__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<seastar_interfaces::msg::DesiredPointing *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DesiredPointing__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const seastar_interfaces::msg::DesiredPointing *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DesiredPointing__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_DesiredPointing(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _DesiredPointing__callbacks = {
  "seastar_interfaces::msg",
  "DesiredPointing",
  _DesiredPointing__cdr_serialize,
  _DesiredPointing__cdr_deserialize,
  _DesiredPointing__get_serialized_size,
  _DesiredPointing__max_serialized_size
};

static rosidl_message_type_support_t _DesiredPointing__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DesiredPointing__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace seastar_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_seastar_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<seastar_interfaces::msg::DesiredPointing>()
{
  return &seastar_interfaces::msg::typesupport_fastrtps_cpp::_DesiredPointing__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, seastar_interfaces, msg, DesiredPointing)() {
  return &seastar_interfaces::msg::typesupport_fastrtps_cpp::_DesiredPointing__handle;
}

#ifdef __cplusplus
}
#endif

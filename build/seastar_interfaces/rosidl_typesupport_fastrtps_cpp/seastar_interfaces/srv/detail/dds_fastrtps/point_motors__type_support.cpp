// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from seastar_interfaces:srv/PointMotors.idl
// generated code does not contain a copyright notice
#include "seastar_interfaces/srv/detail/point_motors__rosidl_typesupport_fastrtps_cpp.hpp"
#include "seastar_interfaces/srv/detail/point_motors__struct.hpp"

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
bool cdr_serialize(
  const seastar_interfaces::msg::DesiredPointing &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  seastar_interfaces::msg::DesiredPointing &);
size_t get_serialized_size(
  const seastar_interfaces::msg::DesiredPointing &,
  size_t current_alignment);
size_t
max_serialized_size_DesiredPointing(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace seastar_interfaces

namespace seastar_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const seastar_interfaces::msg::MotorCommand &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  seastar_interfaces::msg::MotorCommand &);
size_t get_serialized_size(
  const seastar_interfaces::msg::MotorCommand &,
  size_t current_alignment);
size_t
max_serialized_size_MotorCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace seastar_interfaces


namespace seastar_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_seastar_interfaces
cdr_serialize(
  const seastar_interfaces::srv::PointMotors_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: point
  seastar_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.point,
    cdr);
  // Member: input_state
  seastar_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.input_state,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_seastar_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  seastar_interfaces::srv::PointMotors_Request & ros_message)
{
  // Member: point
  seastar_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.point);

  // Member: input_state
  seastar_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.input_state);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_seastar_interfaces
get_serialized_size(
  const seastar_interfaces::srv::PointMotors_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: point

  current_alignment +=
    seastar_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.point, current_alignment);
  // Member: input_state

  current_alignment +=
    seastar_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.input_state, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_seastar_interfaces
max_serialized_size_PointMotors_Request(
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


  // Member: point
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        seastar_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_DesiredPointing(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: input_state
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        seastar_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_MotorCommand(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _PointMotors_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const seastar_interfaces::srv::PointMotors_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PointMotors_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<seastar_interfaces::srv::PointMotors_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PointMotors_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const seastar_interfaces::srv::PointMotors_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PointMotors_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_PointMotors_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _PointMotors_Request__callbacks = {
  "seastar_interfaces::srv",
  "PointMotors_Request",
  _PointMotors_Request__cdr_serialize,
  _PointMotors_Request__cdr_deserialize,
  _PointMotors_Request__get_serialized_size,
  _PointMotors_Request__max_serialized_size
};

static rosidl_message_type_support_t _PointMotors_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PointMotors_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace seastar_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_seastar_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<seastar_interfaces::srv::PointMotors_Request>()
{
  return &seastar_interfaces::srv::typesupport_fastrtps_cpp::_PointMotors_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, seastar_interfaces, srv, PointMotors_Request)() {
  return &seastar_interfaces::srv::typesupport_fastrtps_cpp::_PointMotors_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace seastar_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const seastar_interfaces::msg::MotorCommand &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  seastar_interfaces::msg::MotorCommand &);
size_t get_serialized_size(
  const seastar_interfaces::msg::MotorCommand &,
  size_t current_alignment);
size_t
max_serialized_size_MotorCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace seastar_interfaces


namespace seastar_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_seastar_interfaces
cdr_serialize(
  const seastar_interfaces::srv::PointMotors_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: command
  seastar_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.command,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_seastar_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  seastar_interfaces::srv::PointMotors_Response & ros_message)
{
  // Member: command
  seastar_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.command);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_seastar_interfaces
get_serialized_size(
  const seastar_interfaces::srv::PointMotors_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: command

  current_alignment +=
    seastar_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.command, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_seastar_interfaces
max_serialized_size_PointMotors_Response(
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


  // Member: command
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        seastar_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_MotorCommand(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _PointMotors_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const seastar_interfaces::srv::PointMotors_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PointMotors_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<seastar_interfaces::srv::PointMotors_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PointMotors_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const seastar_interfaces::srv::PointMotors_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PointMotors_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_PointMotors_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _PointMotors_Response__callbacks = {
  "seastar_interfaces::srv",
  "PointMotors_Response",
  _PointMotors_Response__cdr_serialize,
  _PointMotors_Response__cdr_deserialize,
  _PointMotors_Response__get_serialized_size,
  _PointMotors_Response__max_serialized_size
};

static rosidl_message_type_support_t _PointMotors_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PointMotors_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace seastar_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_seastar_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<seastar_interfaces::srv::PointMotors_Response>()
{
  return &seastar_interfaces::srv::typesupport_fastrtps_cpp::_PointMotors_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, seastar_interfaces, srv, PointMotors_Response)() {
  return &seastar_interfaces::srv::typesupport_fastrtps_cpp::_PointMotors_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace seastar_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _PointMotors__callbacks = {
  "seastar_interfaces::srv",
  "PointMotors",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, seastar_interfaces, srv, PointMotors_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, seastar_interfaces, srv, PointMotors_Response)(),
};

static rosidl_service_type_support_t _PointMotors__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PointMotors__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace seastar_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_seastar_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<seastar_interfaces::srv::PointMotors>()
{
  return &seastar_interfaces::srv::typesupport_fastrtps_cpp::_PointMotors__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, seastar_interfaces, srv, PointMotors)() {
  return &seastar_interfaces::srv::typesupport_fastrtps_cpp::_PointMotors__handle;
}

#ifdef __cplusplus
}
#endif

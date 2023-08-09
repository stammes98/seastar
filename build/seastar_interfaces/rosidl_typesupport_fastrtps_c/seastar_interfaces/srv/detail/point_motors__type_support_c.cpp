// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from seastar_interfaces:srv/PointMotors.idl
// generated code does not contain a copyright notice
#include "seastar_interfaces/srv/detail/point_motors__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "seastar_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "seastar_interfaces/srv/detail/point_motors__struct.h"
#include "seastar_interfaces/srv/detail/point_motors__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "seastar_interfaces/msg/detail/desired_pointing__functions.h"  // point
#include "seastar_interfaces/msg/detail/motor_command__functions.h"  // input_state

// forward declare type support functions
size_t get_serialized_size_seastar_interfaces__msg__DesiredPointing(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_seastar_interfaces__msg__DesiredPointing(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, seastar_interfaces, msg, DesiredPointing)();
size_t get_serialized_size_seastar_interfaces__msg__MotorCommand(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_seastar_interfaces__msg__MotorCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, seastar_interfaces, msg, MotorCommand)();


using _PointMotors_Request__ros_msg_type = seastar_interfaces__srv__PointMotors_Request;

static bool _PointMotors_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PointMotors_Request__ros_msg_type * ros_message = static_cast<const _PointMotors_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: point
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, seastar_interfaces, msg, DesiredPointing
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->point, cdr))
    {
      return false;
    }
  }

  // Field name: input_state
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, seastar_interfaces, msg, MotorCommand
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->input_state, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _PointMotors_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PointMotors_Request__ros_msg_type * ros_message = static_cast<_PointMotors_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: point
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, seastar_interfaces, msg, DesiredPointing
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->point))
    {
      return false;
    }
  }

  // Field name: input_state
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, seastar_interfaces, msg, MotorCommand
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->input_state))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_seastar_interfaces
size_t get_serialized_size_seastar_interfaces__srv__PointMotors_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PointMotors_Request__ros_msg_type * ros_message = static_cast<const _PointMotors_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name point

  current_alignment += get_serialized_size_seastar_interfaces__msg__DesiredPointing(
    &(ros_message->point), current_alignment);
  // field.name input_state

  current_alignment += get_serialized_size_seastar_interfaces__msg__MotorCommand(
    &(ros_message->input_state), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _PointMotors_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_seastar_interfaces__srv__PointMotors_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_seastar_interfaces
size_t max_serialized_size_seastar_interfaces__srv__PointMotors_Request(
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

  // member: point
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_seastar_interfaces__msg__DesiredPointing(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: input_state
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_seastar_interfaces__msg__MotorCommand(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _PointMotors_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_seastar_interfaces__srv__PointMotors_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PointMotors_Request = {
  "seastar_interfaces::srv",
  "PointMotors_Request",
  _PointMotors_Request__cdr_serialize,
  _PointMotors_Request__cdr_deserialize,
  _PointMotors_Request__get_serialized_size,
  _PointMotors_Request__max_serialized_size
};

static rosidl_message_type_support_t _PointMotors_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PointMotors_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, seastar_interfaces, srv, PointMotors_Request)() {
  return &_PointMotors_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "seastar_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "seastar_interfaces/srv/detail/point_motors__struct.h"
// already included above
// #include "seastar_interfaces/srv/detail/point_motors__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "seastar_interfaces/msg/detail/motor_command__functions.h"  // command

// forward declare type support functions
size_t get_serialized_size_seastar_interfaces__msg__MotorCommand(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_seastar_interfaces__msg__MotorCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, seastar_interfaces, msg, MotorCommand)();


using _PointMotors_Response__ros_msg_type = seastar_interfaces__srv__PointMotors_Response;

static bool _PointMotors_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PointMotors_Response__ros_msg_type * ros_message = static_cast<const _PointMotors_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: command
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, seastar_interfaces, msg, MotorCommand
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->command, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _PointMotors_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PointMotors_Response__ros_msg_type * ros_message = static_cast<_PointMotors_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: command
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, seastar_interfaces, msg, MotorCommand
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->command))
    {
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_seastar_interfaces
size_t get_serialized_size_seastar_interfaces__srv__PointMotors_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PointMotors_Response__ros_msg_type * ros_message = static_cast<const _PointMotors_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name command

  current_alignment += get_serialized_size_seastar_interfaces__msg__MotorCommand(
    &(ros_message->command), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _PointMotors_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_seastar_interfaces__srv__PointMotors_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_seastar_interfaces
size_t max_serialized_size_seastar_interfaces__srv__PointMotors_Response(
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

  // member: command
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        max_serialized_size_seastar_interfaces__msg__MotorCommand(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _PointMotors_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_seastar_interfaces__srv__PointMotors_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PointMotors_Response = {
  "seastar_interfaces::srv",
  "PointMotors_Response",
  _PointMotors_Response__cdr_serialize,
  _PointMotors_Response__cdr_deserialize,
  _PointMotors_Response__get_serialized_size,
  _PointMotors_Response__max_serialized_size
};

static rosidl_message_type_support_t _PointMotors_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PointMotors_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, seastar_interfaces, srv, PointMotors_Response)() {
  return &_PointMotors_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "seastar_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "seastar_interfaces/srv/point_motors.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t PointMotors__callbacks = {
  "seastar_interfaces::srv",
  "PointMotors",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, seastar_interfaces, srv, PointMotors_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, seastar_interfaces, srv, PointMotors_Response)(),
};

static rosidl_service_type_support_t PointMotors__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &PointMotors__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, seastar_interfaces, srv, PointMotors)() {
  return &PointMotors__handle;
}

#if defined(__cplusplus)
}
#endif

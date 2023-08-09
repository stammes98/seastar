// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from seastar_interfaces:msg/SkyScanOffsetAngles.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "seastar_interfaces/msg/detail/sky_scan_offset_angles__rosidl_typesupport_introspection_c.h"
#include "seastar_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "seastar_interfaces/msg/detail/sky_scan_offset_angles__functions.h"
#include "seastar_interfaces/msg/detail/sky_scan_offset_angles__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void seastar_interfaces__msg__SkyScanOffsetAngles__rosidl_typesupport_introspection_c__SkyScanOffsetAngles_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  seastar_interfaces__msg__SkyScanOffsetAngles__init(message_memory);
}

void seastar_interfaces__msg__SkyScanOffsetAngles__rosidl_typesupport_introspection_c__SkyScanOffsetAngles_fini_function(void * message_memory)
{
  seastar_interfaces__msg__SkyScanOffsetAngles__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember seastar_interfaces__msg__SkyScanOffsetAngles__rosidl_typesupport_introspection_c__SkyScanOffsetAngles_message_member_array[3] = {
  {
    "azimuth",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(seastar_interfaces__msg__SkyScanOffsetAngles, azimuth),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "elevation",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(seastar_interfaces__msg__SkyScanOffsetAngles, elevation),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stokes_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(seastar_interfaces__msg__SkyScanOffsetAngles, stokes_angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers seastar_interfaces__msg__SkyScanOffsetAngles__rosidl_typesupport_introspection_c__SkyScanOffsetAngles_message_members = {
  "seastar_interfaces__msg",  // message namespace
  "SkyScanOffsetAngles",  // message name
  3,  // number of fields
  sizeof(seastar_interfaces__msg__SkyScanOffsetAngles),
  seastar_interfaces__msg__SkyScanOffsetAngles__rosidl_typesupport_introspection_c__SkyScanOffsetAngles_message_member_array,  // message members
  seastar_interfaces__msg__SkyScanOffsetAngles__rosidl_typesupport_introspection_c__SkyScanOffsetAngles_init_function,  // function to initialize message memory (memory has to be allocated)
  seastar_interfaces__msg__SkyScanOffsetAngles__rosidl_typesupport_introspection_c__SkyScanOffsetAngles_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t seastar_interfaces__msg__SkyScanOffsetAngles__rosidl_typesupport_introspection_c__SkyScanOffsetAngles_message_type_support_handle = {
  0,
  &seastar_interfaces__msg__SkyScanOffsetAngles__rosidl_typesupport_introspection_c__SkyScanOffsetAngles_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_seastar_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, seastar_interfaces, msg, SkyScanOffsetAngles)() {
  if (!seastar_interfaces__msg__SkyScanOffsetAngles__rosidl_typesupport_introspection_c__SkyScanOffsetAngles_message_type_support_handle.typesupport_identifier) {
    seastar_interfaces__msg__SkyScanOffsetAngles__rosidl_typesupport_introspection_c__SkyScanOffsetAngles_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &seastar_interfaces__msg__SkyScanOffsetAngles__rosidl_typesupport_introspection_c__SkyScanOffsetAngles_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
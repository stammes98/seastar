// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from seastar_interfaces:srv/PointMotors.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__SRV__DETAIL__POINT_MOTORS__STRUCT_H_
#define SEASTAR_INTERFACES__SRV__DETAIL__POINT_MOTORS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'point'
#include "seastar_interfaces/msg/detail/desired_pointing__struct.h"
// Member 'input_state'
#include "seastar_interfaces/msg/detail/motor_command__struct.h"

/// Struct defined in srv/PointMotors in the package seastar_interfaces.
typedef struct seastar_interfaces__srv__PointMotors_Request
{
  seastar_interfaces__msg__DesiredPointing point;
  seastar_interfaces__msg__MotorCommand input_state;
} seastar_interfaces__srv__PointMotors_Request;

// Struct for a sequence of seastar_interfaces__srv__PointMotors_Request.
typedef struct seastar_interfaces__srv__PointMotors_Request__Sequence
{
  seastar_interfaces__srv__PointMotors_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} seastar_interfaces__srv__PointMotors_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'command'
// already included above
// #include "seastar_interfaces/msg/detail/motor_command__struct.h"

/// Struct defined in srv/PointMotors in the package seastar_interfaces.
typedef struct seastar_interfaces__srv__PointMotors_Response
{
  seastar_interfaces__msg__MotorCommand command;
} seastar_interfaces__srv__PointMotors_Response;

// Struct for a sequence of seastar_interfaces__srv__PointMotors_Response.
typedef struct seastar_interfaces__srv__PointMotors_Response__Sequence
{
  seastar_interfaces__srv__PointMotors_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} seastar_interfaces__srv__PointMotors_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SEASTAR_INTERFACES__SRV__DETAIL__POINT_MOTORS__STRUCT_H_

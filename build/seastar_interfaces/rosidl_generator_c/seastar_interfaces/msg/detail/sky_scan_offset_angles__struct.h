// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from seastar_interfaces:msg/SkyScanOffsetAngles.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET_ANGLES__STRUCT_H_
#define SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET_ANGLES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SkyScanOffsetAngles in the package seastar_interfaces.
typedef struct seastar_interfaces__msg__SkyScanOffsetAngles
{
  double azimuth;
  double elevation;
  double stokes_angle;
} seastar_interfaces__msg__SkyScanOffsetAngles;

// Struct for a sequence of seastar_interfaces__msg__SkyScanOffsetAngles.
typedef struct seastar_interfaces__msg__SkyScanOffsetAngles__Sequence
{
  seastar_interfaces__msg__SkyScanOffsetAngles * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} seastar_interfaces__msg__SkyScanOffsetAngles__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET_ANGLES__STRUCT_H_

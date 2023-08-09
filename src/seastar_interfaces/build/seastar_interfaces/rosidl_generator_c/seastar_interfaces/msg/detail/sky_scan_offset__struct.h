// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from seastar_interfaces:msg/SkyScanOffset.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__STRUCT_H_
#define SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SkyScanOffset in the package seastar_interfaces.
typedef struct seastar_interfaces__msg__SkyScanOffset
{
  double azimuth_offset;
  double elevation_offset;
  double stokes_angle_offset;
} seastar_interfaces__msg__SkyScanOffset;

// Struct for a sequence of seastar_interfaces__msg__SkyScanOffset.
typedef struct seastar_interfaces__msg__SkyScanOffset__Sequence
{
  seastar_interfaces__msg__SkyScanOffset * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} seastar_interfaces__msg__SkyScanOffset__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__STRUCT_H_

// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from seastar_interfaces:msg/SkyEphemeris.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__SKY_EPHEMERIS__STRUCT_H_
#define SEASTAR_INTERFACES__MSG__DETAIL__SKY_EPHEMERIS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SkyEphemeris in the package seastar_interfaces.
typedef struct seastar_interfaces__msg__SkyEphemeris
{
  double azimuth;
  double elevation;
} seastar_interfaces__msg__SkyEphemeris;

// Struct for a sequence of seastar_interfaces__msg__SkyEphemeris.
typedef struct seastar_interfaces__msg__SkyEphemeris__Sequence
{
  seastar_interfaces__msg__SkyEphemeris * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} seastar_interfaces__msg__SkyEphemeris__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__SKY_EPHEMERIS__STRUCT_H_

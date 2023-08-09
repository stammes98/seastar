// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from seastar_interfaces:msg/SkyEphemeris.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__SKY_EPHEMERIS__FUNCTIONS_H_
#define SEASTAR_INTERFACES__MSG__DETAIL__SKY_EPHEMERIS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "seastar_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "seastar_interfaces/msg/detail/sky_ephemeris__struct.h"

/// Initialize msg/SkyEphemeris message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * seastar_interfaces__msg__SkyEphemeris
 * )) before or use
 * seastar_interfaces__msg__SkyEphemeris__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
bool
seastar_interfaces__msg__SkyEphemeris__init(seastar_interfaces__msg__SkyEphemeris * msg);

/// Finalize msg/SkyEphemeris message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
void
seastar_interfaces__msg__SkyEphemeris__fini(seastar_interfaces__msg__SkyEphemeris * msg);

/// Create msg/SkyEphemeris message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * seastar_interfaces__msg__SkyEphemeris__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
seastar_interfaces__msg__SkyEphemeris *
seastar_interfaces__msg__SkyEphemeris__create();

/// Destroy msg/SkyEphemeris message.
/**
 * It calls
 * seastar_interfaces__msg__SkyEphemeris__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
void
seastar_interfaces__msg__SkyEphemeris__destroy(seastar_interfaces__msg__SkyEphemeris * msg);

/// Check for msg/SkyEphemeris message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
bool
seastar_interfaces__msg__SkyEphemeris__are_equal(const seastar_interfaces__msg__SkyEphemeris * lhs, const seastar_interfaces__msg__SkyEphemeris * rhs);

/// Copy a msg/SkyEphemeris message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
bool
seastar_interfaces__msg__SkyEphemeris__copy(
  const seastar_interfaces__msg__SkyEphemeris * input,
  seastar_interfaces__msg__SkyEphemeris * output);

/// Initialize array of msg/SkyEphemeris messages.
/**
 * It allocates the memory for the number of elements and calls
 * seastar_interfaces__msg__SkyEphemeris__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
bool
seastar_interfaces__msg__SkyEphemeris__Sequence__init(seastar_interfaces__msg__SkyEphemeris__Sequence * array, size_t size);

/// Finalize array of msg/SkyEphemeris messages.
/**
 * It calls
 * seastar_interfaces__msg__SkyEphemeris__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
void
seastar_interfaces__msg__SkyEphemeris__Sequence__fini(seastar_interfaces__msg__SkyEphemeris__Sequence * array);

/// Create array of msg/SkyEphemeris messages.
/**
 * It allocates the memory for the array and calls
 * seastar_interfaces__msg__SkyEphemeris__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
seastar_interfaces__msg__SkyEphemeris__Sequence *
seastar_interfaces__msg__SkyEphemeris__Sequence__create(size_t size);

/// Destroy array of msg/SkyEphemeris messages.
/**
 * It calls
 * seastar_interfaces__msg__SkyEphemeris__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
void
seastar_interfaces__msg__SkyEphemeris__Sequence__destroy(seastar_interfaces__msg__SkyEphemeris__Sequence * array);

/// Check for msg/SkyEphemeris message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
bool
seastar_interfaces__msg__SkyEphemeris__Sequence__are_equal(const seastar_interfaces__msg__SkyEphemeris__Sequence * lhs, const seastar_interfaces__msg__SkyEphemeris__Sequence * rhs);

/// Copy an array of msg/SkyEphemeris messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
bool
seastar_interfaces__msg__SkyEphemeris__Sequence__copy(
  const seastar_interfaces__msg__SkyEphemeris__Sequence * input,
  seastar_interfaces__msg__SkyEphemeris__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__SKY_EPHEMERIS__FUNCTIONS_H_

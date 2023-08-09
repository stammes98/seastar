// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from seastar_interfaces:msg/SkyScanOffset.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__FUNCTIONS_H_
#define SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "seastar_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "seastar_interfaces/msg/detail/sky_scan_offset__struct.h"

/// Initialize msg/SkyScanOffset message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * seastar_interfaces__msg__SkyScanOffset
 * )) before or use
 * seastar_interfaces__msg__SkyScanOffset__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
bool
seastar_interfaces__msg__SkyScanOffset__init(seastar_interfaces__msg__SkyScanOffset * msg);

/// Finalize msg/SkyScanOffset message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
void
seastar_interfaces__msg__SkyScanOffset__fini(seastar_interfaces__msg__SkyScanOffset * msg);

/// Create msg/SkyScanOffset message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * seastar_interfaces__msg__SkyScanOffset__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
seastar_interfaces__msg__SkyScanOffset *
seastar_interfaces__msg__SkyScanOffset__create();

/// Destroy msg/SkyScanOffset message.
/**
 * It calls
 * seastar_interfaces__msg__SkyScanOffset__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
void
seastar_interfaces__msg__SkyScanOffset__destroy(seastar_interfaces__msg__SkyScanOffset * msg);

/// Check for msg/SkyScanOffset message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
bool
seastar_interfaces__msg__SkyScanOffset__are_equal(const seastar_interfaces__msg__SkyScanOffset * lhs, const seastar_interfaces__msg__SkyScanOffset * rhs);

/// Copy a msg/SkyScanOffset message.
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
seastar_interfaces__msg__SkyScanOffset__copy(
  const seastar_interfaces__msg__SkyScanOffset * input,
  seastar_interfaces__msg__SkyScanOffset * output);

/// Initialize array of msg/SkyScanOffset messages.
/**
 * It allocates the memory for the number of elements and calls
 * seastar_interfaces__msg__SkyScanOffset__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
bool
seastar_interfaces__msg__SkyScanOffset__Sequence__init(seastar_interfaces__msg__SkyScanOffset__Sequence * array, size_t size);

/// Finalize array of msg/SkyScanOffset messages.
/**
 * It calls
 * seastar_interfaces__msg__SkyScanOffset__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
void
seastar_interfaces__msg__SkyScanOffset__Sequence__fini(seastar_interfaces__msg__SkyScanOffset__Sequence * array);

/// Create array of msg/SkyScanOffset messages.
/**
 * It allocates the memory for the array and calls
 * seastar_interfaces__msg__SkyScanOffset__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
seastar_interfaces__msg__SkyScanOffset__Sequence *
seastar_interfaces__msg__SkyScanOffset__Sequence__create(size_t size);

/// Destroy array of msg/SkyScanOffset messages.
/**
 * It calls
 * seastar_interfaces__msg__SkyScanOffset__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
void
seastar_interfaces__msg__SkyScanOffset__Sequence__destroy(seastar_interfaces__msg__SkyScanOffset__Sequence * array);

/// Check for msg/SkyScanOffset message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_seastar_interfaces
bool
seastar_interfaces__msg__SkyScanOffset__Sequence__are_equal(const seastar_interfaces__msg__SkyScanOffset__Sequence * lhs, const seastar_interfaces__msg__SkyScanOffset__Sequence * rhs);

/// Copy an array of msg/SkyScanOffset messages.
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
seastar_interfaces__msg__SkyScanOffset__Sequence__copy(
  const seastar_interfaces__msg__SkyScanOffset__Sequence * input,
  seastar_interfaces__msg__SkyScanOffset__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__FUNCTIONS_H_

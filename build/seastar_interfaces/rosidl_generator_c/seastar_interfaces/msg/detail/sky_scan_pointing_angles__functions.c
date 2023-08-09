// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from seastar_interfaces:msg/SkyScanPointingAngles.idl
// generated code does not contain a copyright notice
#include "seastar_interfaces/msg/detail/sky_scan_pointing_angles__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
seastar_interfaces__msg__SkyScanPointingAngles__init(seastar_interfaces__msg__SkyScanPointingAngles * msg)
{
  if (!msg) {
    return false;
  }
  // azimuth
  // elevation
  // stokes_angle
  return true;
}

void
seastar_interfaces__msg__SkyScanPointingAngles__fini(seastar_interfaces__msg__SkyScanPointingAngles * msg)
{
  if (!msg) {
    return;
  }
  // azimuth
  // elevation
  // stokes_angle
}

bool
seastar_interfaces__msg__SkyScanPointingAngles__are_equal(const seastar_interfaces__msg__SkyScanPointingAngles * lhs, const seastar_interfaces__msg__SkyScanPointingAngles * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // azimuth
  if (lhs->azimuth != rhs->azimuth) {
    return false;
  }
  // elevation
  if (lhs->elevation != rhs->elevation) {
    return false;
  }
  // stokes_angle
  if (lhs->stokes_angle != rhs->stokes_angle) {
    return false;
  }
  return true;
}

bool
seastar_interfaces__msg__SkyScanPointingAngles__copy(
  const seastar_interfaces__msg__SkyScanPointingAngles * input,
  seastar_interfaces__msg__SkyScanPointingAngles * output)
{
  if (!input || !output) {
    return false;
  }
  // azimuth
  output->azimuth = input->azimuth;
  // elevation
  output->elevation = input->elevation;
  // stokes_angle
  output->stokes_angle = input->stokes_angle;
  return true;
}

seastar_interfaces__msg__SkyScanPointingAngles *
seastar_interfaces__msg__SkyScanPointingAngles__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__msg__SkyScanPointingAngles * msg = (seastar_interfaces__msg__SkyScanPointingAngles *)allocator.allocate(sizeof(seastar_interfaces__msg__SkyScanPointingAngles), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(seastar_interfaces__msg__SkyScanPointingAngles));
  bool success = seastar_interfaces__msg__SkyScanPointingAngles__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
seastar_interfaces__msg__SkyScanPointingAngles__destroy(seastar_interfaces__msg__SkyScanPointingAngles * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    seastar_interfaces__msg__SkyScanPointingAngles__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
seastar_interfaces__msg__SkyScanPointingAngles__Sequence__init(seastar_interfaces__msg__SkyScanPointingAngles__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__msg__SkyScanPointingAngles * data = NULL;

  if (size) {
    data = (seastar_interfaces__msg__SkyScanPointingAngles *)allocator.zero_allocate(size, sizeof(seastar_interfaces__msg__SkyScanPointingAngles), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = seastar_interfaces__msg__SkyScanPointingAngles__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        seastar_interfaces__msg__SkyScanPointingAngles__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
seastar_interfaces__msg__SkyScanPointingAngles__Sequence__fini(seastar_interfaces__msg__SkyScanPointingAngles__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      seastar_interfaces__msg__SkyScanPointingAngles__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

seastar_interfaces__msg__SkyScanPointingAngles__Sequence *
seastar_interfaces__msg__SkyScanPointingAngles__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__msg__SkyScanPointingAngles__Sequence * array = (seastar_interfaces__msg__SkyScanPointingAngles__Sequence *)allocator.allocate(sizeof(seastar_interfaces__msg__SkyScanPointingAngles__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = seastar_interfaces__msg__SkyScanPointingAngles__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
seastar_interfaces__msg__SkyScanPointingAngles__Sequence__destroy(seastar_interfaces__msg__SkyScanPointingAngles__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    seastar_interfaces__msg__SkyScanPointingAngles__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
seastar_interfaces__msg__SkyScanPointingAngles__Sequence__are_equal(const seastar_interfaces__msg__SkyScanPointingAngles__Sequence * lhs, const seastar_interfaces__msg__SkyScanPointingAngles__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!seastar_interfaces__msg__SkyScanPointingAngles__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
seastar_interfaces__msg__SkyScanPointingAngles__Sequence__copy(
  const seastar_interfaces__msg__SkyScanPointingAngles__Sequence * input,
  seastar_interfaces__msg__SkyScanPointingAngles__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(seastar_interfaces__msg__SkyScanPointingAngles);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    seastar_interfaces__msg__SkyScanPointingAngles * data =
      (seastar_interfaces__msg__SkyScanPointingAngles *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!seastar_interfaces__msg__SkyScanPointingAngles__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          seastar_interfaces__msg__SkyScanPointingAngles__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!seastar_interfaces__msg__SkyScanPointingAngles__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

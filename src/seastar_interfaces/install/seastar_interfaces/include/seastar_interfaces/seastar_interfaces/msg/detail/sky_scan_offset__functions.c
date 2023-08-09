// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from seastar_interfaces:msg/SkyScanOffset.idl
// generated code does not contain a copyright notice
#include "seastar_interfaces/msg/detail/sky_scan_offset__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
seastar_interfaces__msg__SkyScanOffset__init(seastar_interfaces__msg__SkyScanOffset * msg)
{
  if (!msg) {
    return false;
  }
  // azimuth_offset
  // elevation_offset
  // stokes_angle_offset
  return true;
}

void
seastar_interfaces__msg__SkyScanOffset__fini(seastar_interfaces__msg__SkyScanOffset * msg)
{
  if (!msg) {
    return;
  }
  // azimuth_offset
  // elevation_offset
  // stokes_angle_offset
}

bool
seastar_interfaces__msg__SkyScanOffset__are_equal(const seastar_interfaces__msg__SkyScanOffset * lhs, const seastar_interfaces__msg__SkyScanOffset * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // azimuth_offset
  if (lhs->azimuth_offset != rhs->azimuth_offset) {
    return false;
  }
  // elevation_offset
  if (lhs->elevation_offset != rhs->elevation_offset) {
    return false;
  }
  // stokes_angle_offset
  if (lhs->stokes_angle_offset != rhs->stokes_angle_offset) {
    return false;
  }
  return true;
}

bool
seastar_interfaces__msg__SkyScanOffset__copy(
  const seastar_interfaces__msg__SkyScanOffset * input,
  seastar_interfaces__msg__SkyScanOffset * output)
{
  if (!input || !output) {
    return false;
  }
  // azimuth_offset
  output->azimuth_offset = input->azimuth_offset;
  // elevation_offset
  output->elevation_offset = input->elevation_offset;
  // stokes_angle_offset
  output->stokes_angle_offset = input->stokes_angle_offset;
  return true;
}

seastar_interfaces__msg__SkyScanOffset *
seastar_interfaces__msg__SkyScanOffset__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__msg__SkyScanOffset * msg = (seastar_interfaces__msg__SkyScanOffset *)allocator.allocate(sizeof(seastar_interfaces__msg__SkyScanOffset), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(seastar_interfaces__msg__SkyScanOffset));
  bool success = seastar_interfaces__msg__SkyScanOffset__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
seastar_interfaces__msg__SkyScanOffset__destroy(seastar_interfaces__msg__SkyScanOffset * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    seastar_interfaces__msg__SkyScanOffset__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
seastar_interfaces__msg__SkyScanOffset__Sequence__init(seastar_interfaces__msg__SkyScanOffset__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__msg__SkyScanOffset * data = NULL;

  if (size) {
    data = (seastar_interfaces__msg__SkyScanOffset *)allocator.zero_allocate(size, sizeof(seastar_interfaces__msg__SkyScanOffset), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = seastar_interfaces__msg__SkyScanOffset__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        seastar_interfaces__msg__SkyScanOffset__fini(&data[i - 1]);
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
seastar_interfaces__msg__SkyScanOffset__Sequence__fini(seastar_interfaces__msg__SkyScanOffset__Sequence * array)
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
      seastar_interfaces__msg__SkyScanOffset__fini(&array->data[i]);
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

seastar_interfaces__msg__SkyScanOffset__Sequence *
seastar_interfaces__msg__SkyScanOffset__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__msg__SkyScanOffset__Sequence * array = (seastar_interfaces__msg__SkyScanOffset__Sequence *)allocator.allocate(sizeof(seastar_interfaces__msg__SkyScanOffset__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = seastar_interfaces__msg__SkyScanOffset__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
seastar_interfaces__msg__SkyScanOffset__Sequence__destroy(seastar_interfaces__msg__SkyScanOffset__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    seastar_interfaces__msg__SkyScanOffset__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
seastar_interfaces__msg__SkyScanOffset__Sequence__are_equal(const seastar_interfaces__msg__SkyScanOffset__Sequence * lhs, const seastar_interfaces__msg__SkyScanOffset__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!seastar_interfaces__msg__SkyScanOffset__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
seastar_interfaces__msg__SkyScanOffset__Sequence__copy(
  const seastar_interfaces__msg__SkyScanOffset__Sequence * input,
  seastar_interfaces__msg__SkyScanOffset__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(seastar_interfaces__msg__SkyScanOffset);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    seastar_interfaces__msg__SkyScanOffset * data =
      (seastar_interfaces__msg__SkyScanOffset *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!seastar_interfaces__msg__SkyScanOffset__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          seastar_interfaces__msg__SkyScanOffset__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!seastar_interfaces__msg__SkyScanOffset__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

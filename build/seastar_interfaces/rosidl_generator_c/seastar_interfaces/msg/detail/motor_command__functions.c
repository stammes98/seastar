// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from seastar_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice
#include "seastar_interfaces/msg/detail/motor_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
seastar_interfaces__msg__MotorCommand__init(seastar_interfaces__msg__MotorCommand * msg)
{
  if (!msg) {
    return false;
  }
  // q1
  // q2
  // q3
  return true;
}

void
seastar_interfaces__msg__MotorCommand__fini(seastar_interfaces__msg__MotorCommand * msg)
{
  if (!msg) {
    return;
  }
  // q1
  // q2
  // q3
}

bool
seastar_interfaces__msg__MotorCommand__are_equal(const seastar_interfaces__msg__MotorCommand * lhs, const seastar_interfaces__msg__MotorCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // q1
  if (lhs->q1 != rhs->q1) {
    return false;
  }
  // q2
  if (lhs->q2 != rhs->q2) {
    return false;
  }
  // q3
  if (lhs->q3 != rhs->q3) {
    return false;
  }
  return true;
}

bool
seastar_interfaces__msg__MotorCommand__copy(
  const seastar_interfaces__msg__MotorCommand * input,
  seastar_interfaces__msg__MotorCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // q1
  output->q1 = input->q1;
  // q2
  output->q2 = input->q2;
  // q3
  output->q3 = input->q3;
  return true;
}

seastar_interfaces__msg__MotorCommand *
seastar_interfaces__msg__MotorCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__msg__MotorCommand * msg = (seastar_interfaces__msg__MotorCommand *)allocator.allocate(sizeof(seastar_interfaces__msg__MotorCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(seastar_interfaces__msg__MotorCommand));
  bool success = seastar_interfaces__msg__MotorCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
seastar_interfaces__msg__MotorCommand__destroy(seastar_interfaces__msg__MotorCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    seastar_interfaces__msg__MotorCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
seastar_interfaces__msg__MotorCommand__Sequence__init(seastar_interfaces__msg__MotorCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__msg__MotorCommand * data = NULL;

  if (size) {
    data = (seastar_interfaces__msg__MotorCommand *)allocator.zero_allocate(size, sizeof(seastar_interfaces__msg__MotorCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = seastar_interfaces__msg__MotorCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        seastar_interfaces__msg__MotorCommand__fini(&data[i - 1]);
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
seastar_interfaces__msg__MotorCommand__Sequence__fini(seastar_interfaces__msg__MotorCommand__Sequence * array)
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
      seastar_interfaces__msg__MotorCommand__fini(&array->data[i]);
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

seastar_interfaces__msg__MotorCommand__Sequence *
seastar_interfaces__msg__MotorCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__msg__MotorCommand__Sequence * array = (seastar_interfaces__msg__MotorCommand__Sequence *)allocator.allocate(sizeof(seastar_interfaces__msg__MotorCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = seastar_interfaces__msg__MotorCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
seastar_interfaces__msg__MotorCommand__Sequence__destroy(seastar_interfaces__msg__MotorCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    seastar_interfaces__msg__MotorCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
seastar_interfaces__msg__MotorCommand__Sequence__are_equal(const seastar_interfaces__msg__MotorCommand__Sequence * lhs, const seastar_interfaces__msg__MotorCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!seastar_interfaces__msg__MotorCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
seastar_interfaces__msg__MotorCommand__Sequence__copy(
  const seastar_interfaces__msg__MotorCommand__Sequence * input,
  seastar_interfaces__msg__MotorCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(seastar_interfaces__msg__MotorCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    seastar_interfaces__msg__MotorCommand * data =
      (seastar_interfaces__msg__MotorCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!seastar_interfaces__msg__MotorCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          seastar_interfaces__msg__MotorCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!seastar_interfaces__msg__MotorCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

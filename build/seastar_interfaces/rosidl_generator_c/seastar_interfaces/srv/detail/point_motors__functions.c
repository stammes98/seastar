// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from seastar_interfaces:srv/PointMotors.idl
// generated code does not contain a copyright notice
#include "seastar_interfaces/srv/detail/point_motors__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `point`
#include "seastar_interfaces/msg/detail/desired_pointing__functions.h"
// Member `input_state`
#include "seastar_interfaces/msg/detail/motor_command__functions.h"

bool
seastar_interfaces__srv__PointMotors_Request__init(seastar_interfaces__srv__PointMotors_Request * msg)
{
  if (!msg) {
    return false;
  }
  // point
  if (!seastar_interfaces__msg__DesiredPointing__init(&msg->point)) {
    seastar_interfaces__srv__PointMotors_Request__fini(msg);
    return false;
  }
  // input_state
  if (!seastar_interfaces__msg__MotorCommand__init(&msg->input_state)) {
    seastar_interfaces__srv__PointMotors_Request__fini(msg);
    return false;
  }
  return true;
}

void
seastar_interfaces__srv__PointMotors_Request__fini(seastar_interfaces__srv__PointMotors_Request * msg)
{
  if (!msg) {
    return;
  }
  // point
  seastar_interfaces__msg__DesiredPointing__fini(&msg->point);
  // input_state
  seastar_interfaces__msg__MotorCommand__fini(&msg->input_state);
}

bool
seastar_interfaces__srv__PointMotors_Request__are_equal(const seastar_interfaces__srv__PointMotors_Request * lhs, const seastar_interfaces__srv__PointMotors_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // point
  if (!seastar_interfaces__msg__DesiredPointing__are_equal(
      &(lhs->point), &(rhs->point)))
  {
    return false;
  }
  // input_state
  if (!seastar_interfaces__msg__MotorCommand__are_equal(
      &(lhs->input_state), &(rhs->input_state)))
  {
    return false;
  }
  return true;
}

bool
seastar_interfaces__srv__PointMotors_Request__copy(
  const seastar_interfaces__srv__PointMotors_Request * input,
  seastar_interfaces__srv__PointMotors_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // point
  if (!seastar_interfaces__msg__DesiredPointing__copy(
      &(input->point), &(output->point)))
  {
    return false;
  }
  // input_state
  if (!seastar_interfaces__msg__MotorCommand__copy(
      &(input->input_state), &(output->input_state)))
  {
    return false;
  }
  return true;
}

seastar_interfaces__srv__PointMotors_Request *
seastar_interfaces__srv__PointMotors_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__srv__PointMotors_Request * msg = (seastar_interfaces__srv__PointMotors_Request *)allocator.allocate(sizeof(seastar_interfaces__srv__PointMotors_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(seastar_interfaces__srv__PointMotors_Request));
  bool success = seastar_interfaces__srv__PointMotors_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
seastar_interfaces__srv__PointMotors_Request__destroy(seastar_interfaces__srv__PointMotors_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    seastar_interfaces__srv__PointMotors_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
seastar_interfaces__srv__PointMotors_Request__Sequence__init(seastar_interfaces__srv__PointMotors_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__srv__PointMotors_Request * data = NULL;

  if (size) {
    data = (seastar_interfaces__srv__PointMotors_Request *)allocator.zero_allocate(size, sizeof(seastar_interfaces__srv__PointMotors_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = seastar_interfaces__srv__PointMotors_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        seastar_interfaces__srv__PointMotors_Request__fini(&data[i - 1]);
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
seastar_interfaces__srv__PointMotors_Request__Sequence__fini(seastar_interfaces__srv__PointMotors_Request__Sequence * array)
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
      seastar_interfaces__srv__PointMotors_Request__fini(&array->data[i]);
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

seastar_interfaces__srv__PointMotors_Request__Sequence *
seastar_interfaces__srv__PointMotors_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__srv__PointMotors_Request__Sequence * array = (seastar_interfaces__srv__PointMotors_Request__Sequence *)allocator.allocate(sizeof(seastar_interfaces__srv__PointMotors_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = seastar_interfaces__srv__PointMotors_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
seastar_interfaces__srv__PointMotors_Request__Sequence__destroy(seastar_interfaces__srv__PointMotors_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    seastar_interfaces__srv__PointMotors_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
seastar_interfaces__srv__PointMotors_Request__Sequence__are_equal(const seastar_interfaces__srv__PointMotors_Request__Sequence * lhs, const seastar_interfaces__srv__PointMotors_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!seastar_interfaces__srv__PointMotors_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
seastar_interfaces__srv__PointMotors_Request__Sequence__copy(
  const seastar_interfaces__srv__PointMotors_Request__Sequence * input,
  seastar_interfaces__srv__PointMotors_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(seastar_interfaces__srv__PointMotors_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    seastar_interfaces__srv__PointMotors_Request * data =
      (seastar_interfaces__srv__PointMotors_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!seastar_interfaces__srv__PointMotors_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          seastar_interfaces__srv__PointMotors_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!seastar_interfaces__srv__PointMotors_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `command`
// already included above
// #include "seastar_interfaces/msg/detail/motor_command__functions.h"

bool
seastar_interfaces__srv__PointMotors_Response__init(seastar_interfaces__srv__PointMotors_Response * msg)
{
  if (!msg) {
    return false;
  }
  // command
  if (!seastar_interfaces__msg__MotorCommand__init(&msg->command)) {
    seastar_interfaces__srv__PointMotors_Response__fini(msg);
    return false;
  }
  return true;
}

void
seastar_interfaces__srv__PointMotors_Response__fini(seastar_interfaces__srv__PointMotors_Response * msg)
{
  if (!msg) {
    return;
  }
  // command
  seastar_interfaces__msg__MotorCommand__fini(&msg->command);
}

bool
seastar_interfaces__srv__PointMotors_Response__are_equal(const seastar_interfaces__srv__PointMotors_Response * lhs, const seastar_interfaces__srv__PointMotors_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (!seastar_interfaces__msg__MotorCommand__are_equal(
      &(lhs->command), &(rhs->command)))
  {
    return false;
  }
  return true;
}

bool
seastar_interfaces__srv__PointMotors_Response__copy(
  const seastar_interfaces__srv__PointMotors_Response * input,
  seastar_interfaces__srv__PointMotors_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  if (!seastar_interfaces__msg__MotorCommand__copy(
      &(input->command), &(output->command)))
  {
    return false;
  }
  return true;
}

seastar_interfaces__srv__PointMotors_Response *
seastar_interfaces__srv__PointMotors_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__srv__PointMotors_Response * msg = (seastar_interfaces__srv__PointMotors_Response *)allocator.allocate(sizeof(seastar_interfaces__srv__PointMotors_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(seastar_interfaces__srv__PointMotors_Response));
  bool success = seastar_interfaces__srv__PointMotors_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
seastar_interfaces__srv__PointMotors_Response__destroy(seastar_interfaces__srv__PointMotors_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    seastar_interfaces__srv__PointMotors_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
seastar_interfaces__srv__PointMotors_Response__Sequence__init(seastar_interfaces__srv__PointMotors_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__srv__PointMotors_Response * data = NULL;

  if (size) {
    data = (seastar_interfaces__srv__PointMotors_Response *)allocator.zero_allocate(size, sizeof(seastar_interfaces__srv__PointMotors_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = seastar_interfaces__srv__PointMotors_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        seastar_interfaces__srv__PointMotors_Response__fini(&data[i - 1]);
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
seastar_interfaces__srv__PointMotors_Response__Sequence__fini(seastar_interfaces__srv__PointMotors_Response__Sequence * array)
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
      seastar_interfaces__srv__PointMotors_Response__fini(&array->data[i]);
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

seastar_interfaces__srv__PointMotors_Response__Sequence *
seastar_interfaces__srv__PointMotors_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  seastar_interfaces__srv__PointMotors_Response__Sequence * array = (seastar_interfaces__srv__PointMotors_Response__Sequence *)allocator.allocate(sizeof(seastar_interfaces__srv__PointMotors_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = seastar_interfaces__srv__PointMotors_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
seastar_interfaces__srv__PointMotors_Response__Sequence__destroy(seastar_interfaces__srv__PointMotors_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    seastar_interfaces__srv__PointMotors_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
seastar_interfaces__srv__PointMotors_Response__Sequence__are_equal(const seastar_interfaces__srv__PointMotors_Response__Sequence * lhs, const seastar_interfaces__srv__PointMotors_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!seastar_interfaces__srv__PointMotors_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
seastar_interfaces__srv__PointMotors_Response__Sequence__copy(
  const seastar_interfaces__srv__PointMotors_Response__Sequence * input,
  seastar_interfaces__srv__PointMotors_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(seastar_interfaces__srv__PointMotors_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    seastar_interfaces__srv__PointMotors_Response * data =
      (seastar_interfaces__srv__PointMotors_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!seastar_interfaces__srv__PointMotors_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          seastar_interfaces__srv__PointMotors_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!seastar_interfaces__srv__PointMotors_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

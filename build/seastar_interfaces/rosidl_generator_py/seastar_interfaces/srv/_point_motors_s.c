// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from seastar_interfaces:srv/PointMotors.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "seastar_interfaces/srv/detail/point_motors__struct.h"
#include "seastar_interfaces/srv/detail/point_motors__functions.h"

bool seastar_interfaces__msg__desired_pointing__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * seastar_interfaces__msg__desired_pointing__convert_to_py(void * raw_ros_message);
bool seastar_interfaces__msg__motor_command__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * seastar_interfaces__msg__motor_command__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool seastar_interfaces__srv__point_motors__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[57];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("seastar_interfaces.srv._point_motors.PointMotors_Request", full_classname_dest, 56) == 0);
  }
  seastar_interfaces__srv__PointMotors_Request * ros_message = _ros_message;
  {  // point
    PyObject * field = PyObject_GetAttrString(_pymsg, "point");
    if (!field) {
      return false;
    }
    if (!seastar_interfaces__msg__desired_pointing__convert_from_py(field, &ros_message->point)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // input_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "input_state");
    if (!field) {
      return false;
    }
    if (!seastar_interfaces__msg__motor_command__convert_from_py(field, &ros_message->input_state)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * seastar_interfaces__srv__point_motors__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PointMotors_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("seastar_interfaces.srv._point_motors");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PointMotors_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  seastar_interfaces__srv__PointMotors_Request * ros_message = (seastar_interfaces__srv__PointMotors_Request *)raw_ros_message;
  {  // point
    PyObject * field = NULL;
    field = seastar_interfaces__msg__desired_pointing__convert_to_py(&ros_message->point);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "point", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // input_state
    PyObject * field = NULL;
    field = seastar_interfaces__msg__motor_command__convert_to_py(&ros_message->input_state);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "input_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "seastar_interfaces/srv/detail/point_motors__struct.h"
// already included above
// #include "seastar_interfaces/srv/detail/point_motors__functions.h"

bool seastar_interfaces__msg__motor_command__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * seastar_interfaces__msg__motor_command__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool seastar_interfaces__srv__point_motors__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[58];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("seastar_interfaces.srv._point_motors.PointMotors_Response", full_classname_dest, 57) == 0);
  }
  seastar_interfaces__srv__PointMotors_Response * ros_message = _ros_message;
  {  // command
    PyObject * field = PyObject_GetAttrString(_pymsg, "command");
    if (!field) {
      return false;
    }
    if (!seastar_interfaces__msg__motor_command__convert_from_py(field, &ros_message->command)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * seastar_interfaces__srv__point_motors__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PointMotors_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("seastar_interfaces.srv._point_motors");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PointMotors_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  seastar_interfaces__srv__PointMotors_Response * ros_message = (seastar_interfaces__srv__PointMotors_Response *)raw_ros_message;
  {  // command
    PyObject * field = NULL;
    field = seastar_interfaces__msg__motor_command__convert_to_py(&ros_message->command);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "command", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

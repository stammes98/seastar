// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from seastar_interfaces:msg/SkyScanOffsetAngles.idl
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
#include "seastar_interfaces/msg/detail/sky_scan_offset_angles__struct.h"
#include "seastar_interfaces/msg/detail/sky_scan_offset_angles__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool seastar_interfaces__msg__sky_scan_offset_angles__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[67];
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
    assert(strncmp("seastar_interfaces.msg._sky_scan_offset_angles.SkyScanOffsetAngles", full_classname_dest, 66) == 0);
  }
  seastar_interfaces__msg__SkyScanOffsetAngles * ros_message = _ros_message;
  {  // azimuth
    PyObject * field = PyObject_GetAttrString(_pymsg, "azimuth");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->azimuth = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // elevation
    PyObject * field = PyObject_GetAttrString(_pymsg, "elevation");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->elevation = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // stokes_angle
    PyObject * field = PyObject_GetAttrString(_pymsg, "stokes_angle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->stokes_angle = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * seastar_interfaces__msg__sky_scan_offset_angles__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SkyScanOffsetAngles */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("seastar_interfaces.msg._sky_scan_offset_angles");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SkyScanOffsetAngles");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  seastar_interfaces__msg__SkyScanOffsetAngles * ros_message = (seastar_interfaces__msg__SkyScanOffsetAngles *)raw_ros_message;
  {  // azimuth
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->azimuth);
    {
      int rc = PyObject_SetAttrString(_pymessage, "azimuth", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // elevation
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->elevation);
    {
      int rc = PyObject_SetAttrString(_pymessage, "elevation", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // stokes_angle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->stokes_angle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "stokes_angle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

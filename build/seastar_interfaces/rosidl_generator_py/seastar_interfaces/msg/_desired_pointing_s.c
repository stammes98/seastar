// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from seastar_interfaces:msg/DesiredPointing.idl
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
#include "seastar_interfaces/msg/detail/desired_pointing__struct.h"
#include "seastar_interfaces/msg/detail/desired_pointing__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool seastar_interfaces__msg__desired_pointing__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("seastar_interfaces.msg._desired_pointing.DesiredPointing", full_classname_dest, 56) == 0);
  }
  seastar_interfaces__msg__DesiredPointing * ros_message = _ros_message;
  {  // azimuth
    PyObject * field = PyObject_GetAttrString(_pymsg, "azimuth");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->azimuth = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // altitude
    PyObject * field = PyObject_GetAttrString(_pymsg, "altitude");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->altitude = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // polarization
    PyObject * field = PyObject_GetAttrString(_pymsg, "polarization");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->polarization = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * seastar_interfaces__msg__desired_pointing__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DesiredPointing */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("seastar_interfaces.msg._desired_pointing");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DesiredPointing");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  seastar_interfaces__msg__DesiredPointing * ros_message = (seastar_interfaces__msg__DesiredPointing *)raw_ros_message;
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
  {  // altitude
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->altitude);
    {
      int rc = PyObject_SetAttrString(_pymessage, "altitude", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // polarization
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->polarization);
    {
      int rc = PyObject_SetAttrString(_pymessage, "polarization", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

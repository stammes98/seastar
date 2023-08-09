// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from seastar_interfaces:msg/SkyEphemeris.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "seastar_interfaces/msg/detail/sky_ephemeris__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace seastar_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SkyEphemeris_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) seastar_interfaces::msg::SkyEphemeris(_init);
}

void SkyEphemeris_fini_function(void * message_memory)
{
  auto typed_message = static_cast<seastar_interfaces::msg::SkyEphemeris *>(message_memory);
  typed_message->~SkyEphemeris();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SkyEphemeris_message_member_array[2] = {
  {
    "azimuth",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(seastar_interfaces::msg::SkyEphemeris, azimuth),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "elevation",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(seastar_interfaces::msg::SkyEphemeris, elevation),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SkyEphemeris_message_members = {
  "seastar_interfaces::msg",  // message namespace
  "SkyEphemeris",  // message name
  2,  // number of fields
  sizeof(seastar_interfaces::msg::SkyEphemeris),
  SkyEphemeris_message_member_array,  // message members
  SkyEphemeris_init_function,  // function to initialize message memory (memory has to be allocated)
  SkyEphemeris_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SkyEphemeris_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SkyEphemeris_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace seastar_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<seastar_interfaces::msg::SkyEphemeris>()
{
  return &::seastar_interfaces::msg::rosidl_typesupport_introspection_cpp::SkyEphemeris_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, seastar_interfaces, msg, SkyEphemeris)() {
  return &::seastar_interfaces::msg::rosidl_typesupport_introspection_cpp::SkyEphemeris_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from seastar_interfaces:srv/PointMotors.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__SRV__DETAIL__POINT_MOTORS__STRUCT_HPP_
#define SEASTAR_INTERFACES__SRV__DETAIL__POINT_MOTORS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'point'
#include "seastar_interfaces/msg/detail/desired_pointing__struct.hpp"
// Member 'input_state'
#include "seastar_interfaces/msg/detail/motor_command__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__seastar_interfaces__srv__PointMotors_Request __attribute__((deprecated))
#else
# define DEPRECATED__seastar_interfaces__srv__PointMotors_Request __declspec(deprecated)
#endif

namespace seastar_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PointMotors_Request_
{
  using Type = PointMotors_Request_<ContainerAllocator>;

  explicit PointMotors_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_init),
    input_state(_init)
  {
    (void)_init;
  }

  explicit PointMotors_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : point(_alloc, _init),
    input_state(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _point_type =
    seastar_interfaces::msg::DesiredPointing_<ContainerAllocator>;
  _point_type point;
  using _input_state_type =
    seastar_interfaces::msg::MotorCommand_<ContainerAllocator>;
  _input_state_type input_state;

  // setters for named parameter idiom
  Type & set__point(
    const seastar_interfaces::msg::DesiredPointing_<ContainerAllocator> & _arg)
  {
    this->point = _arg;
    return *this;
  }
  Type & set__input_state(
    const seastar_interfaces::msg::MotorCommand_<ContainerAllocator> & _arg)
  {
    this->input_state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    seastar_interfaces::srv::PointMotors_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const seastar_interfaces::srv::PointMotors_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<seastar_interfaces::srv::PointMotors_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<seastar_interfaces::srv::PointMotors_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      seastar_interfaces::srv::PointMotors_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<seastar_interfaces::srv::PointMotors_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      seastar_interfaces::srv::PointMotors_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<seastar_interfaces::srv::PointMotors_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<seastar_interfaces::srv::PointMotors_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<seastar_interfaces::srv::PointMotors_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__seastar_interfaces__srv__PointMotors_Request
    std::shared_ptr<seastar_interfaces::srv::PointMotors_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__seastar_interfaces__srv__PointMotors_Request
    std::shared_ptr<seastar_interfaces::srv::PointMotors_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PointMotors_Request_ & other) const
  {
    if (this->point != other.point) {
      return false;
    }
    if (this->input_state != other.input_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const PointMotors_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PointMotors_Request_

// alias to use template instance with default allocator
using PointMotors_Request =
  seastar_interfaces::srv::PointMotors_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace seastar_interfaces


// Include directives for member types
// Member 'command'
// already included above
// #include "seastar_interfaces/msg/detail/motor_command__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__seastar_interfaces__srv__PointMotors_Response __attribute__((deprecated))
#else
# define DEPRECATED__seastar_interfaces__srv__PointMotors_Response __declspec(deprecated)
#endif

namespace seastar_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct PointMotors_Response_
{
  using Type = PointMotors_Response_<ContainerAllocator>;

  explicit PointMotors_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command(_init)
  {
    (void)_init;
  }

  explicit PointMotors_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _command_type =
    seastar_interfaces::msg::MotorCommand_<ContainerAllocator>;
  _command_type command;

  // setters for named parameter idiom
  Type & set__command(
    const seastar_interfaces::msg::MotorCommand_<ContainerAllocator> & _arg)
  {
    this->command = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    seastar_interfaces::srv::PointMotors_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const seastar_interfaces::srv::PointMotors_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<seastar_interfaces::srv::PointMotors_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<seastar_interfaces::srv::PointMotors_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      seastar_interfaces::srv::PointMotors_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<seastar_interfaces::srv::PointMotors_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      seastar_interfaces::srv::PointMotors_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<seastar_interfaces::srv::PointMotors_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<seastar_interfaces::srv::PointMotors_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<seastar_interfaces::srv::PointMotors_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__seastar_interfaces__srv__PointMotors_Response
    std::shared_ptr<seastar_interfaces::srv::PointMotors_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__seastar_interfaces__srv__PointMotors_Response
    std::shared_ptr<seastar_interfaces::srv::PointMotors_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PointMotors_Response_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    return true;
  }
  bool operator!=(const PointMotors_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PointMotors_Response_

// alias to use template instance with default allocator
using PointMotors_Response =
  seastar_interfaces::srv::PointMotors_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace seastar_interfaces

namespace seastar_interfaces
{

namespace srv
{

struct PointMotors
{
  using Request = seastar_interfaces::srv::PointMotors_Request;
  using Response = seastar_interfaces::srv::PointMotors_Response;
};

}  // namespace srv

}  // namespace seastar_interfaces

#endif  // SEASTAR_INTERFACES__SRV__DETAIL__POINT_MOTORS__STRUCT_HPP_

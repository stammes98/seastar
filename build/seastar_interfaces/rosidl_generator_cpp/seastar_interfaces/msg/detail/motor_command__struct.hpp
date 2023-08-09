// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from seastar_interfaces:msg/MotorCommand.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_HPP_
#define SEASTAR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__seastar_interfaces__msg__MotorCommand __attribute__((deprecated))
#else
# define DEPRECATED__seastar_interfaces__msg__MotorCommand __declspec(deprecated)
#endif

namespace seastar_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorCommand_
{
  using Type = MotorCommand_<ContainerAllocator>;

  explicit MotorCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->q1 = 0.0;
      this->q2 = 0.0;
      this->q3 = 0.0;
    }
  }

  explicit MotorCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->q1 = 0.0;
      this->q2 = 0.0;
      this->q3 = 0.0;
    }
  }

  // field types and members
  using _q1_type =
    double;
  _q1_type q1;
  using _q2_type =
    double;
  _q2_type q2;
  using _q3_type =
    double;
  _q3_type q3;

  // setters for named parameter idiom
  Type & set__q1(
    const double & _arg)
  {
    this->q1 = _arg;
    return *this;
  }
  Type & set__q2(
    const double & _arg)
  {
    this->q2 = _arg;
    return *this;
  }
  Type & set__q3(
    const double & _arg)
  {
    this->q3 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    seastar_interfaces::msg::MotorCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const seastar_interfaces::msg::MotorCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<seastar_interfaces::msg::MotorCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<seastar_interfaces::msg::MotorCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      seastar_interfaces::msg::MotorCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<seastar_interfaces::msg::MotorCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      seastar_interfaces::msg::MotorCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<seastar_interfaces::msg::MotorCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<seastar_interfaces::msg::MotorCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<seastar_interfaces::msg::MotorCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__seastar_interfaces__msg__MotorCommand
    std::shared_ptr<seastar_interfaces::msg::MotorCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__seastar_interfaces__msg__MotorCommand
    std::shared_ptr<seastar_interfaces::msg::MotorCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorCommand_ & other) const
  {
    if (this->q1 != other.q1) {
      return false;
    }
    if (this->q2 != other.q2) {
      return false;
    }
    if (this->q3 != other.q3) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorCommand_

// alias to use template instance with default allocator
using MotorCommand =
  seastar_interfaces::msg::MotorCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace seastar_interfaces

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__MOTOR_COMMAND__STRUCT_HPP_

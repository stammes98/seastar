// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from seastar_interfaces:msg/DesiredPointing.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__DESIRED_POINTING__STRUCT_HPP_
#define SEASTAR_INTERFACES__MSG__DETAIL__DESIRED_POINTING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__seastar_interfaces__msg__DesiredPointing __attribute__((deprecated))
#else
# define DEPRECATED__seastar_interfaces__msg__DesiredPointing __declspec(deprecated)
#endif

namespace seastar_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DesiredPointing_
{
  using Type = DesiredPointing_<ContainerAllocator>;

  explicit DesiredPointing_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->azimuth = 0.0;
      this->altitude = 0.0;
      this->polarization = 0.0;
    }
  }

  explicit DesiredPointing_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->azimuth = 0.0;
      this->altitude = 0.0;
      this->polarization = 0.0;
    }
  }

  // field types and members
  using _azimuth_type =
    double;
  _azimuth_type azimuth;
  using _altitude_type =
    double;
  _altitude_type altitude;
  using _polarization_type =
    double;
  _polarization_type polarization;

  // setters for named parameter idiom
  Type & set__azimuth(
    const double & _arg)
  {
    this->azimuth = _arg;
    return *this;
  }
  Type & set__altitude(
    const double & _arg)
  {
    this->altitude = _arg;
    return *this;
  }
  Type & set__polarization(
    const double & _arg)
  {
    this->polarization = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    seastar_interfaces::msg::DesiredPointing_<ContainerAllocator> *;
  using ConstRawPtr =
    const seastar_interfaces::msg::DesiredPointing_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<seastar_interfaces::msg::DesiredPointing_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<seastar_interfaces::msg::DesiredPointing_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      seastar_interfaces::msg::DesiredPointing_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<seastar_interfaces::msg::DesiredPointing_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      seastar_interfaces::msg::DesiredPointing_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<seastar_interfaces::msg::DesiredPointing_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<seastar_interfaces::msg::DesiredPointing_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<seastar_interfaces::msg::DesiredPointing_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__seastar_interfaces__msg__DesiredPointing
    std::shared_ptr<seastar_interfaces::msg::DesiredPointing_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__seastar_interfaces__msg__DesiredPointing
    std::shared_ptr<seastar_interfaces::msg::DesiredPointing_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DesiredPointing_ & other) const
  {
    if (this->azimuth != other.azimuth) {
      return false;
    }
    if (this->altitude != other.altitude) {
      return false;
    }
    if (this->polarization != other.polarization) {
      return false;
    }
    return true;
  }
  bool operator!=(const DesiredPointing_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DesiredPointing_

// alias to use template instance with default allocator
using DesiredPointing =
  seastar_interfaces::msg::DesiredPointing_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace seastar_interfaces

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__DESIRED_POINTING__STRUCT_HPP_

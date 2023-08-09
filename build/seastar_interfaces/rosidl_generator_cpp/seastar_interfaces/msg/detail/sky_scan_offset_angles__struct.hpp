// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from seastar_interfaces:msg/SkyScanOffsetAngles.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET_ANGLES__STRUCT_HPP_
#define SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET_ANGLES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__seastar_interfaces__msg__SkyScanOffsetAngles __attribute__((deprecated))
#else
# define DEPRECATED__seastar_interfaces__msg__SkyScanOffsetAngles __declspec(deprecated)
#endif

namespace seastar_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SkyScanOffsetAngles_
{
  using Type = SkyScanOffsetAngles_<ContainerAllocator>;

  explicit SkyScanOffsetAngles_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->azimuth = 0.0;
      this->elevation = 0.0;
      this->stokes_angle = 0.0;
    }
  }

  explicit SkyScanOffsetAngles_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->azimuth = 0.0;
      this->elevation = 0.0;
      this->stokes_angle = 0.0;
    }
  }

  // field types and members
  using _azimuth_type =
    double;
  _azimuth_type azimuth;
  using _elevation_type =
    double;
  _elevation_type elevation;
  using _stokes_angle_type =
    double;
  _stokes_angle_type stokes_angle;

  // setters for named parameter idiom
  Type & set__azimuth(
    const double & _arg)
  {
    this->azimuth = _arg;
    return *this;
  }
  Type & set__elevation(
    const double & _arg)
  {
    this->elevation = _arg;
    return *this;
  }
  Type & set__stokes_angle(
    const double & _arg)
  {
    this->stokes_angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    seastar_interfaces::msg::SkyScanOffsetAngles_<ContainerAllocator> *;
  using ConstRawPtr =
    const seastar_interfaces::msg::SkyScanOffsetAngles_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<seastar_interfaces::msg::SkyScanOffsetAngles_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<seastar_interfaces::msg::SkyScanOffsetAngles_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      seastar_interfaces::msg::SkyScanOffsetAngles_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<seastar_interfaces::msg::SkyScanOffsetAngles_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      seastar_interfaces::msg::SkyScanOffsetAngles_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<seastar_interfaces::msg::SkyScanOffsetAngles_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<seastar_interfaces::msg::SkyScanOffsetAngles_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<seastar_interfaces::msg::SkyScanOffsetAngles_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__seastar_interfaces__msg__SkyScanOffsetAngles
    std::shared_ptr<seastar_interfaces::msg::SkyScanOffsetAngles_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__seastar_interfaces__msg__SkyScanOffsetAngles
    std::shared_ptr<seastar_interfaces::msg::SkyScanOffsetAngles_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SkyScanOffsetAngles_ & other) const
  {
    if (this->azimuth != other.azimuth) {
      return false;
    }
    if (this->elevation != other.elevation) {
      return false;
    }
    if (this->stokes_angle != other.stokes_angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const SkyScanOffsetAngles_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SkyScanOffsetAngles_

// alias to use template instance with default allocator
using SkyScanOffsetAngles =
  seastar_interfaces::msg::SkyScanOffsetAngles_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace seastar_interfaces

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET_ANGLES__STRUCT_HPP_

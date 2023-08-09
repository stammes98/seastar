// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from seastar_interfaces:msg/SkyScanOffset.idl
// generated code does not contain a copyright notice

#ifndef SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__STRUCT_HPP_
#define SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__seastar_interfaces__msg__SkyScanOffset __attribute__((deprecated))
#else
# define DEPRECATED__seastar_interfaces__msg__SkyScanOffset __declspec(deprecated)
#endif

namespace seastar_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SkyScanOffset_
{
  using Type = SkyScanOffset_<ContainerAllocator>;

  explicit SkyScanOffset_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->azimuth_offset = 0.0;
      this->elevation_offset = 0.0;
      this->stokes_angle_offset = 0.0;
    }
  }

  explicit SkyScanOffset_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->azimuth_offset = 0.0;
      this->elevation_offset = 0.0;
      this->stokes_angle_offset = 0.0;
    }
  }

  // field types and members
  using _azimuth_offset_type =
    double;
  _azimuth_offset_type azimuth_offset;
  using _elevation_offset_type =
    double;
  _elevation_offset_type elevation_offset;
  using _stokes_angle_offset_type =
    double;
  _stokes_angle_offset_type stokes_angle_offset;

  // setters for named parameter idiom
  Type & set__azimuth_offset(
    const double & _arg)
  {
    this->azimuth_offset = _arg;
    return *this;
  }
  Type & set__elevation_offset(
    const double & _arg)
  {
    this->elevation_offset = _arg;
    return *this;
  }
  Type & set__stokes_angle_offset(
    const double & _arg)
  {
    this->stokes_angle_offset = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    seastar_interfaces::msg::SkyScanOffset_<ContainerAllocator> *;
  using ConstRawPtr =
    const seastar_interfaces::msg::SkyScanOffset_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<seastar_interfaces::msg::SkyScanOffset_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<seastar_interfaces::msg::SkyScanOffset_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      seastar_interfaces::msg::SkyScanOffset_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<seastar_interfaces::msg::SkyScanOffset_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      seastar_interfaces::msg::SkyScanOffset_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<seastar_interfaces::msg::SkyScanOffset_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<seastar_interfaces::msg::SkyScanOffset_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<seastar_interfaces::msg::SkyScanOffset_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__seastar_interfaces__msg__SkyScanOffset
    std::shared_ptr<seastar_interfaces::msg::SkyScanOffset_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__seastar_interfaces__msg__SkyScanOffset
    std::shared_ptr<seastar_interfaces::msg::SkyScanOffset_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SkyScanOffset_ & other) const
  {
    if (this->azimuth_offset != other.azimuth_offset) {
      return false;
    }
    if (this->elevation_offset != other.elevation_offset) {
      return false;
    }
    if (this->stokes_angle_offset != other.stokes_angle_offset) {
      return false;
    }
    return true;
  }
  bool operator!=(const SkyScanOffset_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SkyScanOffset_

// alias to use template instance with default allocator
using SkyScanOffset =
  seastar_interfaces::msg::SkyScanOffset_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace seastar_interfaces

#endif  // SEASTAR_INTERFACES__MSG__DETAIL__SKY_SCAN_OFFSET__STRUCT_HPP_

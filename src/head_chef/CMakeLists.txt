cmake_minimum_required(VERSION 3.8)
project(head_chef)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(seastar_interfaces REQUIRED)
find_package(Eigen3 REQUIRED)

find_path(LIBCONFIG_INCLUDE_DIR libconfig.h++
 HINTS ${LIBCONFIG_DIR} $ENV{LIBCONFIG_DIR}
 PATH_SUFFIXES include
 )
 
find_library(LIBCONFIG_LIBRARY NAMES config++ libconfig++
 HINTS ${LIBCONFIG_DIR} $ENV{LIBCONFIG_DIR}
 PATH_SUFFIXES lib${LIB_SUFFIX} lib64 lib
 )

add_executable(head_chef src/head_chef.cpp src/sousChef.cpp src/PID.cpp src/ChefCommand.cpp src/ChefScript.cpp)
target_include_directories(head_chef PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_include_directories(head_chef PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${LIBCONFIG_LIBRARY})
target_link_libraries(head_chef ${LIBCONFIG_LIBRARY})
target_compile_features(head_chef PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17


ament_target_dependencies(head_chef rclcpp std_msgs tf2 tf2_ros sensor_msgs geometry_msgs tf2_geometry_msgs seastar_interfaces Eigen3)

install(TARGETS head_chef
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

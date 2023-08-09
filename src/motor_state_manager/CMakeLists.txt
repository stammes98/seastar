cmake_minimum_required(VERSION 3.8)
project(motor_state_manager)

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

find_path(LIBCONFIG_INCLUDE_DIR libconfig.h++
 HINTS ${LIBCONFIG_DIR} $ENV{LIBCONFIG_DIR}
 PATH_SUFFIXES include
 )
 
find_library(LIBCONFIG_LIBRARY NAMES config++ libconfig++
 HINTS ${LIBCONFIG_DIR} $ENV{LIBCONFIG_DIR}
 PATH_SUFFIXES lib${LIB_SUFFIX} lib64 lib
 )

add_executable(motor_state_manager src/motor_state_manager.cpp src/helper.cpp)
target_include_directories(motor_state_manager PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${LIBCONFIG_LIBRARY})
target_compile_features(motor_state_manager PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_link_libraries(motor_state_manager ${LIBCONFIG_LIBRARY})
ament_target_dependencies(motor_state_manager rclcpp std_msgs)
install(TARGETS motor_state_manager
  DESTINATION lib/${PROJECT_NAME})
  
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/motorsettings.cfg DESTINATION lib/${PROJECT_NAME})

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

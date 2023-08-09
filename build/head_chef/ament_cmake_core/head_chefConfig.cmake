# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_head_chef_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED head_chef_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(head_chef_FOUND FALSE)
  elseif(NOT head_chef_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(head_chef_FOUND FALSE)
  endif()
  return()
endif()
set(_head_chef_CONFIG_INCLUDED TRUE)

# output package information
if(NOT head_chef_FIND_QUIETLY)
  message(STATUS "Found head_chef: 0.0.0 (${head_chef_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'head_chef' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${head_chef_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(head_chef_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${head_chef_DIR}/${_extra}")
endforeach()

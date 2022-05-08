cmake_minimum_required(VERSION 3.5)

project(rcl_logging_android)

# Default to C11
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 11)
endif()
# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

find_package(ament_cmake_ros REQUIRED)
find_package(rcl_logging_interface REQUIRED)
find_package(rcutils REQUIRED)

if(NOT WIN32)
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_library(rcl_logging_android
  src/rcl_logging_android.c)

target_link_libraries(rcl_logging_android PRIVATE
  log  # maybe this comes from NDK toolchain?
  rcutils::rcutils)
target_link_libraries(rcl_logging_android PUBLIC
  rcl_logging_interface::rcl_logging_interface)

target_compile_definitions(rcl_logging_android PRIVATE "RCL_LOGGING_INTERFACE_BUILDING_DLL")

install(TARGETS rcl_logging_android EXPORT export_rcl_logging_android
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)


ament_export_dependencies(rcl_logging_interface)
ament_export_dependencies(rcutils)

ament_export_targets(export_rcl_logging_android)

ament_package()

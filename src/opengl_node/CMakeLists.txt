cmake_minimum_required(VERSION 3.5)

project(opengl_node)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(include)

add_library(openglnode SHARED
  src/opengl_node.cpp)

target_compile_definitions(openglnode
  PRIVATE "OPENGL_NODE_BUILDING_DLL")

ament_target_dependencies(openglnode
  "rclcpp"
  "sensor_msgs"
  "std_msgs"
  "rclcpp_components"
)

rclcpp_components_register_node(openglnode PLUGIN "opengl_node::OpenglNode" EXECUTABLE opengl_node)

install(TARGETS
  openglnode
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()

cmake_minimum_required(VERSION 3.8)
project(point_cloud_processing)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(PCL REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(visualization_msgs REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

#only add here, after creating new files or scripts
add_executable(pcd_import src/table_scene.cpp)
target_link_libraries(pcd_import ${PCL_LIBRARIES})

add_executable(plane_cloud src/planner_cloud.cpp)
target_link_libraries(plane_cloud ${PCL_LIBRARIES})

add_executable(circle_cloud src/circular_cloud.cpp)
target_link_libraries(circle_cloud ${PCL_LIBRARIES})

add_executable(filter_segment src/filtering_segmentation.cpp)
target_link_libraries(filter_segment ${PCL_LIBRARIES})

add_executable(point_path_draw src/point_path_drawing.cpp)
target_link_libraries(point_path_draw ${PCL_LIBRARIES})

add_executable(kitti_data_voxel src/kitti_data_voxel.cpp)
ament_target_dependencies(kitti_data_voxel rclcpp sensor_msgs pcl_conversions)
target_link_libraries(kitti_data_voxel ${PCL_LIBRARIES})

add_executable(kd_tree src/kd_tree.cpp)
# ament_target_dependencies(kd_tree rclcpp sensor_msgs pcl_conversions)
target_link_libraries(kd_tree ${PCL_LIBRARIES})

# and here too
install(TARGETS
  pcd_import plane_cloud circle_cloud filter_segment point_path_draw kitti_data_voxel kd_tree
  DESTINATION lib/${PROJECT_NAME}  
)

install(DIRECTORY
  launch
  rviz
  DESTINATION share/${PROJECT_NAME}
)

ament_package()

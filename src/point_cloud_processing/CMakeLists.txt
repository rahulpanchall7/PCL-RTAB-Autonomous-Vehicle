cmake_minimum_required(VERSION 3.8)
project(point_cloud_processing)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(PCL REQUIRED)

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

# and here too
install(TARGETS
  pcd_import plane_cloud circle_cloud filter_segment point_path_draw
  DESTINATION lib/${PROJECT_NAME}  
)

install(DIRECTORY
  launch
  rviz
  DESTINATION share/${PROJECT_NAME}
)

ament_package()

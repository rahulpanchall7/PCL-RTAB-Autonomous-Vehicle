#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

int main(){
    pcl::PointCloud<pcl::PointXYZ> cloud; // for 3d point cloud of every object
    cloud.push_back(pcl::PointXYZ(1.0,2.0,3.0)); // add a point cloud
    cloud.push_back(pcl::PointXYZ(5.0,7.0,5.0)); 
    cloud.push_back(pcl::PointXYZ(69.0,54.0,34.0)); 
    cloud.push_back(pcl::PointXYZ(6.0,5.0,354.0)); 
    cloud.push_back(pcl::PointXYZ(9.0,54.0,35.0)); 
    cloud.push_back(pcl::PointXYZ(45.0,54.0,65.0)); 


    std::string path = "/home/rahul/nav_pcl_ws/src/point_cloud_processing/point_clouds/plane.pcd";
    pcl::io::savePCDFileASCII(path, cloud); // to save point clouds in a file

    std::cout<<cloud.size();
    return 0;
}
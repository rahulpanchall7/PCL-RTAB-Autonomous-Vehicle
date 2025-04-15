#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

int main(){
    pcl::PointCloud<pcl::PointXYZRGB> cloud; // for 3d point cloud of every object in RGB

    double radius = 3.0;
    int num_points = 50;
    double angular_step_size = 2.0*M_PI_2/num_points;

    for(int i=0; i<num_points; i++){
        pcl::PointXYZRGB point;
        double angle = i *angular_step_size;
        point.x= radius * std::cos(angle);
        point.y= radius * std::sin(angle);
        point.z= 1.0;
    
        point.r= 255*std::cos(angle);
        point.g= 255*std::sin(angle);
        point.b= 255*std::cos(angle +M_PI_2);
    
        cloud.push_back(point);
    }

    std::string path = "/home/rahul/nav_pcl_ws/src/point_cloud_processing/point_clouds/circular.pcd";
    pcl::io::savePCDFileASCII(path, cloud); // to save point clouds in a file

    std::cout<<cloud.size();
    return 0;
}
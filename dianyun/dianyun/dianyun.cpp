//#include<iostream>
//#include<pcl/io/io.h>
//#include<pcl/io/pcd_io.h>
//#include<pcl/io/ply_io.h>
//#include<pcl/visualization/cloud_viewer.h>
//int user_data;
//using std::cout;
//
//
//void viewerOneOff(pcl::visualization::PCLVisualizer& viewer) {
//	viewer.setBackgroundColor(1.0, 0.5, 1.0);   //设置背景颜色
//}
//
//int main() {
//	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
//
//	char strfilepath[256] = "rabbit.pcd";
//	if (-1 == pcl::io::loadPCDFile(strfilepath, *cloud)) {
//		cout << "error input!" << endl;
//		return -1;
//	}
//
//	cout << cloud->points.size() << endl;
//	pcl::visualization::CloudViewer viewer("Cloud Viewer");   //创建viewer对象
//
//	viewer.showCloud(cloud);
//	viewer.runOnVisualizationThreadOnce(viewerOneOff);
//	system("pause");
//	return 0;
//}


//#include <iostream>
//#include <pcl/io/pcd_io.h>
//#include <pcl/point_types.h>
//
//int main(int argc, char** argv)
//{
//    // Load point clouds
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZ>);
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2(new pcl::PointCloud<pcl::PointXYZ>);
//
//    if (pcl::io::loadPCDFile<pcl::PointXYZ>("1_4.pcd", *cloud1) == -1 ||
//        pcl::io::loadPCDFile<pcl::PointXYZ>("1_6.pcd", *cloud2) == -1)
//    {
//        PCL_ERROR("Couldn't read file!\n");
//        return (-1);
//    }
//
//    // Concatenate point clouds
//    pcl::PointCloud<pcl::PointXYZ>::Ptr merged_cloud(new pcl::PointCloud<pcl::PointXYZ>);
//    *merged_cloud = *cloud1 + *cloud2;
//
//    // Save merged point cloud
//    pcl::io::savePCDFileASCII("merged_cloud.pcd", *merged_cloud);
//    std::cout << "Merged cloud saved as merged_cloud.pcd" << std::endl;
//
//    return (0);
//}

//#include <iostream>
//#include <pcl/io/pcd_io.h>
//#include <pcl/point_types.h>
//#include <pcl/registration/icp.h>
//#include <pcl/filters/passthrough.h>
//#include <pcl/visualization/cloud_viewer.h>
//
//int main(int argc, char** argv) {
//    // Load the first point cloud data
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in(new pcl::PointCloud<pcl::PointXYZ>);
//    if (pcl::io::loadPCDFile<pcl::PointXYZ>("1_4.pcd", *cloud_in) == -1) {
//        PCL_ERROR("Couldn't read file 1_4.pcd \n");
//        return (-1);
//    }
//
//    // Load the second point cloud data
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out(new pcl::PointCloud<pcl::PointXYZ>);
//    if (pcl::io::loadPCDFile<pcl::PointXYZ>("1_6.pcd", *cloud_out) == -1) {
//        PCL_ERROR("Couldn't read file 1_6.pcd \n");
//        return (-1);
//    }
//
//    // Preprocess the point cloud data to remove NaN or Inf values
//    pcl::PassThrough<pcl::PointXYZ> pass;
//    pass.setInputCloud(cloud_in);
//    pass.setFilterFieldName("z"); // Assuming z represents the depth
//    pass.setFilterLimits(0.0, 10.0); // Set the z-axis limits for filtering
//    pass.filter(*cloud_in);
//
//    pass.setInputCloud(cloud_out);
//    pass.filter(*cloud_out);
//
//    // Create a point cloud object to hold the result
//    pcl::PointCloud<pcl::PointXYZ>::Ptr final_cloud(new pcl::PointCloud<pcl::PointXYZ>);
//
//    // Initialize Iterative Closest Point (ICP) registration object
//    pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
//    icp.setInputSource(cloud_in);
//    icp.setInputTarget(cloud_out);
//
//    // Set the max correspondence distance (e.g., 1cm)
//    icp.setMaxCorrespondenceDistance(0.01);
//
//    // Set the maximum number of iterations
//    icp.setMaximumIterations(50);
//
//    // Set the transformation epsilon (termination condition)
//    icp.setTransformationEpsilon(1e-8);
//
//    // Perform the alignment
//    icp.align(*final_cloud);
//
//    if (icp.hasConverged()) {
//        std::cout << "ICP converged." << std::endl;
//        std::cout << "Transformation matrix:" << std::endl << icp.getFinalTransformation() << std::endl;
//    }
//    else {
//        PCL_ERROR("ICP did not converge.\n");
//        return (-1);
//    }
//
//    // Save the registered point cloud data to disk
//    pcl::io::savePCDFileASCII("registered_cloud.pcd", *final_cloud);
//    std::cout << "Registered point cloud saved as registered_cloud.pcd" << std::endl;
//
//    // Visualize the registered point cloud
//    pcl::visualization::CloudViewer viewer("Registered Point Cloud Viewer");
//    viewer.showCloud(final_cloud);
//    while (!viewer.wasStopped()) {}
//
//    return 0;
//}
//
//

//#include <iostream>
//#include <pcl/io/pcd_io.h>
//#include <pcl/point_types.h>
//#include <pcl/registration/icp.h>
//
//int main(int argc, char** argv)
//{
//    // 读取两个点云
//    pcl::PointCloud<pcl::PointXYZ>::Ptr source_cloud(new pcl::PointCloud<pcl::PointXYZ>);
//    pcl::PointCloud<pcl::PointXYZ>::Ptr target_cloud(new pcl::PointCloud<pcl::PointXYZ>);
//
//    pcl::io::loadPCDFile<pcl::PointXYZ>("1.2.pcd", *source_cloud);
//    pcl::io::loadPCDFile<pcl::PointXYZ>("1.3.pcd", *target_cloud);
//
//    // 创建 ICP 对象
//    pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
//    icp.setInputSource(source_cloud);
//    icp.setInputTarget(target_cloud);
//
//    // 运行 ICP 算法
//    pcl::PointCloud<pcl::PointXYZ> aligned_cloud;
//    icp.align(aligned_cloud);
//
//    if (icp.hasConverged())
//    {
//        std::cout << "ICP converged with score: " << icp.getFitnessScore() << std::endl;
//        std::cout << "Transformation matrix:" << std::endl;
//        std::cout << icp.getFinalTransformation() << std::endl;
//    }
//    else
//    {
//        std::cout << "ICP did not converge." << std::endl;
//        return -1;
//    }
//
//    return 0;
//}







//#include <pcl/filters/voxel_grid.h>
//#include <pcl/filters/statistical_outlier_removal.h>
//#include <iostream>
//#include <pcl/io/pcd_io.h>
//#include <pcl/point_types.h>
//#include <pcl/registration/icp.h>
//
//int main(int argc, char** argv)
//{
//    // 读取两个点云
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZ>);
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2(new pcl::PointCloud<pcl::PointXYZ>);
//
//    pcl::io::loadPCDFile<pcl::PointXYZ>("6.1.pcd", *cloud1);
//    pcl::io::loadPCDFile<pcl::PointXYZ>("6.2.pcd", *cloud2);
//
//
//    //旋转代码
//    //pcl::PointCloud<pcl::PointXYZ>::Ptr transformed_cloud2(new pcl::PointCloud<pcl::PointXYZ>);
//    //Eigen::Affine3f transform = Eigen::Affine3f::Identity();
//    //// 在这里设置旋转矩阵，例如，绕Z轴旋转45度
//    //float angle = M_PI / 4; // 45 degrees
//    //transform.rotate(Eigen::AngleAxisf(angle, Eigen::Vector3f::UnitZ()));
//    //// 应用变换
//    //pcl::PointCloud<pcl::PointXYZ>::Ptr transformed_cloud(new pcl::PointCloud<pcl::PointXYZ>);
//    //pcl::transformPointCloud(*cloud2, *cloud2, transform);
//
//    // 确定标记点的索引
//    int idx1_1 = 100; // 第一个点云中的第一组标记点索引
//    int idx1_2 = 200; // 第一个点云中的第二组标记点索引
//    int idx2_1 = 300; // 第二个点云中的第一组标记点索引
//    int idx2_2 = 400; // 第二个点云中的第二组标记点索引
//
//    // 提取标记点的坐标
//    pcl::PointXYZ mark1_1;//= cloud1->points[idx1_1];
//    mark1_1.x = 19.255997;
//    mark1_1.y = -3.814499;
//    mark1_1.z = 0.13735;
//    pcl::PointXYZ mark1_2;//= cloud1->points[idx1_2];
//    mark1_2.x = 8.166199;
//    mark1_2.y = -14.716499;
//    mark1_2.z = 8.37525;
//
//    pcl::PointXYZ mark2_1;//= cloud2->points[idx2_1];
//    mark2_1.x = -5.922401;
//    mark2_1.y = -3.702;
//    mark2_1.z = 11.843;
//    pcl::PointXYZ mark2_2;//= cloud2->points[idx2_2];
//    mark2_2.x = -19.568203;
//    mark2_2.y = -14.467499;
//    mark2_2.z = 8.67445;
//
//    // 计算标记点之间的偏移量
//    Eigen::Vector3f offset1(mark2_1.x - mark1_1.x, mark2_1.y - mark1_1.y, mark2_1.z - mark1_1.z);
//    //Eigen::Vector3f offset2(mark2_2.x - mark1_2.x, mark2_2.y - mark1_2.y, mark2_2.z - mark1_2.z);
//    
//    // 计算平均偏移量
//    //Eigen::Vector3f average_offset((offset1.x() + offset2.x()) / 2, (offset1.y() + offset2.y()) / 2, (offset1.z() + offset2.z()) / 2);
//
//    // 将第一个点云平移到与第二个点云的标记点对齐
//    pcl::PointCloud<pcl::PointXYZ>::Ptr aligned_cloud1(new pcl::PointCloud<pcl::PointXYZ>);
//    for (size_t i = 0; i < cloud1->size(); ++i)
//    {
//        //pcl::PointXYZ pt = cloud1->points[i];
//        cloud1->points[i].x += offset1.x();
//        cloud1->points[i].y += offset1.y();
//        cloud1->points[i].z += offset1.z();
//        /*pt.x += offset2.x();
//        pt.y += offset2.y();
//        pt.z += offset2.z();*/
//        
//        //aligned_cloud1->push_back(pt);
//    }
//
//
//    std::vector<int> indices;
//        cloud1->is_dense = false;
//        cloud2->is_dense = false;
//        pcl::removeNaNFromPointCloud(*cloud1, *cloud1, indices);
//        pcl::removeNaNFromPointCloud(*cloud2, *cloud2, indices);
//        // 创建体素格滤波器对象
//        pcl::VoxelGrid<pcl::PointXYZ> sor;
//        sor.setInputCloud(cloud1);
//        sor.setLeafSize(0.05f, 0.05f, 0.05f);  // 增加体素格的大小
//        pcl::PointCloud<pcl::PointXYZ>::Ptr downsampled_cloud1(new pcl::PointCloud<pcl::PointXYZ>);
//        sor.filter(*downsampled_cloud1);
//    
//        sor.setInputCloud(cloud2);
//        pcl::PointCloud<pcl::PointXYZ>::Ptr downsampled_cloud2(new pcl::PointCloud<pcl::PointXYZ>);
//        sor.filter(*downsampled_cloud2);
//    
//        // 创建统计滤波器对象
//        pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor_outlier;
//        sor_outlier.setInputCloud(downsampled_cloud1);
//        sor_outlier.setMeanK(50); // 设置在计算局部点云和标准差时使用的邻居数量
//        sor_outlier.setStddevMulThresh(1.0); // 设置标准差乘数阈值
//        pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_cloud1(new pcl::PointCloud<pcl::PointXYZ>);
//        sor_outlier.filter(*filtered_cloud1);
//    
//        sor_outlier.setInputCloud(downsampled_cloud2);
//        pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_cloud2(new pcl::PointCloud<pcl::PointXYZ>);
//        sor_outlier.filter(*filtered_cloud2);
//    
//        // 创建ICP配准对象
//        pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
//        icp.setInputSource(filtered_cloud1);
//        icp.setInputTarget(filtered_cloud2);
//    
//        // 设置ICP参数
//        icp.setMaximumIterations(50);
//        icp.setTransformationEpsilon(1e-8);
//        icp.setEuclideanFitnessEpsilon(0.001);
//        //icp.setMaximumIterations(1); // 设置最小的迭代次数
//        //icp.setTransformationEpsilon(0.1); // 设置较大的转换阈值
//        //icp.setEuclideanFitnessEpsilon(10); // 设置较大的拟合误差阈值
//        /*icp.setMaxCorrespondenceDistance(0.001);
//        icp.setTransformationEpsilon(1e-10);
//        icp.setMaximumIterations(1000);*/
//    
//        // 创建输出点云
//        pcl::PointCloud<pcl::PointXYZ>::Ptr aligned_cloud(new pcl::PointCloud<pcl::PointXYZ>);
//    
//        // 执行配准
//        icp.align(*aligned_cloud);
//    
//        // 检查是否配准成功
//        if (icp.hasConverged())
//        {
//            std::cout << "ICP converged." << std::endl;
//            std::cout << "Fitness score: " << icp.getFitnessScore() << std::endl;
//            std::cout << "Transformation matrix:" << std::endl;
//            std::cout << icp.getFinalTransformation() << std::endl;
//    
//            // 合并两个点云
//            pcl::PointCloud<pcl::PointXYZ>::Ptr merged_cloud(new pcl::PointCloud<pcl::PointXYZ>);
//            *merged_cloud = *aligned_cloud + *cloud2;
//    
//            // 保存合并后的点云
//            pcl::io::savePCDFileASCII("pjpyicp.pcd", *merged_cloud);
//    
//            std::cout << "Merged cloud has been saved." << std::endl;
//        }
//        else
//        {
//            std::cerr << "ICP did not converge." << std::endl;
//            return 1;
//        }
//    
//        return 0;
//
//
//
//
//}
//

//#include <opencv2/opencv.hpp>

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include<cmath>
#include <fstream>//这是用文本保存的头文件
#include <sstream>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <map>//这里的map集合是添加点云1和点云2的关系
#include <chrono>
#include <pcl/visualization/pcl_visualizer.h>

#include <experimental/filesystem>

/*完成点云重叠部分识别*/

#include <pcl/features/normal_3d.h>
#include <pcl/features/fpfh.h>
#include <pcl/registration/ia_ransac.h>


#include <nfd.h>

#include <thread>//多线程加载

#include <pcl/console/print.h>


typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloud;
typedef pcl::FPFHSignature33 FeatureT;
typedef pcl::PointCloud<FeatureT> FeatureCloud;
/*完成点云重叠部分识别*/

using namespace std;
using namespace pcl;

namespace fs = std::experimental::filesystem;


void readdata(vector<vector<int>>& readVecall)
{

    vector<int> readVec;
    int sign = 0;
    string Path = "D:\\vss\\c++\\shibie\\shibie\\data";
    string startName = "data_0.bin";
    string allpath = Path + "\\" + startName;
    while (fs::exists(allpath)) {
        std::ifstream inFile(allpath, std::ios::binary);

        ++sign;
        startName = "data_" + std::to_string(sign) + ".bin";
        allpath = Path + "\\" + startName;

        if (!inFile) {
            std::cerr << "无法打开文件 '" << allpath << "' !" << std::endl;
            continue;
        }
        size_t size;
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size));

        // 根据大小读取数据
        readVec.resize(size);
        inFile.read(reinterpret_cast<char*>(readVec.data()), size * sizeof(int));
        readVecall.push_back(readVec);
        inFile.close();

    }
    if (readVecall.size() <= 0) {
        cout << "无效文件个数" << endl;
    }
    /*string fileName = "D:\\vss\\c++\\shibie\\shibie\\data\\data_0.bin";*/

}


void fuzhi(vector<int>& i1, const std::string& pathh) {//该方法用于读取索引值并存储到动态数组中,提供数组名称和文件路径
    ifstream file(pathh);

    if (!file.is_open()) {
        cout << "无法打开文件" << endl;
        return;
    }

    string line;
    while (getline(file, line) ) {
        istringstream iss(line);
        
        int number;
        while (iss >> number) {
            i1.push_back(number);
        }
    }

    /*for (int i = 0; i < 3; i++) {
        i1[i] = 123;
    }
    for (int i = 0; i < 3; i++) {
        i2[i] = 123;
    }*/
}

void pcdprint() {
    auto start = std::chrono::high_resolution_clock::now();

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
  
    cloud = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);

    pcl::io::loadPCDFile<pcl::PointXYZ>("G:/杯子/_0.pcd", *cloud);

    printf("%f, %f, %f",cloud->points[2432998].x, cloud->points[2432998].y, cloud->points[2432998].z);



    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end1 - start;
    std::cout << "用时: " << elapsed.count()/1000.0 << " 秒" << std::endl;
    
}//存在对应关系

void loadcloudsy121(vector<pcl::PointCloud<pcl::PointXYZ>::Ptr>& cloud, const vector<vector<int>>& sy, vector<pcl::PointCloud<pcl::PointXYZ>::Ptr>& cloudsy) {

    //注意次加载方法是针对中间点云对应两个数量的索引点点云
    int n = 2;//此处n为载入的点云数量
    if (n < 2) return;
    cloud.resize(n);//设置点云个数
    cloudsy.resize((n - 1) * 2);//设置索引点点云个数


    for (int i = 0; i < cloud.size(); i++) {
        cloud[i] = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
    }
    //分配智能指针
    for (int i = 0; i < cloudsy.size(); i++) {
        cloudsy[i] = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
    }//为两种点云分配智能指针


    pcl::io::loadPCDFile<pcl::PointXYZ>("cup/_0.pcd", *cloud[0]);
    pcl::io::loadPCDFile<pcl::PointXYZ>("cup/_2.pcd", *cloud[1]);
   //pcl::io::loadPCDFile<pcl::PointXYZ>("cup/_5.pcd", *cloud[2]);//点云部分的加载


    /* pcl::io::loadPCDFile<pcl::PointXYZ>("zy/2.2.pcd", *cloud[2]);
     pcl::io::loadPCDFile<pcl::PointXYZ>("zy/2.10.pcd", *cloud[3]);
     pcl::io::loadPCDFile<pcl::PointXYZ>("zy/2.11.pcd", *cloud[4]);
     pcl::io::loadPCDFile<pcl::PointXYZ>("zy/2.3.pcd", *cloud[5]);
     pcl::io::loadPCDFile<pcl::PointXYZ>("zy/2.4.pcd", *cloud[6]);
     pcl::io::loadPCDFile<pcl::PointXYZ>("zy/2.5.pcd", *cloud[7]);*///加载需要的点云


     /*将点放入动态数组中*/
    //for (int i = 0; i < sy[0].size(); i++) {
    //    pcl::PointXYZ a;
    //    a.x = cloud[0]->points[sy[0][i]].x;
    //    a.y = cloud[0]->points[sy[0][i]].y;
    //    a.z = cloud[0]->points[sy[0][i]].z;
    //    //yu1.push_back(a);


    //    cloudsy[0]->points.push_back(a);

    //}

    for (int i = 0, intex = 0; i < sy.size(); i++) {
        for (int j = 0; j < sy[i].size(); j++) {
            pcl::PointXYZ a;
            pcl::PointXYZ b;
            if (i == 0 || i == sy.size() - 1) {//如果是第一个或者最后一个点云的点
                a.x = cloud[intex]->points[sy[i][j]].x;
                a.y = cloud[intex]->points[sy[i][j]].y;
                a.z = cloud[intex]->points[sy[i][j]].z;

                cloudsy[i]->points.push_back(a);
            }
            else {
                a.x = cloud[intex]->points[sy[i][j]].x;
                a.y = cloud[intex]->points[sy[i][j]].y;
                a.z = cloud[intex]->points[sy[i][j]].z;

                b.x = cloud[intex]->points[sy[i + 1][j]].x;
                b.y = cloud[intex]->points[sy[i + 1][j]].y;
                b.z = cloud[intex]->points[sy[i + 1][j]].z;//两个索引出自同一个点云
                //yu2.push_back(a);

                cloudsy[i]->points.push_back(a);
                cloudsy[i + 1]->points.push_back(b);//cloudsy和sy是一一对应的

            }
        }
        if (i != 0) {
            i++;
        }
        intex++;
    }

 

    for (int x = 0; x < sy.size(); x++) {
        for (int i = 0; i < sy[x].size(); i++)
            printf("%d index %d :x:%f y:%f z:%f\n", x, i, cloudsy[x]->points[i].x, cloudsy[x]->points[i].y, cloudsy[x]->points[i].z);
        printf("\n");

    }

    //完成了索引值导入到索引值点云中的内容
    //第0点云和最后点云分别对应一个索引值点云，中间点云对应两个索引值点云
    //后续完成对以下代码的调用
    for (int i = 0; i < cloudsy.size(); i++) {
        cloudsy[i]->width = cloudsy[i]->points.size();
        cloudsy[i]->height = 1; // 无序点云
        cloudsy[i]->is_dense = true; // 所有数据都是有效的
    }

}

void rf(vector<string>& pathstr) {


    nfdresult_t result;

    // 使用 NFD_OpenDialogMultiple 来选择多个文件
    nfdpathset_t outPaths;
    result = NFD_OpenDialogMultiple("pcd", NULL, &outPaths);//"D:\vss\c++\shibie\shibie\cup"


    if (result == NFD_OKAY) {
        puts("get Success!");

        // 遍历选中的文件路径
        nfdchar_t* path = NULL;
        size_t count = NFD_PathSet_GetCount(&outPaths);
        for (size_t i = 0; i < count; i++) {
            if (path = NFD_PathSet_GetPath(&outPaths, i)) {
                pathstr.push_back(path);

                // puts(path);
                 // 在这里可以对 path 进行处理，比如保存到列表中
            }
        }

        // 释放 outPaths 的内存
        //NFD_FreePathSet(&outPaths);
    }
    else if (result == NFD_CANCEL) {
        puts("User pressed cancel.");
    }
    else {
        printf("Error: %s\n", NFD_GetError());
    }

}

void loaddianyun(string path, pcl::PointCloud<pcl::PointXYZ>::Ptr &cloud){
    cout << "Start loading: " << path << endl;
    try {
        pcl::io::loadPCDFile<pcl::PointXYZ>(path, *cloud);
        cout << "Finish loading: " << path << endl;
    }
    catch (const pcl::IOException& e) {
        cerr << "Error loading " << path << ": " << e.what() << endl;
    }
}

void loadcloudsy(vector<pcl::PointCloud<pcl::PointXYZ>::Ptr>& cloud, const vector<vector<int>>& sy, vector<pcl::PointCloud<pcl::PointXYZ>::Ptr>& cloudsy, const int& n, const vector<string>& pathstr) {
   
    //注意次加载方法是针对中间点云对应1个数量的索引点点云
    //int n = 4;//此处n为载入的点云数量
    if (n < 2) return;
    cloud.resize(n);//设置点云个数
    cloudsy.resize(n);//设置索引点点云个数


    for (int i = 0; i < cloud.size(); i++) {
        cloud[i] = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
    }
    //分配智能指针
    for (int i = 0; i < cloudsy.size(); i++) {
        cloudsy[i] = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
    }//为两种点云分配智能指针

     //vector<thread> tn;
    
    for (int i = 0; i < n; i++) {
        cout << "Start loading: " << pathstr[i] << endl;
        pcl::io::loadPCDFile<pcl::PointXYZ>(pathstr[i], *cloud[i]);//此处读取无问题
        cout << "Finish loading: " << pathstr[i] << endl;
        //tn.emplace_back(loaddianyun, pathstr[i], cloud[i]);
    }
    /*printf("拼接中.....\n");
    std::this_thread::sleep_for(std::chrono::seconds(2));

    printf("拼接完成，文件名称：finalXXXXX.pcd\n");
    return ;*/

    /*for (auto& t : tn) {
        t.join();
    }*/
    //pcl::io::loadPCDFile<pcl::PointXYZ>("cup/_0.pcd", *cloud[0]);
    //pcl::io::loadPCDFile<pcl::PointXYZ>("cup/_2.pcd", *cloud[1]);
    //pcl::io::loadPCDFile<pcl::PointXYZ>("cup/_5.pcd", *cloud[2]);//点云部分的加载
    //pcl::io::loadPCDFile<pcl::PointXYZ>("cup/_8.pcd", *cloud[3]);//此处需要根据点云数进行修改
    //pcl::io::loadPCDFile<pcl::PointXYZ>("cup/_10.pcd", *cloud[4]);
    //pcl::io::loadPCDFile<pcl::PointXYZ>("cup/_11.pcd", *cloud[5]);
    //pcl::io::loadPCDFile<pcl::PointXYZ>("cup/_12.pcd", *cloud[6]);
    //pcl::io::loadPCDFile<pcl::PointXYZ>("cup/_13.pcd", *cloud[7]);
    //pcl::io::loadPCDFile<pcl::PointXYZ>("cup/_15.pcd", *cloud[8]);
    //pcl::io::loadPCDFile<pcl::PointXYZ>("cup/_17.pcd", *cloud[9]);


    
   

    for (int i = 0; i < n; i++) {//此处修改为点云个数否则根据索引点个数可能会产生越界
        for (int j = 0; j < sy[i].size(); j++) {
            pcl::PointXYZ a;
            
                a.x = cloud[i]->points[sy[i][j]].x;
                a.y = cloud[i]->points[sy[i][j]].y;
                a.z = cloud[i]->points[sy[i][j]].z;

                if (pcl::isFinite(a)) {//对于无效的剔除操作
                   
                    cloudsy[i]->points.push_back(a);

                }

                //cloudsy[i]->points.push_back(a);
            }

        // 移除无效点
        //pcl::removeNaNFromPointCloud(*cloudsy[i], *cloudsy[i]);
    }

    //for (int j = 1, syx = 1; j <= 11; j = j + 2, syx++) {
    //    for (int i = 0; i < 3; i++) {//另外三个三维点结构体
    //        pcl::PointXYZ a, b;//a只是作为一个点
    //        a.x = cloud[syx]->points[sy[j][i]].x;
    //        a.y = cloud[syx]->points[sy[j][i]].y;
    //        a.z = cloud[syx]->points[sy[j][i]].z;
    //        b.x = cloud[syx]->points[sy[j + 1][i]].x;
    //        b.y = cloud[syx]->points[sy[j + 1][i]].y;
    //        b.z = cloud[syx]->points[sy[j + 1][i]].z;//两个索引出自同一个点云
    //        //yu2.push_back(a);
    //        cloudsy[j]->points.push_back(a);
    //        cloudsy[j + 1]->points.push_back(b);//cloudsy和sy是一一对应的
    //    }
    //}


    //for (int i = 0; i < sy[13].size(); i++) {//三个三维点结构体
    //    pcl::PointXYZ a;
    //    a.x = cloud[7]->points[sy[13][i]].x;
    //    a.y = cloud[7]->points[sy[13][i]].y;
    //    a.z = cloud[7]->points[sy[13][i]].z;
    //    cloudsy[13]->points.push_back(a);
    //}

    cout << "finish" << endl;

    for (int x = 0; x < n; x++) {//此处修改为点云个数否则根据索引点个数可能会产生越界
        for (int i = 0; i < cloudsy[x]->size(); i++)//该点云中的点进行遍历
            printf("%d index %d :x:%f y:%f z:%f \n", x, i,cloudsy[x]->points[i].x, cloudsy[x]->points[i].y, cloudsy[x]->points[i].z);
        printf("\n");

    }


    //添加对无效点的剔除操作

    cout << "finish1" << endl;
    //完成了索引值导入到索引值点云中的内容
    //第0点云和最后点云分别对应一个索引值点云，中间点云对应两个索引值点云
    //后续完成对以下代码的调用
    for (int i = 0; i < cloudsy.size(); i++) {
        cloudsy[i]->width = cloudsy[i]->points.size();
        cloudsy[i]->height = 1; // 无序点云
        cloudsy[i]->is_dense = true; // 所有数据都是有效的
    }
    // 索引点点云设置

}

void showsy(const vector<pcl::PointCloud<pcl::PointXYZ>::Ptr>& cloudsy) {
    // 创建可视化窗口
    visualization::PCLVisualizer::Ptr viewer(new visualization::PCLVisualizer("ICP demo"));

    // 设置背景颜色
    viewer->setBackgroundColor(0.0, 0.0, 0.0);

    // 设置点云颜色
    visualization::PointCloudColorHandlerCustom<PointXYZ> color_handler1(cloudsy[0], 255, 0, 0); // 红色
    visualization::PointCloudColorHandlerCustom<PointXYZ> color_handler2(cloudsy[1], 0, 255, 0); // 绿色
    visualization::PointCloudColorHandlerCustom<PointXYZ> color_handler3(cloudsy[2], 0, 0, 255);
    visualization::PointCloudColorHandlerCustom<PointXYZ> color_handler4(cloudsy[3], 0, 255, 255);
    // 添加点云到可视化窗口
    viewer->addPointCloud(cloudsy[0], color_handler1, "cloud1");
    viewer->addPointCloud(cloudsy[1], color_handler2, "cloud2");
    viewer->addPointCloud(cloudsy[2], color_handler3, "cloud3");
    viewer->addPointCloud(cloudsy[3], color_handler4, "cloud4");
    // 设置点云显示属性
    viewer->setPointCloudRenderingProperties(visualization::PCL_VISUALIZER_POINT_SIZE, 2, "cloud1");
    viewer->setPointCloudRenderingProperties(visualization::PCL_VISUALIZER_POINT_SIZE, 2, "cloud2");
    viewer->setPointCloudRenderingProperties(visualization::PCL_VISUALIZER_POINT_SIZE, 2, "cloud3");
    viewer->setPointCloudRenderingProperties(visualization::PCL_VISUALIZER_POINT_SIZE, 2, "cloud4");
    // 添加坐标系
    viewer->addCoordinateSystem(1.0);

    // 启动可视化
    while (!viewer->wasStopped()) {
        viewer->spinOnce(100);
    }
}

Eigen::Matrix4f getfinal(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1, pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2) {
    /*完成点云重叠部分识别*/
    // 1. 读取点云

    /*pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1;
    cloud1 = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2;
    cloud2 = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
    cloud1 = cloudsy[0];
    cloud2 = cloudsy[1];*/


    /*pcl::io::loadPCDFile("cloud1.pcd", *cloud1);
    pcl::io::loadPCDFile("cloud2.pcd", *cloud2);*/

    // 2. 预处理（去噪与下采样）
    float voxel_size = 0.05f;
    pcl::VoxelGrid<PointT> voxel_filter;
    voxel_filter.setLeafSize(voxel_size, voxel_size, voxel_size);
    voxel_filter.setInputCloud(cloud1);
    voxel_filter.filter(*cloud1);
    voxel_filter.setInputCloud(cloud2);
    voxel_filter.filter(*cloud2);

    // 统计滤波去噪
    pcl::StatisticalOutlierRemoval<PointT> sor;
    sor.setMeanK(20);
    sor.setStddevMulThresh(2.0);
    sor.setInputCloud(cloud1);
    sor.filter(*cloud1);
    sor.setInputCloud(cloud2);
    sor.filter(*cloud2);

    // 3. 法线估计
    pcl::NormalEstimation<PointT, pcl::Normal> ne;
    ne.setInputCloud(cloud1);
    pcl::search::KdTree<PointT>::Ptr tree(new pcl::search::KdTree<PointT>());
    ne.setSearchMethod(tree);
    ne.setRadiusSearch(0.1);
    pcl::PointCloud<pcl::Normal>::Ptr normals1(new pcl::PointCloud<pcl::Normal>);
    ne.compute(*normals1);

    ne.setInputCloud(cloud2);
    pcl::PointCloud<pcl::Normal>::Ptr normals2(new pcl::PointCloud<pcl::Normal>);
    ne.compute(*normals2);

    // 4. 提取FPFH特征
    pcl::FPFHEstimation<PointT, pcl::Normal, FeatureT> fpfh;
    fpfh.setInputCloud(cloud1);
    fpfh.setInputNormals(normals1);
    fpfh.setSearchMethod(tree);
    fpfh.setRadiusSearch(0.25);
    FeatureCloud::Ptr features1(new FeatureCloud);
    fpfh.compute(*features1);

    fpfh.setInputCloud(cloud2);
    fpfh.setInputNormals(normals2);
    FeatureCloud::Ptr features2(new FeatureCloud);
    fpfh.compute(*features2);

    // 5. 基于特征的RANSAC粗配准
    pcl::SampleConsensusInitialAlignment<PointT, PointT, FeatureT> sac_ia;
    sac_ia.setMinSampleDistance(0.05);
    sac_ia.setMaxCorrespondenceDistance(voxel_size * 1.5);
    sac_ia.setMaximumIterations(100000);
    sac_ia.setInputSource(cloud1);
    sac_ia.setInputTarget(cloud2);
    sac_ia.setSourceFeatures(features1);
    sac_ia.setTargetFeatures(features2);
    pcl::PointCloud<pcl::PointXYZ>::Ptr aligned_cloud1(new pcl::PointCloud<pcl::PointXYZ>);
    sac_ia.align(*aligned_cloud1);
    Eigen::Matrix4f initial_transform = sac_ia.getFinalTransformation();

    // 6. ICP精配准
    pcl::IterativeClosestPoint<PointT, PointT> icp;
    icp.setInputSource(aligned_cloud1);
    icp.setInputTarget(cloud2);
    icp.setMaxCorrespondenceDistance(0.05);
    icp.setMaximumIterations(100);
    icp.setTransformationEpsilon(1e-8);
    pcl::PointCloud<pcl::PointXYZ>::Ptr final_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    icp.align(*final_cloud);
    Eigen::Matrix4f final_transform = icp.getFinalTransformation() * initial_transform;

    //// 输出变换矩阵
    //std::cout << "Final transformation matrix:\n" << final_transform << std::endl;
    ///*此处final矩阵可以用于整体点云的匹配了*/
    //// 可视化（可选）
    /*pcl::visualization::PCLVisualizer viewer("Point Cloud Alignment");
    viewer.addPointCloud(cloud2, "cloud2");
    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 0.0, 1.0, 0.0, "cloud2");
    pcl::PointCloud<pcl::PointXYZ>::Ptr transformed_cloud1(new pcl::PointCloud<pcl::PointXYZ>);

    pcl::transformPointCloud(*cloud1, *transformed_cloud1, final_transform);
    viewer.addPointCloud(transformed_cloud1, "transformed_cloud1");
    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 1.0, 0.0, 0.0, "transformed_cloud1");
    viewer.spin();*/

    return final_transform;
}

#include<thread>

int main(int argc, char** argv)
{   
    // 在调用 ICP 前设置日志级别为 ERROR
    pcl::console::setVerbosityLevel(pcl::console::L_ERROR);


    vector<string> pathstr;
    rf(pathstr);

   
    std::vector<std::vector<int>> indices;
    readdata(indices);//读取指定文件夹中二进制数据并将路径保存至路径数组中

    if (pathstr.size() > indices.size()) {
        cout<<"操作不合法"<<endl;
        return -1;
    }
    for (auto ab : indices) {
        cout << "{";
        for (auto value : ab) {
            cout << value << ",";
        }
        cout << "}" << endl;
    }//显示读取到的数据



    std::vector<std::vector<int>> indices1 = { 
        { 1700760, 1147084, 3253274, 2323818, 2877658, 1883960, 138806, 3174474, 1538118, 2433000, 2685408, 979796, 114676, 1919250, 2853908, 2245872, 441322, 1741636, 2794786},//0
        { 1863894,207698, 3134606, 1527878, 2417812, 2665252, 964572, 94502, 1899086, 2848612, 386590, 2230706, 1706700, 2789522, 589584, 3195162, 1949338} ,//2
        { 3189586,2764116,539466,2210234,2309754,1904218,390824,1291334,1691166,2803434,1138394,1761348},//5
        { 1780534,3065960,564236,1058784,2289412,119620,1943920,1261096,1375414,1888820,3149490,583428,1464668},//8
        { 109156,1700960,1355070,2324362,1419690,934922,1933466,1063154,806822,2547170,583456,3040690,1779974,1531295},//10
        { 2537008,1474204,747198,376664,2309224,1389716,3125644,806922,1840246,914852,1359738,103940,2137092,149566,2463482,1093924, 1925791,1708158},//11
        { 356404,3115550,781732,1820008,74980,3115298,1458894,65274,1049004,2521710,2107040,1054108,2448268,761564,1384348,841768},//12
        { 2096848,1014082,3115246,1004370,2438088,2201020,3100170,1804872,2789408,776482,1592954,757512,2438540,35108,361064,1438842,2521468,822020,2488152, 1051679},//13
        { 1013956,1721428,2428034,742318,178920,2467810,2175664,1572538,2769004,2527366,989928,3066380,1028476,2407828,74242,2061674,2171740, 724731, 2267993},//15
        { 2521998,2245356,920298,35450,1681440,3095644,99372,2452542,2141728,697374,3056400,1123302,2422670,721848,1242234, 998716},//17
        { 99112,594226,711982,900258,1103284,1202482,1676238,2126658,2230266,2432526,2511850,2517506,3046280,3090444,2265344}//18 参数可行可以作为展示数据
    };


    //std::vector<std::vector<int>> indices12 = {
    //{ 115912,137569,442558,978560,1148319,1539354,1699524,1737925,1882723,1918014,2249595,2290444,2434235,2626502,2686644,2791052,2857626,2876422,3175709,3247097},
    //{ 95738,206462,387825,593293,965808,1561250,1705463,1857715,1900322,1945604,2231941,2419048,2666487,2790758,2847375,3135841,3193925},
    //{ 392059,540702,1137158,1290098,1689929,1762583,1905454,2208997,2310989,2765352,2802198,3188350},
    //{ 118383,562999,584663,973796,1060019,1259859,1374178,1465904,1779297,1897475,1945156,2288176,3064724,3150725},
    //{ 107920,584692,808057,916045,936158,1061918,1343703,1356306,1420925,1702196,1781210,1932229,2323125,2354752,2545933,3041925},
    //{ 105175,148330,377899,745961,808158,913616,1095159,1360974,1388479,1472967,1839009,1949275,2135856,2310459,2464718,2538243,3126880},
    //{ 64037,73744,357640,762800,780495,840531,1047767,1055343,1385584,1460130,1818772,2108276,2449503,2520473,3114313,3116534},
    //{ 33872,359827,758748,775246,823255,1005606,1012845,1440077,1591718,1803635,2098083,2199784,2439324,2439776,2486916,2520231,2790644,3098934,3114009},
    //{ 73005,177684,743553,991164,1012720,1029712,1573773,1720192,2062910,2170503,2176900,2406592,2426797,2466573,2528602,2767767,3067616},
    //{ 34214,100608,698609,723083,919062,1124537,1243470,1682675,1866368,2142963,2246592,2423906,2451305,2520761,3055163,3094408}
    //   };
    
    //编辑动态数组。此处根据需要值进行修改

    int cloudnum = pathstr.size();
    cout << cloudnum << endl;
    
    

    vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> cloud;
    vector<pcl::PointCloud<pcl::PointXYZ>::Ptr> cloudsy;
    loadcloudsy(cloud, indices, cloudsy, cloudnum,pathstr);//这里更改indices下标决定调用数据

    
    //return 0;
    

    const int num = cloudnum-1;//旋转变换矩阵个数

    Eigen::Matrix4f* final_transform = new Eigen::Matrix4f[num];//初始变换矩阵
    //Eigen::Matrix4f final_transform_1ebetter = getfinal(cloudsy[0], cloudsy[pathstr.size()-1]);//第一点云和最后点云必须要有重合部分才行
    //针对全局优化的问题现在有两个方案一个是g2o但是在window上较为复杂
    //2是用误差计算将误差平摊到所有点云上，实现较为简单，但是理论上效果不如前者
    for (int i = 0; i < num; i++) {
        cout << i << " " << i + 1 << endl;
        final_transform[i] = getfinal(cloudsy[i], cloudsy[i + 1]);//源点云，目标点云
    }

    Eigen::Matrix4f* final_transform_final = new Eigen::Matrix4f[num];//迭代矩阵
    for (int i = 0; i < num; i++) {
        Eigen::Matrix4f identityMatrix4x4 = Eigen::Matrix4f::Identity();//设置一个单位矩阵
        for (int j = num-1; j >= i; j--) {
            identityMatrix4x4 = identityMatrix4x4 * final_transform[j];
        }
        final_transform_final[i] = identityMatrix4x4;
    }

    for(int i =0; i< num;i++)pcl::transformPointCloud(*cloud[i], *cloud[i], final_transform_final[i]);
   // for (int i = 1; i < num; i++)pcl::transformPointCloud(*cloud[i], *cloud[i], final_transform_final[i]);
    //pcl::transformPointCloud(*cloud[0], *cloud[0], final_transform_1ebetter);
    for (int i = num-1; i >= 0; i--) {
        *cloud[cloudnum-1] += *cloud[i];
    }
//    Eigen::Matrix4f final_transform = getfinal(cloudsy[1], cloudsy[2]);
//
//pcl::transformPointCloud(*cloud[1], *cloud[1], final_transform);//转换点云并完成拼接
//*cloud[2] +=  *cloud[1];


  //  return 0;
int ret = pcl::io::savePCDFileASCII("finalXXXXX.pcd", *cloud[cloudnum-1]);
if (ret == -1)
{
    std::cerr << "Couldn't save the point cloud to pjpyicp.pcd" << std::endl;
}
else {
    printf("拼接完成\n");
}
    return 0;
    /*完成点云重叠部分识别*/
  /*拼接效果非常完美*/
}




   
// shibie.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>
//#include<opencv2/opencv.hpp>
//using namespace cv;
//using namespace std;
//int main()
//{
//	Mat image = imread("I:/R-C (1).jpg");
//    namedWindow("Detected Circles", WINDOW_NORMAL);
//	if (image.empty()) {
//		cout << "没有输入值" << endl;
//		return 0;
//	}
//
//    // 将图像转换为灰度图像
//    Mat gray;
//    cvtColor(image, gray, COLOR_BGR2GRAY);
//
//    // 使用霍夫圆检测来检测圆
//    vector<Vec3f> circles;
//    HoughCircles(gray, circles, HOUGH_GRADIENT, 1, gray.rows / 8, 200, 100, 0, 0);
//
//    // 绘制检测到的圆并提取中心坐标
//    for (size_t i = 0; i < circles.size(); i++) {
//        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
//        int radius = cvRound(circles[i][2]);
//
//        // 绘制圆心
//        circle(image, center, 3, Scalar(0, 255, 0), -1, 8, 0);
//
//        // 绘制圆边界
//        circle(image, center, radius, Scalar(0, 0, 255), 3, 8, 0);
//
//        // 输出圆心坐标
//        cout << "圆心坐标: (" << center.x << ", " << center.y << ")" << endl;
//    }
//
//    // 显示图像
//    
//    imshow("Detected Circles", image);
//    waitKey(0);
//
//    return 0;
//}

////#include <opencv2/opencv.hpp>
////#include <iostream>
////#include<vector>
////#include <fstream>
////
////
////void creattxt() {
////
////    //创建文本文档
////    std::string filename = "Indexvalue.txt";
////    std::ofstream outFile(filename);
////    if (!outFile.is_open()) {
////        std::cerr << "无法打开文件" << filename << std::endl;
////    }
////}
////
////int main() {
////    // 读取图像
////
////    int xs_wide = 2472;
////    int xs_long = 0;
////    cv::Mat image0 = cv::imread("cup/_0.bmp");
////    cv::Mat image1 = cv::imread("cup/_2.bmp");
////    cv::Mat image2 = cv::imread("cup/_5.bmp");
////    //cv::Mat image1= cv::imread("dy/2.2.bmp");
////    /*cv::Mat image2 = cv::imread("dy/2.3.bmp");
////    cv::Mat image3 = cv::imread("dy/2.4.bmp");
////    cv::Mat image4 = cv::imread("dy/2.5.bmp");
////    cv::Mat image5 = cv::imread("dy/2.6.bmp");
////    cv::Mat image6 = cv::imread("dy/2.7.bmp");
////    cv::Mat image7 = cv::imread("dy/2.8.bmp");
////    cv::Mat image8 = cv::imread("dy/2.9.bmp");
////    cv::Mat image9 = cv::imread("dy/2.10.bmp");
////    cv::Mat image10 = cv::imread("dy/2.11.bmp")*/;
////    /*for (int i = 0; i < 11; i++) {
////        image0 = cv::imread("dy/2." + std::to_string(i+1) + ".bmp");
////        if (image0.empty()) {
////            std::cerr << "无法读取图像文件" << std::endl;
////            return -1;
////        }
////    }*/
////    /* cv::namedWindow("Detected Circles", cv::WINDOW_NORMAL);
////     for (int i = 0; i < 11; i++) {
////         cv::imshow("Detected Circles", image0);
////         cv::waitKey();
////     }*/
////
////
////
////     //1,125,755
////
////
////
////
////     // 将图像转换为灰度图
////    cv::Mat gray;
////    cv::Mat gray1;
////    cv::Mat gray2;
////    cv::cvtColor(image0, gray, cv::COLOR_BGR2GRAY);
////    cv::cvtColor(image1, gray1, cv::COLOR_BGR2GRAY);
////    cv::cvtColor(image2, gray2, cv::COLOR_BGR2GRAY);
////    // 对图像进行高斯模糊，以便更好地进行圆检测
////    cv::GaussianBlur(gray, gray, cv::Size(1311, 1311), 12, 12);
////    cv::imshow("a1", gray);
////    cv::GaussianBlur(gray1, gray1, cv::Size(9, 9), 2, 2);
////    cv::GaussianBlur(gray2, gray2, cv::Size(9, 9), 2, 2);
////    std::vector<int> suoyin;
////    // 使用霍夫圆变换检测圆
////    std::vector<cv::Vec3f> circles;
////    std::vector<cv::Vec3f> circles1;
////    std::vector<cv::Vec3f> circles2;
////    //cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1/*累加器分辨率越低圆质量要求越低，小于等于1*/, gray.rows / 10/*最小圆心距离*/, 200/*越大质量越高数量越少*/, 20/*小于前者，边缘中筛选圆*/, 0/*最小圆半径*/, 60/*最大圆半径*/);
////    cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1, gray.rows / 10, 165, 25, 10, 45);//160
////    cv::HoughCircles(gray1, circles1, cv::HOUGH_GRADIENT, 1, gray.rows / 10, 165, 25, 10, 45);//160
////    cv::HoughCircles(gray2, circles2, cv::HOUGH_GRADIENT, 1, gray.rows / 10, 165, 25, 10, 45);//160
////    //输入图像类型，存储圆信息变量，检测圆方法，圆心之间距离倒数，
////    // 累加器图像分辨率，高斯滤波阈值，圆心累加阈值，圆中心的初始累加阈值，最小圆半径
////    // 
////    // 绘制检测到的圆
////    for (size_t i = 0; i < circles.size(); i++) {//遍历识别到的每一个标记点圆心坐标并转换成索引值，以空格为间隔保存在文本文档中
////        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
////        int radius = cvRound(circles[i][2]);
////
////        int value = center.x + center.y * xs_wide;
////        suoyin.push_back(value);
////        //outFile << value << ' ';
////
////        //计算索引值并存储数据
////
////        std::cout << "Circle " << i + 1 << " - Center: (" << center.x << ", " << center.y << ")" << std::endl;
////
////        // 绘制圆心
////
////        cv::circle(image0, center, 1, cv::Scalar(0, 255, 0), -1, 8, 0);
////
////        // 绘制圆轮廓
////
////        cv::circle(image0, center, radius, cv::Scalar(0, 0, 255), 3, 8, 0);
////    }
////
////    for (size_t i = 0; i < circles1.size(); i++) {//遍历识别到的每一个标记点圆心坐标并转换成索引值，以空格为间隔保存在文本文档中
////        cv::Point center(cvRound(circles1[i][0]), cvRound(circles1[i][1]));
////        int radius = cvRound(circles1[i][2]);
////
////        int value = center.x + center.y * xs_wide;
////        suoyin.push_back(value);
////        //outFile << value << ' ';
////
////        //计算索引值并存储数据
////
////        std::cout << "Circle " << i + 1 << " - Center: (" << center.x << ", " << center.y << ")" << std::endl;
////
////        // 绘制圆心
////
////        cv::circle(image1, center, 1, cv::Scalar(0, 255, 0), -1, 8, 0);
////
////        // 绘制圆轮廓
////
////        cv::circle(image1, center, radius, cv::Scalar(0, 0, 255), 3, 8, 0);
////    }
////    for (size_t i = 0; i < circles2.size(); i++) {//遍历识别到的每一个标记点圆心坐标并转换成索引值，以空格为间隔保存在文本文档中
////        cv::Point center(cvRound(circles2[i][0]), cvRound(circles2[i][1]));
////        int radius = cvRound(circles2[i][2]);
////
////        int value = center.x + center.y * xs_wide;
////        suoyin.push_back(value);
////        //outFile << value << ' ';
////
////        //计算索引值并存储数据
////
////        std::cout << "Circle " << i + 1 << " - Center: (" << center.x << ", " << center.y << ")" << std::endl;
////
////        // 绘制圆心
////
////        cv::circle(image2, center, 1, cv::Scalar(0, 255, 0), -1, 8, 0);
////
////        // 绘制圆轮廓
////
////        cv::circle(image2, center, radius, cv::Scalar(0, 0, 255), 3, 8, 0);
////    }
////    cv::namedWindow("Detected Circles", cv::WINDOW_NORMAL);
////    // 显示结果
////    cv::imshow("Detected Circles", image0);
////
////    cv::namedWindow("Detected CirclesZZZ", cv::WINDOW_NORMAL);
////    // 显示结果
////    cv::imshow("Detected CirclesZZZ", image1);
////
////    cv::namedWindow("Detected CirclesZZZ1", cv::WINDOW_NORMAL);
////    // 显示结果
////    cv::imshow("Detected CirclesZZZ1", image2);
////
////    cv::waitKey(0);
////
////    return 0;
////}

//#include <opencv2/opencv.hpp>
//#include<vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace cv;
//using namespace std;
//
//
//
//
//bool compareX(const Vec3f& a, const Vec3f& b) {
//    return a[0] < b[0];
//}
//
//void circlecheack(const cv::Mat &gray, vector<Vec3f> &yuan,int a, int b, int minruis, int maxruis) {
//    cv::HoughCircles(gray, yuan, cv::HOUGH_GRADIENT, 1, gray.rows/10, a, b, minruis, maxruis);
//    sort(yuan.begin(), yuan.end(), compareX);
//}
//
//void drawpic(vector<Vec3f>&yuan, cv::Mat& img) {
//    for (int i = 0; i < yuan.size(); i++) {
//        cv::Point center(cvRound(yuan[i][0]), cvRound(yuan[i][1]));
//        int radius = cvRound(yuan[i][2]);
//        int value = center.x + center.y * 2472;
//        std::cout << "Circle " << i + 1 << " - Center: (" << center.x << ", " << center.y << ")" << ":" << value << std::endl;
//        cv::circle(img, center, 1, cv::Scalar(0, 255, 0), -1, 8, 0);
//        cv::circle(img, center, radius, cv::Scalar(0, 0, 255), 3, 8, 0);
//    }
//    yuan.clear();
//
//}
//vector<Vec3f> all;
//void draw(Mat& img, const vector<Vec3f>& yuan, int sw) {
//    
//    for (int i = 0; i < yuan.size(); i++) {
//        //if (yuan[i][0] <= 193 || yuan[i][0] >= 1242) continue;
//        //if (yuan[i][0] > 193) continue;
//        if (yuan[i][1] > 1589) {
//            continue;
//        }
//       if (sw == 2) { if (yuan[i][0] < 1242) continue; }
//        else if (sw == 1) { if (yuan[i][0] <= 193 || yuan[i][0] >= 1242) continue; }
//        else if (sw == 0) { if (yuan[i][0] > 193) continue; }
//
//        all.push_back(yuan[i]);
//        
//    }
//    
//}
//
//
//
//int main() {
//    // 读取两张图像
//    Mat img = imread("cup/_0.bmp");
//    Mat img1 = imread("cup/_2.bmp");
//
//    if (img.empty() || img1.empty()) {
//        cout << "Could not open or find the images!" << endl;
//        return -1;
//    }
//
//   
//
//
//    Mat gray;
//    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);//转灰度值
//    cv::GaussianBlur(gray, gray, cv::Size(9, 9), 2, 2);//高斯滤波
//
//    Mat gray1;
//    cv::cvtColor(img1, gray1, cv::COLOR_BGR2GRAY);//转灰度值
//    cv::GaussianBlur(gray1, gray1, cv::Size(9, 9), 2, 2);//高斯滤波
//
//
//    /*中间区域参数
//    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);//转灰度值
//    cv::GaussianBlur(gray, gray, cv::Size(9, 9), 2, 2);//高斯滤波
//    vector<Vec3f> yuan;
//    cv::HoughCircles(gray, yuan, cv::HOUGH_GRADIENT, 1, gray.rows / 10, 165, 25, 10, 45);// */
//    /*中间区域参数*/
//
//    /*边缘区域参数1
//    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);//转灰度值
//    cv::GaussianBlur(gray, gray, cv::Size(9, 9), 2, 2);//高斯滤波
//    vector<Vec3f> yuan;
//    cv::HoughCircles(gray, yuan, cv::HOUGH_GRADIENT, 1, gray.rows / 10, 40, 10, 10, 20);// */ //输入图像，输出数组，检测方式，累加器分辨率，最小圆心距，边缘阈值，圆心阈值，最小半径，最大半径
//    /*边缘区域参数1*/
//    vector<Vec3f> yuan;
//    vector<Vec3f> yuan1;
//    /*边缘区域参数2
//    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);//转灰度值
//    cv::GaussianBlur(gray, gray, cv::Size(9, 9), 2, 2);//高斯滤波
//    vector<Vec3f> yuan;
//    cv::HoughCircles(gray, yuan, cv::HOUGH_GRADIENT, 1, gray.rows / 10, 40, 10, 10, 28);// */
//    /*边缘区域参数2*/
//
//   circlecheack(gray, yuan, 40, 10, 10, 20);
//    draw(img, yuan, 0);
//    yuan.clear();
//    circlecheack(gray, yuan, 165, 25, 10, 45);
//    draw(img, yuan, 1);
//    yuan.clear();
//    circlecheack(gray, yuan, 40, 10, 10, 28);
//    draw(img, yuan, 2);
//    yuan.clear();
//    drawpic(all, img);
//
//    circlecheack(gray1, yuan1, 40, 10, 10, 20);
//    draw(img1, yuan1, 0);
//    yuan1.clear();
//    circlecheack(gray1, yuan1, 165, 25, 10, 45);
//    draw(img1, yuan1, 1);
//    yuan1.clear();
//    circlecheack(gray1, yuan1, 40, 10, 10, 28);
//    draw(img1, yuan1, 2);
//    yuan1.clear();
//    drawpic(all, img1);
//
//    
//
//    //for (int i = 0; i < yuan.size(); i++) {
//    //    //if (yuan[i][0] <= 193 || yuan[i][0] >= 1242) continue;
//    //    //if (yuan[i][0] > 193) continue;
//    //    if (yuan[i][0] < 1242) continue;
//    //    cv::Point center(cvRound(yuan[i][0]), cvRound(yuan[i][1]));
//    //            int radius = cvRound(yuan[i][2]);
//    //            int value = center.x + center.y * 2472;           
//    //            std::cout << "Circle " << i + 1 << " - Center: (" << center.x << ", " << center.y << ")" << std::endl;
//    //            cv::circle(img, center, 1, cv::Scalar(0, 255, 0), -1, 8, 0);
//    //            cv::circle(img, center, radius, cv::Scalar(0, 0, 255),3, 8, 0);
//    //}
//
//  cv::namedWindow("Matches", cv::WINDOW_NORMAL);
//    cv::imshow("Matches",img);
//
//    cv::namedWindow("Matches1", cv::WINDOW_NORMAL);
//    cv::imshow("Matches1", img1);
//
//    cv::waitKey(0);
//
//
//    cv::destroyAllWindows();
//
//    return 0;
//}

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <experimental/filesystem>
#include <fstream>
#include< filesystem >

#include <nfd.h>

namespace fs = std::experimental::filesystem;

using namespace cv;
using namespace std;


//写入二进制数据
void writedata(vector<int> vec) {//往指定文件夹写入二进制数据
    int sign = 0;
    string Path = "D:\\vss\\c++\\shibie\\shibie\\data";
    string startName = "data_0.bin";
    string allpath = Path + "\\" + startName;
    while (fs::exists(allpath)) {
        ++sign;
         startName = "data_" + std::to_string(sign) + ".bin";
         allpath = Path + "\\" + startName;
    }
    std::ofstream outFile(allpath, std::ios::binary);
        if (!outFile) {
            std::cerr << "无法打开文件 '" << startName << "' !" << std::endl;
            
            return;
        }

        // 先写入容器的大小
        size_t size = vec.size();
        outFile.write(reinterpret_cast<char*>(&size), sizeof(size));//写入容器大小，传入元素个数和元素计量变量的字节长度，方便后续读取时读取元素个数

        // 写入容器数据
        outFile.write(reinterpret_cast<char*>(vec.data()), vec.size() * sizeof(int));
        outFile.close();
}
//读取二进制数据
void readdata(vector<vector<int>>& readVecall)//根据文件路径写入二进制数据为动态数组数据
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
    /*string fileName = "D:\\vss\\c++\\shibie\\shibie\\data\\data_0.bin";*/
    
}

//索引值大小排序
bool compareX(const int& a, const int& b) {
        return a < b;
    }
//霍夫圆参数结构体
struct CircleDetectionParams {
    int blurSize = 9;          // 高斯模糊核尺寸（奇数）
    int cannyThreshold = 165;  // Canny边缘检测阈值
    int accumThreshold = 25;   // 累加器阈值（越小检测越多圆）
    int minRadius = 10;        // 最小圆半径
    int maxRadius = 45;       // 最大圆半径
    double minDistFactor = 0.1;// 最小圆心距离因子（相对于图像尺寸）
};
//霍夫圆识别
vector<Vec3f> detectCircles(const Mat& input, const CircleDetectionParams& params) {
    Mat gray, blurred;
    vector<Vec3f> circles;

    // 图像预处理
    cvtColor(input, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, blurred, Size(params.blurSize, params.blurSize), 2, 2);

    // 计算动态参数
    double minDist = input.rows * params.minDistFactor;//将double类型转换成int类型static_cast<int>()

    // 霍夫圆检测
    HoughCircles(blurred, circles, HOUGH_GRADIENT,
        1,   // 累加器分辨率（与图像相同）
        minDist,          // 最小圆心间距
        params.cannyThreshold,  // Canny高阈值
        params.accumThreshold,  // 累加器阈值
        params.minRadius,       // 最小半径
        params.maxRadius);      // 最大半径

    return circles;
}
//绘制圆心方法
void drawpic(const vector<Vec3f>& circles, Mat result) {
    if (circles.empty()) {
        cout << "未检测到任何圆形" << endl;
    }
    else {
       
        for (const auto& c : circles) {
            Point center(cvRound(c[0]), cvRound(c[1]));//cvRound 会将输入的浮点数四舍五入到最接近的整数
            int radius = cvRound(c[2]);
            //cout << "这是方法里的索引值" << center.x + center.y * 2472 << endl;
            // 绘制圆心和轮廓
            circle(result, center, 3, Scalar(0, 255, 0), -1);   // 绿色圆心
            circle(result, center, radius, Scalar(0, 0, 255), 2); // 红色轮廓

          
        }
        
    }

    // 显示结果图像
    cv::namedWindow("检测结果", cv::WINDOW_NORMAL);
    imshow("检测结果", result);
    waitKey(0);
}

//识别方法抽象类
class basepic {
public:
    //"=0"为抽象类的标志，如果不重写那么派生类也为抽象类不会被实例化
    virtual vector<int> allpic(Mat src) = 0 {};
    //纯虚函数必须被定义，当然也可以在派生类中重写定义
    virtual ~basepic() =0{
    //如果基类析构函数不为虚函数，在调用基类虚构函数时不会自动调用子类虚构函数造成未定义行为
    //纯虚析构函数表明了该类为抽象类，不能被实例化，且必须定义该虚构函数
    //纯虚析构函数需要在派生类中被重写，否则派生类无法实例化。这一规则与普通纯虚函数的行为一致
        //printf("父类已清除\n");
    };//声明后必须接定义
};




bool cmp(vector<Point> a, vector<Point> b) {
    return  contourArea(a) < contourArea(b);
}

int  sign = 0;

//灰度质心法
class huidu : public basepic {
public:
    ~huidu() override {}
    vector<int> allpic(Mat src) override {
        
        //存储索引值
        vector<int> sy;

        if (src.empty()) {
            cout << "无法加载图像！" << endl;
            return sy;
        }

        // 2. 转换为灰度图
        Mat gray;
        cvtColor(src, gray, COLOR_BGR2GRAY);

        // 3. 高斯模糊去噪
        GaussianBlur(gray, gray, Size(5, 5), 0);

        // 4. 二值化分割
        Mat binary, binary1;
        //将图像进行二值化操作
        threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);//输入图像、输出图像、变换值、变换值、二值化模式、自动阈值标志

        // 反转黑白关系
       // bitwise_not(binary, binary1);
        bitwise_not(binary, binary);
        
        //// 二值化并反转黑白关系
        //threshold(gray, binary, 127, 255, THRESH_BINARY_INV);

        

        // 5. 形态学闭运算填充孔洞
        Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));//将图像上指定图像进行指定类型的腐蚀膨胀操作，这里的模型为椭圆
        morphologyEx(binary, binary, MORPH_CLOSE, kernel);
        // 对二值图像binary进行闭运算操作。闭运算可以有效地去除图像中的小黑点或者连接一些断开的部分，同时保持图像的整体形状和大小不变。

         //针对背景为白色的问题，反转二值化用标记点黑边作为轮廓识别

        // 6. 查找所有外轮廓
        vector<vector<Point>> contours;
        findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
        //RETR_EXTERNAL：轮廓检索模式，表示只检测最外层的轮廓，忽略内部的孔洞或其他嵌套轮廓。
       // CHAIN_APPROX_SIMPLE：轮廓近似方法，表示将轮廓压缩为简单的顶点，例如将直线上的多个点简化为两个端点。
        if (contours.empty()) {
            cout << "未检测到轮廓！" << endl;
            return sy;
        }

        // 6.1 按面积从小到大排序轮廓
        sort(contours.begin(), contours.end(), cmp);

        

        // 7. 遍历所有轮廓并计算圆心
        for (size_t i = 0; i < contours.size(); i++) {
            // 7.1 跳过过小的轮廓（根据实际需求调整阈值）
            double area = contourArea(contours[i]);
            if (area < 20) { // 示例阈值：面积小于100的轮廓忽略
                continue;
            }
            else if (area > 30000) {
                break;
            }
            cout << area << endl;

            // 7.2 创建当前轮廓的掩膜
            Mat mask = Mat::zeros(binary.size(), CV_8UC1);
            drawContours(mask, contours, i, Scalar(255), FILLED);

            // 7.3 计算灰度重心
            Rect roi = boundingRect(contours[i]);
            double sumX = 0.0, sumY = 0.0, sumWeight = 0.0;

            for (int y = roi.y; y < roi.y + roi.height; y++) {
                for (int x = roi.x; x < roi.x + roi.width; x++) {
                    if (mask.at<uchar>(y, x) == 255) {
                        uchar weight = gray.at<uchar>(y, x);
                        sumX += x * weight;
                        sumY += y * weight;
                        sumWeight += weight;
                    }
                }
            }

            if (sumWeight <= 0) {
                cout << "轮廓 " << i << " 权重总和为0，跳过！" << endl;
                continue;
            }

            // 7.4 计算圆心并绘制
            Point2d center(sumX / sumWeight, sumY / sumWeight);
            circle(src, center, 7, Scalar(0, 255, 0), -1); // 绿色圆心
            cout << "轮廓 " << i << " 圆心坐标: (" << center.x << ", " << center.y << ")" << endl;

           int x = cvRound(center.x) + cvRound(center.y) * 2472;
          //  int x = cvRound(center.x+ center.y * 2472);
            sy.push_back(x);
        }

       /* if (sign == 5 || sign == 6) {
            cv::namedWindow("Result1", cv::WINDOW_NORMAL);
            imshow("Result1", binary1);
        }
        sign++;*/
        // 8. 显示结果
        cv::namedWindow("Result", cv::WINDOW_NORMAL);
        imshow("Result", src);
        waitKey(0);


        return sy;
    }
};


vector<Point2d> huiduzhixin(Mat src) {

    //存储索引值
    vector<Point2d> sy;

    if (src.empty()) {
        cout << "无法加载图像！" << endl;
        
    }

    // 2. 转换为灰度图
    Mat gray;
    cvtColor(src, gray, COLOR_BGR2GRAY);

    // 3. 高斯模糊去噪
    GaussianBlur(gray, gray, Size(5, 5), 0);

    // 4. 二值化分割
    Mat binary, binary1;
    //将图像进行二值化操作
    threshold(gray, binary, 0, 255, THRESH_BINARY | THRESH_OTSU);//输入图像、输出图像、变换值、变换值、二值化模式、自动阈值标志

    // 反转黑白关系
 //   bitwise_not(binary, binary1);
    bitwise_not(binary, binary);

    //// 二值化并反转黑白关系
    //threshold(gray, binary, 127, 255, THRESH_BINARY_INV);



    // 5. 形态学闭运算填充孔洞
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));//将图像上指定图像进行指定类型的腐蚀膨胀操作，这里的模型为椭圆
    morphologyEx(binary, binary, MORPH_CLOSE, kernel);
    // 对二值图像binary进行闭运算操作。闭运算可以有效地去除图像中的小黑点或者连接一些断开的部分，同时保持图像的整体形状和大小不变。

     //针对背景为白色的问题，反转二值化用标记点黑边作为轮廓识别

    // 6. 查找所有外轮廓
    vector<vector<Point>> contours;
    findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    //RETR_EXTERNAL：轮廓检索模式，表示只检测最外层的轮廓，忽略内部的孔洞或其他嵌套轮廓。
   // CHAIN_APPROX_SIMPLE：轮廓近似方法，表示将轮廓压缩为简单的顶点，例如将直线上的多个点简化为两个端点。
    if (contours.empty()) {
        cout << "未检测到轮廓！" << endl;
     
    }

    // 6.1 按面积从小到大排序轮廓
    sort(contours.begin(), contours.end(), cmp);



    // 7. 遍历所有轮廓并计算圆心
    for (size_t i = 0; i < contours.size(); i++) {
        // 7.1 跳过过小的轮廓（根据实际需求调整阈值）
        double area = contourArea(contours[i]);
        if (area < 20) { // 示例阈值：面积小于100的轮廓忽略
            continue;
        }
        else if (area > 30000) {
            break;
        }
        cout <<"区域大小为"<< area << endl;

        // 7.2 创建当前轮廓的掩膜
        Mat mask = Mat::zeros(binary.size(), CV_8UC1);
        drawContours(mask, contours, i, Scalar(255), FILLED);

        // 7.3 计算灰度重心
        Rect roi = boundingRect(contours[i]);
        double sumX = 0.0, sumY = 0.0, sumWeight = 0.0;

        for (int y = roi.y; y < roi.y + roi.height; y++) {
            for (int x = roi.x; x < roi.x + roi.width; x++) {
                if (mask.at<uchar>(y, x) == 255) {
                    uchar weight = gray.at<uchar>(y, x);
                    sumX += x * weight;
                    sumY += y * weight;
                    sumWeight += weight;
                }
            }
        }

        if (sumWeight <= 0) {
            cout << "轮廓 " << i << " 权重总和为0，跳过！" << endl;
            continue;
        }

        // 7.4 计算圆心并绘制
        Point2d center(sumX / sumWeight, sumY / sumWeight);

        circle(src, center, 10, Scalar(0, 255, 0), -1); // 绿色圆心

        cout << "偏移圆心坐标: (" << center.x << ", " << center.y << ")" << endl;

        /*int x = cvRound(center.x) + cvRound(center.y) * 2472; */
        sy.push_back(center);
    }

    //if (sign == 5 || sign == 6) {
    //    cv::namedWindow("Result1", cv::WINDOW_NORMAL);
    //    imshow("Result1", binary1);
    //}
    //sign++;
   

    // 8. 显示结果
   /* cv::namedWindow("Result", cv::WINDOW_NORMAL);
    imshow("Result", src);
    waitKey(0);*/


    return sy;
}

class sonpic1 : public basepic {
public:
    ~sonpic1() override {//推荐增加override，表示对基类虚构函数的重写
        //printf("子类已清除\n");
    };
    vector<int> allpic(Mat src) override {
        Vec2i leftpoint = Vec2i(0, 0);//左端起始点
        Vec2i midpoint = Vec2i(193, 0);//中端起始点
        Vec2i rightpoint = Vec2i(2000, 0);//右端起始点
        int mid_left = midpoint[0] - leftpoint[0];//中间到左边的像素宽度
        int right_mid = rightpoint[0] - midpoint[0];//右边到中间的像素宽度
        int end_right = 347;//右端延伸宽度
        Rect leftrect(leftpoint[0], leftpoint[1], mid_left, src.rows - 500);//左上角xy值，以及像素宽度和像素高度,算上起点一共193个像素
        Rect midrect(midpoint[0], midpoint[1], right_mid, src.rows - 500);
        Rect rightrect(rightpoint[0], rightpoint[1], end_right, src.rows - 500);


        Mat leftpart = src(leftrect);
        Mat midpart = src(midrect);
        Mat rightpart = src(rightrect);


        // 设置检测参数（可根据实际情况调整）
        vector<Vec3f> all;
        vector<Vec3f> circles;
        /* vector<Point2d> circles;
         vector<Point2d> all;*/
        CircleDetectionParams params;//图片识别阈值结构体
        params.blurSize = 9;//高斯滤波卷积核大小
        params.cannyThreshold = 165;//边缘识别阈值
        params.accumThreshold = 25;//圆心投票阈值
        params.minRadius = 10;//最小圆半径
        params.maxRadius = 200;//最大圆半径
        params.minDistFactor = 0.1;//最小圆心距
        //  执行检测
        circles = detectCircles(midpart, params);//返回存储有圆心坐标的动态数组
        // 对circles中的坐标值进行修正
        for (int i = 0; i < circles.size(); i++) {
            circles[i][0] += midpoint[0];//对x坐标值进行修正
        }
        all.insert(all.end(), circles.begin(), circles.end());
        circles.clear();


        //circles = huiduzhixin(midpart);

        ////对circles中的坐标值进行修正
        //for (int i = 0; i < circles.size(); i++) {
        //    circles[i].x += midpoint[0];//对x坐标值进行修正
        //}
        //all.insert(all.end(), circles.begin(), circles.end());
        //circles.clear();


        //Mat result = src.clone();与Mat result = src;存在深拷贝和浅拷贝的问题，前者相互独立，后者共享内存

        params.blurSize = 7;
        params.cannyThreshold = 40;
        params.accumThreshold = 10;
        params.minRadius = 10;
        params.maxRadius = 20;
        params.minDistFactor = 0.1;
        circles = detectCircles(leftpart, params);//最左区域无需进行修正
        all.insert(all.end(), circles.begin(), circles.end());
        circles.clear();

        /*circles = huiduzhixin(leftpart);
        all.insert(all.end(), circles.begin(), circles.end());
        circles.clear();*/



        params.blurSize = 7;
        params.cannyThreshold = 40;
        params.accumThreshold = 10;
        params.minRadius = 10;
        params.maxRadius = 28;
        params.minDistFactor = 0.1;
        circles = detectCircles(rightpart, params);
        for (int i = 0; i < circles.size(); i++) {
            circles[i][0] += rightpoint[0];//对x坐标值进行修正
        }
        all.insert(all.end(), circles.begin(), circles.end());
        circles.clear();

        //circles = huiduzhixin(rightpart);

        ////对circles中的坐标值进行修正
        //for (int i = 0; i < circles.size(); i++) {
        //    circles[i].x += rightpoint[0];//对x坐标值进行修正
        //}
        //all.insert(all.end(), circles.begin(), circles.end());
        //circles.clear();


        vector<int> as;
        for (auto a : all) {
            int sy = cvRound(a[0]) + cvRound(a[1]) * 2472;//少了四舍五入经浮点数算出的索引值带入点云中会产生极多的无效值
            as.push_back(sy);
        }
        sort(as.begin(), as.end(), compareX);

        cout << "{";
        for (int i = 0; i < as.size(); i++) {
            if (i != as.size() - 1) {
                cout << as[i] << ",";
            }
            else {
                cout << as[i];
            }
        }
        cout << "}" << endl;

        //vector<Vec3f>all1(all.size());
        //for (int i = 0; i < all1.size(); i++) {
        //    all1[i][0] = all[i].x;
        //    all1[i][1] = all[i].y;
        //    all1[i][2] = 0;
        //}
        drawpic(all, src);//已规范化，后续增加批处理
        //
        //vector<int> as;
        //for (auto a : all) {
        //    int x = cvRound(a.x) + cvRound(a.y) * 2472;
        //    as.push_back(x);
        //}


        return as;
    }
};


// 读取二进制文件
void  readBinaryData(vector<vector<Rect>> &rects) {
    String directorypath = "D:/yolo10/result_binary";
    String filename = "_0.bin";
    String path = directorypath + "/" + filename;
    int signs = 1;
    while (fs::exists(path)) {
        cout <<signs-1<<endl;
        ifstream inFile(path, ios::binary);
        path = directorypath + "/_" + std::to_string(signs) + ".bin";//更新path
         signs++;
        if (!inFile) {
            cerr << "无法打开文件: " << path << endl;
            return;
        }

        // 读取矩形框数量（前4字节）
        uint32_t numBoxes;
        inFile.read(reinterpret_cast<char*>(&numBoxes), sizeof(numBoxes));

        // 读取每个矩形框的坐标
        vector<Rect>rect;
        for (uint32_t i = 0; i < numBoxes; i++) {
            float x1, y1, u, v;
            inFile.read(reinterpret_cast<char*>(&x1), sizeof(float));
            inFile.read(reinterpret_cast<char*>(&y1), sizeof(float));
            inFile.read(reinterpret_cast<char*>(&u), sizeof(float));
            inFile.read(reinterpret_cast<char*>(&v), sizeof(float));


            rect.push_back(Rect(cvRound(x1), cvRound(y1), cvRound(u), cvRound(v)));
          cout << i << ": x,y,u,v is: " << x1 << " " << " " << y1 << " " << u << " " << v << endl;;
        }

        cout << endl;
        
        rects.push_back(rect);
        inFile.close();
    }

    
    return ;
}


void rectandhuidu(Mat src,const vector<Rect>& rect, vector<int> &sy) {
    for (int i = 0; i < rect.size(); i++) {
       Mat rectp =  src(rect[i]);
         vector<Point2d> points = huiduzhixin(rectp);
         for (auto point : points) {
             point.x += rect[i].x;
             point.y += rect[i].y;//还原为真实值
             cout << "真实圆心坐标: (" << point.x << ", " << point.y << ")" << endl;
             //circle(src, point, 9, Scalar(0, 255, 0), -1); // 绿色圆心
             int temp = cvRound(point.x) + cvRound(point.y) * 2472;
             cout << "索引值(" << temp<< ")" << endl;

             sy.push_back(temp);//单个索引值划入动态数组
         }
    }

    cv::namedWindow("Resultureth", cv::WINDOW_NORMAL);
    imshow("Resultureth", src);
    waitKey(0);
    
}


//图像分区方法
class sonpic : public basepic {
public:
    ~sonpic() override {//推荐增加override，表示对基类虚构函数的重写
        //printf("子类已清除\n");
    };
    vector<int> allpic(Mat src) override {
        Vec2i leftpoint = Vec2i(0, 0);//左端起始点
        Vec2i midpoint = Vec2i(193, 0);//中端起始点
        Vec2i rightpoint = Vec2i(1242, 0);//右端起始点
        int mid_left = midpoint[0] - leftpoint[0];//中间到左边的像素宽度
        int right_mid = rightpoint[0] - midpoint[0];//右边到中间的像素宽度
        int end_right = 347;//右端延伸宽度
        Rect leftrect(leftpoint[0], leftpoint[1], mid_left, src.rows - 500);//左上角xy值，以及像素宽度和像素高度,算上起点一共193个像素
        Rect midrect(midpoint[0], midpoint[1], right_mid, src.rows - 500);
        Rect rightrect(rightpoint[0], rightpoint[1], end_right, src.rows - 500);


        Mat leftpart = src(leftrect);
        Mat midpart = src(midrect);
        Mat rightpart = src(rightrect);


        // 设置检测参数（可根据实际情况调整）
        vector<Vec3f> all;
        vector<Vec3f> circles;
       /* vector<Point2d> circles;
        vector<Point2d> all;*/
        CircleDetectionParams params;//图片识别阈值结构体
        params.blurSize = 9;//高斯滤波卷积核大小
        params.cannyThreshold = 165;//边缘识别阈值
        params.accumThreshold = 25;//圆心投票阈值
        params.minRadius = 10;//最小圆半径
        params.maxRadius = 45;//最大圆半径
        params.minDistFactor = 0.1;//最小圆心距
       //  执行检测
         circles = detectCircles(midpart, params);//返回存储有圆心坐标的动态数组
       // 对circles中的坐标值进行修正
        for (int i = 0; i < circles.size(); i++) {
            circles[i][0] += midpoint[0];//对x坐标值进行修正
        }
        all.insert(all.end(), circles.begin(), circles.end());
        circles.clear();
        
        
        //circles = huiduzhixin(midpart);

        ////对circles中的坐标值进行修正
        //for (int i = 0; i < circles.size(); i++) {
        //    circles[i].x += midpoint[0];//对x坐标值进行修正
        //}
        //all.insert(all.end(), circles.begin(), circles.end());
        //circles.clear();
        
        
        //Mat result = src.clone();与Mat result = src;存在深拷贝和浅拷贝的问题，前者相互独立，后者共享内存

        params.blurSize = 7;
        params.cannyThreshold = 40;
        params.accumThreshold = 10;
        params.minRadius = 10;
        params.maxRadius = 20;
        params.minDistFactor = 0.1;
        circles = detectCircles(leftpart, params);//最左区域无需进行修正
        all.insert(all.end(), circles.begin(), circles.end());
        circles.clear();

        /*circles = huiduzhixin(leftpart);
        all.insert(all.end(), circles.begin(), circles.end());
        circles.clear();*/



        params.blurSize = 7;
        params.cannyThreshold = 40;
        params.accumThreshold = 10;
        params.minRadius = 10;
        params.maxRadius = 28;
        params.minDistFactor = 0.1;
        circles = detectCircles(rightpart, params);
        for (int i = 0; i < circles.size(); i++) {
            circles[i][0] += rightpoint[0];//对x坐标值进行修正
        }
        all.insert(all.end(), circles.begin(), circles.end());
        circles.clear();
        
        //circles = huiduzhixin(rightpart);

        ////对circles中的坐标值进行修正
        //for (int i = 0; i < circles.size(); i++) {
        //    circles[i].x += rightpoint[0];//对x坐标值进行修正
        //}
        //all.insert(all.end(), circles.begin(), circles.end());
        //circles.clear();


        vector<int> as;
        for (auto a : all) {
            int sy = cvRound(a[0]) + cvRound(a[1]) * 2472;//少了四舍五入经浮点数算出的索引值带入点云中会产生极多的无效值
            as.push_back(sy);
        }
        sort(as.begin(), as.end(), compareX);

        cout << "{";
        for (int i = 0; i < as.size(); i++) {
            if (i != as.size() - 1) {
                cout << as[i] << ",";
            }
            else {
                cout << as[i];
            }
        }
        cout << "}" << endl;
        
        //vector<Vec3f>all1(all.size());
        //for (int i = 0; i < all1.size(); i++) {
        //    all1[i][0] = all[i].x;
        //    all1[i][1] = all[i].y;
        //    all1[i][2] = 0;
        //}
       
        
        //drawpic(all, src);//已规范化，后续增加批处理
        
        //
        //vector<int> as;
        //for (auto a : all) {
        //    int x = cvRound(a.x) + cvRound(a.y) * 2472;
        //    as.push_back(x);
        //}


        return as;
    }
};

class sonpic10 : public basepic {
public:
    ~sonpic10() override {//推荐增加override，表示对基类虚构函数的重写
        //printf("子类10已清除\n");
    };
    vector<int> allpic(Mat src) override {
        Vec2i leftpoint = Vec2i(0, 0);//左端起始点
        Vec2i midpoint = Vec2i(193, 0);//中端起始点
        Vec2i rightpoint = Vec2i(1242, 0);//右端起始点
        int mid_left = midpoint[0] - leftpoint[0];
        int right_mid = rightpoint[0] - midpoint[0];
        int end_right = 347;//右端延伸宽度
        Rect leftrect(leftpoint[0], leftpoint[1], mid_left, src.rows - 500);//左上角xy值，以及像素宽度和像素高度,算上起点一共193个像素
        Rect midrect(midpoint[0], midpoint[1], right_mid, src.rows - 500);
        Rect rightrect(rightpoint[0], rightpoint[1], end_right, src.rows - 500);


        Mat leftpart = src(leftrect);
        Mat midpart = src(midrect);
        Mat rightpart = src(rightrect);


        /*imshow("aaaaaa1", leftpart);

        imshow("aaaaaa2", midpart);

        imshow("aaaaaa3", rightpart);
        waitKey(0);*/

        // 设置检测参数（可根据实际情况调整）

        vector<Vec3f> all;
        vector<Vec3f> circles;
        CircleDetectionParams params;
        params.blurSize = 9;
        params.cannyThreshold = 165;
        params.accumThreshold = 25;
        params.minRadius = 10;
        params.maxRadius = 45;
        params.minDistFactor = 0.1;

        // 执行检测
        circles = detectCircles(midpart, params);//返回存储有圆心坐标的动态数组 //中区识别
        //对circles中的坐标值进行修正
        for (int i = 0; i < circles.size(); i++) {
            circles[i][0] += midpoint[0];//对x坐标值进行修正
        }
        all.insert(all.end(), circles.begin(), circles.end());
        // 显示结果
        //Mat result = src.clone();与Mat result = src;存在深拷贝和浅拷贝的问题，前者相互独立，后者共享内存
        circles.clear();


        params.blurSize = 7;
        params.cannyThreshold = 40;
        params.accumThreshold = 10;
        params.minRadius = 10;
        params.maxRadius = 20;
        params.minDistFactor = 0.2;
        circles = detectCircles(leftpart, params);//左区识别
        all.insert(all.end(), circles.begin(), circles.end());
        circles.clear();

        params.blurSize = 7;
        params.cannyThreshold = 40;
        params.accumThreshold = 10;
        params.minRadius = 10;
        params.maxRadius = 28;
        params.minDistFactor = 0.1;
        circles = detectCircles(rightpart, params);//右区识别
        for (int i = 0; i < circles.size(); i++) {
            circles[i][0] += rightpoint[0];//对x坐标值进行修正
        }
        all.insert(all.end(), circles.begin(), circles.end());
        circles.clear();




        vector<int> as;
        for (auto a : all) {
            int sy = cvRound(a[0]) + cvRound(a[1]) * 2472;
            as.push_back(sy);
        }
        sort(as.begin(), as.end(), compareX);

        cout << "{";
        for (int i = 0; i < as.size(); i++) {
            if (i != as.size() - 1) {
                cout << as[i] << ",";
            }
            else {
                cout << as[i];
            }
        }
        cout << "}" << endl;
        //  drawpic(all, src);//已规范化，后续增加批处理
        return as;
    }
};


//读取文件路径
void rf(vector<string>& pathstr) {
    

    nfdresult_t result;

    // 使用 NFD_OpenDialogMultiple 来选择多个文件
    nfdpathset_t outPaths;
    result = NFD_OpenDialogMultiple("bmp", NULL, &outPaths);//"D:\vss\c++\shibie\shibie\cup"
    

    if (result == NFD_OKAY) {
        puts("Success!");

        // 遍历选中的文件路径
        nfdchar_t* path = NULL;
        size_t count = NFD_PathSet_GetCount(&outPaths);
        for (size_t i = 0; i < count; i++) {
            if (path = NFD_PathSet_GetPath(&outPaths,i)) {
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


int main(int argc, char** argv) {

    vector<vector<Rect>> rects;//二维动态数组，i标识图片，j标识分区
    readBinaryData(rects);//没问题了




    vector<string> pathstr;
    rf(pathstr);//读取问价路径并放到动态数组中

    //Mat result = src.clone();与Mat result = src;存在深拷贝和浅拷贝的问题，前者相互独立，后者共享内存
    //std::vector<std::vector<int>> indices1 = {
    //   { 1700760, 1147084, 3253274, 2323818, 2877658, 1883960, 138806, 3174474, 1538118, 2433000, 2685408, 979796, 114676, 1919250, 2853908, 2245872, 441322, 1741636, 2794786},//0
    //   { 1863894,207698, 3134606, 1527878, 2417812, 2665252, 964572, 94502, 1899086, 2848612, 386590,2230706, 1706700, 2789522, 589584, 3195162, 1949338} ,//2
    //   { 3189586,2764116,539466,2210234,2309754,1904218,390824,1291334,1691166,2803434,1138394,1761348},//5
    //   { 1780534,3065960,564236,1058784,2289412,119620,1943920,1261096,1375414,1888820,3149490,583428,1464668},//8
    //   { 109156,1700960,1355070,2324362,1419690,934922,1933466,1063154,806822,2547170,583456,3040690,1779974,1531295},//10     
    //   { 2537008,1474204,747198,376664,2309224,1389716,3125644,806922,1840246,914852,1359738,103940,2137092,149566,2463482,1093924, 1925791,1708158},//11
    //   { 356404,3115550,781732,1820008,74980,3115298,1458894,65274,1049004,2521710,2107040,1054108,2448268,761564,1384348,841768},//12
    //   { 2096848,1014082,3115246,1004370,2438088,2201020,3100170,1804872,2789408,776482,1592954,757512,2438540,35108,361064,1438842,2521468,822020,2488152, 1051679},//13
    //   { 1013956,1721428,2428034,742318,178920,2467810,2175664,1572538,2769004,2527366,989928,3066380,1028476,2407828,74242,2061674,2171740, 724731, 2267993},//15
    //   { 2521998,2245356,920298,35450,1681440,3095644,99372,2452542,2141728,697374,3056400,1123302,2422670,721848,1242234, 998716}//17
    //};

     int numpa = pathstr.size();//根据文件路径个数创建图片个数

    
        // 读取输入图像
     vector<Mat> src(numpa);
     for (int i = 0; i < numpa; i++) {//图像识别有问题导致存在无效点
         src[i] = imread(pathstr[i]);//读取图片
         if (src[i].empty()) {
             cerr << i <<"错误：无法加载图像！" << endl;
             return -1;
         }

         

         //vector<Vec3f> circles;
         //CircleDetectionParams params;//图片识别阈值结构体
         //params.blurSize = 9;//高斯滤波卷积核大小
         //params.cannyThreshold = 165;//边缘识别阈值
         //params.accumThreshold = 25;//圆心投票阈值
         //params.minRadius = 10;//最小圆半径
         //params.maxRadius = 50;//最大圆半径
         //params.minDistFactor = 0.1;//最小圆心距
         ////  执行检测
         //circles = detectCircles(src[i], params);//返回存储有圆心坐标的动态数组
         //drawpic(circles, src[i]);//已规范化，后续增加批处理

         //continue;
          //以上注释作为调试时使用

             vector<int> all;

             rectandhuidu(src[i], rects[i], all);

            /* return 0;*/

         

         /*霍夫圆心识别方法*/
         //if (i <= 8) {
         //    sonpic a;//图像识别的子类
         //    basepic* b = &a;//图像识别父类承接子类
         //     all = b->allpic(src[i]);
         //    //这个给8及以前的图像使用

         //}
         //else {
         //    sonpic10 a;
         //    basepic* b = &a;
         //    all = b->allpic(src[i]);
         //    //这个给8以后的图像使用
         //}
        /*霍夫圆心识别方法*/
        
        //sonpic a;//此处修改所继承子类即可更换识别方法
        ////
        // basepic* b = &a;
        // all = b->allpic(src[i]);
       
        // cout << "{";
        // for (auto a : all) {
        //     cout << a<<" ";
        // }
        // cout << "}"<<endl;

        writedata(all);//此处保存二进制数据
         all.clear();

     }
        
    //    此处添加图片分隔，并记录偏移量
    //    int width, int height
    //    src.rows获取像素高度，src.cols获取像素宽度
    //    Rect leftrect(0,0,193,src.rows);//左上角xy值，以及像素宽度和像素高度,算上起点一共193个像素
    //    Rect midrect(193, 0, 1049, src.rows);
    //    Rect rightrect(1242, 0, 347, src.rows);
    //    
    //    实例化类对象行为
    //     sonpic* a = new sonpic();//是另一种实例化对象行为而new关键字返回的是指针
    //    
    //sonpic10 a;
    //basepic* b = &a;
    //b->allpic(src);
    //关于先定义子类在按指针分配或引用分配给父类对象其定义在栈上声明周期结束时自动调用析构函数清理
    //而用new关键字分配对象其定义在堆上需要手动调用delete关键字
    //
    //
    //实例化对象有两种方式：
    //1.new 分配在堆上手动调用delete 返回指针
    //2.是类名+名称 分配在栈上自动调用析构函数 返回对象实例
    //传递给父类有两种方式：
    //1.指针传递 传递指针
    //2.&传递 传递实例
    //

    return 0;
}




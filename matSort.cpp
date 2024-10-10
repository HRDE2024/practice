#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 创建一个随机的3x3矩阵
    cv::Mat mat = (cv::Mat_<float>(3, 3) << 0.1, 2.5, 0.3, 5.0, 1.5, 6.8, 7.1, 8.0, 3.5);
    
    // 展示原矩阵
    std::cout << "Original Matrix:\n" << mat << std::endl;

    // 将矩阵展平为一维数组
    cv::Mat flatMat = mat.reshape(1, 1); // 将矩阵展平

    // 使用cv::sortIdx来获取排序后的索引
    cv::Mat sortedIdx;
    cv::sortIdx(flatMat, sortedIdx, cv::SORT_DESCENDING); // 降序排序

    // 获取前N个最大值及其索引
    int N = 3; // 获取前3个最大值
    for (int i = 0; i < N; i++) {
        int idx = sortedIdx.at<int>(i);  // 获取第i个最大的值的索引
        float value = flatMat.at<float>(idx);  // 获取对应的值
        cv::Point originalIdx = cv::Point(idx % mat.cols, idx / mat.cols);  // 转换回原始二维矩阵中的位置

        std::cout << "Top " << i + 1 << ": Value = " << value 
                  << ", Original Index = (" << originalIdx.y << ", " << originalIdx.x << ")\n";
    }

    return 0;
}

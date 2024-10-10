#include <iostream>
#include <vector>

int main() {
    // 示例数据，可以替换为你的实际数据
    std::vector<double> vector1 /*= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}*/;
    std::vector<double> vector2 = {16, 17, 18, 19, 20};

    for (double j = 0; j < 500'000'000; j++)
        vector1.push_back(j);

    // 采样率（每秒多少个数据点，例如100Hz表示每秒100个数据点）
    int sampling_rate = 1'000'000;

    // 计算0.5秒对应的采样点数
    int points_in_half_second = static_cast<int>(0.5 * sampling_rate);

    // 获取vector1中倒数0.5秒内的数据
    std::vector<double> last_half_second_data_vector1;
    if (points_in_half_second <= vector1.size()) {
        last_half_second_data_vector1.assign(vector1.end() - points_in_half_second, vector1.end());
    } else {
        last_half_second_data_vector1 = vector1; // 如果vector1的长度小于0.5秒的数据量，则获取全部数据
    }

    // 获取vector2的所有数据
    std::vector<double> all_data_vector2 = vector2;

    // 合并数据到一个新的vector
    std::vector<double> combined_data;
    combined_data.reserve(last_half_second_data_vector1.size() + all_data_vector2.size()); // 预先分配足够的空间
    combined_data.insert(combined_data.end(), last_half_second_data_vector1.begin(), last_half_second_data_vector1.end());
    combined_data.insert(combined_data.end(), all_data_vector2.begin(), all_data_vector2.end());

    // 输出结果
    std::cout << "Combined data: ";
    for (double data : combined_data) {
        std::cout << data << " ";
    }
    std::cout << std::endl;

    return 0;
}

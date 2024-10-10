#include <chrono> // for std::chrono::milliseconds
#include <iostream>
#include <thread> // for std::this_thread::sleep_for
#include <vector>

int main() {
    std::vector<double> temp;
    for (double j = 0.0; j < 50'000'000; j++)
        temp.push_back(j);

    // std::cout << "SizeofTemp = " << sizeof(temp) << " " << temp.capacity() << " " << temp.size() << std::endl;

    // 创建一个100个vector的vector，每个vector<double>为空
    std::vector<std::vector<double>> vec_of_vecs;

    // 目标vector<double>
    std::vector<double> target_vec;

    // 遍历vec_of_vecs，将每个vector移动到目标target_vec中
    for (int i = 0; i < 100; i++) {

        vec_of_vecs.clear();
        // 一个vector有20个数组，有20个不同地址的待交换变量
        for (int i = 0; i <= 10; i++) {
            // 往里面加非空数组
            vec_of_vecs.push_back(temp);
        }

        for (auto &vec : vec_of_vecs) {

            std::cout << /*std::addressof(vec) <<*/ "b address: " << &vec[0] << std::endl;
            // auto add = std::addressof(vec);
            // target_vec.clear();
            target_vec = std::move(vec);

            // 打印目标vector的首地址
            // 用一个小的延迟以便观察地址变化
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 暂停 100 毫秒
            std::cout << "after a = move(b)\na address: " << &target_vec[0] << std::endl;
            std::cout << "b address: " << &vec[0] << std::endl;

            std::cout << "------------\n";
        }
    }
    return 0;
}

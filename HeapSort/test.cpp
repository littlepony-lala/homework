#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "Heapsort.h"
#include <algorithm>

template <typename T>
bool check(const std::vector<T> &vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i - 1] > vec[i]) {
            return false; // 如果前一个元素大于后一个元素，排序失败
        }
    }
    return true; // 排序正确
}

// 打印测试结果的函数test
template <typename T>
void test(const std::string& description, std::vector<T> vec, void (*sort_func)(std::vector<T>&)) 
{
    std::cout << "Testing: " << description << std::endl;

    // 记录排序前的时间
    auto start = std::chrono::high_resolution_clock::now();
    sort_func(vec);
    auto end = std::chrono::high_resolution_clock::now();
    
    // 检查排序结果
    bool is_sorted = check(vec);
    if (is_sorted) {
        std::cout << "排序成功 ";
    } else {
        std::cerr << "排序失败 ";
    }

    // 输出排序所用时间
    std::cout << "Time taken: " 
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() 
              << " ms "
              << std::endl;
}
template <typename T>
void heapsort(std::vector<T>& vec){
    std::make_heap(vec.begin(), vec.end());
    std::sort_heap(vec.begin(), vec.end());
}


int main() {
    constexpr size_t LENGTH = 1000000; // 测试序列长度

    // 随机序列
    std::vector<int> random_seq(LENGTH);
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 1000000);
    std::generate(random_seq.begin(), random_seq.end(), [&]() { return dist(gen); });

    // 有序序列
    std::vector<int> sorted_seq(LENGTH);
    std::iota(sorted_seq.begin(), sorted_seq.end(), 0); // 生成 0, 1, 2, ...

    // 逆序序列
    std::vector<int> reversed_seq(LENGTH);
    std::iota(reversed_seq.rbegin(), reversed_seq.rend(), 0); // 生成 LENGTH-1, LENGTH-2, ...

    // 部分重复序列
    std::vector<int> duplicate_seq(LENGTH);
    std::generate(duplicate_seq.begin(), duplicate_seq.end(), [&]() { return dist(gen) % 10; });

    // 对随机序列测试
    test("随机序列 (HeapSort)", random_seq, HeapSort<int>);
    test("随机序列 (std::sort_heap)", random_seq, heapsort<int>);

    // 对有序序列测试
    test("有序序列 (HeapSort)", sorted_seq, HeapSort<int>);
    test("有序序列 (std::sort_heap)", sorted_seq, heapsort<int>);

    // 对逆序序列测试
    test("逆序序列 (HeapSort)", reversed_seq, HeapSort<int>);
    test("逆序序列 (std::sort_heap)", reversed_seq, heapsort<int>);

    // 对部分重复序列测试
    test("部分重复序列 (HeapSort)", duplicate_seq, HeapSort<int>);
    test("部分重复序列 (std::sort_heap)", duplicate_seq, heapsort<int>);

    return 0;
}

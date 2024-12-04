#include <vector>
#include <algorithm>

template <typename T>
void HeapSort(std::vector<T>& vec) {
    // 使用std::make_heap将输入的vec转换为最大堆。
    std::make_heap(vec.begin(), vec.end());
    
    // 从堆中依次取出最大元素
    for (auto it = vec.end(); it != vec.begin(); --it) {
        // 将堆顶元素（当前最大值）放在当前堆的最后位置。
        std::pop_heap(vec.begin(), it);
    }
}

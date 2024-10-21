#include "List.h"
#include <iostream>
void printList(const List<int>& lst) {
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


int main()
{
    // 1. 测试默认构造函数与empty
    List<int> lst1;
    std::cout << "Test 1: 默认构造函数, list should be empty" << std::endl;
    std::cout << "Is empty: " << lst1.empty() << std::endl;
    List<int> lst;
    
    // 2.测试初始化列表构造函数
    List<int> lst2 = {1, 2, 3, 4};
    std::cout << "Test 2: 初始化列表构造函数" << std::endl;
    printList(lst2);
    
    // 3.测试push_back, push_front 和 size
    lst2.push_back(10);
    lst2.push_back(20);
    lst2.push_front(5);
    std::cout << "Test 2: push_back(10, 20) and push_front(5) :" << std::endl;
    printList(lst2);
    std::cout << "Size: " << lst2.size() << std::endl;

    // 4.测试pop_front, pop_back
    lst2.pop_front();
    lst2.pop_back();
    std::cout << "Test 4:  pop_front and pop_back :" << std::endl;
    printList(lst2);
    
    // 5.测试insert
    auto it = lst2.begin();
    lst1.insert(it, 15);
    std::cout << "Test 5: insert 15 at the front:" << std::endl;
    printList(lst2);

    // 6. 测试 erase
    it = lst2.begin();
    lst2.erase(it);
    std::cout << "Test 6: erase (remove 15):" << std::endl;
    printList(lst2);
    
    // 7. 测试拷贝构造函数
    List<int> lst3 = lst2;
    std::cout << "Test 7: 拷贝构造函数:" << std::endl;
    printList(lst3);

    // 8. 测试 front, back
    std::cout << "Test 8: Front and Back:" << std::endl;
    std::cout << "front of lst3 : " << lst3.front() << std::endl;
    std::cout << "back of lst3: " << lst3.back() << std::endl;

    // 9. 测试移动构造函数
    List<int> lst4 = std::move(lst3);
    std::cout << "Test 9: 移动构造函数 (move from list 3):" << std::endl;
    printList(lst4);
    std::cout << "size of List 3 after move (should be empty): " << lst3.size() << std::endl;

    // 10. 测试赋值运算符
    List<int> lst5 = lst4;
    std::cout << "Test 10: 赋值运算符 :" << std::endl;
    printList(lst5);

     // 11. 测试 clear
    lst5.clear();
    std::cout << "Test 11: After clear (list 2 should be empty):" << std::endl;
    std::cout << "Is empty: " << lst5.empty() << std::endl;
    std::cout << "Size: " << lst5.size() << std::endl;


    return 0;
}

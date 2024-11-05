#include <iostream>
#include "BinarySearchTree.h"  

void testBinarySearchTree() {
    BinarySearchTree<int> bst;
    //构建树
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);
    bst.insert(19);
    bst.insert(1);
    bst.insert(20);

    // 打印initial tree
    std::cout << "Initial Tree:" << std::endl;
    bst.printTree();

    // 删除无孩子的树
    bst.remove(20);
    std::cout << "Tree after removing 20:" << std::endl;
    bst.printTree();
    //删除只有右孩子的树
    bst.remove(18);
    std::cout << "Tree after removing 18:" << std::endl;
    bst.printTree();
    //删除只有左孩子的树
    bst.remove(3);
    std::cout << "Tree after removing 3:" << std::endl;
    bst.printTree();
    //删除有两个孩子的树
    bst.remove(15);
    std::cout << "Tree after removing 15:" << std::endl;
    bst.printTree();  
    //删除一个不存在的元素
    std::cout << "尝试删除不存在的元素(100)后: " << std::endl;
    bst.remove(100);  
    bst.printTree();
}

int main() {
    testBinarySearchTree();
    return 0;
}
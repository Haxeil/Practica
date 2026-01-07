#include <iostream>
#include <stdexcept>
#include "BSTree.h"

int main() {
    BSTree<int> bstree;

    std::cout << "Creating BSTree<int> bstree ...\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.insert(15);
    std::cout << "bstree.insert(15)\n-----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(15): " << bstree.search(15) << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.insert(7);
    std::cout << "bstree.insert(7)\n----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(7): " << bstree.search(7) << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.insert(3);
    std::cout << "bstree.insert(3)\n----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(3): " << bstree.search(3) << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.insert(11);
    std::cout << "bstree.insert(11)\n-----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(11): " << bstree.search(11) << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.insert(9);
    std::cout << "bstree.insert(9)\n----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(9): " << bstree.search(9) << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.insert(18);
    std::cout << "bstree.insert(18)\n-----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(18): " << bstree.search(18) << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.insert(21);
    std::cout << "bstree.insert(21)\n-----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(21): " << bstree.search(21) << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.insert(20);
    std::cout << "bstree.insert(20)\n-----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "bstree.search(20): " << bstree.search(20) << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    try {
        bstree.search(0);
        std::cout << "bstree.search(0) => OK! It did not throw std::runtime_error.\n";
    } catch (const std::runtime_error&) {
        std::cout << "bstree.search(0) => OK! It throwed std::runtime_error: Element not found!\n";
    }

    try {
        bstree.search(9);
        std::cout << "bstree.search(9) => OK! It did not throw std::runtime_error.\n";
    } catch (const std::runtime_error&) {
        std::cout << "bstree.search(9) => ERROR! It throwed std::runtime_error.\n";
    }

    try {
        bstree.insert(9);
        std::cout << "bstree.insert(9) => ERROR! It did not throw std::runtime_error.\n";
    } catch (const std::runtime_error&) {
        std::cout << "bstree.insert(9) => OK! It throwed std::runtime_error: Duplicated element!\n";
    }

    try {
        bstree.remove(50);
        std::cout << "bstree.remove(50) => ERROR! It did not throw std::runtime_error.\n";
    } catch (const std::runtime_error&) {
        std::cout << "bstree.remove(50) => OK! It throwed std::runtime_error: Element not found!\n";
    }

    bstree.remove(9);
    std::cout << "bstree.remove(9)\n----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.insert(9);
    std::cout << "bstree.insert(9)\n----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.remove(11);
    std::cout << "bstree.remove(11)\n-----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.insert(11);
    std::cout << "bstree.insert(11)\n-----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.remove(7);
    std::cout << "bstree.remove(7)\n----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.insert(7);
    std::cout << "bstree.insert(7)\n----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.remove(15);
    std::cout << "bstree.remove(15)\n-----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    bstree.insert(15);
    std::cout << "bstree.insert(15)\n-----------------\n";
    std::cout << "bstree.size(): " << bstree.size() << std::endl;
    std::cout << "cout << bstree:\n" << bstree << std::endl;

    return 0;
}

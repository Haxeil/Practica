#include <iostream>
#include <stdexcept>
#include "HashTable.h"

int main() {
    HashTable<int> dict(3);

    std::cout << dict << std::endl;

    std::cout << "dict.capacity(): " << dict.capacity() << std::endl;
    std::cout << "dict.entries(): " << dict.entries() << std::endl;

    std::cout << "dict.insert('One', 1) ...\n";
    dict.insert("One", 1);
    std::cout << "dict.insert('Two', 2) ...\n";
    dict.insert("Two", 2);
    std::cout << "dict.insert('Three', 3) ...\n";
    dict.insert("Three", 3);
    std::cout << "dict.insert('Four', 4) ...\n";
    dict.insert("Four", 4);
    std::cout << "dict.insert('Five', 5) ...\n";
    dict.insert("Five", 5);
    std::cout << "dict.insert('Six', 6) ...\n";
    dict.insert("Six", 6);

    std::cout << dict << std::endl;

    std::cout << "dict.search('One'): " << dict.search("One") << std::endl;
    std::cout << "dict['Four']: " << dict["Four"] << std::endl;

    std::cout << "dict.remove('Three'): " << dict.remove("Three") << std::endl;

    std::cout << dict << std::endl;

    try {
        dict.insert("One", 999);
    } catch (const std::runtime_error& e) {
        std::cout << "dict.insert('One') => throwed " << e.what() << std::endl;
    }

    try {
        dict.search("Ten");
    } catch (const std::runtime_error& e) {
        std::cout << "dict.search('Ten') => throwed " << e.what() << std::endl;
    }

    try {
        dict.remove("Ten");
    } catch (const std::runtime_error& e) {
        std::cout << "dict.remove('Ten') => throwed " << e.what() << std::endl;
    }

    return 0;
}

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "../PRA_2526_P1/ListLinked.h"  // <-- Ruta a tu ListLinked de la práctica 1

template <typename V>
class HashTable : public Dict<V> {
private:
    int n;
    int max;
    ListLinked<TableEntry<V>>* table;

    int h(std::string key) {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<int>(c);
        }
        return sum % max;
    }

public:
    HashTable(int size) : n(0), max(size) {
        table = new ListLinked<TableEntry<V>>[max];
    }

    ~HashTable() {
        delete[] table;
    }

    int capacity() { return max; }

    void insert(std::string key, V value) override {
        int pos = h(key);
        TableEntry<V> entry(key, value);

        // Buscar si ya existe
        int idx = table[pos].search(entry);
        if (idx != -1) {
            throw std::runtime_error("Key '" + key + "' already exists!");
        }

        table[pos].append(entry);
        n++;
    }

    V search(std::string key) override {
        int pos = h(key);
        TableEntry<V> entry(key);

        int idx = table[pos].search(entry);
        if (idx == -1) {
            throw std::runtime_error("Key '" + key + "' not found!");
        }

        return table[pos].get(idx).value;
    }

    V remove(std::string key) override {
        int pos = h(key);
        TableEntry<V> entry(key);

        int idx = table[pos].search(entry);
        if (idx == -1) {
            throw std::runtime_error("Key '" + key + "' not found!");
        }

        V value = table[pos].get(idx).value;
        table[pos].remove(idx);
        n--;
        return value;
    }

    int entries() override { return n; }

    V operator[](std::string key) {
        return search(key);
    }

    friend std::ostream& operator<<(std::ostream& out, const HashTable<V>& th) {
        out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]\n";
        out << "==============\n";
        for (int i = 0; i < th.max; i++) {
            out << "== Cubeta " << i << " ==\n";
            out << th.table[i] << "\n";
        }
        out << "==============\n";
        return out;
    }
};

#endif

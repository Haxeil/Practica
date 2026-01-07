#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;
    int n;

public:
    ListLinked() : first(nullptr), n(0) {}

    ~ListLinked() {
        Node<T>* aux;
        while (first) {
            aux = first->next;
            delete first;
            first = aux;
        }
    }

    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) throw std::out_of_range("Posición inválida");
        if (pos == 0) {
            prepend(e);
            return;
        }
        Node<T>* prev = first;
        for (int i = 1; i < pos; ++i) prev = prev->next;
        prev->next = new Node<T>(e, prev->next);
        ++n;
    }

    void append(T e) override {
        if (empty()) {
            prepend(e);
        } else {
            Node<T>* last = first;
            while (last->next) last = last->next;
            last->next = new Node<T>(e);
            ++n;
        }
    }

    void prepend(T e) override {
        first = new Node<T>(e, first);
        ++n;
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posición inválida");
        Node<T>* prev = nullptr;
        Node<T>* curr = first;
        for (int i = 0; i < pos; ++i) {
            prev = curr;
            curr = curr->next;
        }
        T value = curr->data;
        if (prev == nullptr) first = curr->next;
        else prev->next = curr->next;
        delete curr;
        --n;
        return value;
    }

    T get(int pos) const override {
        if (pos < 0 || pos >= n) throw std::out_of_range("Posición inválida");
        Node<T>* curr = first;
        for (int i = 0; i < pos; ++i) curr = curr->next;
        return curr->data;
    }

    int search(T e) const override {
        Node<T>* curr = first;
        int pos = 0;
        while (curr) {
            if (curr->data == e) return pos;
            curr = curr->next;
            ++pos;
        }
        return -1;
    }

    bool empty() const override { return n == 0; }
    int size() const override { return n; }

    T operator[](int pos) const { return get(pos); }

    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& l) {
        out << "List => [";
        Node<T>* curr = l.first;
        while (curr) {
            out << curr->data;
            if (curr->next) out << " ";
            curr = curr->next;
        }
        out << "]";
        return out;
    }
};

#endif

#pragma once
#include <iostream>
using namespace std;

template <typename T>
class list {
    class Node {
    public:
        T value;
        Node* prev;
        Node* next;
        Node(T value) : value(value), prev(nullptr), next(nullptr) {}
        Node(T value, Node* prev) : value(value), prev(prev), next(nullptr) {}
        Node(Node* next, T value) : value(value), prev(nullptr), next(next) {}
    };
private:
    Node* head;
    Node* tail;
    size_t size;
public:
    list() : head(nullptr), tail(nullptr), size(0) {}
    ~list() { clear(); }
    void push_back(T value) {
        if (tail) {
            tail->next = new Node(value, tail);
            tail = tail->next;
        }
        else {
            head = tail = new Node(value);
        }
        size++;
    }
    void push_front(T value) 
    {
        if (head) {
            head = new Node(head, value);
            head->next->prev = head;
        }
        else {
            head = tail = new Node(value);
        }
        size++;
    }
    void pop_back() 
    {
        if (!tail) return;
        Node* to_delete = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete to_delete;
        size--;
    }
    void pop_front() 
    {
        if (!head) return;
        Node* to_delete = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete to_delete;
        size--;
    }
    void clear() 
    {
        while (head) pop_front();
    }
    void show() const 
    {
        Node* current = head;
        while (current) {
            cout << current->value << '\t';
            current = current->next;
        }
        cout << endl;
    }

    T front() const { return head ? head->value : T(); }
    T back() const { return tail ? tail->value : T(); }

    list(const list& other) : head(nullptr), tail(nullptr), size(0) {
        Node* current = other.head;
        while (current) {
            push_back(current->value);
            current = current->next;
        }
    }
    list& operator=(const list& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current) {
                push_back(current->value);
                current = current->next;
            }
        }
        return *this;
    }
    T operator[](int index) const {
        Node* current = head;
        for (int i = 0; i < index && current; ++i) {
            current = current->next;
        }
        return current ? current->value : T();
    }
    list operator+(const list& other) const {
        list result;
        Node* current = this->head;
        while (current) {
            result.push_back(current->value);
            current = current->next;
        }
        current = other.head;
        while (current) {
            result.push_back(current->value);
            current = current->next;
        }
        return result;
    }
    list operator*(const list& other) const {
        list result;
        Node* current = this->head;
        while (current) {
            Node* other_current = other.head;
            while (other_current) {
                if (current->value == other_current->value) {
                    result.push_back(current->value);
                    break;
                }
                other_current = other_current->next;
            }
            current = current->next;
        }
        return result;
    }
};

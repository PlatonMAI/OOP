#include <iostream>

#include <iterator.h>

template <class T, class Allocator>
class Stack {
public:
    Stack();
    Stack(std::initializer_list<T>);
    void push(T);
    T pop();
    void print();
    ~Stack();

    Iterator< T, Stack<T, Allocator> > begin() {
        return Iterator< T, Stack<T, Allocator> >(this, 0, size);
    }
    Iterator< T, Stack<T, Allocator> > end() {
        return Iterator< T, Stack<T, Allocator> >(this, size, size);
    }
private:
    T* data{};
    size_t size{}, capacity{};
    Allocator allocator;
};

template <class T, class Allocator>
Stack<T, Allocator>::Stack() {}

template <class T, class Allocator>
Stack<T, Allocator>::Stack(std::initializer_list<T> list) : size(list.size()), capacity(list.size()) {
    data = allocator.allocate(capacity);

    int i = 0;
    for (T elem : list) {
        data[i++] = elem;
    }
}

template <class T, class Allocator>
void Stack<T, Allocator>::push(T value) {
    ++size;

    if (capacity < size) {
        allocator.deallocate(data, capacity);
        capacity *= 2;
        data = allocator.allocate(capacity);
    }

    data[size - 1] = value;
}

template <class T, class Allocator>
T Stack<T, Allocator>::pop() {
    --size;

    return data[size];
}

template <class T, class Allocator>
void Stack<T, Allocator>::print() {
    std::cout << "Стек:" << std::endl;
    for (int i = size - 1; i >= 0; --i)
        std::cout << data[i] << std::endl;
    std::cout << std::endl;
}

template <class T, class Allocator>
Stack<T, Allocator>::~Stack() {
    std::cout << "Дтор стека" << std::endl;
    allocator.deallocate(data, capacity);
}
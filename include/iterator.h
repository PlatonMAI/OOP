#pragma once

#include <iostream>

template <class ItemType, class ArrayType>
class Iterator : public std::iterator<std::forward_iterator_tag, ItemType, ptrdiff_t, ItemType*, ItemType&> {
private:
    ArrayType* array;
    size_t index;
    size_t size;

public:
    typedef std::iterator<std::forward_iterator_tag, ItemType, ptrdiff_t, ItemType*, ItemType&> iterator;

    Iterator(ArrayType *value, size_t i, size_t s) : array(value), index(i), size(s){};

    iterator::reference operator*() {
        if (index >= size)
            throw std::out_of_range("Out of range");
        return (*array)[index];
    }

    iterator::reference operator->() {
        if (index >= size)
            throw std::out_of_range("Out of range");
        return (*array)[index];
    }

    bool operator==(const Iterator<typename iterator::value_type, ArrayType> &other) const {
        return (other.index == index) && (other.array == array);
    }
    bool operator!=(const Iterator<typename iterator::value_type, ArrayType> &other) const {
        return (other.index != index) || (other.array != array);
    }

    Iterator<typename iterator::value_type, ArrayType>& operator++() {
        ++index;
        return *this;
    }
};
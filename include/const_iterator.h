#pragma once

#include <iostream>

template <class ItemType, class ArrayType>
class ConstIterator : public std::iterator<std::forward_iterator_tag, ItemType, ptrdiff_t, const ItemType*, const ItemType&> {
private:
    ArrayType* array;
    size_t index;
    size_t size;

public:
    typedef std::iterator<std::forward_iterator_tag, ItemType, ptrdiff_t, const ItemType*, const ItemType&> iterator;

    ConstIterator(ArrayType *value, size_t i, size_t s) : array(value), index(i), size(s){};

    iterator::reference operator*() const {
        if (index >= size)
            throw std::out_of_range("Out of range");
        return (*array)[index];
    }

    iterator::reference operator->() const {
        if (index >= size)
            throw std::out_of_range("Out of range");
        return (*array)[index];
    }

    bool operator==(const ConstIterator<typename iterator::value_type, ArrayType> &other) const {
        return (other.index == index) && (other.array == array);
    }
    bool operator!=(const ConstIterator<typename iterator::value_type, ArrayType> &other) const {
        return (other.index != index) || (other.array != array);
    }

    ConstIterator<typename iterator::value_type, ArrayType>& operator++() {
        ++index;
        return *this;
    }
};
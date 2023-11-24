#include <iostream>
#include <memory>

template <class T, std::size_t BLOCK_SIZE>
class Allocator {
public:
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;
    using size_type = std::size_t;

    struct Free_block {
        char* ptr;
        size_type size = -1;
    };

    Allocator();

    ~Allocator();

    template <class U, std::size_t BLOCK_SIZE_>
    struct rebind {
        using type = U;
        using other = Allocator<U, BLOCK_SIZE_>;
    };

    T *allocate(size_t);

    void deallocate(T*, size_t);

private:
    char* _used_blocks;
    Free_block* _free_blocks;
    size_type _free_count;
};



// ========================================



template <class T, std::size_t BLOCK_SIZE>
Allocator<T, BLOCK_SIZE>::Allocator() {
    _used_blocks = (char*)malloc(sizeof(T) * BLOCK_SIZE);
    _free_blocks = (Free_block*)malloc(sizeof(Free_block) * BLOCK_SIZE);

    for (uint64_t i = 0; i < BLOCK_SIZE; i++)
        _free_blocks[i] = Free_block{_used_blocks + i * sizeof(T)};
    _free_blocks[0].size = BLOCK_SIZE;
    _free_count = BLOCK_SIZE;
}

template <class T, std::size_t BLOCK_SIZE>
Allocator<T, BLOCK_SIZE>::~Allocator() {
    free(_free_blocks);
    free(_used_blocks);

    // _free_blocks = nullptr;
    // _used_blocks = nullptr;
}

template <class T, std::size_t BLOCK_SIZE>
T* Allocator<T, BLOCK_SIZE>::allocate(size_t n) {
    T *result = nullptr;
    if (_free_count >= n) {
        for (size_t i = 0; i < BLOCK_SIZE; ++i) {
            if (_free_blocks[i].size >= n && _free_blocks[i].ptr != nullptr) {
                result = (T*)_free_blocks[i].ptr;

                _free_blocks[i + n].size = _free_blocks[i].size - n;
                _free_blocks[i].size = n;
                _free_blocks[i].ptr = nullptr;

                _free_count -= n;

                break;
            }
        }

        if (result == nullptr) {
            std::cout << "allocator: No memory exception :-)" << std::endl;
            throw std::bad_alloc();
        }
    }
    else {
        std::cout << "allocator: No memory exception :-)" << std::endl;
        throw std::bad_alloc();
    }
    return result;
}

template <class T, std::size_t BLOCK_SIZE>
void Allocator<T, BLOCK_SIZE>::deallocate(T* pointer, size_t n) {
    for (size_t i = 0; i < BLOCK_SIZE; ++i) {
        if (_free_blocks[i].size == n && _free_blocks[i].ptr == nullptr) {
            _free_blocks[i].ptr = (char*)pointer;

            if (_free_blocks[i + n].ptr != nullptr) {
                _free_blocks[i].size = _free_blocks[i + n].size + n;
                _free_blocks[i + n].size = -1;
            }

            _free_count += n;

            break;
        }
    }
}

// template <typename U, typename... Args>
// void construct(U *p, Args &&...args)
// {
//     new (p) U(std::forward<Args>(args)...);
// }

// void destroy(pointer p)
// {
//     p->~T();
// }

// template <class T, class U>
// constexpr bool operator==(const Allocator<T> &lhs, const Allocator<U> &rhs) 
// {
//     return true;
// }

// template <typename T, typename U, size_t BLOCK_COUNT>
// constexpr bool operator!=(const Allocator<T> &lhs, const Allocator<U> &rhs)  
// {
//     return false;
// }
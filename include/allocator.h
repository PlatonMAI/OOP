#include <iostream>
#include <memory>

template <class T, std::size_t BLOCK_SIZE>
class Allocator {
public:
    using const_pointer = const T*;
    using const_reference = const T&;
    using difference_type = std::size_t;
    using pointer = T*;
    using reference = T&;
    using size_type = std::size_t;
    using value_type = T;

    struct Free_block {
        char* ptr;
        size_type size = 0;
    };

    Allocator();

    ~Allocator();

    template <class U>
    struct rebind {
        // using type = U;
        using other = Allocator<U, BLOCK_SIZE>;
    };

    T *allocate(size_t);

    void deallocate(T*, size_t);

    void printDump();

private:
    std::array<char, sizeof(T) * BLOCK_SIZE> _used_blocks;
    std::array<Free_block, BLOCK_SIZE> _free_blocks;

    // char* _used_blocks;
    // Free_block* _free_blocks;

    size_type _free_count;
};



// ========================================



template <class T, std::size_t BLOCK_SIZE>
Allocator<T, BLOCK_SIZE>::Allocator() {
    // _used_blocks = (char*)malloc(sizeof(T) * BLOCK_SIZE);
    // _free_blocks = (Free_block*)malloc(sizeof(Free_block) * BLOCK_SIZE);

    for (uint64_t i = 0; i < BLOCK_SIZE; i++)
        _free_blocks[i] = Free_block{_used_blocks.begin() + i * sizeof(T)};
        // _free_blocks[i] = Free_block{_used_blocks + i * sizeof(T)};
    _free_blocks[0].size = BLOCK_SIZE;
    _free_count = BLOCK_SIZE;
}

template <class T, std::size_t BLOCK_SIZE>
Allocator<T, BLOCK_SIZE>::~Allocator() {
    if (_free_count != BLOCK_SIZE) {
        std::cout << "Утечка!" << std::endl;
    }

    // free(_free_blocks);
    // free(_used_blocks);
}

template <class T, std::size_t BLOCK_SIZE>
T* Allocator<T, BLOCK_SIZE>::allocate(size_t n) {
    std::cout << "Выделение " << n << std::endl;

    T *result = nullptr;
    if (_free_count >= n) {
        for (size_t i = 0; i < BLOCK_SIZE; ++i) {
            if (_free_blocks[i].size >= n && _free_blocks[i].ptr != nullptr) {
                std::cout << "Кандидат " << i << ", его размер: " << _free_blocks[i].size << std::endl;
                result = (T*)_free_blocks[i].ptr;

                if (_free_blocks[i + n].size == 0)
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

    printDump();

    return result;
}

template <class T, std::size_t BLOCK_SIZE>
void Allocator<T, BLOCK_SIZE>::deallocate(T* pointer, size_t n) {
    std::cout << "Освобождение " << n << std::endl;

    for (size_t i = 0; i < BLOCK_SIZE; ++i) {
        if (_free_blocks[i].size == n && _free_blocks[i].ptr == nullptr) {
            _free_blocks[i].ptr = (char*)pointer;

            _free_blocks[i].size = n;

            // Склеиваем со следующим
            if (i + n < BLOCK_SIZE) {
                if (_free_blocks[i + n].ptr != nullptr) {
                    std::cout << "Слили со следующим" << std::endl;
                    _free_blocks[i].size += _free_blocks[i + n].size;
                    _free_blocks[i + n].size = 0;

                    printDump();
                }
            }

            // С предыдущим
            if (i > 0) {
                for (size_t j = i - 1; j >= 0; --j) {
                    if (_free_blocks[j].size != 0) {
                        if (_free_blocks[j].ptr != nullptr) {
                            std::cout << "Слили с предыдущим" << std::endl;
                            _free_blocks[j].size += _free_blocks[i].size;
                            _free_blocks[i].size = 0;
                        }

                        break;
                    }
                }
            }

            _free_count += n;

            break;
        }
    }

    printDump();
}

template <class T, std::size_t BLOCK_SIZE>
void Allocator<T, BLOCK_SIZE>::printDump() {
    std::cout << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "Количество свободных: " << _free_count << std::endl;

    for (size_t i = 0; i < BLOCK_SIZE; ++i) {
        Free_block block = _free_blocks[i];
        if (block.size == 0)
            continue;

        bool isAllocate = (block.ptr == nullptr);
        std::cout << "\t" << i << ": " << isAllocate << " " << block.size << std::endl;
    }
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;
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

template <class T, class U, size_t BLOCK_COUNT1, size_t BLOCK_COUNT2>
constexpr bool operator==(const Allocator<T, BLOCK_COUNT1> &lhs, const Allocator<U, BLOCK_COUNT2> &rhs) 
{
    return true;
}

template <typename T, typename U, size_t BLOCK_COUNT1, size_t BLOCK_COUNT2>
constexpr bool operator!=(const Allocator<T, BLOCK_COUNT1> &lhs, const Allocator<U, BLOCK_COUNT2> &rhs)  
{
    return false;
}
// 17. Стек, std::array

#include <bits/stdc++.h>

#include <allocator.h>
#include <stack.h>

#include <iterator.h>
#include <const_iterator.h>

using namespace std;

const size_t BLOCK_SIZE = 100000;

// проверим по какой стратегии увеличивается количество элементов в Vector
void testReallocate() {
    std::cout << "\ntestReallocate\n";

    std::vector< int, Allocator< int, BLOCK_SIZE > > values;

    auto capacity = values.capacity();
    std::cout << '[' << 0 << ']' << " capacity = " << values.capacity() << std::endl;
    for (int i=0; i<10000; ++i) {
        if (capacity != values.capacity()) {
            std::cout << '[' << i << ']' << " capacity = " << values.capacity() << std::endl;
            capacity = values.capacity();
        }
        values.push_back(i);
    }
    std::cout << std::endl;
}

int main() {
    // map< int, int, less<int>, Allocator< pair<const int, int>, BLOCK_SIZE > > my_map;

    // my_map[0] = 1;
    // for (int i = 1; i < 10; ++i) {
    //     my_map[i] = my_map[i - 1] * i;
    // }

    // for (const auto& [k, v] : my_map)
    //     std::cout << k << "->" << v << std::endl;

    // testReallocate();



    // Stack< int, Allocator<int, BLOCK_SIZE> > s{1, 2, 3, 4, 5, 6};
    // s.print();

    // s.push(10);

    // s.print();

    // cout << s.pop() << endl;
    // s.push(11);

    // s.print();



    vector<int> a(10, 10);
    Iterator<int, vector<int>> it(&a, 2, 10);
    cout << *it << endl;

    *it = 5;
    cout << *it << endl;

    ++it;
    cout << *it << endl;

    ConstIterator<int, vector<int>> cit(&a, 2, 10);
    cout << *cit << endl;
    // *cit = 5; - CE
    // cout << *cit << endl;

    return 0;
}
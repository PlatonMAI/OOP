// 17. Стек, std::array

#include <bits/stdc++.h>

#include <allocator.h>

using namespace std;

const size_t BLOCK_SIZE = 100;

int main() {
    map< int, int, less<int>, Allocator< pair<const int, int>, BLOCK_SIZE > > my_map;

    my_map[1]=10;
    my_map[2]=20;
    my_map[3]=30;

    for (const auto& [k,v]: my_map)
        std::cout << k << "->" << v << std::endl;

    return 0;
}
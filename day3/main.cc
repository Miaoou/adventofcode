#include <iostream>
#include <sstream>
#include <cstdint>
#include <streambuf>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <set>
#include <array>

using namespace std;

template< typename T, T... Ns >
auto constexpr
make_data( std::integer_sequence< T, Ns... > ) noexcept
    -> array< T, sizeof...( Ns ) > {
    return {{ Ns... }};
}

template< typename T, size_t N >
auto constexpr
make_data() noexcept {
    return make_data< T >( std::make_integer_sequence< T, N >{} );
}

uint32_t
part1() {
    auto constexpr data = make_data< uint32_t, 12 >();
    uint32_t dist = data.size();
    
    return dist;
}

int
main() {
    auto dist = part1();

    cout << dist << "\n";
    return 0;
}

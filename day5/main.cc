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
#include <cmath>
#include <cstdlib>
#include <vector>
#include <optional>
#include <memory>
#include <fstream>
#include <numeric>

using namespace std;

uint32_t
part1() {
    uint32_t steps = 0;
    ifstream ifs( "input.txt" );
    vector< int32_t > data( istream_iterator< int32_t >( ifs ), {} );

    for( auto p = begin( data ); p != end( data ); ++steps )
        p += ( *p )++;

    return steps;
}

uint32_t
part2() {
    uint32_t steps = 0;
    ifstream ifs( "input.txt" );
    vector< int32_t > data( istream_iterator< int32_t >( ifs ), {} );

    for( auto p = begin( data ); p != end( data ); ++steps )
        p += ( ( *p ) >= 3 ) ? ( *p )-- : ( *p )++;

    return steps;
}

int
main() {
    cout << part2();

    return 0;
}

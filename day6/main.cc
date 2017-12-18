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
    ifstream ifs( "C:\\code\\adventofcode\\day6\\input.txt" );
    //vector< uint32_t > banks{ 0, 2, 7, 0 };
    vector< uint32_t > banks( istream_iterator< uint32_t >( ifs ), {} );
    vector< vector< uint32_t > > states;
    bool loop_detected = false;

    auto find_state = [&states] ( vector< uint32_t > const& curr_state ) {
        for( auto const& state : states ) {
            if( equal( begin( state ), end( state ), begin( curr_state ) ) )
                return true;
        }
        return false;
    };

    uint32_t cycles = 0;

    while( !loop_detected ) {
        auto e = max_element( begin( banks ), end( banks ) );
        auto max_bank = *e;
        *e = 0;

        for( auto p = e + 1; max_bank != 0; --max_bank, ++p ) {
            if( p == end( banks ) )
                p = begin( banks );

            ++( *p );
        }

        loop_detected = find_state( banks );
        states.push_back( banks );
        ++cycles;
    }
    return cycles;
}

int
main() {
    cout << part1();
    system( "pause" );
    return 0;
}

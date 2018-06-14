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
#include <unordered_map>

using namespace std;

string
part1() {
    ifstream ifs( "C:\\code\\adventofcode\\day7\\input.txt" );

    unordered_map< string, string > programs;

    string line;
    // fwft (72) -> ktlj, cntj, xhth
    while( getline( ifs, line ) ) {
        istringstream sline( line );
        string name;
        sline >> name;
        sline.ignore( std::numeric_limits< std::streamsize >::max(), '>' );
        
        for( size_t i = 0; i < 3 && sline.good(); ++i ) {
            string child;
            getline( sline, child, ',' );
            child.erase( 0, 1 );
            programs[ child ] = name;
        }        
    }

    auto it = programs.begin();
    auto& top = it->second;
    while( it != end( programs ) ) {
        top = it->second;
        it = programs.find( it->second );
    }

    return top;
}

struct Program {
    string parent;
    vector< string > children;
    uint32_t weight;
};

void
update_weights( unordered_map< string, Program >& programs, string const& top ) {
    auto& p = programs[ top ];
    for( auto const& child : p.children ) {
        update_weights( programs, child );
        p.weight += programs[ child ].weight;
    }
}

uint32_t
part2() {
    ifstream ifs( "C:\\code\\adventofcode\\day7\\input.txt" );

    
    unordered_map< string, Program > programs;

    string line;
    // fwft (72) -> ktlj, cntj, xhth
    while( getline( ifs, line ) ) {
        istringstream sline( line );

        string name;
        sline >> name;
        sline.get(); sline.get(); // ' ('
        sline >> programs[ name ].weight;
        sline.ignore( std::numeric_limits< std::streamsize >::max(), '>' );

        for( size_t i = 0; i < 3 && sline.good(); ++i ) {
            string child;
            sline.get();
            getline( sline, child, ',' );
            programs[ child ].parent = name;

            programs[ name ].children.push_back( child );
        }
    }

    auto it = programs.begin();
    auto top = it->first;
    while( it != end( programs ) ) {
        top = it->first;
        it = programs.find( it->second.parent );
    }

    update_weights( programs, top );

    auto find_unbalanced_diff = [&] (string const& top) -> uint32_t {
        auto const& p = programs[ top ];
        auto expected_w = 0u;
        for( auto const& child : p.children ) {
            if( expected_w == 0 )
                expected_w = p.weight + programs[ child ].weight;
            else if( p.weight + programs[ child ].weight != expected_w ) {
                return std::abs((int)(expected_w - p.weight + programs[ child ].weight));
            }
        }

        return 0;
    };

    return find_unbalanced_diff( top );
}

int
main() {
    cout << part2();
    system( "pause" );
    return 0;
}

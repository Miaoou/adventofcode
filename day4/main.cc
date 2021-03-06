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
    uint32_t nb_valid = 0;
    ifstream ifs("input");
    string line;
    while( getline( ifs, line ) ) {
        set< string > words;
        istringstream sline( line );
        string word;

        bool valid = true;
        while( getline( sline, word, ' ' ) ) {
            if( !words.insert( word ).second )
                valid = false;
        }

        nb_valid += valid ? 1 : 0;
    }

    return nb_valid;
}

uint32_t
part2() {
    uint32_t nb_valid = 0;
    ifstream ifs("input");
    string line;

    while( getline( ifs, line ) ) {
        set< string > words;
        istringstream sline( line );

        nb_valid += all_of( istream_iterator< string >( sline ), {}, [&words] ( auto word ) {
            sort( begin( word ), end( word ) );
            return words.insert( word ).second;
        } );

    }

    return nb_valid;
}

int
main() {
    cout << part2();

    return 0;
}

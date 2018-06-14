#include <iostream>
#include <sstream>
#include <cstdint>
#include <streambuf>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <set>

using namespace std;


string const in_s =
"6046 6349 208 276 4643 1085 1539 4986 7006 5374 252 4751 226 6757 7495 2923\n"
"1432 1538 1761 1658 104 826 806 109 939 886 1497 280 1412 127 1651 156\n"
"244 1048 133 232 226 1072 883 1045 1130 252 1038 1022 471 70 1222 957\n"
"87 172 93 73 67 192 249 239 155 23 189 106 55 174 181 116\n"
"5871 204 6466 6437 5716 232 1513 7079 6140 268 350 6264 6420 3904 272 5565\n"
"1093 838 90 1447 1224 744 1551 59 328 1575 1544 1360 71 1583 75 370\n"
"213 166 7601 6261 247 210 4809 6201 6690 6816 7776 2522 5618 580 2236 3598\n"
"92 168 96 132 196 157 116 94 253 128 60 167 192 156 76 148\n"
"187 111 141 143 45 132 140 402 134 227 342 276 449 148 170 348\n"
"1894 1298 1531 1354 1801 974 85 93 1712 130 1705 110 314 107 449 350\n"
"1662 1529 784 1704 1187 83 422 146 147 1869 1941 110 525 1293 158 1752\n"
"162 1135 3278 1149 3546 3686 182 149 119 1755 3656 2126 244 3347 157 865\n"
"2049 6396 4111 6702 251 669 1491 245 210 4314 6265 694 5131 228 6195 6090\n"
"458 448 324 235 69 79 94 78 515 68 380 64 440 508 503 452\n"
"198 216 5700 4212 2370 143 5140 190 4934 539 5054 3707 6121 5211 549 2790\n"
"3021 3407 218 1043 449 214 1594 3244 3097 286 114 223 1214 3102 257 3345";

uint32_t
part2( istringstream& in ) {
    uint32_t sum = 0;

    string line;
    while( getline( in, line ) ) {
        istringstream line_stream( line );
        set< uint32_t, greater< uint32_t > > numbers(
                ( istream_iterator< uint32_t >( line_stream ) ),
                istream_iterator< uint32_t >()
                );

        uint32_t rest = 0;
        for( auto it_curr = begin( numbers ); it_curr != end( numbers ); ++it_curr ) {
            auto it_next = it_curr;
            ++it_next;
            for( ; it_next != end( numbers ); ++it_next ) {
                if( *it_curr % *it_next == 0 ) {
                    rest = *it_curr / *it_next;
                    break;
                }
            }
        }
        
        sum += rest;
    }
    return sum;
}

uint32_t
part1( istringstream& in ) {
    uint32_t sum = 0;

    string line;
    while( getline( in, line ) ) {
        uint32_t max = 0;
        uint32_t min = std::numeric_limits< uint32_t >::max();
        uint32_t curr = 0;
        istringstream line_stream( line );

        while( line_stream >> curr ) {
            max = curr > max ? curr : max;
            min = curr < min ? curr : min;
        }
        sum += max - min;
    }
    return sum;
}

int
main() {
    istringstream in( in_s );

    //auto sum = part1( in );
    auto sum = part2( in );

    cout << sum << "\n";
    return 0;
}

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

using namespace std;

uint32_t
part1( uint32_t n ) {
    if (n == 1)
        return 0;
    
    uint32_t nb_full_lines = 1;

    for (auto i = 2; i < n; ++i) {
        if (i == pow(nb_full_lines + 2, 2)) {
            nb_full_lines += 2;
        }
    }

    uint32_t last_corner = pow(nb_full_lines, 2); // 9

    auto top_right = last_corner + nb_full_lines + 1; // 13
    auto top_left = top_right + nb_full_lines + 1; // 17
    auto bot_left = top_left + nb_full_lines + 1; // 21
    auto bot_right = bot_left + nb_full_lines + 1; // 25

    auto curr_case = nb_full_lines + 1;
    bool decrement = true;

    for (auto i = last_corner + 1; i <= n; ++i) {
        if (i == top_right || i == top_left || i == bot_left || i == bot_right) {
            curr_case = nb_full_lines + 1;
            decrement = true;
        }
        else {
            if (curr_case == ((nb_full_lines + 1) / 2)) {
                decrement = false;
            }

            decrement ? --curr_case : ++curr_case;
        }        
    }

    return curr_case;

}

int
main() {
    cout << "3:" << part1(12) << "\n";
    cout << "2:" << part1(23) << "\n";
    cout << "31:" << part1(1024) << "\n";
    cout << "326:" << part1(361527) << "\n";

    system("pause");
    return 0;
}

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

using namespace std;

uint32_t
part1() {
    auto constexpr n = 12;

    if (n == 1)
        return 0;
    
    uint32_t nb_full_lines = 1;

    for (auto i = 1; i <= 12; ++i) {
        if (i == pow(nb_full_lines, 2)) {
            nb_full_lines += 2;
        }
    }

    uint32_t last_corner = pow(nb_full_lines, 2); // 9

    auto top_right = last_corner + nb_full_lines + 1; // 13
    auto top_left = top_right + nb_full_lines + 1; // 17
    auto bot_left = top_left + nb_full_lines + 1; // 21
    auto bot_right = bot_left + nb_full_lines + 1; // 25

    auto curr_case = 0;
    for (auto i = last_corner; i <= bot_right && i != n; ++i) {
        if (i == top_right || i == top_left || i == bot_left || i == bot_right)
            curr_case = 0;
        else
            ++curr_case;
    }
    ++curr_case;

    if (curr_case == 0)
        return 2 * (nb_full_lines - 1);
    else
        return nb_full_lines - 1 + ((curr_case - 1) / 2);
    


    return 0;
}

int
main() {
    auto dist = part1();

    cout << dist << "\n";
    return 0;
}

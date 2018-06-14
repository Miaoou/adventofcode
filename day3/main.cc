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

using namespace std;

uint32_t
part1( uint32_t n ) {
    if (n == 1)
        return 0;
    
    uint32_t nb_full_lines = 1;

    for (size_t i = 2; i < n; ++i) {
        if (i == pow(nb_full_lines + 2, 2)) {
            nb_full_lines += 2;
        }
    }

    uint32_t last_corner = static_cast< uint32_t >( pow(nb_full_lines, 2) ); // 9

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

size_t
part2() {
    static size_t const max_size = 100;
    struct coords {
        using v_coord_t = array< std::optional< size_t >, max_size >;
        array< v_coord_t, max_size > px_py;
        array< v_coord_t, max_size > mx_py;
        array< v_coord_t, max_size > mx_my;
        array< v_coord_t, max_size > px_my;
    };
    optional< size_t > first_match;
    auto c = make_unique< coords >();
    c->px_py[0][0] = 1;

    auto get_coords_v = [&c] ( int32_t x, int32_t y ) -> auto& {
        if( x < 0 && y >= 0 )
            return c->mx_py;
        if( x >= 0 && y < 0 )
            return c->px_my;
        if( x < 0 && y < 0 )
            return c->mx_my;
      
        return c->px_py;
    };

    auto update_val_from = [&get_coords_v] ( size_t& val, int32_t x, int32_t y ) {
        auto& coords_v = get_coords_v( x, y );
        optional< size_t > tmp = coords_v[abs( x )][abs( y )];
        if( tmp.has_value() )
            val += tmp.value();
    };

    auto update_val = [&get_coords_v, &update_val_from, &first_match] ( int32_t x, int32_t y ) {
        size_t val = 0;
        update_val_from( val, x - 1, y - 1 );
        update_val_from( val, x - 1, y );
        update_val_from( val, x - 1, y + 1 );
        update_val_from( val, x, y - 1 );
        update_val_from( val, x, y + 1 );
        update_val_from( val, x + 1, y - 1 );
        update_val_from( val, x + 1, y );
        update_val_from( val, x + 1, y + 1 );

        auto& coords_v = get_coords_v( x, y );
        coords_v[abs( x )][abs( y )] = val;

        if( val > 361527 && !first_match.has_value() )
            first_match = val;
    };

    auto fill_next_lines = [&update_val] ( int32_t curr_nb_lines ) {
        int32_t x = curr_nb_lines;
        int32_t y = 1 - curr_nb_lines;

        for( ; y < curr_nb_lines; ++y )
            update_val( x, y );
        for( ; x > -curr_nb_lines; --x )
            update_val( x, y );
        for( ; y > -curr_nb_lines; --y )
            update_val( x, y );
        for( ; x <= curr_nb_lines; ++x )
            update_val( x, y );        
    };



    for( size_t curr_nb_lines = 1; !first_match.has_value(); ++curr_nb_lines ) {
        fill_next_lines( curr_nb_lines );
    }   

    return first_match.value();
}

int
main() {
    cout << part2();

    return 0;
}

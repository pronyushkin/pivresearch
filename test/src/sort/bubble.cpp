/// @file
/// @brief bubblesort.
/// @copyright Copyright 2015 Igor V. Pronyushkin.
/// @author Igor V. Pronyushkin
/// @date 2015

#include <algorithm>
#include <vector>

namespace nspiv
{
namespace research
{

/// @brief Bubble sort implementation
/// @param[in,out] data - data for sorting
void SortBubble( std::vector< int >& v )
{
     if( 2 > v.size() )
          return;

     for( size_t i = 0; i != v.size() - 1; ++i )
     {
          for( size_t j = 0; j != v.size() - i - 1; ++j )
          {
               if( v[ j ] > v[ j + 1 ] )
                    std::swap( v[ j ], v[ j + 1 ] );
          }
     }
}


} // namespace research
} // namespace nspiv

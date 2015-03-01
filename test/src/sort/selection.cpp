/// @file
/// @brief selection sort.
/// @copyright Copyright 2015 Igor V. Pronyushkin.
/// @author Igor V. Pronyushkin
/// @date 2015

#include <algorithm>
#include <vector>

namespace nspiv
{
namespace research
{

/// @brief selection sort implementation
/// @param[in,out] data - data for sorting
void SortSelection( std::vector< int >& v )
{
     if( 2 > v.size() )
          return;

     for( size_t i = 0; i != v.size(); ++i )
     {
          size_t m = i;
          for( size_t j = i + 1; j < v.size(); ++j )
          {
               if( v[ j ] < v[ m ] )
                    m = j;
          }
          if( m != i ) 
               std::swap( v[ m ], v[ i ] );
     }
}


} // namespace research
} // namespace nspiv

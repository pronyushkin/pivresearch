/// @file
/// @brief The checker for sort algorithms.
/// @copyright Copyright 2015 Igor V. Pronyushkin.
/// @author Igor V. Pronyushkin
/// @date 2015

#include "check.h"

#include <algorithm>
#include <vector>

#include <ctime>
#include <cstdlib>

namespace nspiv
{
namespace research
{

const size_t EVEN_ARRAY_SIZE = 10000;
const size_t ODD_ARRAY_SIZE = EVEN_ARRAY_SIZE + 1;

extern void SortBubble( std::vector< int >& v );
extern void SortSelection( std::vector< int >& v );

namespace // anonymous
{



SortingChecker::SortFunction sortFunctions[] =
{
     &SortBubble,
     &SortSelection,
     0
}; // SortFunction sortFunctions[]

} // namespace anonymous

SortingChecker::SortingChecker()
               : emptyArray_( 0 ), 
                 oneArray_( 1, 0 ),
                 oddArray_( ODD_ARRAY_SIZE, 0 ),
                 evenArray_( EVEN_ARRAY_SIZE, 0 ),
                 sortedOddArray_(),
                 sortedEvenArray_()
{
     unsigned int randomInitiator = static_cast< unsigned int >( std::time( NULL ) );
     std::srand( randomInitiator );
     std::generate( oddArray_.begin(),  oddArray_.end(),  [](){ return std::rand(); } );
     std::generate( evenArray_.begin(), evenArray_.end(), [](){ return std::rand(); } );

     sortedOddArray_   = oddArray_;
     sortedEvenArray_  = evenArray_;
     std::sort( sortedOddArray_.begin(), sortedOddArray_.end() );
     std::sort( sortedEvenArray_.begin(), sortedEvenArray_.end() );
}


void SortingChecker::CheckAll()
{
     //TODO range-based for for( auto x : sortFunctions ) on a newest compiler
     for( SortFunction* foo = sortFunctions; *foo ; ++foo )
     {
          CheckOne( *foo, emptyArray_, emptyArray_ );
          CheckOne( *foo, oneArray_,   oneArray_   );
          CheckOne( *foo, oddArray_,   sortedOddArray_  );
          CheckOne( *foo, evenArray_,  sortedEvenArray_ );
     }
}


void SortingChecker::CheckOne( SortingChecker::SortFunction foo, 
     const std::vector< int >& source,
     const std::vector< int >& pattern )
{
     std::vector< int > t( source.begin(), source.end() );
     foo( t );
     if( pattern != t )
     {
          throw std::runtime_error(" sorting result is wrong ");
     }
}


} // namespace research
} // namespace nspiv

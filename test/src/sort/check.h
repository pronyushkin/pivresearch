#pragma once

/// @file
/// @brief The checker for sort algorithms. Definition.
/// @copyright Copyright 2015 Igor V. Pronyushkin.
/// @author Igor V. Pronyushkin
/// @date 2015


#include <vector>

namespace nspiv
{
namespace research
{


/// @brief The sorting checker.
class SortingChecker
{
public:
     /// @brief typedef for an algorithm for tests
     typedef void ( *SortFunction)( std::vector< int >& );

     SortingChecker();

     /// @brief The check for all algorithms.
     /// @throws std::runtime_error if failed
     void CheckAll();
private:

     /// @brief The check an algorithm.
     /// @throws std::runtime_error if failed
     void CheckOne( SortingChecker::SortFunction foo, 
                    const std::vector< int >& source,
                    const std::vector< int >& pattern );

     std::vector< int > emptyArray_;
     std::vector< int > oneArray_;
     std::vector< int > oddArray_;
     std::vector< int > evenArray_;

     std::vector< int > sortedOddArray_;
     std::vector< int > sortedEvenArray_;


}; // class SortingChecker


} // namespace research
} // namespace nspiv

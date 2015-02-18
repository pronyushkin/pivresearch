/// @file
/// @brief The main function for the test application.
/// @copyright Copyright 2015 Igor V. Pronyushkin.
/// @author Igor V. Pronyushkin
/// @date 2015

#include <exception>
#include <iostream>

#include <sort/check.h>

/// @brief The main function.
int main( int argc, char** argv )
{
     std::cout << "all tests" << std::endl;
     try
     {
          std::cout << "all sorting tests" << std::endl;
          nspiv::research::SortingChecker sortChecker;
          sortChecker.CheckAll();
          std::cout << " SUCCESS " << std::endl;
          return EXIT_SUCCESS;
     }
     catch( std::exception& e )
     {
          std::cout << " FAILURE. Exception:" << e.what() << std::endl;
     }
     catch( ... )
     {
          std::cout << " FAILURE. Unknown exception." << std::endl;
     }

    return EXIT_FAILURE;
}


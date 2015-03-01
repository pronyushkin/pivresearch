/// @file
/// @brief The main function for the quick test application.
/// @copyright Copyright 2015 Igor V. Pronyushkin.
/// @author Igor V. Pronyushkin
/// @date 2015

#include <iostream>


struct Node 
{
     size_t value;
     Node*  next;
     
     ~Node()
     {
          delete next;
     }
};


Node* MakeList( size_t n )
{
     if( !n )
     {
          return nullptr;
     }

     size_t i = 0;
     Node* r = new Node();
     Node* p = r;

     p->value = ++i;
     p->next  = nullptr;

     while(  i != n )
     {
          p->next = new Node();
          p = p->next;
          p->value = ++i;
          p->next  = nullptr;
     }
     return r;
}


void PrintList( Node* l )
{
     while( l )
     {
          std::cout << l->value << " ";
          l = l->next;
     }
     std::cout << std::endl;
}


Node* RevertList( Node* l )
{
     if( !l || !l->next )
     {
          return l;
     }

     Node* tail = nullptr;
     Node* head = l;
     
     while( head->next )
     {
          Node* next = head->next;
          head->next = tail;
          tail = head;
          head = next;          
     }
     head->next = tail;
     return head;
}


bool CheckList( Node* l, size_t s )
{
     if( !l )
     {
          if( !s )
               return true;

          std::cerr << "CheckList failed. s=" << s << " but  list is empty" << std::endl;
          return false;
     }

     if( !l->next )
     {
          if( 1 == s )
               return true;

          std::cerr << "CheckList failed. s=" << s << " but  list has one node" << std::endl;
          return false;
     }

     size_t c = 1;
     while( l->next )
     {
          ++c;
          if( l->value < l->next->value )
          {
               std::cerr << "CheckList failed. c=" << c << " prev=" << l->value << " next=" << l->next->value << std::endl;
               return false;
          }
          l = l->next;
     }
     if( c != s )
     {
          std::cerr << "CheckList failed. c=" << c << " s=" << s << std::endl;
          return false;     
     }

     return true;
}


void TestRevertList( size_t s )
{
     std::cout << "TestRevertList s=" << s << std::endl;
     Node* l1 = MakeList( s );
     PrintList( l1 );
     delete l1;

     Node* l2 = MakeList( s );
     l2 = RevertList( l2 );
     PrintList( l2 );
     bool result = CheckList( l2, s );
     delete l2;

     std::cout << ( result ? "SUCCESS" : "FAILED" ) << std::endl;
}

/// @brief The main function.
int main( int argc, char** argv )
{
    std::cout << "quick test" << std::endl;

    TestRevertList( 0 );
    TestRevertList( 1 );
    TestRevertList( 2 );
    TestRevertList( 3 );
    TestRevertList( 10 );

    return EXIT_SUCCESS;
}


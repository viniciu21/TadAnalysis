#include <iostream>

#include "./Node.hpp"

using namespace std;

class Doubly_Linked_List {
   private:
    Node *head = new Node();

   public:
    Doubly_Linked_List();
    void insert(int x);
    void removeFirst();
    void print_nodes();
};

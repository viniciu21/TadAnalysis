#include <iostream>

using namespace std;

class Node {
   private:
    int key;
    Node *prev;
    Node *next;

   public:
    Node();
    void set_key(int x);
    void set_prev(Node *x);
    void set_next(Node *x);
    int get_key();
    Node *get_prev();
    Node *get_next();

    ~Node();
};

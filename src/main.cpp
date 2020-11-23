#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;

#include "../include/Doubly_Linked_List.hpp"

// class Node {
//    private:
//     int key;
//     Node *prev;
//     Node *next;

//    public:
//     Node() {}
//     void set_key(int x) { key = x; }
//     void set_prev(Node *x) { prev = x; }
//     void set_next(Node *x) { next = x; }
//     int get_key() { return this->key; }
//     Node *get_prev() { return this->prev; }
//     Node *get_next() { return this->next; }

//     ~Node() {
//         cout << "Delete " << this->key << " value" << endl;
//     }
// };

// class Doubly_Linked_List {
//    private:
//     Node *head = new Node();

//    public:
//     Doubly_Linked_List() {
//         head->set_key(0);
//         head->set_prev(NULL);
//         head->set_next(NULL);
//     }
//     void insert(int x) {
//         Node *n = new Node();
//         n->set_key(x);
//         n->set_next(head->get_next());
//         if (head->get_next() != NULL)
//             (head->get_next())->set_prev(n);
//         head->set_next(n);
//         n->set_prev(NULL);
//     }
//     void removeFirst() {
//         Node *x = head->get_next()->get_next();
//         delete head->get_next();
//         head->set_next(x);
//         x->set_prev(head);
//     }
//     void print_nodes() {
//         Node *x = head->get_next();
//         while (x != NULL) {
//             cout << x->get_key() << endl;
//             x = x->get_next();
//         }
//     }
// };

int main() {
    Doubly_Linked_List *l = new Doubly_Linked_List();

    ofstream doublyLinkedListInsertion, stackInsertion, doublyLinkedListDelete, stackDelete;  //Arquivos de saida
    doublyLinkedListInsertion.open("data/insertion/linkedInsertion.txt");
    stackInsertion.open("data/insertion/stackInsertion.txt");
    doublyLinkedListDelete.open("data/delete/linkedDelete.txt");
    stackDelete.open("data/delete/stackDelete.txt");

    long double linked_values[100], stack_values[100];

    for (size_t index{50}; index < 100000; index++) {
    }

    return 0;
}

#include "../include/Doubly_Linked_List.hpp"

#include <iostream>

using namespace std;

Doubly_Linked_List::Doubly_Linked_List() {
    head->set_key(0);
    head->set_prev(NULL);
    head->set_next(NULL);
}
void Doubly_Linked_List::insert(int x) {
    Node *n = new Node();
    n->set_key(x);
    n->set_next(head->get_next());
    if (head->get_next() != NULL)
        (head->get_next())->set_prev(n);
    head->set_next(n);
    n->set_prev(NULL);
}

void Doubly_Linked_List::removeFirst() {
    Node *x = head->get_next()->get_next();
    delete head->get_next();
    head->set_next(x);
    x->set_prev(head);
}
void Doubly_Linked_List::print_nodes() {
    Node *x = head->get_next();
    while (x != NULL) {
        x = x->get_next();
    }
}

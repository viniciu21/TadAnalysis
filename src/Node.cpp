#include "../include/Node.hpp"

#include <iostream>

using namespace std;

Node::Node() {}
void Node::set_key(int x) {
    this->key = x;
}
void Node::set_prev(Node *x) {
    this->prev = x;
}
void Node::set_next(Node *x) {
    this->next = x;
}
int Node::get_key() {
    return this->key;
}
Node *Node::get_next() {
    return this->next;
}
Node *Node::get_prev() {
    return this->prev;
}

Node::~Node() {
    cout << "Delete " << this->key << " value" << endl;
}

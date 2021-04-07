#include <iostream>

using namespace std;

class Node {
    public:
    char data;
    Node* next;
    Node(char c, Node* n = nullptr) : data(c) , next(n) {}
};

int main() {
    Node *node = new Node('y', 
                 new Node('o',
                 new Node('u', 
                 new Node('s', 
                 new Node('s', 
                 new Node('e', 
                 new Node('f')))))));

    // Printing nodes..
    while (node != nullptr){
        cout << node->data;
        node = node->next;
    }

    return 0;
}

/*
OUT:
    youssef
*/
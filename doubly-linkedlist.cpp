#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* prev;
    Node *next;
    Node(int value) {
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
    void recursive_reverse(Node*);
public:
    void push_front(int);
    void push_back(int);
    int pop_front();
    int pop_back();
    Node* find(int);
    bool remove(int);
    bool remove(Node*);
    bool add_after(Node*,int);
    bool add_after(int,int);
    bool add_before(Node*,int);
    bool add_before(int,int);
    void reverse();
    int get_size();
    bool is_empty();
    void print();
    void print_reversed();
};

void DoublyLinkedList::push_front(int value){
    Node *new_node = new Node(value);
    if (size == 0){
        head = new_node;
        tail = new_node;
    }
    else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    size++;
}

void DoublyLinkedList::push_back(int value){
    Node *new_node = new Node(value);
    if (size == 0){
        head = new_node;
        tail = new_node;
    }
    else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}

int DoublyLinkedList::pop_front(){
    if (size == 0){
        cerr << "Error Popping: empty list!" << endl;
        exit(-1);
    }
    int tmp = head->value;
    Node* node = head->next;
    node->prev = nullptr;
    delete head;
    head = node;
    size--;
    return tmp;
}

int DoublyLinkedList::pop_back(){
    if (size == 0){
        cerr << "Error Popping: empty list!" << endl;
        exit(-1);
    }
    int tmp = tail->value;
    Node* node = tail->prev;
    node->next = nullptr;
    delete tail;
    tail = node;
    size--;
    return tmp;
}

Node* DoublyLinkedList::find(int value){
    Node* node = head;
    while (node != nullptr){
        if (node->value == value)
            return node;
        node = node->next;
    }
    return nullptr;
}

bool DoublyLinkedList::remove(Node* node) {
    if (node == nullptr)
        return false;
    if (node == head){
        pop_front();
        return true;
    }
    if (node == tail){
        pop_back();
        return true;
    }
    Node* nxt = node->next;
    Node* prv = node->prev;
    prv->next = nxt;
    nxt->prev = prv;
    delete node;
    size--;
    return true;
}

bool DoublyLinkedList::remove(int value) {
    return remove(find(value));
}

bool DoublyLinkedList::add_after(Node* node, int value){
    if (node == nullptr)
        return false;
    Node* new_node = new Node(value);
    new_node->prev = node;
    new_node->next = node->next;
    if (node->next != nullptr)
        node->next->prev = new_node;
    node->next = new_node;
    size++;
    return true;
}

bool DoublyLinkedList::add_after(int node_value, int value){
    return add_after(find(node_value), value);
}

bool DoublyLinkedList::add_before(Node* node, int value){
    if (node == nullptr)
        return false;
    Node* new_node = new Node(value);
    new_node->prev = node->prev;
    new_node->next = node;
    if (node->prev != nullptr)
        node->prev->next = new_node;
    node->prev = new_node;
    size++;
    return true;
}

bool DoublyLinkedList::add_before(int node_value, int value){
    return add_before(find(node_value), value);
}

void DoublyLinkedList::recursive_reverse(Node* node) {
    if (node==nullptr) return;
    recursive_reverse(node->next);
    swap(node->next, node->prev);
}

void DoublyLinkedList::reverse() {
    recursive_reverse(head);
    swap(head,tail);
}

int DoublyLinkedList::get_size() {
    return size;
}

bool DoublyLinkedList::is_empty(){
    return size == 0;
}

void DoublyLinkedList::print(){
    if (is_empty()) return;
    Node* tmp = head;
    while (tmp != nullptr){
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void DoublyLinkedList::print_reversed(){
    if (is_empty()) return;
    Node* tmp = tail;
    while (tmp != nullptr){
        cout << tmp->value << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}


// Driver 

int main() {
    DoublyLinkedList dl;
    for (int i = 6;i<11;i++) dl.push_back(i);
    for (int i = 5;i>0;i--) dl.push_front(i);
    dl.print();
    cout << "Size: " << dl.get_size() << endl;
    cout << "pop_front() " << dl.pop_front() << endl;
    dl.print();
    cout << "pop_back() " << dl.pop_back() << endl;
    dl.print();
    dl.reverse();
    dl.print();
    cout << "Print using backward iteration.." << endl;
    dl.print_reversed();
    return 0;
}
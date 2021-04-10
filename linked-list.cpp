#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node *next;
    Node(int value){
        this->value = value;
        next = nullptr;
    }
};

class List {
private:
    Node *head;
    Node *tail;
    int sz = 0;
public:
    List() : head(nullptr) , tail(nullptr) {}
    void push_front(int);
    void push_back(int);
    Node* find(int);
    bool remove(int);
    bool add_after(int, int);
    int pop_front();
    int pop_back();
    bool isEmpty();
    int size();
    void print();
};

void List::push_front(int value){
    Node *node = new Node(value);
    if (sz == 0){
        head=node;
        tail=node;
    }
    else {
        node->next = head;
        head = node;
    }
    sz++;
}

void List::push_back(int value) {
    Node *node = new Node(value);
    if (sz == 0){
        head=node;
        tail=node;
    }
    else {
        tail->next = node;
        tail = node;
    }
    sz++;
}

Node *List::find(int value){
    Node *it = head;
    while (it != nullptr){
        if (it->value == value)
            return it;
        it = it->next;
    }
    return nullptr;
}

bool List::remove(int value){
    Node *it = head;
    if (!isEmpty() && head->value == value) {
        pop_front();
        return true;
    }
    while (it->next != nullptr){
        if (it->next->value == value){
            Node* tmp = it->next->next;
            delete it->next;
            it->next = tmp;
            sz--;
            return true;
        }
        it = it->next;
    }
    return false;
}

bool List::add_after(int find_value, int value) {
    Node *node = find(find_value);
    if (node != nullptr){
        Node *tmp = node->next;
        Node *new_node = new Node(value);
        new_node->next = tmp;
        node->next = new_node;
        sz++;
        return true;
    }
    return false;
}

int List::pop_front() {
    if (sz == 0){
        cerr << "error popping: empty List." << endl;
        exit(-1);
    }
    int tmp = head->value;
    Node* node = head->next;
    delete head;
    head = node;
    sz--;
    if (sz == 1){
        delete head;
        delete tail;
    }
    return tmp;
}

int List::pop_back() {
    if (sz == 0){
        cerr << "error popping: empty List." << endl;
        exit(-1);
    }
    int tmp = tail->value;
    Node* node = head;
    for (int i = 0;i<sz-2;i++) 
        node=node->next;
    delete tail;
    tail = node;
    tail->next = nullptr;
    sz--;
    if (sz == 1){
        delete head;
        delete tail;
    }
    return tmp;
}

bool List::isEmpty(){
    return sz == 0;
}

int List::size() {
    return sz;
}

void List::print() {
    if (sz == 0) return;
    Node* it = head;
    while (it != nullptr){
        cout << it->value << " ";
        it = it->next;
    }
    cout << endl;
}

int main() {
    List l;
    for (int x = 1;x<11;x++) l.push_back(x);
    while(!l.isEmpty()) {
        cout << l.pop_back() << " ";
    }
    l.print();
    return 0;
}
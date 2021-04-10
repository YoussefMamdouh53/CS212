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

class Queue {
private:
    Node *head;
    Node *tail;
    int sz;
public:
    Queue() : head(nullptr) , tail(nullptr), sz(0) {}
    void push(int);
    int pop();
    int peak();
    bool isEmpty();
    int size();
};

void Queue::push(int value){
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

int Queue::pop() {
    if (sz == 0){
        cerr << "error popping: empty Queue." << endl;
        exit(-1);
    }
    int tmp = tail->value;
    Node* node = head;
    for (int i = 0;i<sz-2;i++) 
        node=node->next;
    delete tail;
    tail = node;
    tail->next = nullptr;
    if (sz == 1){
        delete head;
        delete tail;
    }
    sz--;
    return tmp;
}
int Queue::peak() {
    if (!isEmpty())
        return tail->value;
    cerr << "Error peaking: empty Queue!" << endl;
    exit(-1);
}
bool Queue::isEmpty(){
    return sz == 0;
}

int Queue::size() {
    return sz;
}
int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    cout << q.peak();
    return 0;
}
/*
Name    :   Youssef Mamdouh
Reg no.     19108541
Group   :   A
Problem :   Stack implementaion based on linked list.
*/

#include <iostream>
using namespace std;

template<typename T>

class Node {
public:
    T data;
    Node<T>* next;
    Node(T value, Node<T>* next){
        data = value;
        this->next = next;
    }
};

template<typename T>

class Stack {
    Node<T> *top = nullptr;
    int length = 0;
public:
    void push(T value) {
        Node<T>* tmp = new Node<T>(value,top);
        top=tmp;
        length++;
    }
    int pop() {
        if (top==nullptr) {
            cout << "Empty Stack" << endl;
            exit(1);
        }
        Node<T> *tmp = top->next;
        int value = top->data;
        delete top;
        top = tmp;
        length--;
        return value;
    }
    int peak() {
        if (top==nullptr){
            cout << "Empty Stack" << endl;
            exit(1);
        }
        return top->data;
    }
    bool isEmpty() {
        return length==0;
    }
    int getLength() {
        return length;
    }
};

// driver..
int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.peak() << endl;
    while(!s.isEmpty()){
        cout << s.pop() << endl;
    }
}
/*
Name    :   Youssef Mamdouh
Reg no.     19108541
Group   :   A
Problem :   Stack implementaion based on array.
*/

#include <iostream>

using namespace std;

class Stack {
    int size;
    int *arr;
    int top;
public:
    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = 0;
    }
    Stack() : Stack(10) {}
    int pop() {
        if (top>0)
            return arr[--top];
        else {
            cout << "Empty Stack" << endl;
            exit(1);
        }
    }
    void push(int value) {
        if (top < size) arr[top++]=value;
        else
            cout << "Stack overflow!" << endl;
    }
    int findMin() {
        Stack s(size);
        int Min = INT_MAX;
        while (!isEmpty()){
            Min = min(Min,pop());
        }
        while (!s.isEmpty()){
            push(s.pop());
        }
        return Min;
    }
    bool isEmpty(){
        return top==0;
    }
};

// Driver

int main() {
    Stack s;
    s.push(43);
    s.push(55);
    s.push(13);
    s.push(1);
    s.push(19);
    s.push(98);
    cout << s.findMin() << endl;
    return 0;
}

// OUTPUT:  1
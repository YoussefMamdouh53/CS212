/*
Name    :   Youssef Mamdouh
Reg no.     19108541
Group   :   A
Problem :   Three stacks implementaion based on one array.
*/

#include <iostream>

using namespace std;

class Stack {
    int size;
    int *arr;
    int top1;
    int top2;
    int top3;

    public:
        Stack(int size)
        {
            this->size = size;
            arr = new int[size*3];
            top1 = 0;
            top2 = size;
            top3 = size*2;
    }
    Stack() : Stack(10) {}
    int pop1() {
        if (top1>0)
            return arr[--top1];
        else {
            cout << "Empty Stack 1" << endl;
            exit(1);
        }
    }
    int pop2() {
        if (top2>size)
            return arr[--top2];
        else {
            cout << "Empty Stack 2" << endl;
            exit(1);
        }
    }
    int pop3() {
        if (top3>size*2)
            return arr[--top3];
        else {
            cout << "Empty Stack 3" << endl;
            exit(1);
        }
    }
    void push1(int value) {
        if (top1 < size) arr[top1++]=value;
        else
            cout << "Stack 1 overflow!" << endl;
    }
    void push2(int value) {
        if (top2 < size * 2) arr[top2++]=value;
        else
            cout << "Stack 2 overflow!" << endl;
    }
    void push3(int value) {
        if (top3 < size*3) arr[top3++]=value;
        else
            cout << "Stack 3 overflow!" << endl;
    }
    bool isEmpty1(){
        return top1==0;
    }
    bool isEmpty2(){
        return top2 == size;
    }
    bool isEmpty3(){
        return top3==size*2;
    }
};

int main() {
    Stack s;
    s.push1(1);
    s.push1(2);
    s.push1(3);
    s.push1(4);
    s.push1(5);
    s.push2(6);
    s.push2(7);
    s.push2(8);
    s.push2(9);
    s.push2(10);
    s.push3(11);
    s.push3(12);
    s.push3(13);
    s.push3(14);
    s.push3(15);
    while(!s.isEmpty1()){
        cout << s.pop1() << " ";
    }
    cout << endl;
     while(!s.isEmpty2()){
        cout << s.pop2() << " ";
    }
    cout << endl;
     while(!s.isEmpty3()){
        cout << s.pop3() << " ";
    }
    cout << endl;

}
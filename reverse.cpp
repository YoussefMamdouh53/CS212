/*
    Name    :  Youssef Mamdouh
    Reg no. :  19108541
    Problem :  Reverse whole sentence using pointers technique
*/
#include <iostream>
#include <string>

using namespace std;

void reverse(string *s) {
    int l = 0, r = s->size() - 1;
    while (l<r){
        char tmp = (*s)[l];
        (*s)[l] = (*s)[r];
        (*s)[r] = tmp;
        l++, r--;
    }
}

int main() {
    string name;
    getline(cin, name);
    reverse(&name);
    cout << name << endl;
    return 0;
}

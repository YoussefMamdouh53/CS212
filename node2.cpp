#include <iostream>

using namespace std;

class Node {
public:
    Node* next;
};

int main() {
    // Y
    Node n1, n2, n3, n4;
    n1.next = &n2;
    n3.next = &n2;
    n2.next = &n4;
    // O
    Node n5, n6, n7, n8;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;
    n8.next = &n5;
    // U
    Node n9, n10, n11, n12;
    n9.next = &n10;
    n10.next = &n11;
    n11.next = &n12;
    // S
    Node n13, n14, n15, n16, n17, n18;
    n13.next = &n14;
    n14.next = &n15;
    n15.next = &n16;
    n16.next = &n17;
    n17.next = &n18;
    // E
    Node n19, n20, n21, n22, n23, n24;
    n19.next = &n20;
    n20.next = &n21;
    n21.next = &n22;
    n22.next = &n23;
    n21.next = &n24;
    // F
    Node n25, n26, n27, n28, n29;
    n25.next = &n26;
    n26.next = &n27;
    n27.next = &n28;
    n27.next = &n29;
    return 0;
}
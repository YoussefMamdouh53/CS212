/*
Name    :   Youssef Mamdouh
Reg no. :   19108541
Group   :   A
Prob.   :   Dynamic list using ADT.
*/

#include <iostream>
#include <cstring>

using namespace std;

// Class Header
class List {
private:

	int size;
	int capacity;
	int* arr;

	void reAllocate();

public:
	List(int c);
	List();
	int getSize();
	int getCapacity();
	int get(int index);
	void set(int index, int value);
	void push_back(int value);
	void push_front(int value);
	void pop_back();
	void pop_front();
	int front();
	int back();
	void remove(int index);
	bool isEmpty();
	void print();
};

// Class Implementation
void List::reAllocate() {
	int* tmp = new int[capacity * 2];
	memcpy(tmp, arr, size * sizeof(*arr));
	capacity *= 2;
	delete[] arr;
	arr = tmp;
	cout << "Reallocated: new capacity is " << capacity << endl;
}

List::List(int c) {
	capacity = c;
	size = 0;
	arr = new int[c];
}

List::List() : List(5) {}

int List::getSize() {
	return size;
}

int List::getCapacity() {
	return capacity;
}

int List::get(int index) {
	if (index < 0 || index >= size) {
		cout << "ERROR: Index out of bounds" << endl;
		exit(1);
	}
	return arr[index];
}

void List::set(int index, int value) {
	if (index < 0 || index >= size) {
		cout << "ERROR: Index out of bounds" << endl;
		return;
	}
	arr[index]=value;
}
void List::push_back(int value) {
	if (size >= capacity)
		reAllocate();
	arr[size++] = value;
}

void List::push_front(int value) {
	if (size >= capacity) {
		reAllocate();
	}
	for (int i = size; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = value;
	size++;
}

void List::pop_back() {
	remove(size - 1);
}

void List::pop_front() {
	remove(0);
}

int List::front() {
	return !isEmpty() ? arr[0] : NULL;
	if (!isEmpty()) return arr[0];
	else {
		cout << "Empty List" << endl;
		exit(1);
	}
}

int List::back() {
	if (!isEmpty()) return arr[size - 1];
	else {
		cout << "Empty List" << endl;
		exit(1);
	}
}

void List::remove(int index) {
	if (index < 0 || index >= size) {
		cout << "ERROR REMOVING: Index out of bounds" << endl;
		return;
	}
	for (int i = index; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	size--;
}

bool List::isEmpty() {
	return size == 0;
}

void List::print() {
	if (size == 0) cout << "Empty list\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	List l;
	l.push_back(5);
	l.push_back(4);
	l.push_back(53);
	l.push_back(21);
	l.push_back(46);
	l.push_back(12);
	l.print();
	l.pop_front();
	l.set(1,55);
	l.print();
	l.pop_back();
	l.print();
	l.remove(1);
	l.print();
	l.push_front(14);
	l.print();
	cout << l.getSize() << endl;
	cout << l.front() << endl;
	cout << l.back() << endl;
	return 0;
}

/*
OUTPUT:

	Reallocated: new capacity is 10
	5 4 53 21 46 12
	4 55 21 46 12
	4 55 21 46
	4 21 46
	14 4 21 46 
	14
	46

*/

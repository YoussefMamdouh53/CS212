/*
Name    :   Youssef Mamdouh
Reg no. :   19108541
Group   :   A
Prob.   :   Get Permutaion of word using recursion.
Complx  :   O(N!)
*/

#include <iostream>

using namespace std;

void permute(string str, int low, int high) {
	if (low == high) {
		cout << str << endl;
		return;
	}
	for (int j = low; j <= high; j++) {
		swap(str[low], str[j]);
		permute(str, low + 1, high);
		swap(str[low], str[j]);
	}
}
void permute(string str) {
	permute(str, 0, str.size() - 1);
}

int main() {
	string s;
	cin >> s;
	permute(s);
	return 0;
}

/*
Sample test:

IN: abcd

OUT:
	abcd
	abdc
	acbd
	acdb
	adcb
	adbc
	bacd
	badc
	bcad
	bcda
	bdca
	bdac
	cbad
	cbda
	cabd
	cadb
	cdab
	cdba
	dbca
	dbac
	dcba
	dcab
	dacb
	dabc

*/
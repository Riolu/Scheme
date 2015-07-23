#include "calc_exp.h"
#include <iostream>
using namespace std;

int main() {
	try {
		for (Datatype *res;;) {
			res = calc_exp();
			res->print();
			cout << endl;
		}
	}
	catch (int){ cerr << "Wrong"; }
	//system("pause");
	return 0;
}
#include <iostream>
#include <array>
#include "HeatFlow.hpp"

using namespace std;

void tester() {
	cout << "Starting Testing" << endl;
	HeatFlow testrod(1);

	cout << testrod.pretty_print();
	testrod.tick();
	cout << testrod.pretty_print();
	testrod.tick();
	cout << testrod.pretty_print();
	testrod.tick();
	cout << testrod.pretty_print();

	cout << "Testing Sink" << endl;
	HeatFlow testrod(2);

	cout << testrod.pretty_print();
	testrod.tick();
	cout << testrod.pretty_print();
	testrod.tick();
	cout << testrod.pretty_print();
	testrod.tick();
	cout << testrod.pretty_print();
}

int main(){
	tester();

	return 0;
}
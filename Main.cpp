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

	cout << endl << endl << "Testing Sink" << endl;
	HeatFlow sinkrod(2);

	cout << sinkrod.pretty_print();
	sinkrod.tick();
	cout << sinkrod.pretty_print();
	sinkrod.tick();
	cout << sinkrod.pretty_print();
	sinkrod.tick();
	cout << sinkrod.pretty_print();

	cout << endl << endl << "Testing multiple locations" << endl;
	HeatFlow multirod(3);

	cout << multirod.pretty_print();
	multirod.tick();
	cout << multirod.pretty_print();
	multirod.tick();
	cout << multirod.pretty_print();
	multirod.tick();
	cout << multirod.pretty_print();

	cout << endl << endl << "Testing completed" << endl;
}

int main(){
	string userinput;
	cout << "\t\t Welcome to Go With The Flow!" << endl;
	cout << "Please enter start to begin or test to test the program." << endl;
	cin >> userinput;
	if (toupper(userinput[0]) == 'T') {
		tester();
	}
	else {
		HeatFlow rodulus;

		bool inprogress = true;
		string YorN;

		while (inprogress == true) {
			cout << endl << "Do you want to run a tick? ";
			cin >> YorN;
			if (toupper(YorN[0]) == 'Y') {
				rodulus.tick();
				cout << rodulus.pretty_print() << endl;
			} else { inprogress = false; }

		}
	}
	
	cout << endl << "\t\t Thank you for using my program :)";
	return 0;
}
#include <iostream>
#include <array>
#include "HeatFlow.hpp"
#include "AdvancedFlow.hpp"
#include "MultiK.hpp"

using namespace std;

void tester() {
	cout << "Starting Testing" << endl;
	HeatFlow testrod(1);

	//tests a basic rod with a source at the start and ticks 3 times
	cout << testrod.pretty_print();
	testrod.tick();
	cout << testrod.pretty_print();
	testrod.tick();
	cout << testrod.pretty_print();
	testrod.tick();
	cout << testrod.pretty_print();

	cout << endl << endl << "Testing Sink" << endl;
	HeatFlow sinkrod(2);

	//tests out a rod with sink in the middle
	cout << sinkrod.pretty_print();
	sinkrod.tick();
	cout << sinkrod.pretty_print();
	sinkrod.tick();
	cout << sinkrod.pretty_print();
	sinkrod.tick();
	cout << sinkrod.pretty_print();

	cout << endl << endl << "Testing multiple locations" << endl;
	HeatFlow multirod(3);

	//tests a rod with mulitple sinks and sources
	cout << multirod.pretty_print();
	multirod.tick();
	cout << multirod.pretty_print();
	multirod.tick();
	cout << multirod.pretty_print();
	multirod.tick();
	cout << multirod.pretty_print();


	cout << endl << endl << "Testing complex formula locations" << endl;
	AdvFlow complexrod(1);

	//tests a rod with big formula
	cout << complexrod.pretty_print();
	complexrod.tick();
	cout << complexrod.pretty_print();
	complexrod.tick();
	cout << complexrod.pretty_print();
	complexrod.tick();
	cout << complexrod.pretty_print();

	cout << endl << endl << "Testing individual insulators" << endl;
	MultiK insulatorrod(2);

	//tests a rod with big formula
	cout << insulatorrod.pretty_print();
	insulatorrod.tick();
	cout << insulatorrod.pretty_print();
	insulatorrod.tick();
	cout << insulatorrod.pretty_print();
	insulatorrod.tick();
	cout << insulatorrod.pretty_print();

	cout << endl << endl << "Testing completed" << endl;
}

int main(){
	string userinput;
	cout << "\t\t Welcome to Go With The Flow!" << endl;

	//Menu for user to start test or use program.
	cout << "Please enter which program you want to run." << endl;
	cin >> userinput;
	if (toupper(userinput[0]) == 'T') {
		tester();
	}
	else if (toupper(userinput[0]) == 'C') {
		AdvFlow rodger;

		bool inprogress = true;
		string YorN;
		cout << rodger.pretty_print() << endl;

		while (inprogress == true) {
			cout << endl << "Do you want to run a tick? ";
			cin >> YorN;
			if (toupper(YorN[0]) == 'Y') {
				rodger.tick();
				cout << rodger.pretty_print() << endl;
			}
			else { inprogress = false; }
		}
	}
	else if (toupper(userinput[0]) == 'I') {
		MultiK rodney;

		bool inprogress = true;
		string YorN;
		cout << rodney.pretty_print() << endl;

		while (inprogress == true) {
			cout << endl << "Do you want to run a tick? ";
			cin >> YorN;
			if (toupper(YorN[0]) == 'Y') {
				rodney.tick();
				cout << rodney.pretty_print() << endl;
			}
			else { inprogress = false; }
		}
	}
	else {
		HeatFlow rodulus;

		bool inprogress = true;
		string YorN;
		cout << rodulus.pretty_print() << endl;

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
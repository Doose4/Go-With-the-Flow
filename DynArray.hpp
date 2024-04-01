#pragma once
#include <string>

using namespace std;

class Myarray
{
private:
	int max = 1;
	double* array_pntr;
	double* top;
	double* start;
	double* resize_array();

public:
	explicit Myarray();
	void append_element(double element);
	double get_element_at_index(int index);
	int arraysize();
	void reset();
};


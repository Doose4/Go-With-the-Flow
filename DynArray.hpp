#include <string>

using namespace std;

class Myarray
{
private:
	int max = 1;
	int* array_pntr;
	int* top;
	int* start;
	int* resize_array();

public:
	explicit Myarray();
	void append_element(int element);
	int get_element_at_index(int index);
	int arraysize();
	void reset();
	int* getPointer();
};


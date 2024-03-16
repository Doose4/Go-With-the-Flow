#include <string>
#include <array>
#include <iostream>
#include "DynArray.hpp"

using namespace std;

class HeatFlow
{
    double intTemp;
    int rodLen;
    double contK;
    Myarray rod;
    Myarray sourceNsink;
    string Cleanup(double element);

public:
    explicit HeatFlow(int indicator = 0);
    void tick();
    string pretty_print();
};
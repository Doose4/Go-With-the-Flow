#include <string>
#include <array>
#include <iostream>
#include "DynArray.hpp"

using namespace std;

class HeatFlow
{
    int intTemp;
    int rodLen;
    double contK;
    Myarray rod;
    Myarray sourceNsink;
    //int* rodPtr = rod.getPointer();
    //int* sourceNsinkPtr = sourceNsink.getPointer();

public:
    explicit HeatFlow(int indicator = 0);
    void tick();
    string pretty_print();
};
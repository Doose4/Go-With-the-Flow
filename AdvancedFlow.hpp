#include <string>
#include <array>
#include <iostream>
#include "DynArray.hpp"

using namespace std;

class AdvFlow
{
    double intTemp;
    int rodLen;
    double conduct;
    double timebetween;
    double distance;
    Myarray rod;
    Myarray sourceNsink;
    string Cleanup(double element);

public:
    explicit AdvFlow(int indicator = 0);
    void tick();
    string pretty_print();
};
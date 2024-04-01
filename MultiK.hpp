#include <string>
#include <array>
#include <iostream>
#include "DynArray.hpp"

using namespace std;

class MultiK
{
    double intTemp;
    int rodLen;
    Myarray smallK;
    Myarray rod;
    Myarray sourceNsink;
    string Cleanup(double element);

public:
    explicit MultiK(int indicator = 0);
    void tick();
    string pretty_print();
};
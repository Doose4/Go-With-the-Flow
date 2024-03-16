#include <iostream>
#include "DynArray.hpp"

Myarray::Myarray() {
    max = 1;
    array_pntr = new double[max];
    start = array_pntr;
    top = start;

}

double* Myarray::resize_array()
{
    // Create a new dynamic array that is one larger than the old array
    max++;
    double* new_array = new double[max];
    start = new_array;
    top = start + max - 1;

    // Copy the elements from the original array to the new array
    for (int i = 0; i < max; i++)
    {
        new_array[i] = array_pntr[i];
    }

    // Delete the original array
    delete[] array_pntr;

    return new_array;
}

//Adds an element onto the array, whether it expands the dynamic array or rewrites an existing varible that wasn't called
void Myarray::append_element(double element) {
    int dif = top - start;
    if (dif == 0) {
        *top = element;
        //cout << "Pushed element: " << element << " onto the stack.\n";
        top++;
    }
    else if (max == dif) {
        array_pntr = resize_array();
        *top = element;
        //cout << "Pushed element: " << element << " onto the stack.\n";
        top++;
    }
    else {
        *top = element;
        //cout << "Pushed element: " << element << " onto the stack.\n";
        top++;
    }

}

//Pulls value at specific location
double Myarray::get_element_at_index(int index) {
    return *(start + index);
}

//finds the arrays size
int Myarray::arraysize() {
    return (top - start);
}

//Resets the Array to no elements
void Myarray::reset() {
    top = start;
}
#include <iostream>
#include <string>
#include <vector>
#include "HeatFlow.hpp"
using namespace std;

HeatFlow::HeatFlow(int indicator) {
    int sinks;
    int locations;
    int temps;

    switch (indicator)
    {
    case 1:
        intTemp = 10;
        rodLen = 5;
        contK = 0.1;
        sinks = 1;
        locations = 0;
        sourceNsink.append_element(locations);
        temps = 100;
        sourceNsink.append_element(temps);
        break;
    case 2:
        intTemp = 20;
        rodLen = 10;
        contK = 0.2;
        sinks = 1;
        locations = 4;
        sourceNsink.append_element(locations);
        temps = 0;
        sourceNsink.append_element(temps);
        break;
    case 3:
        intTemp = 10;
        rodLen = 10;
        contK = 0.1;
        sinks = 3;
        locations = 0;
        sourceNsink.append_element(locations);
        temps = 100;
        sourceNsink.append_element(temps);
        locations = 4;
        sourceNsink.append_element(locations);
        temps = 50;
        sourceNsink.append_element(temps);
        locations = 8;
        sourceNsink.append_element(locations);
        temps = 100;
        sourceNsink.append_element(temps);
        break;
    default:
        cout << "Please enter the initial temperator throgh out the rod: ";
        cin >> intTemp;

        cout << "\nPlease enter how many sections are in the rod: ";
        cin >> rodLen;

        cout << "\nPlease enter the K constant for the rod: ";
        cin >> contK;

        cout << "\nPlease enter the number of sinks and sources you want on the rod: ";
        cin >> sinks;

        string english;
        for (int i = 0; i < sinks; i++)
        {
            switch (i)
            {
            case 0:
                english = "st";
                break;
            case 1:
                english = "nd";
                break;
            case 2:
                english = "rd";
                break;
            default:
                english = "th";
                break;
            }
            cout << "\nPlease enter the " << i + 1 << english << " location on the rod (starting with 0): ";
            cin >> locations;
            sourceNsink.append_element(locations);
            cout << "\nPlease enter the constant temperator at the " << i + 1 << english << " location (in celcius): ";
            cin >> temps;
            sourceNsink.append_element(temps);
        }
        break;
    }
    
    locations = sourceNsink.get_element_at_index(0);
    temps = sourceNsink.get_element_at_index(1);
    int j = 0;

    for (int i = 0; i < rodLen; i++)
    {
        if (i == locations)
        {
            rod.append_element(temps);
            j++;
            if (j < sinks)
            {
                locations = sourceNsink.get_element_at_index(j*2);
                temps = sourceNsink.get_element_at_index((j*2)+1);
            }
        } else
        {
            rod.append_element(intTemp);
        }
    }

    //rodPtr = rod.getPointer();
    //sourceNsinkPtr = sourceNsink.getPointer();
}

void HeatFlow::tick() {
    vector <double> tempvector;
    double newval = 0;
    int j = rod.arraysize();
    int k = 0;

    if (sourceNsink.get_element_at_index(k*2) == 0)
    {
        tempvector.push_back(rod.get_element_at_index(0));
        k++;
    } else {
        newval = rod.get_element_at_index(0) + (contK * (rod.get_element_at_index(1) - rod.get_element_at_index(0)));
        tempvector.push_back(newval);
    }

    for (int i = 1; i < j-1; i++)
    {
        if (sourceNsink.get_element_at_index(k * 2) == i)
        {
            tempvector.push_back(rod.get_element_at_index(i));
            k++;
        }
        else {
            newval = rod.get_element_at_index(i) + (contK * (rod.get_element_at_index(i + 1) - (2 * rod.get_element_at_index(i)) + rod.get_element_at_index(i - 1)));
            tempvector.push_back(newval);
        }
        
    }

    if (sourceNsink.get_element_at_index(k * 2) == j)
    {
        tempvector.push_back(rod.get_element_at_index(j));
        k++;
    }
    else {
        newval = rod.get_element_at_index(j-1) + (contK * ((-1 * rod.get_element_at_index(j-1)) + rod.get_element_at_index(j - 2)));
        tempvector.push_back(newval);
    }

    rod.reset();
    for (int i = 0; i < j; i++)
    {
        rod.append_element(tempvector[i]);
    }
}

string HeatFlow::pretty_print() {
    string bars = "+";
    string valu = "|";

    for (int i = 0; i < rodLen; i++)
    {
        bars = bars + "-----+";
        string leng = to_string(rod.get_element_at_index(i));
        switch (leng.length())
        {
        case 1:
            valu = valu + "  " + leng + "  |";
            break;
        case 2:
            valu = valu + " " + leng + "  |";
            break;
        case 3:
            valu = valu + " " + leng + " |";
            break;
        case 4:
            valu = valu + "" + leng + " |";
            break;
        default:
            valu = valu + "" + leng + "|";
            break;
        }
    
    }
    return (bars + "\n" + valu + "\n" + bars + "\n");

}
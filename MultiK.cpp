#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include "MultiK.hpp"
using namespace std;

//Private sub to clean up doubles to not have 4 trailing zeros
string MultiK::Cleanup(double element) {
    stringstream ss;
    ss << fixed << std::setprecision(2) << element;
    string str = ss.str();

    if (str.find('.') != std::string::npos) {
        str = str.substr(0, str.find_last_not_of('0') + 1);
        if (str.find('.') == str.size() - 1) {
            str = str.substr(0, str.size() - 1);
        }
    }

    return str;
}

//constructs Heatflow class, uses an indicator to set specific varibles for testing
MultiK::MultiK(int indicator) {
    double sinks;
    double locations;
    double temps;

    switch (indicator)
    {
    case 1:
        intTemp = 10;
        rodLen = 5;
        smallK.append_element(0.5);
        smallK.append_element(0.4);
        smallK.append_element(0.3);
        smallK.append_element(0.2);
        smallK.append_element(0.1);
        sinks = 1;
        locations = 0;
        sourceNsink.append_element(locations);
        temps = 100;
        sourceNsink.append_element(temps);
        break;
    case 2:
        intTemp = 22.2;
        rodLen = 3;
        smallK.append_element(0.68);
        smallK.append_element(0.22);
        smallK.append_element(0.68);
        sinks = 1;
        locations = 0;
        sourceNsink.append_element(locations);
        temps = 0;
        sourceNsink.append_element(temps);
        break;
    default:
        string english;
        cout << "Please enter the initial temperator through out the rod: ";
        cin >> intTemp;

        cout << "\nPlease enter how many sections are in the rod: ";
        cin >> rodLen;

        for (int i = 1; i <= rodLen; i++)
        {
            double smlk;
            cout << endl << "Please enter the constant k for the insulator between rod " << i << endl;
            cin >> smlk;
            smallK.append_element(smlk);
        }

        cout << "\nPlease enter the number of sinks and sources you want on the rod: ";
        cin >> sinks;

        for (int i = 0; i < sinks; i++)
        {
            bool inprogresss = true;

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

            while (inprogresss == true) {
                cout << "\nPlease enter the " << i + 1 << english << " location on the rod (starting with 0): ";
                cin >> locations;
                inprogresss = false;
                for (int i = 0; i < sinks; i++)
                {
                    if (locations == sourceNsink.get_element_at_index(i * 2)) {
                        cout << "That location was already used..." << endl;
                        inprogresss = true;
                    }
                }
            }

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
                locations = sourceNsink.get_element_at_index(j * 2);
                temps = sourceNsink.get_element_at_index((j * 2) + 1);
            }
        }
        else
        {
            rod.append_element(intTemp);
        }
    }
}

//Goes forward one tick to find new temps throughout the sections
void MultiK::tick() {
    vector <double> tempvector;
    Myarray temparray;
    double newval = 0;
    int j = rod.arraysize();
    int k = 0;

    if (sourceNsink.get_element_at_index(k * 2) == 0)
    {
        temparray.append_element(rod.get_element_at_index(0));
        k++;
    }
    else {
        newval = rod.get_element_at_index(0) + (smallK.get_element_at_index(0) * (rod.get_element_at_index(1) - rod.get_element_at_index(0)));
        temparray.append_element(newval);
    }

    for (int i = 1; i < j - 1; i++)
    {
        if (sourceNsink.get_element_at_index(k * 2) == i)
        {
            temparray.append_element(rod.get_element_at_index(i));
            k++;
        }
        else {
            newval = rod.get_element_at_index(i) + (smallK.get_element_at_index(i) * (rod.get_element_at_index(i + 1) - (2 * rod.get_element_at_index(i)) + rod.get_element_at_index(i - 1)));
            temparray.append_element(newval);
        }

    }

    if (sourceNsink.get_element_at_index(k * 2) == j - 1)
    {
        temparray.append_element(rod.get_element_at_index(j - 1));
        k++;
    }
    else {
        newval = rod.get_element_at_index(j - 1) + (smallK.get_element_at_index(j-1) * ((-1 * rod.get_element_at_index(j - 1)) + rod.get_element_at_index(j - 2)));
        temparray.append_element(newval);
    }

    rod.reset();
    for (int i = 0; i < j; i++)
    {
        rod.append_element(temparray.get_element_at_index(i));
    }
}

//Prints out a pretty output for the user to enjoy
string MultiK::pretty_print() {
    string bars = "+";
    string valu = "|";

    for (int i = 0; i < rodLen; i++)
    {
        bars = bars + "-----+";
        string leng = Cleanup(rod.get_element_at_index(i));
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
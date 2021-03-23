/*
 *        File: auto_parts.cc
 *      Author: Jonah Brautigam
 *        Date: 3/23/2021
 * Description: Finds price of most expensive and least expensive auto part
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Loads prices file into a vector
 * @return vector that has the prices data
*/
vector <double> loadPrices ();

/**
 * Loads parts file into a vector
 * @return vector that has the parts data
*/
vector <string> loadParts ();

/**
 * Gets input file name
 * @return string of input file
*/
string inputFile ();

/**
 * Opens up input file
 * @param input_file string for file name
 * @param ins inStream reference variable
*/
void openFile (string input_file, ifstream &ins);

/**
 * Gets the vector index for most expensive part
 * @param prices vector that this function loops through
 * @return the index of most expensive part
*/
size_t highPrice (vector <double> prices);

/**
 * Gets the vector index for least expensive part
 * @param prices vector that this function loops through
 * @return the index of least expensive part
*/
size_t lowPrice (vector <double> prices);

int main(int argc, char const *argv[]) {

    vector <double> prices = loadPrices ();
    vector <string> parts = loadParts ();

    size_t high_index = highPrice (prices);
    size_t low_index = lowPrice (prices);

    cout << fixed << setprecision(2);

    cout << "The name of the most expensive part is ";
    cout << parts.at(high_index) << " ($" << prices.at(high_index) << ")" << endl;

    cout << "The name of the least expensive part is ";
    cout << parts.at(low_index) << " ($" << prices.at(low_index) << ")" << endl;

    return 0;
}// main

vector <double> loadPrices ()
{
    ifstream ins;
    vector <double> prices;
    double price;

    cout << "Auto part prices" << endl;
    string file_name = inputFile ();

    openFile (file_name, ins);

    ins >> price;
    while (!ins.eof())
    {
        prices.push_back(price);
        ins >> price;
    }

    ins.close();

    return prices;
}

vector <string> loadParts ()
{
    ifstream ins;
    vector <string> parts;
    string part;

    cout << "Auto parts" << endl;
    string file_name = inputFile ();

    openFile (file_name, ins);

    ins >> part;
    while (!ins.eof())
    {
        parts.push_back(part);
        ins >> part;
    }

    ins.close();

    return parts;
}

string inputFile ()
{
    cout << "Enter file name: ";
    string file_name;
    cin >> file_name;
    cout << endl;
    return file_name;
}

void openFile (string input_file, ifstream &ins)
{
    ins.open(input_file);
    if (ins.fail())
    {
        cout << "Error: File could not be open" << endl;
        exit(0);
    }
}

size_t highPrice (vector <double> prices)
{
    double get_price = prices.at(0);
    double high_price = get_price;
    size_t high_index = 0;

    for (size_t i = 1; i < prices.size(); i++)
    {
        get_price = prices.at(i);
        if (get_price > high_price)
        {
            high_price = get_price;
            high_index = i;
        }
    }
    return high_index;
}

size_t lowPrice (vector <double> prices)
{
    double get_price = prices.at(0);
    double low_price = get_price;
    size_t low_index = 0;

    for (size_t i = 1; i < prices.size(); i++)
    {
        get_price = prices.at(i);
        if (get_price < low_price)
        {
            low_price = get_price;
            low_index = i;
        }
    }
    return low_index;
}
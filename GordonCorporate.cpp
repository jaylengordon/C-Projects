// GordonCorporate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Jaylen Gordon
//Programming Assignment #14
//GordonCorporate
//Short Program Description: Corporate sales
//June 28, 2020


#include <iostream>
using namespace std;
// declaring class
class DivSales
{
private:
    double quaterSales[4];
    static double totCorporateSales;
public:
    // Zero argumented constructor
    DivSales()
    {
    }
    // This function will read 4 quarter sales
    void readSales(double quat1, double quat2, double quat3, double quat4)
    {
        quaterSales[0] = quat1;
        quaterSales[1] = quat2;
        quaterSales[2] = quat3;
        quaterSales[3] = quat4;
        totCorporateSales += (quat1 + quat2 + quat3 + quat4);
    }
    double getQuarterlySales(int quarter)
    {
        return quaterSales[quarter];
    }
    double getTotalYearlySales()
    {
        return totCorporateSales;
    }
};
double DivSales::totCorporateSales;

int getValidSales();
int main()
{
    // declare variables

    int size = 6;
    double quat1, quat2, quat3, quat4;

    // instances

    DivSales d[6], d1;

    // get values from user input

    for (int x = 0; x < size; x++)
    {
        cout << "Division#" << x + 1 << ":" << endl;
        cout << "Enter sales of Quarter#1:$";
        quat1 = getValidSales();
        cout << "Enter sales of Quarter#2:$";
        quat2 = getValidSales();
        cout << "Enter sales of Quarter#3:$";
        quat3 = getValidSales();
        cout << "Enter sales of Quarter#4:$";
        quat4 = getValidSales();
        d[x].readSales(quat1, quat2, quat3, quat4);
    }
    cout << endl;

    // Displaying the output

    cout << "\t\tQ#1\tQ#2\tQ#3\tQ#4" << endl;
    for (int x = 0; x < size; x++)
    {
        cout << "Division#" << x + 1 << "\t";
        for (int y = 0; y < 4; y++)
        {
            cout << d[x].getQuarterlySales(y) << "\t";
        }
        cout << endl;
    }
    cout << "Total yearly Sales :$" << d1.getTotalYearlySales();

    return 0;
}

int getValidSales()
{
    int sales;
    while (true)
    {
        cin >> sales;
        if (sales < 0)
        {
            cout << "** Invalid. Must be (greater than) > 0 **" << endl;
            cout << "Re-Enter :";
        }
        else
        {
            break;
        }
    }
    return sales;
}



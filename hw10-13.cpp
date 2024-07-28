//HW10-13.cpp - displays two monthly car payments
//Revised by Andrew Drake on 07/28/2024

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
void getPayment(int prin, double monthRate, int months, double &payment);

int main()
{
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;

    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    //display payments
    cout << fixed << setprecision(2) << endl;
    getPayment(carPrice - rebate, creditRate / 12, term *12, creditPayment);
    cout << "Credit union payment: $" << creditPayment << endl;
    getPayment(carPrice, dealerRate / 12, term * 12, dealerPayment);
    cout << "Dealer payment: $" << dealerPayment << endl;

    return 0;
}//end of main function 

//*****function definitions*****
void getPayment(int prin, double monthRate, int months, double &payment)
{
    payment = prin * monthRate / (1-pow(monthRate + 1, -months)); 
} //end of getPayment function

//hw9-19.cpp - displays two monthly car payments
//Revised by Andrew Drake on 07/27/2024

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
double getPayment(int, double, int);
//additional function prototype
double getTotal(double, int);

int main()
{
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;
    double totalCredit = 0.0;
    double totalDealer = 0.0;

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

    //call function to calculate payments
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, term *12);
    dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);

    //call function to calculate total payments
    totalCredit = getTotal(creditPayment, term * 12);
    totalDealer = getTotal(dealerPayment, term * 12); 

    //display payments
    cout << fixed << setprecision(2) << endl;
    cout << "Credit union payment: $" << creditPayment << endl;
    cout << "Credit union total: $" << totalCredit << endl;
    cout << "Dealer payment: $" << dealerPayment << endl;
    cout << "Dealer total: $" << totalDealer << endl;

    return 0;
}//end of main function 

//*****function definitions*****
double getPayment(int prin, double monthRate, int months)
{
    double monthPay = 0.0;
    double roundedPay = 0.0;
    
    if (months == 0)
        monthPay = -1;
    else
        //calculate and returns a monthly payment
        //double monthPay = 0.0;
         monthPay = prin * monthRate / (1-pow(monthRate + 1, -months));
         
    //end if
    
    roundedPay = static_cast<int>((monthPay + .005) * 100) / 100.0;
    return roundedPay;
} //end of getPayment function


//****additional function definition*****
double getTotal(double monthRate, int months)
{
    //calculates and returns cumulative payment total
    double total = 0.00;
    total = monthRate * months;
    return total;
 }//end of getTotal function


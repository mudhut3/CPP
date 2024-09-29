/*Cisc 1610: Computer Science I
Lab 2: Coffee Shop

Coffee shop program that takes users order and prints their receipt
must input strictly numbers for amounts, and the correct payment amount > the total

Harrison Groves
Last editied Jan 30, 2024
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    string name;
    //variables for menu items, setting their price.
    double coffee = 2.50;
    double bagel = 1.75;
    double donut = 1.00;
    //variables to store amount of item user inputs
    int cofAmount;
    int bagAmount;
    int donAmount;
    //payment of customer, needs change
    double payment;
    //io statements to interact with user for ordering
    cout << "Hello!\nWelcome to our our coffee shop. Whats's your name? ";
    cin >> name;
    cout << "Welcome " << name << ',' << endl << "How many coffees would you like? ";
    cin >> cofAmount;
    cout << "How many bagels? ";
    cin >> bagAmount;
    cout << "How many donuts? ";
    cin >> donAmount;
     //what customer needs to pay
    double total = ((cofAmount * coffee) + (bagAmount * bagel) + (donAmount * donut)) * 1.085;
    cout << "Your total is $"<< total << ',' << endl << "What amount will you pay with? ";
    cin >> payment;
     //change$$$ for the user by subtracting the bill given from the total
    double receipt = payment - total;
    //output statement to print users receipt
    cout << "Receipt for customer " << name << endl;
    cout << "Coffees: " << cofAmount << endl;
    cout << "Bagels: " << bagAmount << endl;
    cout << "Donuts: " << donAmount << endl;
    cout << "Your change is: $" << receipt << endl;
    cout << "Thank You!";
    return 0;
}
/*Cisc 1610: Computer Science I
Lab 3: FordhamAir

Program that takes user input for where they would like to travel and sells them tickets

Harrison Groves
Last editied Feb 13, 2024
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
//for decimal presicion
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
//variables
    char destination;
    int flightTime;
    bool isDayflight;
    bool isWeekend;
    int numTix;
    char weekendOrWeekday;
    float totalCost;
    float userPayment;
    float changeReturn;
    float ticketPrice;
//interacting w user i/o statements
    cout << "Welcome to Fordham Airlines! ";
    cout << "What is your destination? ([C]hicago, [M]iami, [P]ortland): ";
    cin >> destination; 
    cout << "What time will you travel? (enter time between 0-2359): ";
    cin >> flightTime; 
    cout << "What type of day are you traveling? (week[E]nd or week[D]ay): ";
    cin >> weekendOrWeekday;
//if statement for day or night flight
    if (flightTime < 1900 && flightTime >= 500 ) 
        isDayflight = true;
    
    else 
        isDayflight = false;
    
//if isWeekend?
    if (weekendOrWeekday == 'E') {
        isWeekend = true;  
    }
    else if (weekendOrWeekday =='D') {
        isWeekend = false;
    }
    else {
    cout << "enter valid letter \n";
    }
//calculates total for user to pay
// miami weekday day flight
    if ((destination == 'M') && isDayflight && !isWeekend ) {
        ticketPrice = 150;
    }
// chicago weekday day flight
    else if (destination == 'C' && isDayflight && !isWeekend) {
        ticketPrice = 75;
    }
// portland weekday day flight
    else if (destination == 'P' && isDayflight && !isWeekend ) {
        ticketPrice = 300;
    }
// miami weekday night flight
    else if (destination == 'M' && !isDayflight && !isWeekend) {
        ticketPrice = 100;
    }
// Chicago weekday night flight
    else if (destination == 'C' && !isDayflight && !isWeekend) {
        ticketPrice = 50;
    }
// portland weekday night flight
    else if (destination ==  'P' && !isDayflight && !isWeekend) {
        ticketPrice = 200;
    }
// miami weekEnd day flight
    else if (destination ==  'M' && isDayflight && isWeekend) {
        ticketPrice = 180;
    }
// chicago weekEnd day flight
    else if (destination == 'C'  && isDayflight && isWeekend ) {
        ticketPrice = 90;
    }
// portland weekEnd day flight
    else if (destination ==  'P' && isDayflight && isWeekend) {
        ticketPrice = 360;
    }
// miami weekEnd night flight
    else if (destination ==  'M' && !isDayflight && isWeekend) {
        ticketPrice = 120;
    }
// chicago weekEnd night flight
    else if (destination == 'C'  && !isDayflight && isWeekend) {
        ticketPrice = 60;
    }
// portland weekEnd night flight
    else if (destination == 'P' && !isDayflight && isWeekend) {
        ticketPrice = 240;
    }
    else {
        cout << "error";
    }

    cout << "Each ticket costs $" << ticketPrice << "\n How many Tickets do you want? ";
    cin >> numTix;

    totalCost = numTix * ticketPrice;

    cout << "You owe: $" << totalCost << endl;

    cout << "Amount you're paying with?: ";
    cin >> userPayment;

    if (userPayment < totalCost) {
        cout << "That is too little! No tickets ordered.";
    }
    else if (userPayment >= totalCost) {
       changeReturn = userPayment - totalCost;
       cout << "You will get $" << changeReturn << " in change \n Your tickets have been ordered!";
    }
    else {
        cout << "error";
    }
    
    return 0;
}
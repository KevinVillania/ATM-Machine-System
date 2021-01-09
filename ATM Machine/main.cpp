/*===========================================================================
ATM BANKING SYSTEM
created by: Kevin Villania
written in C++, standard banking interface and features
such as withdrawal, deposit and balance inquiry.

Key features: offline database using fstream library, do-while loop,
password/pin verification.

TO-DO: Withdraw, deposit advance database feature rewrites thru ofstream
PROBLEM, How to do hash mapping
implement map pair or database. Include password hidden (****) feature
==============================================================================*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//function prototype
int printDetails();
double readDatabase();
int anotherTransaction();


int main(){

    system("Color 3F");
    int pin, command, attempt=0, password=123; //default password 123
    double accountBal;
    bool isTrue = true;

    cout << "====== K E V I N ' S  B A N K =======\n";
    cout << "Please enter card\n\n";

    accountBal = readDatabase();
    //loads amount into accountBal

    //Do while loop to check password input and attempt counter
    do{

        cout << "\nEnter pin: ";
        cin >> pin;

        if(pin == password){
            //atm body
            while(command != 4){

                command = printDetails();

                switch(command){
                    int withdraw;
                    int deposit;

                    case 1: //Withdraw

                        cout << "\n             WITHDRAW\n";
                        cout << "\nEnter amount: ";
                        cin >> withdraw;

                            if(accountBal > withdraw){

                                accountBal = accountBal - withdraw;
                                cout << "Please get your money\n\n";
                            }else{

                                cout << "INVALID AMOUNT\n\n";
                            }

                        command = anotherTransaction();
                        break;

                    case 2: //Deposit

                        cout << "\nDEPOSIT\n";
                        cout << "\nEnter amount: ";
                        cin >> deposit;
                        accountBal = accountBal + deposit;

                        command = anotherTransaction();
                        break;

                    case 3://Balance Inquiry

                        cout << "\nExisting Balance = PHP " << accountBal << endl;
                        command = anotherTransaction();
                        break;

                }
            }
            isTrue = false;
        }else{
            attempt++;
            /*increases pin attempt up to 3 chances
            if attempt equals 3, program exits
            */
            if(attempt == 3){
                cout << "Max attempt, card captured!";
                isTrue = false; //changes bool condition to false, program exits
            }else{
                cout << "\nWRONG PIN\n";
            }

        }
    }while(isTrue != false);
}

//prints services function
int printDetails(){

    int select;

    cout << endl;
    cout << "       1   WITHDRAW" << endl;
    cout << "       2   DEPOSIT" << endl;
    cout << "       3   BALANCE INQUIRY" << endl;
    cout << "       4   QUIT PROGRAM" << endl;

    cout << "       Press selection ";
    cin >> select;
    cout << "=======================================";
    return select;
}

//reads BDO database text file
double readDatabase(){

    double accountBalance;
    vector<double> balance;

    //reads and open BDO database text file
    ifstream file("BDO Database.txt");

    if(file.is_open()){
        while(!file.eof()){
        //eof - end of file
        file >> accountBalance;
        balance.push_back(accountBalance);
        }
    }else{
        cout << "Error file not open";
    }
    return balance[0];
}

//repeat transaction function
int anotherTransaction(){

    char YesNo;
    cout << "Do you want another transaction? Y/N\n";
    cin >> YesNo;

        if(YesNo == 'Y' || YesNo == 'y'){
            return 0;
        }else{

            cout << endl << "Please get your card" << endl;
            return 4;
        }
}





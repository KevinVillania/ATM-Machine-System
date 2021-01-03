/*=======================================================
ATM BANKING SYSTEM
created by: Kevin Villania
written in C++, standard banking interface and features
such as withdrawal, deposit and balance inquiry.

Key features: offline database using fstream library, do-while loop,
password/pin verification.

TO-DO: FINISH BASIC FUNCTIONALITIES, DEPOSIT AND BAL INQ
SETUP DATABASE AND READOUT


===========================================================*/
#include <iostream>
#include <fstream>
using namespace std;

int printDetails();
void readDatabase();
int anotherTransaction();


int main(){

    system("Color 3F");
    int pin, command;
    int password = 123;
    int attempt = 0;
    bool isTrue = true;

    cout << "====== K E V I N ' S  B A N K =======\n";

    //Do while loop to check password input and attempt counter
    do{

        cout << "Enter pin\n";
        cin >> pin;

        if(pin == password){
            //atm body
            //command = printDetails();
            while(command != 4){

                command = printDetails();

                switch(command){

                    char YesNo;
                    int withdraw;

                    case 1: //Withdraw

                        cout << "Enter amount" << endl;
                        cin >> withdraw;
                        //accountBalance = accountBalance - withdraw;

                        command = anotherTransaction();
                        break;

                    case 2: //Deposit
                        break;
                    case 3://Balance Inquiry
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
                cout << "Max attempt\n";
                isTrue = false; //changes bool condition to false, program exits
            }else{
                cout << "Wrong pin\n";
            }

        }
    }while(isTrue != false);
}

//prints services function
int printDetails(){

    int serviceSelect;

    cout << "1. Withdraw" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Balance Inquiry" << endl;
    cout << "4. Quit program" << endl;

    cout << "Press selection" << endl;
    cin >> serviceSelect;
    return serviceSelect;
}

//reads 'Prototype' database
void readDatabase(){

    string accountName;
    int password;
    double accountBalance;
    ifstream objectFile("BDO Database.txt");

}

//repeat transaction function
int anotherTransaction(){

    char YesNo;
    cout << "Do you want another transaction? Y/N\n";
    cin >> YesNo;

        if(YesNo == 'Y'){
            return 0;
        }else{
            return 4;
        }
}

/*
Name: Pascal Triangle Calculator
Written by: Ivan Chavez.
Date: 2020-08-09
Version: TBD
  Description: This program has been writen in C++ for practice pourposes, and this program calculates the pascal triangle pattern and saves it on a csv file.

*/

#include <iostream>
#include <istream>
#include <regex>
#include <string>
#include <cstdlib>

const int max_Cap = 1000; // This variable defines the maximum power able to calculate.
unsigned long long int pascal_Triangle[max_Cap][max_Cap]; // Defines the array where the pascal triangle is going to be saved.

// Defining functions
int check_Power(std::string power_String); // Checks using Regex if the power indexed is a valid input.
int create_Triangle(int power); // Though an algorithm creates the pascal triangle and saves it in the array.
void create_Logs(); // Creates the logs of the program by text.
void check_Value(); // For internal testing pourposes.

using namespace std;

int main(){

    // Defining main function variables
    string power_String;
    bool match;
    int power;

    // Asks tot he user to input the power to be calculated
    cout << "Please Index up to the power number you want to calculate: ";
    cin >> power_String; // Reads the power indexed by the user and saves it as string.
    power = check_Power(power_String); // Calls to a custom function to verify the value indexed and saves it on power integer variable.
    
    // Calls creating Pascal triangle function algorithm
    cout << "\nCreating Triangle... " << endl;
    create_Triangle(power);
    //create_Logs();

    return 0;

}
 

 /*
 This function recieves the power indexed by the user as string and it validates it using regex.
 */
int check_Power(string power_String){

    // Valid_Powwer, its a variable wich allows 
    bool valid_Power = false;

    while(valid_Power == false){
        // Condition wich means if it's a number...
        if( regex_match(power_String, regex("^[0-9]{1,}") )){ 
                int power = stoi(power_String);
                // If it's a number then check if it's not 0 or greater than max cap pre-defined, fits both conditions then it sets the valid power flags true and function returns the power.
                if ( ( power <= max_Cap) && (power != 0) ){
                    cout << "Power String: "<< power_String <<"\nPower indexed is rignt processing..." << endl;
                    valid_Power = true;
                    return power;
                }
                // In case don't fit any of both conditions of max cap or zero, then check each case and displays a error message.
                else{
                    if(power > max_Cap){
                    cout << "The power Indexed is greater than max capacity allowed: \a" << max_Cap << endl;
                    }
                    if(power == 0){
                    cout << "If the power is equal to 0 the result is 1: \a" << endl;
                    }
                }
        }
        // If is not a number sends a message and asks to index again.
        else{
            cout << "The power Indexed is not a number \a" << endl;
        }
        cout << "\nPlease index the power again: ";
        cin >> power_String;
    }

    // According to the workflow defined using the while statement in this function will no return 0.
    return 0;
}
 /*
 This function contains the algorithm which creates the pascal triangle and saves it on pascal_Triangle[][] array.
 */
int create_Triangle(int power){
    
    /*
    Pre-defines the first values of the pascal triangle. 
    Power | Values
        0 | 1
        1 | 1 1
        2 | 1 2 1
    */
    pascal_Triangle[0][0] = 1;
    pascal_Triangle[0][1] = 1;
    pascal_Triangle[1][1] = 1;
    pascal_Triangle[0][2] = 1;
    pascal_Triangle[1][2] = 2;
    pascal_Triangle[2][2] = 1;
    
    // In case the power indexed it's equal or greater than 3 it runs the algorithm to calculate the values of each power.
    if(power >= 3){

        // This for which contains the "y" variable this sweeps between power levels 'y'
        for( int y = 3 ; y <= power ; y++ ){

            /*
            This sets one's to the first and last value wich means matematically in a binomium both terms will be elevated to the power defined without any other variable multippling it, i.e:
            (A + B)^n = A^n + ... + B^n
            */ 
            pascal_Triangle[0][y] = 1;
            pascal_Triangle[y][y] = 1;

            // Just a print to identify each 'y' increment.
            cout << "\n*** y = " << y ;

            // This for which contains the "x" variable changes between values of the same power 'x' axis.
            for( int x = 0 ; x <= y ; x++ ){

                // Console output just to identify each time x value changes. 
                cout << "\n  x = " << x  << endl;
                
                // This if checks if the actual value or the value to calculate isn't equal to zero, if true then it's a value/spot wich need to be calculated.
                if( pascal_Triangle[x][y] != 1){
                    
                    // The spot/value to be calculated is equal to the same spot in x but lowered -1 in 'Y' plus the value minus 1 in x and y axis. 
                    pascal_Triangle[x][y] = pascal_Triangle[x][y-1] + pascal_Triangle[x-1][y-1];

                    // Prints out the same value calculared.
                    cout << pascal_Triangle[x][y-1] << "+"<<  pascal_Triangle[x-1][y-1] << "=" << pascal_Triangle[x][y];
                }

                // Prints position and value in each x iteration.
                cout << "\n Position [" << x << "][" << y <<"] = " << pascal_Triangle[x][y] << endl;
                
            }
        }
        
    }

    // Calls a void function wich allows to check any spot/value indexing 'X' and 'Y' positions. 
    check_Value();

    return 0;

}

/* 
This functions creates logs of the program and creates the Pascal Triangle in a text file.
*/
void create_Logs(){
    // To Be Developed.
}

/*
Function who checks any spot/value as long the user index 'x' & 'y' coordinates
*/
void check_Value(){

    char answer;

    cout << "\n\aDo you want to check any position? Y/N ";
    cin >> answer;

    while (answer == 'Y' || answer == 'y'){

        int x_Position, y_Position;

        // Reads coordianates to check
        cout << "\nIndex position X to check: " ;
        cin >> x_Position;
        cout << "\nIndex position Y to check: " ;
        cin >> y_Position;

        // Prints out the position requested and asks if the user wants to check any other position. 
        cout << "\n Position [" << x_Position << "][" << y_Position <<"] = " << pascal_Triangle[x_Position][y_Position] << endl;
        cout << "Do you want to check any other position? Y/N ";
        cin >> answer;
    }
}

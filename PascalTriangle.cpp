/*
Name: Pascal Triangle Calculator
Written by: Ivan Chavez.
Date: 2020-08-09
Version: TBD
  Description: This program has been writen in C++ for practice pourposes, and this program calculates the pascal triangle pattern and saves it on a csv file.

*/

//Space added to check changes in first-new commit

#include <iostream>
#include <istream>
#include <regex>
#include <string>
#include <cstdlib>

const int max_Cap = 1000;
unsigned long long int pascal_Triangle[max_Cap][max_Cap];

int check_Power(std::string power_String);
int create_Triangle(int power);
void create_Logs();
void check_Value();

using namespace std;

int main(){

    string power_String;
    bool match;
    int power;

    cout << "Please Index up to the power number you want to calculate: ";
    cin >> power_String;
    cout << "Power in string Indexed is \"" << power_String <<"\"" << endl;
    power = check_Power(power_String);
    cout << "Power validated is " << power << endl;
    
    cout << "\nCreating Triangle... " << endl;
    create_Triangle(power);
    //create_Logs();

    return 0;

}
 
int check_Power(string power_String){

    bool valid_Power = false;

    while(valid_Power == false){
        if( regex_match(power_String, regex("^[0-9]{1,}") )){
                int power = stoi(power_String);
                if ( ( power <= max_Cap) && (power != 0) ){
                    cout << "Power String: "<< power_String <<"\nPower indexed is rignt processing..." << endl;
                    valid_Power = true;
                    return power;
                }
                else{
                    if(power > max_Cap){
                    cout << "The power Indexed is greater than max capacity allowed: \a" << max_Cap << endl;
                    }
                    if(power == 0){
                    cout << "If the power is equal to 0 the result is 1: \a" << endl;
                    }
                }
        }
        else{
            cout << "The power Indexed is not a number \a" << endl;
        }
        cout << "\nPlease index the power again: ";
        cin >> power_String;
    }

    return 0;
}

int create_Triangle(int power){
    
    pascal_Triangle[0][0] = 1;
    pascal_Triangle[0][1] = 1;
    pascal_Triangle[1][1] = 1;
    pascal_Triangle[0][2] = 1;
    pascal_Triangle[1][2] = 2;
    pascal_Triangle[2][2] = 1;
    

    if(power > 3){

        for( int y = 3 ; y <= power ; y++ ){
            pascal_Triangle[0][y] = 1;
            pascal_Triangle[y][y] = 1;

            cout << "\n*** y = " << y ;
            //cout << "\n power = " << power ;

            for( int x = 0 ; x <= y ; x++ ){
                cout << "\n  x = " << x  << endl;
                
                if( pascal_Triangle[x][y] != 1){

                    pascal_Triangle[x][y] = pascal_Triangle[x][y-1] + pascal_Triangle[x-1][y-1];

                    cout << pascal_Triangle[x][y-1] << "+"<<  pascal_Triangle[x-1][y-1] << "=" << pascal_Triangle[x][y];
                }
                cout << "\n Position [" << x << "][" << y <<"] = " << pascal_Triangle[x][y] << endl;
                
            }
        }
        
    }

    check_Value();

    return 0;

}

void create_Logs(){

}

void check_Value(){

    char answer;

    cout << "\n\aDo you want to check any position? Y/N ";
    cin >> answer;

    while (answer == 'Y' || answer == 'y'){

        int x_Position, y_Position;

        cout << "\nIndex position X to check: " ;
        cin >> x_Position;
        cout << "\nIndex position Y to check: " ;
        cin >> y_Position;

        cout << "\n Position [" << x_Position << "][" << y_Position <<"] = " << pascal_Triangle[x_Position][y_Position] << endl;
        cout << "Do you want to check any other position? Y/N ";
        cin >> answer;
    }
}

/*
File:          app.cpp
Author:        Dominic Rando
Course:        CSC402
Professor:     **********
Assignment:    **********
Purpose:       Reads a file titled 'spacex_launch_data.csv' and creates a vector of Launch objects
               Allows user to print data from, and manipulate, the vector
Creation Date: April 13, 2021
Due Date:      May 11, 2021
*/

/*!
*    \file app.cpp
*    \brief Reads a file 'sp.csv' stores in the data in Launch objects
*
*    This application will read the file and create a vector of Launch ovject with that data.
*    The user can print the data in various ways, and can manipulate the vector 
*    to specify certain launch objects. User can also recreate the vector by reading the file again.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Date.h"
#include "Time.h"
#include "Launch.h"

using namespace std;

/*!
*    \param filename The name of the file being read
*    \param launchVec The vector of Launch objects
*    \brief Creates the vector of Launch object based off the data in the filename
*
*    This function will open a file to read formatted excel sheet into a vector of Launch objects
*/
void readFile(string filename, vector<Launch> &launchVec);

/*!
*    \param str The string that will be capitalized
*    \brief Takes a string and returns it with every char being uppercased
*
*    Will go through the string by char and capitalize that char. Returns the new string
*/
string stringToUpper(string str);

/*!
*    \param check A string will the only valid options the user can choose
*    \brief Returns a char for the user's choice in the menu
*
*    This will keep aksing the user for a char until it matches one in check
*/
char getChoice(string check);

/*!
*    \param LaunchVec The vector of Launch objects
*    \param its A vector of iterators
*    \brief Will remove the elements in the vector based off the interators
*
*    Will go through each iterator in its in reverse order to preserve the iterators correct position.
*    It will use the vector.erase() function to delete that Launch object
*/
void removeElts(vector<Launch> &launchVec, vector<vector<Launch>::iterator> its);

/*!
*    \param launchVec The vector of Launch objects
*    \param mode A boolean that tells program if its in manipulation mode
*    \brief Will show the basic print and search functions for the application
*
*    Allows the user to print, search through multiple data members, recreate the vector,
*    swap modes, or quit the application
*/
void showMenu(vector<Launch> launchVec, bool mode);

/*!
*    \param launchVec The vector of Launch Objects
*    \brief Interactive menu or printing the Launch Objects
*
*    User can print every Launch in the vector, or print by the order numbers of the Launches
*/
void printMenu(vector<Launch> launchVec);

/*!
*    \param launchVec The vector of Launch Objects
*    \brief Will print all Launch objects in the vector
*
*    Prints every Launch object in the vector
*/
void printAll(vector<Launch> launchVec);

/*!
*    \param launchVec The vector of Launch Objects
*    \brief Prints Launch objects by order number given a range 
*
*    Asks the user for two integers and prints the Launch objects between that range
*/
void printRange(vector<Launch> launchVec);

/*!
*    \param launchVec The vector of Launch objects
*    \param mode A boolean that tells program if its in manipulation mode
*    \brief Displays the menu for searching by customer
*
*    User can search by the exact customer, or by matching a word
*/
void customerSearch(vector<Launch> &launchVec, bool mode);

/*!
*    \param launchVec The vector of Launch objects
*    \param mode A boolean that tells program if its in manipulation mode
*    \brief Will print a Launch object if the user's input customer is an exact match
*
*    Asks the user for a customer name, loops through vector and if it finds a match, 
*    it will print that object.
*    If mode is true, then any object not printed will be deleted from the vector
*/
void customerExact(vector<Launch> &launchVec, bool mode);

/*!
*    \param launchVec The vector of Launch objects
*    \param mode A boolean that tells program if its in manipulation mode
*    \brief Will print a Launch object if the user's input customer is somewhere in the Launch's customer value
*
*    Asks the user for a customer name, loops through vector and if it finds a match, 
*    it will print that object.
*    If mode is true, then any object not printed will be deleted from the vector
*/
void customerMatch(vector<Launch> &launchVec, bool mode);

/*!
*    \param launchVec The vector of Launch objects
*    \param mode A boolean that tells program if its in manipulation mode
*    \brief Displays the menu for searching by orbit
*
*    User can search by the exact orbit, or by matching a word
*/
void orbitSearch(vector<Launch> &launchVec, bool mode);

/*!
*    \param launchVec The vector of Launch objects
*    \param mode A boolean that tells program if its in manipulation mode
*    \brief Will print a Launch object if the user's input orbit is an exact match
*
*    Asks the user for a orbit name, loops through vector and if it finds a match, 
*    it will print that object.
*    If mode is true, then any object not printed will be deleted from the vector
*/
void orbitExact(vector<Launch> &launchVec, bool mode);

/*!
*    \param launchVec The vector of Launch objects
*    \param mode A boolean that tells program if its in manipulation mode
*    \brief Will print a Launch object if the user's input orbit is somewhere in the Launch's orbit value
*
*    Asks the user for a orbit name, loops through vector and if it finds a match, 
*    it will print that object.
*    If mode is true, then any object not printed will be deleted from the vector
*/
void orbitMatch(vector<Launch> &launchVec, bool mode);

/*!
*    \brief Asks user for a date and returns it
*
*    Asks the user for a Date in (mm dd yy) format. Returns it as a Date object
*/
Date askDate();

/*!
*    \param launchVec The vector of Launch objects
*    \param mode A boolean that tells program if its in manipulation mode
*    \brief Displays the menu for searching by date
*
*    User can search by the exact date, or by a range
*/
void dateSearch(vector<Launch> &launchVec, bool mode);

/*!
*    \param launchVec The vector of Launch objects
*    \param mode A boolean that tells program if its in manipulation mode
*    \brief Prints a Launch object if the date is an exact match
*
*    Asks the user for a date and loops through vector comparing it to each Launch object.
*    If it finds a match, it will print out that Launch object.
*    If mode is true, any object not printed will be deleted from the vector.
*/
void dateExact(vector<Launch> &launchVec, bool mode);

/*!
*    \param launchVec The vector of Launch objects
*    \param mode A boolean that tells program if its in manipulation mode
*    \brief Prints a launch object if it is within a given date range
*
*    Asks the user for two dates and loops through vector comparing it to each Launch object.
*    If date is within the range, that Launch object will be printed.
*    If mode is true, any object not printed will be deleted from the vector.
*/
void dateRange(vector<Launch> &launchVec, bool mode);

/*!
*    \param launchVec The vector of Launch objects
*    \param SortType A character that says the order the vector is in
*    \brief Will reorder the Launch vector
*
*    Displays an interactive menu for the user to choose how they will reorder the data.
*    For efficiency, will not reorder if it is already in that order type.
*    Makes use of std::sort and Launch functors.
*/
void reorder(vector<Launch> &launchVec, char SortType);

int main(int argc,char *argv[]){
  string filename;
  ifstream file;
  bool mode = 0;

  vector<Launch> launchVec;
  readFile("spacex_launch_data.csv", launchVec); 
  showMenu(launchVec, mode);
 
  return 0;
}  

void readFile(string filename, vector<Launch> &launchVec){
  // removes elements from vector
  launchVec.clear();
  
  ifstream file(filename.c_str());
  string line;
  
  Launch object;
  
  while(getline(file,line)){
    istringstream iss(line);
    iss >> object;
    launchVec.push_back(object);
  }  
}

string stringToUpper(string str){
  // for every char in string, make it uppercase
  for(int i = 0; i < str.length(); i++){
    str[i] = toupper(str[i]);
  }
  return str;
}

char getChoice(string check){
  string line;
  char ch=' '; // user input
  do{
    ch=toupper(cin.get());
  } 
  // check if input is a valid option
  while (check.find(ch)==string::npos);
  
  cin.get();
  return(toupper(ch));
}

void removeElts(vector<Launch> &launchVec, vector<vector<Launch>::iterator> its){
  // Goes in reverse order to remove elts
  vector<Launch>::iterator it;
  for(int i = its.size()-1; i >= 0; i--){
    it = its[i];
    launchVec.erase(it);
  }
}

void showMenu(vector<Launch> launchVec, bool mode){
  // SortType means vector will not reorder for the same results
  char choice, SortType = ' ';
  do
  {
    if(mode)
      cout<<"\n[MANIPULATION MODE]"<<endl;
    else
      cout<<"\n[  PRINTING MODE  ]"<<endl;
    cout<<"Choose an Option:"<<endl;
    cout<<"P)rint"<<endl;
    cout<<"C)ustomer Search"<<endl;
    cout<<"O)rbit Search"<<endl;
    cout<<"D)ate Search"<<endl;
    cout<<"R)eorder"<<endl;
    cout<<"S)wap mode"<<endl;
    cout<<"F)ile read"<<endl;
    cout<<"Q)uit"<<endl<<endl<<">";
  
    choice = getChoice("PCODRSFQ");
    switch(choice)
    {
      case 'P':
        printMenu(launchVec);
        break;
      case 'C':
        customerSearch(launchVec, mode);
        break;
      case 'O':
        orbitSearch(launchVec, mode);
        break;
      case 'D':
        dateSearch(launchVec, mode);
        break;
      case 'R':
        reorder(launchVec, SortType);
        break;
      case 'S':
        if (mode)
          mode = 0;
        else
          mode = 1;
        break;
      case 'F':
        readFile("spacex_launch_data.csv", launchVec);
        break;
    }
  }while(choice != 'Q');
}

void printMenu(vector<Launch> launchVec){
  char choice;
  do
  {
    cout<<"Choose an Option:"<<endl;
    cout<<"A)ll"<<endl;
    cout<<"R)ange (by flight number)"<<endl;
    cout<<"G)o Back"<<endl<<endl<<">";
  
    choice = getChoice("ARG");
    switch(choice)
    {
      case 'A':
        printAll(launchVec);
        break;
      case 'R':
        printRange(launchVec);
        break;
    }
  }while(choice != 'G');
}

void printAll(vector<Launch> launchVec){
  cout << "\n";
  bool fail = true;
  
  // Iterate through all elts of vector
  for(int i = 0; i < launchVec.size(); i++){
    fail = false;
    cout << launchVec[i] << endl;
  }
  if (fail)
    cout << "Nothing to print" << endl;
}

void printRange(vector<Launch> launchVec){
  int start, end;
  bool fail = true;
  
  cout << "Enter the starting number" << endl << ">";
  cin >> start;
  cout << "Enter the ending number" << endl << ">";
  cin >> end;
  cout << "\n";
  
  if(start <= 0){
    cout << "Enter a number greater than 0" << endl << endl;
    return;
  }
  for(int i = 0; i < launchVec.size(); i++){
    if (start <= launchVec[i].getOrder() && launchVec[i].getOrder() <= end){
      fail = false;
      cout << launchVec[i] << endl;
    }
  }
  
  if(fail)
    cout << "Nothing to print" << endl;
}

void customerSearch(vector<Launch> &launchVec, bool mode){
  char choice;
  do
  {
    cout<<"Choose an option:"<<endl;
    cout<<"E)xact Search"<<endl;
    cout<<"M)atch Search"<<endl;
    cout<<"G)o Back"<<endl<<endl<<">";
    choice = getChoice("EMG");
    switch(choice)
    {
      case 'E':
        customerExact(launchVec, mode);
        break;
      case 'M':
      customerMatch(launchVec, mode);
        break;
    }
  }while(choice !='G');   
}

void customerExact(vector<Launch> &launchVec, bool mode){
  bool fail = true;
  string customerIn;
  cout<<"Enter name of customer to search for"<<endl<<">";
  getline(cin,customerIn);
  customerIn = stringToUpper(customerIn);
  vector<Launch>::iterator it;
  
  // vector of iterators, used to erase all non-found elements
  vector<vector<Launch>::iterator> its;
  for(it = launchVec.begin(); it != launchVec.end(); it++){
    Launch test = *it;
    if(test.getCustomer() == customerIn){
      fail = false;
      cout << *it << endl;
    }
    else if (mode){
      its.push_back(it);}
  }
  removeElts(launchVec, its);
  if(fail && mode)
    cout << "Nothing to print and vector has no elements" << endl;
  else if (fail)
    cout << "Nothing to print" << endl;
}

void customerMatch(vector<Launch> &launchVec, bool mode){
  bool fail = true;
  string customerIn;
  cout<<"Enter name of customer to search for"<<endl<<">";
  getline(cin,customerIn);
  customerIn = stringToUpper(customerIn);
  vector<Launch>::iterator it;
  vector<vector<Launch>::iterator> its;
  
  // Go through each Launch
  for(it = launchVec.begin(); it != launchVec.end(); it++){
    Launch curr = *it;
    string customer = curr.getCustomer();
    bool print = false;
    // Go through chars of launch.customer
    for(int j = 0; j < customer.size(); j++){
      if (customer[j] == customerIn[0] && !print) {
        print = true;
        // Compare with chars in customerIn
        for(int x = 0; x < customerIn.size(); x++){
          if (customer[j+x]!=customerIn[x]){
            print = false;}
        }
      }  
    }
    if (print){ 
      fail = false;
      cout << *it << endl;
    }
    else if (mode)
      its.push_back(it);
  }
  removeElts(launchVec, its);
  if(fail && mode)
    cout << "Nothing to print and vector has no elements" << endl;
  else if (fail)
    cout << "Nothing to print" << endl;
}

void orbitSearch(vector<Launch> &launchVec, bool mode){
  char choice;
  do
  {
    cout<<"Choose an option:"<<endl;
    cout<<"E)xact Search"<<endl;
    cout<<"M)atch Search"<<endl;
    cout<<"G)o Back"<<endl<<endl<<">";
    choice = getChoice("EMG");
    switch(choice)
    {
      case 'E':
        orbitExact(launchVec, mode);
        break;
      case 'M':
        orbitMatch(launchVec, mode);
        break;
    }
  }while(choice !='G');
}

void orbitExact(vector<Launch> &launchVec, bool mode){
  // All leo (iss) orbits have the same customer, NASA
  bool fail = true;
  string orbitIn;
  cout<<"Enter name of orbit to search for"<<endl<<">";
  getline(cin,orbitIn);
  orbitIn = stringToUpper(orbitIn);
  
  vector<Launch>::iterator it;
  vector<vector<Launch>::iterator> its;
  
  // iterate through vector
  for(it = launchVec.begin(); it != launchVec.end(); it++){
    Launch curr = *it;
    if(curr.getOrbit() == orbitIn){
      fail = false;
      cout << *it << endl;
    }
    else if (mode){
      its.push_back(it);}
  }
  
  removeElts(launchVec, its);
  if(fail && mode)
    cout << "Nothing to print and vector has no elements" << endl;
  else if (fail)
    cout << "Nothing to print" << endl;
  
}

// will check if input matches ANYWHERE in the orbit
// Ex) if you put in L, it will print any Launch with an L in the orbit
void orbitMatch(vector<Launch> &launchVec, bool mode){
  // 15 is only one without an 'o' in the orbit, it has "SUNAE EARTH L1"
  bool fail = true;
  string orbitIn;
  cout<<"Enter name of orbit to search for"<<endl<<">";
  getline(cin,orbitIn);
  orbitIn = stringToUpper(orbitIn);
  vector<Launch>::iterator it;
  vector<vector<Launch>::iterator> its;
  
  // Go through each Launch
  for(it = launchVec.begin(); it != launchVec.end(); it++){
    Launch curr = *it;
    string orbit = curr.getOrbit();
    bool print = false;
    // Go through chars of launch.customer
    for(int j = 0; j < orbit.size(); j++){
      if (orbit[j] == orbitIn[0] && !print) {
        print = true;
        // Compare with chars in customerIn
        for(int x = 0; x < orbitIn.size(); x++){
          fail = false;
          if (orbit[j+x]!=orbitIn[x]){
            print = false;}
        }
      }  
    }
    if (print) 
      cout << *it << endl;
    else if (mode)
      its.push_back(it);
  }
  removeElts(launchVec, its);
  if(fail && mode)
    cout << "Nothing to print and vector has no elements" << endl;
  else if (fail)
    cout << "Nothing to print" << endl;
}

Date askDate(){
  string dateIn;
  cout<<"Enter a date (MM DD YYYY)"<<endl<<">";
  getline(cin,dateIn);
  
  string mm, dd, yy;
  istringstream date_s(dateIn);
  getline(date_s, mm, ' ');
  int month = stoi(mm);
  getline(date_s, dd, ' ');
  int day = stoi(dd);
  getline(date_s, yy, '\n');
  int year = stoi(yy);
  Date d1(month, day, year);
  return d1;
}

void dateSearch(vector<Launch> &launchVec, bool mode){
  char choice;
  do
  {
    cout<<"Choose an option:"<<endl;
    cout<<"E)xact Search"<<endl;
    cout<<"R)ange Search"<<endl;
    cout<<"G)o Back"<<endl<<endl<<">";
    choice = getChoice("ERG");
    switch(choice)
    {
      case 'E':
        dateExact(launchVec, mode);
        break;
      case 'R':
        dateRange(launchVec, mode);
        break;
    }
  }while(choice !='G');
}

void dateExact(vector<Launch> &launchVec, bool mode){
  Date d1 = askDate();
  bool fail = true;
  vector<Launch>::iterator it;
  vector<vector<Launch>::iterator> its;
  
  // Iterate through vector
  for(it = launchVec.begin(); it != launchVec.end(); it++){
    Launch curr = *it;
    if(curr.getDate() == d1){
      fail = false;
      cout << *it << endl;
    }
    else
      its.push_back(it);
  }
  if(mode)
    removeElts(launchVec, its);
  if(fail && mode)
    cout << "Nothing to print and vector has no elements" << endl;
  else if (fail)
    cout << "Nothing to print" << endl;
}

void dateRange(vector<Launch> &launchVec, bool mode){
  Date d1 = askDate();
  Date d2 = askDate();
  bool fail = true;
  vector<Launch>::iterator it;
  vector<vector<Launch>::iterator> its;
  
  for(it = launchVec.begin(); it != launchVec.end(); it++){
    Launch curr = *it;
    if(d1 <= curr.getDate() && curr.getDate() <= d2){
      fail = false;
      cout << *it << endl;
    }
    else if (mode)
      its.push_back(it);
  }
  
  if(mode)
    removeElts(launchVec, its);
  if(fail && mode)
    cout << "Nothing to print and vector has no elements" << endl;
  else if (fail)
    cout << "Nothing to print" << endl;
}

void reorder(vector<Launch> &launchVec, char SortType){
  char choice;
  do
  {
    cout<<"Sort By:"<<endl;
    cout<<"D)ate"<<endl
        <<"T)ime"<<endl
        <<"M)ass"<<endl
        <<"S)ite"<<endl
        <<"G)o Back"<<endl<<endl<<">";
      
    choice=getChoice("DTMSCG");
    // check if already reordered this way 
    if(choice == SortType){
      return;                           
    }
    if(launchVec.size() == 0){
      cout << "Vector is empty" << endl;
      return;
    }
    
    // Uses the functors
    switch(choice)
    {
      case 'D':
        sort(launchVec.begin(), launchVec.end(), Launch::cmpDate());
        SortType = 'D';
        return;
      case 'T':
        sort(launchVec.begin(), launchVec.end(), Launch::cmpTime());
        SortType = 'T';
        return;
      case 'M':
        sort(launchVec.begin(), launchVec.end(), Launch::cmpMass());
        SortType = 'M';
        return;
      case 'S':
        sort(launchVec.begin(), launchVec.end(), Launch::cmpSite());
        SortType = 'S';
        return;
    }
  }while(choice != 'G');
  return;
}
 
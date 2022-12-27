/*
File:          Launch.cpp
Author:        Dominic Rando
Course:        CSC402
Professor:     **********
Assignment:    **********
Purpose:       Implementation file for the Launch class 
Creation Date: April 19, 2021
Due Date:      May 11, 2021
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>  
#include "Launch.h"
#include "Date.h"
#include "Time.h"

/*!
*    \file Launch.cpp
*    \brief Implementations for the Launch class functions found in Launch.h
*
*    \class Time
*    This class has a variety of data members that can be set by reading form a file
*/  

using namespace std;

/*!
  *    \fn stringUpper
  *    Takes in a string and returns it capitalized. Used to consistently store string names in data members
  */
// Used to capitalize input from file
string stringUpper(string str){
  for(int i = 0; i < str.length(); i++){
    str[i] = toupper(str[i]);
  }
  return str;
}

/*!
*    Default constructor that sets the data members to random values
*/
Launch::Launch(){
  Date d1(9,15,2001);
  Time t1(2,01,50);
  
  order = 0;
  launchDate = d1;
  launchTime = t1;
  
  site = "site";
  orbit = "orbit";
  customer = "customer";
  outcome = "outcome";
  mass = 0;
}

/*!
*    Function that returns the value for data member "order"
*/
int Launch::getOrder(){
  return (order);
}

/*!
*    Function that returns a Date object for data member "launchDate"
*/
Date Launch::getDate(){
  return (launchDate);
}

/*!
*    Function that returns a Time object for data member "launchTime"
*/
Time Launch::getTime(){
  return (launchTime);
}

/*!
*    Function that returns the value for data member "site"
*/
string Launch::getSite(){
  return (site);
}

/*!
*    Function that returns the value for data member "mass"
*/
int Launch::getMass(){
  return (mass);
}

/*!
*    Function that returns the value for data member "orbit"
*/
string Launch::getOrbit(){
  return (orbit);
}

/*!
*    Function that returns the value for data member "customer"
*/
string Launch::getCustomer(){
  return (customer);
}

/*!
*    Function that returns the value for data member "outcome"
*/
string Launch::getOutcome(){
  return(outcome);
}

/*!
*    Operator overload that takes a line from the stream and uses it to make a Launch object
*/
istream &operator>>(istream &Source,  Launch &l){
  string line;
  string temp;

  // Go through every line in file
  while(getline(Source,line)){
    istringstream iss(line);
    string flight, date, time, site, mass, orbit, customer, outcome;  
    string mm, dd, yy;
    string hr, min, sec;
    
    getline(iss, temp, ','); // flight number
    if (temp == "FH 1")
      l.order = 0;
    else
      l.order = stoi(temp);
    
    getline(iss, temp, ','); // date 
    istringstream date_s(temp);
    getline(date_s, mm, '/');
    int month = stoi(mm);
    getline(date_s, dd, '/');
    int day = stoi(dd);
    getline(date_s, yy, '/');
    int year = stoi(yy);
    Date d1(month,day,year);
    l.launchDate = d1;
    
    
    getline(iss, temp, ','); // time 
    istringstream time_s(temp);
    getline(time_s, hr, ':');
    int hour = stoi(hr);
    getline(time_s, min, ':');
    int minute = stoi(min);
    getline(time_s, sec, ':');
    int second = stoi(sec);
    Time t1(hour,minute,second);
    l.launchTime = t1;
    
    getline(iss, temp, ','); // booster
    getline(iss, site, ','); // launch site 
    l.site = stringUpper(site);
    
    getline(iss, temp, ','); // payload
    
    getline(iss, mass, ',');// payload mass 
    if (mass == "") {mass = "0";}
    if (mass == "Classified") {mass = "-1";}
    int massL = stoi(mass);
    l.mass = massL;
    
    getline(iss, orbit, ','); // orbit 
    l.orbit = stringUpper(orbit);
    getline(iss, customer, ','); // customer 
    l.customer = stringUpper(customer);
    getline(iss, outcome, ','); // mission outcome 
    l.outcome = stringUpper(outcome);
  }
  return Source;	
}

/*!
*    Operator overload that prints a Launch class to the output stream
*/
ostream &operator<<( ostream &output, const Launch &l){
  
  output.setf(ios::left);
  output << l.order << endl;
  // setw only affects the next value into output 
  // can't be on 1 line. setw affects the month and hour value, not the entire output
  output << "Date: " << l.launchDate << endl;
  output << "Time: " << l.launchTime << endl;
  
  output << "Mass: ";
  if (l.mass >=1)
    output << l.mass << " kg" << endl;
  else if (l.mass == 0)
    output << "Not given" << endl;
  else
    output << "Classified" << endl;

  output << "Site: " << setw(20) << l.site;
  output << setw(8) << "Orbit: " << setw(20) << l.orbit;
  output << setw(9) << "Outcome: " << setw(10) << l.outcome << endl;
  output << "Customer: " << l.customer << endl;
 
  return output;
}


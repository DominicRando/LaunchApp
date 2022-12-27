/*
File:          Date.cpp
Author:        Dominic Rando
Course:        CSC402
Professor:     **********
Assignment:    **********
Purpose:       Implementation file for the Date class 
Creation Date: April 13, 2021
Due Date:      May 11, 2021
*/

#include <iostream>
#include "Date.h"
    
/*!
*    \file Date.cpp
*    \brief Implementations for the Date class functions found in Date.h
*
*    \class Date
*    This class will take three integers that will represent the month, day, and year for the date
*/    

using namespace std;

/*!
*    Default constructor uses the setDate function to set the values of month, day, and year
*/
Date::Date( int m, int d, int y ){
  setDate(m,d,y);
}

/*!
*    Copy constructor sets "this" Date object's members to the same ones as the other Date object
*/
Date::Date(const Date &d){
  this->day = d.day;
  this->month = d.month;
  this->year = d.year;
}

/*!
*    Sets the date given the 3 parameters
*/
void Date::setDate(int m, int d, int y){
  month = m;
  day = d;
  year = y;
}

/*!
*    Function that returns the value for data member "month"
*/
int Date::getMonth(){ return(month); }

/*!
*    Function that returns the value for data member "dat"
*/
int Date::getDay(){ return(day); }

/*!
*    Function that returns the value for data member "year"
*/
int Date::getYear(){ return(year); }

/*!
*    Operator overload that compares two Date objects and determines if "this"
*    is less than the other object based on the values of month, day, and year
*/
bool Date::operator<(Date d){
  // check if years are different, then months, then days
  // make this look genuine
  if (this->year < d.year)
    return true;
  else if (this->year == d.year && this->month < d.month)
    return true;
  else if (this->year == d.year && this -> month == d.month && this->day < d.day)
    return true;
  return false;
}

/*!
*    Operator overload that compares two Date objects and determines if "this"
*    is less than or equal the other object based on the values of month, day, and year
*/
bool Date::operator<=(Date d){
  // check if years are different, then months, then days
  // make this look genuine
  if (this->year == d.year)
    return true;
  if (this->year < d.year)
    return true;
  else if (this->year == d.year && this->month < d.month)
    return true;
  else if (this->year == d.year && this -> month == d.month && this->day < d.day)
    return true;
  return false;
}

/*!
*    Operator overload that compares two Date objects and determines if "this"
*    is equal the other object based on the values of month, day, and year
*/
bool Date::operator==(Date d){
  if(this->month == d.month && this->day == d.day && this->year == d.year)
    return true;
  else
    return false;
}

/*!
*    Operator overload that prints a Date class to the output stream
*    It will display the months as their names instead of their integer value
*/
ostream &operator<<( ostream &output, const Date &d )
{
   string monthName[13] = { "", "January",
      "February", "March", "April", "May", "June",
      "July", "August", "September", "October",
      "November", "December"};

   output << monthName[ d.month ] << ' '
          << d.day << ", " << d.year;

   return output;   // enables cascading
}
/*
File:          Date.h
Author:        Dominic Rando
Course:        CSC402
Professor:     **********
Assignment:    **********
Purpose:       Header file for the Date class 
Creation Date: April 13, 2021
Due Date:      May 11, 2021
*/

/*!
*    \file Date.h 
*    \brief Header file for Date class
*/
#ifndef DATE_H
#define DATE_H
#include <iostream>

using namespace std;

/*!
*    \class Date
*    \brief Date class that will be used in Launch class
*
*    This class can create a Date, inspect their variables, and compare between other Date objects
*/

class Date {

public:

   /*!
  *    \fn Constructor
  *    The default contructor initializes the day and month to 1, and the year to 1900
  */
  Date( int m = 1, int d = 1, int y = 1900 ); 

   /*!
  *    \fn Copy Constructor
  *    Allows for a Date object to copy the variables from another Date object
  */
  Date(const Date &);

  // mutator
   /*!
  *    \fn setDate
  *    Takes 3 parameters that will become the Date's month, day, and year
  */
  void setDate(int m, int d, int y);

   // inspectors
   /*!
  *    \fn getMonth
  *    Inspector function that return the month as an integer
  */
  int getMonth();
  
  /*!
  *    \fn getDay
  *    Inspector function that return the day as an integer
  */
  int getDay();
  
  /*!
  *    \fn getYear
  *    Inspector function that return the year as an integer
  */
  int getYear();
   
  /*!
  *    Compares a Date to another Date and determines if the left Date
  *    is less than the right Date
  */
  bool operator<(Date d);
  
  /*!
  *    Compares a Date to another Date and determines if the left Date
  *    is less than or equal to the right Date
  */
  bool operator<=(Date d);
  
  /*!
  *    Compares a Date to another Date and determines if the left Date
  *    and the right Date are the same
  */
  bool operator==(Date);

private:

  /*!
  *    \var month 
  *    The month of the year represented as an integer
  */
  int month;
  
  /*!
  *    \var day 
  *     The day of the month represented as an integer
  */
  int day;
  
  /*!
  *    \var year 
  *    An integer that represents the year for the Date
  */
  int year;

  friend ostream &operator<<( ostream &, const Date & );
};

#endif

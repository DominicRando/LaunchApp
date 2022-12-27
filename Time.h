/*
File:          Time.h
Author:        Dominic Rando
Course:        CSC402
Professor:     **********
Assignment:    **********
Purpose:       Header file for the Time class 
Creation Date: April 13, 2021
Due Date:      May 11, 2021
*/

/*!
*    \file Time.h 
*    \brief Header file for Time class
*/

#ifndef TIME_H
#define TIME_H
#include <iostream>

using namespace std;

/*!
*    \class Time
*    \brief Time class that will be used in Launch class
*
*    This class can create a Time, inspect their variables, and compare between other Time objects
*/

class Time {
        
public:

  /*!
  *    \fn Constructor
  *    The default contructor initializes the time to 23:59:59 (hh:mm:ss)
  */
  Time (int h = 23, int m = 59, int s = 59);
  
  /*!
  *    \fn Copy Constructor
  *    Allows for a Time object to copy the variables from another Time object
  */
  Time(const Time&);
  
  // mutator
  /*!
  *    \fn setDate
  *    Takes 3 parameters that will become the Time's hour, minute, and seconds
  */
  void setTime(int h, int m, int s);
  
  // inspectors
  /*!
  *    \fn getHour
  *    Inspector function that return the hour as an integer
  */
  int getHour();
  
  /*!
  *    \fn getMinute
  *    Inspector function that return the minute as an integer
  */
  int getMinute();
  
  /*!
  *    \fn getSecond
  *    Inspector function that return the second as an integer
  */
  int getSecond();
  
  // operators
  /*!
  *    Compares a Time to another Time and determines if the left Time
  *    is less than the right Time. Used in the functors for Launch class
  */
  bool operator<(Time t);

private:

  /*!
  *    \var hour 
  *    The hour of the Time represented as an integer
  */
  int hour;
  
  /*!
  *    \var minute 
  *    The minute of the Time represented as an integer
  */
  int minute;
  
  /*!
  *    \var second 
  *    The minute of the Time represented as an integer
  */
  int second;
  
  friend ostream &operator<<( ostream &, const Time &);
  
};

#endif
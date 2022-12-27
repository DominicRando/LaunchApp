/*
File:          Time.cpp
Author:        Dominic Rando
Course:        CSC402
Professor:     **********
Assignment:    **********
Purpose:       Implementation file for the Time class 
Creation Date: April 13, 2021
Due Date:      May 11, 2021
*/

#include <iostream>
#include "Time.h"

/*!
*    \file Time.cpp
*    \brief Implementations for the Time class functions found in Time.h
*
*    \class Time
*    This class will take three integers that will represent the hour, minute, and second for the Time object
*/  

using namespace std;

/*!
*    Default constructor uses the setTime function to set the values of hour, minute, and second
*/
Time::Time(int h, int m, int s){
  setTime(h,m,s);
}

/*!
*    Copy constructor sets "this" Time object's members to the same ones as the other Time object
*/
Time::Time(const Time &t){
  this->hour = t.hour;
  this->minute = t.minute;
  this->second = t.second;
}

/*!
*    Sets the Time given the 3 parameters for hour, minute, and second
*/
void Time::setTime(int h, int m, int s){
  hour = h;
  minute = m;
  second = s;
}

/*!
*    Function that returns the value for data member "hour"
*/
int Time::getHour(){ return(hour); }

/*!
*    Function that returns the value for data member "minute"
*/
int Time::getMinute(){ return(minute); }

/*!
*    Function that returns the value for data member "second"
*/
int Time::getSecond(){ return(second); }

/*!
*    Operator overload that compares two Time objects and determines if "this"
*    is less than the other object based on the values of hour, minute, and second
*/
bool Time::operator<(Time t){
  if (this->hour < t.hour)
    return true;
  else if (this->hour == t.hour && this->minute < t.minute)
    return true;
  else if (this->hour == t.hour && this->minute == t.minute && this->second < t.second)
      return true;
  return false;
}

/*!
*    Operator overload that prints a Time class to the output stream
*    It will add 0's to the end of each member (except hour) if they are less than 10
*/
ostream &operator<<( ostream &output, const Time &t){
  output << t.hour << ":";
  if (t.minute < 10)
    output << 0 << t.minute;
  else 
    output << t.minute;
  output << ":";
  if (t.second < 10)
    output << 0 << t.second;
  else
    output << t.second;
  return output; 
}
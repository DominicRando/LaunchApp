/*
File:          Launch.h
Author:        Dominic Rando
Course:        CSC402
Professor:     **********
Assignment:    **********
Purpose:       Header file for the Launch class 
Creation Date: April 19, 2021
Due Date:      May 11, 2021
*/

/*!
*    \file Launch.h 
*    \brief Header file for Launch class
*/

#ifndef LAUNCH_H
#define LAUNCH_H
#include <iostream>
#include "Launch.h"
#include "Date.h"
#include "Time.h"

/*!
*    \class Launch
*    \brief Launch class that holds data from a file
*
*    This class uses the Date and Time class as variable types for members
*/

class Launch {
        
public:
  // FUNCTORS
  
  /*! \brief Launch functor cmpDate
  *
  *  Used in std::sort() to compare Date objects
  */
  struct cmpDate : public binary_function<Launch, Launch, bool> {
    bool operator()
    (Launch x, Launch y) {return (x.getDate() < y.getDate());}
  };
  
  /*! \brief Launch functor cmpTime
  *
  *  Used in std::sort() to compare Time object
  */
  struct cmpTime : public binary_function<Launch, Launch, bool> {
    bool operator()
    (Launch x, Launch y) {return (x.getTime() < y.getTime());}
  }; 
  
  /*! \brief Launch functor cmpMass
  *
  *  Used in std::sort() to compare the int mass values of Launch objects
  */
  struct cmpMass : public binary_function<Launch, Launch, bool> {
    bool operator()
    (Launch x, Launch y) {return (x.getMass() < y.getMass());}
  };
  
  /*! \brief Launch functor cmpSite
  *
  *  Used in std::sort() to compare the string site values of Launch objects
  */
  struct cmpSite : public binary_function<Launch, Launch, bool> {
    bool operator()
    (Launch x, Launch y) {return (x.getSite() < y.getSite());}
  };

  /*!
  *    \fn Constructor
  *    The default contructor initializes the data members with random values
  */
  Launch();
  
  /*!
  *    \fn getOrder
  *    Returns an integer as the order in which the flight launched according to the date
  */
  int getOrder();
  
  /*!
  *    \fn getDate
  *    Returns a Date object that is the value of the Launch's data member LaunchDate
  */
  Date getDate();
  
  /*!
  *    \fn getTime
  *    Returns a Time object that is the value of the Launch's data member LaunchTime
  */
  Time getTime();
  
  /*!
  *    \fn getSite
  *    Returns a string as the value of the data member site
  */
  string getSite();
  
  /*!
  *    \fn getMass
  *    Returns an integer of the value of mass in the Launch object. 
  */
  int getMass();
  
  /*!
  *    \fn getOrbit
  *    Returns a string as the value of the data member orbit
  */
  string getOrbit();
  
  /*!
  *    \fn getCustomer
  *    Returns a string as the value of the data member customer
  */
  string getCustomer();
  
  /*!
  *    \fn getOutcome
  *    Returns a string as the value of the data member otucome
  */
  string getOutcome();
  
private:
  
  /*!
  *    \var launchDate 
  *    The day that this spacecraft launched
  */
  Date launchDate;
  
  /*!
  *    \var launchTime 
  *    The time that this spacecraft launched
  */
  Time launchTime;
  
  /*!
  *    \var site 
  *    The place the spacecraft took flight from
  */
  string site;
  
  /*!
  *    \var orbit 
  *    This is where the spacecraft stayed in orbit/flight for in space
  */
  string orbit;
  
  /*!
  *    \var customer 
  *    This is who sponsored the building of the spacecraft
  */
  string customer; 
  
  /*!
  *    \var outcome 
  *    This is whether or not lift off was possible for this aircraft
  */
  string outcome;
  
  /*!
  *    \var mass 
  *    Mass is determined by how much the spacecraft weighed in Kilograms
  */
  int mass, order;

friend istream &operator>>(istream&, Launch &l);
friend ostream &operator<<( ostream &, const Launch &);
};



#endif
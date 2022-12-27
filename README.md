# LaunchApp

Documentation:
The following files have limited comments in the functions, but do have comments describing the functions. There are also comments that are used for Doxygen, a website that presents documentation.
Link for the doxygen site: https://acad.kutztown.edu/~drand808/csc402/Project3/

This program was created for a project in one of my classes. The assignment was to find a dataset online, store it in objects, then manipulate it. 
We had to show an understanding of STL datatypes and object functors.
I chose a dataset titled SpaceX Launch Data, which is a comma separated file.
Link for dataset: https://www.kaggle.com/datasets/scoleman/spacex-launch-data

Design:
I created two classes, Date and Time, that will be used as a datatype in the Launch class
  - Both have three integer values that represent the indivual components to make up their class.
  - Both have inspectors functions to view their three data members, and they have one mutator function where you can change the data members
  - Both overloaded the < operator 
  - Date
    * overloaded output operator to show the date using the word of the month (January, ..., December), and their day and year as a number
    * overloaded the <= operator. This is used when finding a range between two dates
    * overloaded the == operator. This is used when finding an exact date
  - Time
    * overloaded output operator to show the time represented as hh:mm:ss, where h = hour, m = minute, and s = second
 
The main class, Launch, holds data for each line in the file "spacex_launch_data.csv"
  - Has inspector functions for each data member (8 in total). No mutator functions as they are not needed for the application
  - There is a function called stringUpper at the beginning of the file
    * This will take a string and return it with all uppercase letters
    * This is used when obtaining string data members so that everything is consistent
  - overloaded input operator to read a line from a file and assign its data members based on that input.
  - overloaded output operator to display the data for that objects in a decently neat fashion
    ex) 56
	  Date: June 4, 2018
	  Time: 4:45:00
	  Mass: 5384 kg
	  Site: CCAFS SLC-40        Orbit:  GTO                 Outcome: SUCCESS
        Customer: SES
    * The 56 represents the order of this Launch object. It is given in the file and corresponds to the date the event took place
    * If the data is ordered by date, then it is also ordered by their file-given order
  - This class has 4 data members that are of type string. There are multiple points where I maniuplate the string and access them character by character

Then there is the application file, app (How to run it is detailed in the next section)
  - It operates using menu and sub-menus
  - It reads the file spacex_launch_date.csv and creates a Launch object for each line. Those are then stored in a vector
  - This vector can be used to print the data in a variety of ways based on the individual data members
  - It can also be reordered based on its date, time, mass, and site data members
    * This function uses std::sort() and passes iterators and functors. Functors can be found at the beginning of the Launch class
  - There is also a manipulation mode
    * In this mode, the vector is manipulated to only contain data that was found in a search
    * This uses a vector function .erase() that takes an iterator and deletes that data in the vector
      a) I pass a boolean to search functions, and when its true, it adds an iterator to a vector of iterators when a Launch does not show up in the search
      b) This vector is then passed to a function that erases those elements from the list

How to run:

Assuming you are using the terminal, you should type the "make" command. This will create an executable file called app and you run it using "./app". This program does not take arguments.
From here, you will be presented with a menu of options. When you enter in a character for these options, the program will take you to a submenu to complete your choice.

P)rint allows you to print all Launch objects you currently have, or print range will print objects within a range according to the Launch object's order

C)ustomer search allows you to print Launch objects based on an exact search, or a match search.
  - The match search takes your input and will print any Launch object whose customer value contains your input. It can be anywhere in the customer value

O)rbit search acts exactly like customer search, allowing for an exact match or a matching match, but it looks for orbit values instead.

D)ate will search for an exact date or a range of dates. Give it a date in the format of (MM DD YYYY). 
  - You will have to provide two dates, on separate enters, when using the range fucntion.

S)wap mode allows you to switch the mode. There are two modes: printing and manipulation.
  - Printing will only print the Launch objects when you select a choice from the menu
  - Manipulation will delete all non-found Launch objects when you select a choice from the menu
    * Ex) if you search for an exact date like 06 04 2018, only one Launch object is printed. If you try to print all, only this object will appear.

F)ile read will reread the file and recreate your vector of Launch objects. It's intended use is with the manipulation mode.

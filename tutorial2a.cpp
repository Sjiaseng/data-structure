// Section B Question 3

// A C++ Program to Implement a Calendar
// of an year
#include<cstdlib>
#include<string>
#include<iomanip>
#include<iostream>
using namespace std;
 
 
/*A Function that returns the index of the day
  of the date- day/month/year
  For e.g-
 
  Index     Day
  0         Sunday
  1         Monday
  2         Tuesday
  3         Wednesday
  4         Thursday
  5         Friday
  6         Saturday*/
int dayNumber(int day, int month, int year)
{
 
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
                       4, 6, 2, 4 };
    year -= month < 3;
    return (year + year / 4 - year / 100 +
        year / 400 + t[month - 1] + day) % 7;
}
 
/*
  A Function that returns the name of the month
  with a given month number
 
  Month Number     Name
  0                January
  1                February
  2                March
  3                April
  4                May
  5                June
  6                July
  7                August
  8                September
  9                October
  10               November
  11               December */
string getMonthName(int monthNumber)
{
    string months[] = { "January", "February", "March",
                       "April", "May", "June",
                       "July", "August", "September",
                       "October", "November", "December"
    };
 
    return (months[monthNumber]);
}
 
// A Function to prompt user to enter the calendar year and month to print
void get_year_month(int* year, int* month)
{
    cout << "Enter calendar\'s year: ";
    cin >> *year;
    cout << "Enter calendar\'s month: ";
    cin >> *month;
    (*month)--;
}
 
/* A Function to return the number of days in
   a month
 
  Month Number     Name        Number of Days
  0                January     31
  1                February    28 (non-leap) / 29 (leap)
  2                March       31
  3                April       30
  4                May         31
  5                June        30
  6                July        31
  7                August      31
  8                September   30
  9                October     31
  10               November    30
  11               December    31
 
*/
int numberOfDays(int monthNumber, int year)
{
    // January, March, May, July, August, October, December
    if (monthNumber == 0 || monthNumber == 2 || monthNumber == 4 || monthNumber == 6 || monthNumber == 7 || monthNumber == 9 || monthNumber == 11)
        return (31);
 
    // February
    else if (monthNumber == 1)
    {
        // If the year is leap then February has
        // 29 days
        if (year % 400 == 0 ||
            (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }
 
    // April, June, September, November
    else
        return (30);
}
 
// Function to print the calendar of the given year
void printCalendar(int year, int month)
{
    cout << "         Calendar - " << year << endl << endl;
    int days;
 
    // Index of the day from 0 to 6
    int current = dayNumber(1, 1, year);
 
    // i --> Iterate through all the months
    // j --> Iterate through all the days of the
    //       month - i
 
        days = numberOfDays(month, year);
 
        // Print the current month name
        cout << "\n  ------------" << getMonthName(month) << "------------ - \n";
 
        // Print the columns
        cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
 
        // Print appropriate spaces
        int k;
        for (k = 0; k < current; k++)
            cout << "     ";
 
        for (int j = 1; j <= days; j++)
        {
            cout << setw(5) << j;
 
            if (++k > 6)
            {
                k = 0;
                cout << "\n";
            }
        }
 
        if (k)
            cout << endl;
 
        current = k;
 
    return;
}


// Driver Program to check above functions
int main()
{
    int year, month, days;

    get_year_month(&year, &month);
    printCalendar(year, month);

    return (0);
}
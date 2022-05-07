#include "../std_lib_facilities.h"

class Date
{
    int year, month, day; // year, month, day
	
    public:
        Date(int y, int m, int d); 	// check for valid date and initialize
        void add_day(int n); 		// increase the Date by n days
        int get_month() { return month; }
        int get_day() { return day; }
        int get_year() { return year; }
};

Date::Date(int y, int m, int d)
{
    if (y > 0)
        year = y;
    else
        error("Invalid year");
    if (m > 0 && m < 13)
        month = m;
    else 
        error("Invalid month");
    if (d > 0 && d < 32)
        day = d;
    else 
        error("Invalid day");
}

void Date::add_day(int n)
{
    day += n;
	if (day > 31) 
	{
		month++;
		day -= 31;
		if (month > 12)
		{
			year++;
			month -= 12;
		}
	}
}
       

int main()
try
{   
    Date today {1978, 6, 25};
    cout << "today: " << today.get_year() << "." << today.get_month() << "." << today.get_day() << endl;
	
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << "tomorrow: " << tomorrow.get_year() << "." << tomorrow.get_month() << "." << tomorrow.get_day() << endl;
	
    Date my_birthday {2020, 12, 31};
    cout << "check Date: " << my_birthday.get_year() << "." << my_birthday.get_month() << "." << my_birthday.get_day() << endl;

    my_birthday.add_day(1);
    cout << "check Date: " << my_birthday.get_year() << "." << my_birthday.get_month() << "." << my_birthday.get_day() << endl;
	
    //invalid date to check
    Date x {-2, 13, 32};
    cout << x.get_year() << "." << x.get_month() << "." << x.get_day() << endl;
     
    return 0;
}
catch (exception& e)
{
    cout << "Error: " << e.what() << endl;
    return 1;
}

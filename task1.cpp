#include <iostream>
using namespace std;

int main()
{
    int day, month, year;

    cout << "Enter day: ";
    cin >> day;

    cout << "Enter month: ";
    cin >> month;

    cout << "Enter year: ";
    cin >> year;

    cout << "Date entered(yyyy/mm/dd): " << year << "-" << month << "-" << day << endl;

    return 0;
}
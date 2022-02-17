#include <iostream>

using std::cout;
using std::endl;

class Date {
    private:
        int year_;
        int month_;
        int day_;

    public:
        void SetDate(int year, int month, int day);
        void AddDay(int inc);
        void AddMonth(int inc);
        void AddYear(int inc);
        int GetCurrentMonthTotalDay(int year, int month);
        void ShowDate();

    Date() {
        cout << "initial date setup!" << endl;
        year_ = 2022;
        month_ = 2;
        day_ = 17;
    }

    Date(int year, int month, int day) {
        cout << "call & initialization!" << endl;
        year_ = year;
        month_ = month;
        day_ = day;
    }
};

void Date::SetDate(int year, int month, int day) {
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::GetCurrentMonthTotalDay(int year, int month) {
    static int month_length[12] = {31, 28, 31, 30, 31, 60, 31, 31, 30, 31, 30, 31};
    if (month != 2) {
        return month_length[month - 1];
    } else if (year % 4 == 0 && year % 100 != 0) {
        return 29;
    } else {
        return 28;
    }
}

void Date::AddDay(int inc) {
    int current_month_toal_days = GetCurrentMonthTotalDay(year_, month_);
    day_ += inc;
    while (day_ > current_month_toal_days) {
        day_ -= current_month_toal_days;
        AddMonth(1);
    }
}

void Date::AddMonth(int inc) {
    month_ += inc;
    while (month_ > 12) {
        month_ -= 12;
        AddYear(1);
    }
}

void Date::AddYear(int inc) {
    year_ += inc;
}

void Date::ShowDate() {
    cout << "the date: " <<  year_ << "-" << month_ << "-" << day_ << endl;
}

int main() {
    Date date1;
    date1.ShowDate();

    date1.SetDate(2022, 3, 8);
    date1.ShowDate();

    date1.AddYear(3);
    date1.ShowDate();

    date1.AddMonth(20);
    date1.ShowDate();

    date1.AddDay(50);
    date1.ShowDate();

    return 0;
}
#include <iostream>
using namespace std;
int day, monthe, year, p = 0, sum = 0, j = 0, arr[8];
int CURRENT_DAY = 12, CURRENT_MONTHE = 1, CURRENT_YEAR = 2021;
string day1, dayear;
void printday() {
  int day1 = day, month1 = monthe, year1 = year;
  system("cls");
  (day1 < 10) ? arr[0] = 0, arr[1] = day1 : arr[0] = day1 / 10,
                arr[1] = day1 % 10;
  (month1 < 10) ? arr[2] = 0, arr[3] = month1 : arr[2] = month1 / 10,
                  arr[3] = month1 % 10;
  arr[4] = year1 / 1000;
  year1 %= 1000;
  arr[5] = year1 / 100;
  year1 %= 100;
  arr[6] = year1 / 10;
  year1 %= 10;
  arr[7] = year1;
  cout << "\t";
  for (int i = 0; i < 8; i++) {
    if (i == 2 || i == 4)
      cout << " / ";
    cout << arr[i];
  }
  cout << endl;
}
void the_main_day_of_year(int num) {
  switch (num) {
  case 0:
    dayear = "satrday";
    break;
  case 1:
    dayear = "sunday";
    break;
  case 2:
    dayear = "monday";
    break;
  case 3:
    dayear = "tusday";
    break;
  case 4:
    dayear = "wensday";
    break;
  case 5:
    dayear = "thurthday";
    break;
  case 6:
    dayear = "friday";
    break;
  }
  cout << "the main day of the year is :" << dayear << endl;
}
void choose_day(int num) {
  switch (num) {
  case 0:
    day1 = "satrday";
    break;
  case 1:
    day1 = "sunday";
    break;
  case 2:
    day1 = "monday";
    break;
  case 3:
    day1 = "tusday";
    break;
  case 4:
    day1 = "wensday";
    break;
  case 5:
    day1 = "thurthday";
    break;
  case 6:
    day1 = "friday";
    break;
  }
  cout << "the name of the day is      :" << day1 << endl;
}
void get_data() {
  cout << "enter the day you bourn in                    :";
  cin >> day;
  cout << "enter the monthe you bourn in                 :";
  ;
  cin >> monthe;
  cout << "enter the year you bourn in betewn(1900:2999) :";
  cin >> year;
}
bool check_the_year(int year) {
  return ((year % 4 != 0)     ? false
          : (year % 100 != 0) ? true
          : (year % 400 == 0) ? true
                              : false);
}

void how_old_are_you() {
  long long day2 = day, month2 = monthe, year2 = year, sum2;
  if ((CURRENT_DAY - day2) < 0) {
    if (CURRENT_MONTHE == 1 || CURRENT_MONTHE == 3 || CURRENT_MONTHE == 5 ||
        CURRENT_MONTHE == 7 || CURRENT_MONTHE == 8 || CURRENT_MONTHE == 10 ||
        CURRENT_MONTHE == 12)
      CURRENT_DAY += 31;
    else if (CURRENT_MONTHE == 4 || CURRENT_MONTHE == 6 ||
             CURRENT_MONTHE == 9 || CURRENT_MONTHE == 11)
      CURRENT_DAY += 30;
    else if (CURRENT_MONTHE == 2)
      (check_the_year(year2)) ? CURRENT_MONTHE += 29 : CURRENT_MONTHE += 28;
    --CURRENT_MONTHE;
  }

  day2 = CURRENT_DAY - day2;
  if ((CURRENT_MONTHE - month2) < 0) {
    CURRENT_YEAR--;
    CURRENT_MONTHE += 12;
  }

  month2 = CURRENT_MONTHE - month2;
  year2 = CURRENT_YEAR - year2;

  cout << "your age is  :" << year2 << " years" << endl
       << "             :" << month2 << " monthes" << endl
       << "             :" << day2 << " days" << endl;
}
void check_general() {
  try {
    get_data();
    if ((day > 31 &&
         (monthe == 1 || monthe == 3 || monthe == 5 || monthe == 7 ||
          monthe == 8 || monthe == 10 || monthe == 12)) ||
        day < 1 || monthe < 1 || monthe > 12)
      throw "day exception";
  }

  catch (const char *n) {
    cout << "please enter right day\n";
    get_data();
  }
}
void check_data() {
  try {
    if (cin.fail())
      throw exception();
    else if ((day > 31 &&
              (monthe == 1 || monthe == 3 || monthe == 5 || monthe == 7 ||
               monthe == 8 || monthe == 10 || monthe == 12)) ||
             day < 1 || monthe < 1 || monthe > 12)
      throw exception();
    else if (day > 30 &&
             (monthe == 4 || monthe == 6 || monthe == 9 || monthe == 11))
      throw exception();
    else if (day > 28 && monthe == 2 && check_the_year(year) == false)
      throw exception();
    else if (day > 29 && monthe == 2)
      throw exception();
    else if (year < 1900 || year > 3000)
      throw exception();
  } catch (exception e) {
    cout << "please enter right data\a\n";
    cin.clear();
    cin.ignore(100, '\n');
    get_data();
    check_data();
  }
}
void calculat_the_main_day(int num) {
  sum = year % 100;
  p = sum % 12;
  ;
  sum /= 12;
  j = p / 4;
  p = p + sum + j;
  if (year < 2000)
    p += 4;
  else if (year > 2000)
    p += 3;
  while (p > 6)
    p %= 7;
}
void choose_name_of_day(int monthe) {
  switch (monthe) {
  case 1: {
    if (check_the_year(year) == true) {
      if (day == 4) {
        day = p;
      } else if (day > 4) {
        day -= 4;
        day += p;
        while (day > 6)
          day %= 7;

      } else {
        day = 4 - day;
        day = p - day;
        if (day < 0) {
          day += 7;
        }
      }
    } else {
      if (day == 3)
        day = p;
      else if (day > 3) {
        day -= 3;
        day += p;
        while (day > 6)
          day %= 7;
      } else {
        day = 3 - day;
        day = p - day;
        if (day < 0)
          day += 7;
      }
    }
  } break;
  case 2: {
    if (check_the_year(year) == true) {
      if (day == 1)
        day = p;
      else if (day > 1) {
        day -= 1;
        day += p;
        while (day > 6)
          day %= 7;
      }
    } else {
      day %= 7;
      if (day + p < 7)
        day += p;
      else {
        day += p;
        day %= 7;
      }
    }
  } break;
  case 3: {
    day %= 7;
    if (day + p < 7)
      day += p;
    else {
      day += p;
      day %= 7;
    }
  } break;
  case 4: {
    if (day == 4) {
      day = p;
    } else if (day > 4) {
      day -= 4;
      day += p;
      while (day > 6)
        day %= 7;

    } else {
      day = 4 - day;
      day = p - day;
      if (day < 0) {
        day += 7;
      }
    }

  } break;
  case 5: {
    if (day == 2)
      day = p;
    else if (day > 2) {
      day -= 2;
      day += p;
      while (day > 6)
        day %= 7;

    } else {
      day = 2 - day;
      day = p - day;
      if (day < 0)
        day += 7;
    }
  } break;
  case 6: {
    if (day == 6)
      day = p;
    else if (day > 6) {
      day -= 6;
      day += p;
      while (day > 6)
        day %= 7;
    } else {
      day = 6 - day;
      day = p - day;
      if (day < 0)
        day += 7;
    }
  } break;
  case 7: {
    if (day == 4) {
      day = p;
    } else if (day > 4) {
      day -= 4;
      day += p;
      while (day > 6)
        day %= 7;

    } else {
      day = 4 - day;
      day = p - day;
      if (day < 0) {
        day += 7;
      }
    }
  } break;
  case 8: {
    if (day == 1)
      day = p;
    else if (day > 1) {
      day -= 1;
      day += p;
      while (day > 6)
        day %= 7;
    }
  } break;
  case 9: {
    if (day == 5)
      day = p;
    else if (day > 5) {
      day -= 5;
      day += p;
      while (day > 6)
        day %= 7;
    } else {
      day = 5 - day;
      day = p - day;
      if (day < 0)
        day += 7;
    }

  } break;
  case 10: {
    if (day == 3)
      day = p;
    else if (day > 3) {
      day -= 3;
      day += 3;
      while (day > 6)
        day %= 7;
    } else {
      day = 3 - day;
      day = p - day;
      if (day < 0)
        day += 7;
    }

  } break;
  case 11: {
    if (day == 7)
      day = p;
    else if (day > 7) {
      day -= 7;
      day += p;
      while (day > 6)
        day %= p;
    } else {
      day = day - 7;
      day = p - day;
      if (day < 0)
        day += 7;
    }
  } break;
  case 12: {
    if (day == 5)
      day = p;
    else if (day > 5) {
      day -= 5;
      day += p;
      while (day > 6) {
        day %= 7;
      }
    } else {
      day = 5 - day;
      day = p - day;
      if (day < 0)
        day += 7;
    }
  } break;
  }
  choose_day(day);
};
int main() {
  get_data();
  check_data();
  printday();
  how_old_are_you();
  calculat_the_main_day(year);
  the_main_day_of_year(p);
  choose_name_of_day(monthe);
  (check_the_year(year)) ? cout << "this year is leap\n"
                         : cout << "the year isn't leap\n";
  system("pause");

  return 0;
}
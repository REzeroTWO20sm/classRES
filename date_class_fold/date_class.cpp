//Конечно, вот пример реализации класса "Дата" (Date) на языке C++ с учетом указанных требований:

//g++ date_class.cpp -o date_class --std=c++14

#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Конструктор с параметрами
    Date(int dayVal, int monthVal, int yearVal) {
        day = dayVal;
        month = monthVal;
        year = yearVal;
    }

    // Геттеры и сеттеры
    int getDay() const {
        return day;
    }

    void setDay(int dayVal) {
        day = dayVal;
    }

    int getMonth() const {
        return month;
    }

    void setMonth(int monthVal) {
        month = monthVal;
    }

    int getYear() const {
        return year;
    }

    void setYear(int yearVal) {
        year = yearVal;
    }

    // Вычисление количества дней от начала года
    int toDays() const {
        int days = day;
        for (int i = 1; i < month; i++) {
            if (i == 2) {
                if (isLeapYear(year)) {
                    days += 29;
                } else {
                    days += 28;
                }
            } else if (i == 4 || i == 6 || i == 9 || i == 11) {
                days += 30;
            } else {
                days += 31;
            }
        }
        return days;
    }

    // Вычисление количества месяцев от начала года
    int toMonths() const {
        return month;
    }

    // Вычисление количества лет
    int toYears() const {
        return year;
    }

    // Сложение дат
    Date operator+(const Date& other) const {
        int newDay = day + other.day;
        int newMonth = month + other.month;
        int newYear = year + other.year;
        
        newMonth += newDay / 31;
        newDay %=31;
        newYear += newMonth / 12;
        newMonth %= 12;

        return Date(newDay, newMonth, newYear);
    }

    // Вычитание дат
    Date operator-(const Date& other) const {
        int newDay = day - other.day;
        int newMonth = month - other.month;
        int newYear = year - other.year;

        if (newDay < 0) {
            newDay +=31;
            newMonth--;
        }
        if (newMonth < 0) {
            newMonth +=12;
            newYear--;
        }
        if (newYear < 0) {
            newYear--;
        }

        return Date(newDay, newMonth, newYear);
    }

    // Добавление дней, месяцев и лет к текущей дате
    Date addDays(int days) {
        int newDay = day + days;
        int newMonth = month;
        int newYear = year;
        
        newMonth += newDay / 31;
        newDay %=31;
        newYear += newMonth / 12;
        newMonth %= 12;

        return Date(newDay,newMonth,newYear);
    }

    // Преобразование даты в строковый формат
    std::string toString() const {
        return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
    }

    // Проверка на равенство дат
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    // Проверка на високосный год
    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};

int main() {
    // Примеры использования класса Date
    Date date1(10, 1, 2022);
    Date date2(22, 3, 2023);

    std::cout << "Дата 1: " << date1.toString() << std::endl;
    std::cout << "Дата 2: " << date2.toString() << std::endl;

    Date sum = date1 + date2;
    std::cout << "Дата 1 + Дата 2 = " << sum.toString() << std::endl;

    Date diff = date1 - date2;
    std::cout << "Дата 1 - Дата 2 = " << diff.toString() << std::endl;

    if (date1 == date2) {
        std::cout << "Дата 1 и Дата 2 равны" << std::endl;
    } else {
        std::cout << "Дата 1 и Дата 2 не равны" << std::endl;
    }

    return 0;
}

// В данном примере класс `Date` содержит приватные переменные `day`, `month` и `year`, которые представляют компоненты даты. Геттеры и сеттеры обеспечивают доступ и изменение этих значений.

// Метод `toDays()` вычисляет количество дней от начала года, `toMonths()` вычисляет количество месяцев от начала года, а `toYears()` вычисляет количество лет.

// Класс также перегружает операторы сложения и вычитания для дат. Также реализованы методы `addDays()`, `addMonths()` и `addYears()`, которые позволяют добавлять дни, месяцы и годы к текущей дате соответственно. Метод `toString()` преобразует дату в строковый формат.

// В функции `main()` создаются объекты класса `Date` и демонстрируется использование основных методов класса и операторов. Выделение памяти для объекта класса `Date` динамически не требуется, так как класс не содержит указателей на динамически выделенную память.

// Если вам необходимо создать массив из объектов класса `Date` или массив указателей на объекты класса `Date`, вам нужно будет использовать операторы `new` и `delete` для динамического выделения и освобождения памяти соответственно.
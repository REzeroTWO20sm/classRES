//Конечно, вот пример реализации класса "Обыкновенная дробь" на языке C++ с учетом указанных требований:
//g++ drob_class.cpp -o drob_class --std=c++14
#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Конструктор с параметрами
    Fraction(int num, int denom) {
        if (denom == 0) {
            throw std::invalid_argument("Знаменатель не может быть равен нулю!");
        }
        
        numerator = num;
        denominator = denom;
    }
    
    // Геттер для числителя
    int getNumerator() const {
        return numerator;
    }
    
    // Сеттер для числителя
    void setNumerator(int num) {
        numerator = num;
    }
    
    // Геттер для знаменателя
    int getDenominator() const {
        return denominator;
    }
    
    // Сеттер для знаменателя
    void setDenominator(int denom) {
        if (denom == 0) {
            throw std::invalid_argument("Знаменатель не может быть равен нулю!");
        }
        
        denominator = denom;
    }
    
    // Метод для сокращения дроби
    void simplify() {
        int gcd = greatestCommonDivisor(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
    
    // Метод для получения наибольшего общего делителя
    int greatestCommonDivisor(int a, int b) const {
        if (b == 0) {
            return a;
        }
        return greatestCommonDivisor(b, a % b);
    }
    
    // Оператор сложения дробей
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    
    // Оператор вычитания дробей
    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    
    // Оператор умножения дробей
    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }
    
    // Оператор деления дробей
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Деление на ноль невозможно!");
        }
        
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }
    
    // Оператор проверки на равенство дробей
    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }
};

int main() {
    // Примеры использования класса Fraction
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    
    Fraction sum = f1 + f2;
    std::cout << "Сумма: " << sum.getNumerator() << "/" << sum.getDenominator() << std::endl;
    
    Fraction diff = f1 - f2;
    std::cout << "Разность: " << diff.getNumerator() << "/" << diff.getDenominator() << std::endl;
    
    Fraction prod = f1 * f2;
    std::cout << "Произведение: " << prod.getNumerator() << "/" << prod.getDenominator() << std::endl;
    
    Fraction quotient = f1 / f2;
    std::cout << "Частное: " << quotient.getNumerator() << "/" << quotient.getDenominator() << std::endl;
    
    if (f1 == f2) {
        std::cout << "Дроби равны" << std::endl;
    } else {
        std::cout << "Дроби не равны" << std::endl;
    }
    
    return 0;
}

// В данном примере класс `Fraction` представляет обыкновенную дробь и содержит приватные переменные `numerator` (числитель) и `denominator` (знаменатель). Есть геттеры и сеттеры для доступа и изменения этих значений.

// Класс также перегружает операторы сложения, вычитания, умножения и деления для обыкновенных дробей. Метод `simplify()` используется для сокращения дроби до наименьших целых чисел. Оператор проверки на равенство `==` также перегружен для дробей.

// В функции `main()` создаются объекты класса `Fraction` и демонстрируется использование основных методов и операторов. Для работы с динамическим выделением памяти и массивами из объектов класса `Fraction`, вам нужно будет использовать оператор `new` и `delete`, а также знание работы с указателями и динамическим выделением памяти.
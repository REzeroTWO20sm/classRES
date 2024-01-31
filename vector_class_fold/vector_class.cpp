#include <iostream>
#include <cmath>

//g++ vector_class.cpp -o vector_class --std=c++14

class Vector {
private:
    double x;
    double y;
    double z;

public:
    // Конструктор с параметрами
    Vector(double xVal, double yVal, double zVal) {
        x = xVal;
        y = yVal;
        z = zVal;
    }

    // Геттеры и сеттеры
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    double getZ() const {
        return z;
    }

    void setX(double xVal) {
        x = xVal;
    }
    void setY(double yVal) {
        y = yVal;
    }
    void setZ(double zVal) {
        z = zVal;
    }

    // Вычисление длины вектора
    double length() const {
        return sqrt(x * x + y * y + z * z);
    }

    // Вычисление угла между вектором и одной из осей
    double angleWithAxis(char axis) const {
        double radians = 0.0;

        switch (axis) {
            case 'x':
                radians = acos(x / length());
                break;
            case 'y':
                radians = acos(y / length());
                break;
            case 'z':
                radians = acos(z / length());
                break;
            default:
                std::cout << "Неверная ось!" << std::endl;
                break;
        }

        return radians * 180.0 / M_PI; // Возвращаем угол в градусах
    }

    // Оператор сложения векторов
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

    // Оператор вычитания векторов
    Vector operator-(const Vector& other) const {
        return Vector(x - other.x, y - other.y, z - other.z);
    }

    // Оператор умножения вектора на число
    Vector operator*(double scalar) const {
        return Vector(x * scalar, y * scalar, z * scalar);
    }

    // Оператор проверки на равенство векторов
    bool operator==(const Vector& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

int main() {
    // Примеры использования класса Vector
    Vector v1(1.0, 2.0, 3.0);
    Vector v2(4.0, 5.0, 6.0);

    std::cout << "Длина v1: " << v1.length() << std::endl;
    std::cout << "Угол между v1 и осью x: " << v1.angleWithAxis('x') << " градусов" << std::endl;

    Vector v3 = v1 + v2;
    std::cout << "Результат сложения v1 и v2: (" << v3.getX() << ", " << v3.getY() << ", " << v3.getZ() << ")" << std::endl;

    Vector v4 = v2 - v1;
    std::cout << "Результат вычитания v1 из v2: (" << v4.getX() << ", " << v4.getY() << ", " << v4.getZ() << ")" << std::endl;

    Vector v5 = v1 * 2.5;
    std::cout << "Результат умножения v1 на 2.5: (" << v5.getX() << ", " << v5.getY() << ", " << v5.getZ() << ")" << std::endl;

    if (v1 == v2) {
        std::cout << "v1 и v2 равны" << std::endl;
    } else {
        std::cout << "v1 и v2 не равны" << std::endl;
    }

    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

class EquilateralTriangle {
private: // Все поля приватные
    double side; // Длина стороны

public:
    // Конструктор
    EquilateralTriangle(double s) : side(s) {}

    // Методы вычислений
    double calculatePerimeter() const {
        return 3 * side;
    }

    double calculateArea() const {
        return (sqrt(3) / 4) * side * side;
    }

    double calculateHeight() const {
        return (sqrt(3) / 2) * side;
    }

    // Геттер для стороны
    double getSide() const {
        return side;
    }

    // Метод для вывода информации
    virtual void printInfo() const {
        cout << "Равносторонний треугольник:" << endl;
        cout << "  Сторона: " << side << endl;
        cout << "  Периметр: " << calculatePerimeter() << endl;
        cout << "  Площадь: " << calculateArea() << endl;
        cout << "  Высота: " << calculateHeight() << endl;
        cout << "----------------------------" << endl;
    }

    // Геттер для площади
    double getArea() const {
        return calculateArea();
    }

    // Виртуальный деструктор
    virtual ~EquilateralTriangle() {}
};

class TriangularPrism : public EquilateralTriangle {
private: // Все поля приватные
    double height; // Высота призмы

public:
    // Конструктор
    TriangularPrism(double s, double h) : EquilateralTriangle(s), height(h) {}

    // Метод вычисления объема
    double calculateVolume() const {
        return getArea() * height; // Используем публичный метод родителя
    }

    // Геттер для высоты
    double getHeight() const {
        return height;
    }

    // Переопределенный метод для вывода информации
    void printInfo() const override {
        cout << "Правильная треугольная призма:" << endl;
        cout << "  Сторона основания: " << getSide() << endl; // Используем геттер
        cout << "  Высота призмы: " << height << endl;
        cout << "  Площадь основания: " << getArea() << endl; // Используем геттер
        cout << "  Объем: " << calculateVolume() << endl;
        cout << "----------------------------" << endl;
    }

    // Геттер для объема
    double getVolume() const {
        return calculateVolume();
    }
};

int main() {
    // setlocale(LC_ALL, "Russian"); // Для кириллицы в Windows

    const int N = 4; // Количество треугольников
    const int M = 3; // Количество призм

    // Создаем массивы объектов
    EquilateralTriangle* triangles[N];
    TriangularPrism* prisms[M];

    // Инициализируем треугольники
    triangles[0] = new EquilateralTriangle(5.0);
    triangles[1] = new EquilateralTriangle(3.0);
    triangles[2] = new EquilateralTriangle(7.0);
    triangles[3] = new EquilateralTriangle(4.0);

    // Инициализируем призмы
    prisms[0] = new TriangularPrism(3.0, 10.0);
    prisms[1] = new TriangularPrism(5.0, 6.0);
    prisms[2] = new TriangularPrism(4.0, 15.0);

    // Выводим всю информацию для наглядности
    cout << "*** ВСЕ ТРЕУГОЛЬНИКИ ***" << endl;
    for (int i = 0; i < N; i++) {
        triangles[i]->printInfo();
    }

    cout << "*** ВСЕ ПРИЗМЫ ***" << endl;
    for (int i = 0; i < M; i++) {
        prisms[i]->printInfo();
    }

    // 1. Находим среднюю площадь треугольников
    double totalTriangleArea = 0;
    for (int i = 0; i < N; i++) {
        totalTriangleArea += triangles[i]->getArea();
    }
    double averageTriangleArea = totalTriangleArea / N;

    // 2. Считаем количество треугольников с площадью меньше средней
    int countLessThanAverage = 0;
    for (int i = 0; i < N; i++) {
        if (triangles[i]->getArea() < averageTriangleArea) {
            countLessThanAverage++;
        }
    }

    // 3. Находим призму с максимальным объемом
    int maxVolumeIndex = 0;
    double maxVolume = prisms[0]->getVolume();
    for (int i = 1; i < M; i++) {
        if (prisms[i]->getVolume() > maxVolume) {
            maxVolume = prisms[i]->getVolume();
            maxVolumeIndex = i;
        }
    }

    // Выводим результаты расчетов
    cout << "РЕЗУЛЬТАТЫ РАСЧЕТОВ:" << endl;
    cout << "Средняя площадь треугольников: " << averageTriangleArea << endl;
    cout << "Количество треугольников с площадью меньше средней: " << countLessThanAverage << endl;
    cout << "Призма с наибольшим объемом:" << endl;
    prisms[maxVolumeIndex]->printInfo();

    // Освобождаем память
    for (int i = 0; i < N; i++) {
        delete triangles[i];
    }
    for (int i = 0; i < M; i++) {
        delete prisms[i];
    }

    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

class EquilateralTriangle {
private:
    double side;

public:
    EquilateralTriangle(double s) : side(s) {}

    // Метод расчета площади (будет перегружен в наследнике)
    virtual double calculateArea() const {
        return (sqrt(3) / 4) * side * side;
    }

    double calculatePerimeter() const {
        return 3 * side;
    }

    double calculateHeight() const {
        return (sqrt(3) / 2) * side;
    }

    // Геттер для стороны
    double getSide() const {
        return side;
    }

    // Виртуальный метод для вывода информации (будет перегружен)
    virtual void printInfo() const {
        cout << "Равносторонний треугольник:" << endl;
        cout << "  Сторона: " << side << endl;
        cout << "  Периметр: " << calculatePerimeter() << endl;
        cout << "  Площадь: " << calculateArea() << endl;
        cout << "  Высота: " << calculateHeight() << endl;
        cout << "----------------------------" << endl;
    }

    virtual ~EquilateralTriangle() {}
};

class TriangularPrism : public EquilateralTriangle {
private:
    double height;

public:
    TriangularPrism(double s, double h) : EquilateralTriangle(s), height(h) {}

    // ПЕРЕГРУЗКА метода расчета площади
    // Теперь считает полную площадь поверхности призмы
    double calculateArea() const override {
        // Полная площадь = 2 * площадь основания + площадь боковой поверхности
        double baseArea = EquilateralTriangle::calculateArea(); // площадь треугольника
        double lateralArea = calculatePerimeter() * height;     // периметр * высоту
        return 2 * baseArea + lateralArea;
    }

    // Новый метод - объем призмы
    double calculateVolume() const {
        return EquilateralTriangle::calculateArea() * height;
    }

    // ПЕРЕГРУЗКА метода вывода информации
    void printInfo() const override {
        cout << "Правильная треугольная призма:" << endl;
        cout << "  Сторона основания: " << getSide() << endl;
        cout << "  Высота призмы: " << height << endl;
        cout << "  Площадь основания: " << EquilateralTriangle::calculateArea() << endl;
        cout << "  Полная площадь: " << calculateArea() << endl; // перегруженный метод
        cout << "  Объем: " << calculateVolume() << endl;
        cout << "----------------------------" << endl;
    }

    // Геттер для объема
    double getVolume() const {
        return calculateVolume();
    }

    // Геттер для высоты
    double getHeight() const {
        return height;
    }
};

int main() {
    const int N = 3;
    const int M = 2;

    // Создаем массивы объектов
    EquilateralTriangle* triangles[N];
    TriangularPrism* prisms[M];

    // Инициализируем треугольники
    triangles[0] = new EquilateralTriangle(5.0);
    triangles[1] = new EquilateralTriangle(3.0);
    triangles[2] = new EquilateralTriangle(4.0);

    // Инициализируем призмы
    prisms[0] = new TriangularPrism(3.0, 8.0);
    prisms[1] = new TriangularPrism(4.0, 12.0);

    // Демонстрация полиморфизма через массив указателей на базовый класс
    EquilateralTriangle* figures[5];
    figures[0] = new EquilateralTriangle(6.0);
    figures[1] = new TriangularPrism(5.0, 10.0); // Призма, но через указатель на треугольник!
    figures[2] = new EquilateralTriangle(7.0);
    figures[3] = new TriangularPrism(2.0, 6.0);  // Еще призма
    figures[4] = new EquilateralTriangle(3.0);

    cout << "=== ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА ===" << endl;
    cout << "Вызов перегруженных методов через указатели на базовый класс:" << endl;
    for (int i = 0; i < 5; i++) {
        figures[i]->printInfo(); // Для призм вызовется перегруженная версия!
    }

    // Расчеты по заданию
    cout << "=== РЕЗУЛЬТАТЫ РАСЧЕТОВ ===" << endl;
    
    // 1. Средняя площадь треугольников (только обычных треугольников)
    double totalTriangleArea = 0;
    for (int i = 0; i < N; i++) {
        totalTriangleArea += triangles[i]->calculateArea();
    }
    double averageTriangleArea = totalTriangleArea / N;

    // 2. Количество треугольников с площадью меньше средней
    int countLessThanAverage = 0;
    for (int i = 0; i < N; i++) {
        if (triangles[i]->calculateArea() < averageTriangleArea) {
            countLessThanAverage++;
        }
    }

    // 3. Призма с максимальным объемом
    int maxVolumeIndex = 0;
    double maxVolume = prisms[0]->getVolume();
    for (int i = 1; i < M; i++) {
        if (prisms[i]->getVolume() > maxVolume) {
            maxVolume = prisms[i]->getVolume();
            maxVolumeIndex = i;
        }
    }

    // Вывод результатов
    cout << "Средняя площадь треугольников: " << averageTriangleArea << endl;
    cout << "Количество треугольников с площадью меньше средней: " << countLessThanAverage << endl;
    cout << "Призма с наибольшим объемом:" << endl;
    prisms[maxVolumeIndex]->printInfo();

    // Дополнительно: покажем разницу в расчете площади
    cout << "=== СРАВНЕНИЕ ПЕРЕГРУЖЕННЫХ МЕТОДОВ ===" << endl;
    EquilateralTriangle triangle(4.0);
    TriangularPrism prism(4.0, 10.0);
    
    cout << "Площадь треугольника: " << triangle.calculateArea() << endl;
    cout << "Полная площадь призмы: " << prism.calculateArea() << endl;
    cout << "Площадь основания призмы: " << prism.EquilateralTriangle::calculateArea() << endl;

    // Освобождение памяти
    for (int i = 0; i < N; i++) delete triangles[i];
    for (int i = 0; i < M; i++) delete prisms[i];
    for (int i = 0; i < 5; i++) delete figures[i];

    return 0;
}

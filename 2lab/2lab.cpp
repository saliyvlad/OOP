#include <iostream>
#include <cmath>
using namespace std;

class EquilateralTriangle {
protected:
    double side; // Длина стороны

public:
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

    
    virtual void printInfo() const {
        cout << "Равносторонний треугольник:" << endl;
        cout << "  Сторона: " << side << endl;
        cout << "  Периметр: " << calculatePerimeter() << endl;
        cout << "  Площадь: " << calculateArea() << endl;
        cout << "  Высота: " << calculateHeight() << endl;
        cout << "----------------------------" << endl;
    }

    
    double getArea() const {
        return calculateArea();
    }

    
    virtual ~EquilateralTriangle() {}
};


class TriangularPrism : public EquilateralTriangle {
private:
    double height; // Высота призмы

public:

    TriangularPrism(double s, double h) : EquilateralTriangle(s), height(h) {}

    
    double calculateVolume() const {
        return calculateArea() * height;
    }

    
    void printInfo() const override {
        cout << "Правильная треугольная призма:" << endl;
        cout << "  Сторона основания: " << side << endl;
        cout << "  Высота призмы: " << height << endl;
        cout << "  Площадь основания: " << calculateArea() << endl;
        cout << "  Объем: " << calculateVolume() << endl;
        cout << "----------------------------" << endl;
    }

    
    double getVolume() const {
        return calculateVolume();
    }
};


int main() {
    

    const int N = 4; // Количество треугольников
    const int M = 3; // Количество призм

    
    EquilateralTriangle* triangles[N];
    TriangularPrism* prisms[M];

    
    triangles[0] = new EquilateralTriangle(5.0);
    triangles[1] = new EquilateralTriangle(3.0);
    triangles[2] = new EquilateralTriangle(7.0);
    triangles[3] = new EquilateralTriangle(4.0);

    
    prisms[0] = new TriangularPrism(3.0, 10.0);
    prisms[1] = new TriangularPrism(5.0, 6.0);
    prisms[2] = new TriangularPrism(4.0, 15.0);

    
    cout << "*** ВСЕ ТРЕУГОЛЬНИКИ ***" << endl;
    for (int i = 0; i < N; i++) {
        triangles[i]->printInfo();
    }

    cout << "*** ВСЕ ПРИЗМЫ ***" << endl;
    for (int i = 0; i < M; i++) {
        prisms[i]->printInfo();
    }

    
    double totalTriangleArea = 0;
    for (int i = 0; i < N; i++) {
        totalTriangleArea += triangles[i]->getArea();
    }
    double averageTriangleArea = totalTriangleArea / N;

    
    int countLessThanAverage = 0;
    for (int i = 0; i < N; i++) {
        if (triangles[i]->getArea() < averageTriangleArea) {
            countLessThanAverage++;
        }
    }

    
    int maxVolumeIndex = 0;
    double maxVolume = prisms[0]->getVolume();
    for (int i = 1; i < M; i++) {
        if (prisms[i]->getVolume() > maxVolume) {
            maxVolume = prisms[i]->getVolume();
            maxVolumeIndex = i;
        }
    }

    
    cout << "РЕЗУЛЬТАТЫ РАСЧЕТОВ:" << endl;
    cout << "Средняя площадь треугольников: " << averageTriangleArea << endl;
    cout << "Количество треугольников с площадью меньше средней: " << countLessThanAverage << endl;
    cout << "Призма с наибольшим объемом:" << endl;
    prisms[maxVolumeIndex]->printInfo();

    
    for (int i = 0; i < N; i++) {
        delete triangles[i];
    }
    for (int i = 0; i < M; i++) {
        delete prisms[i];
    }

    return 0;
}
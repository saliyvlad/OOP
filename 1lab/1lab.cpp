#include<iostream>
#include<string>

using namespace std;

class PublicCatering {
private:
    string institutionType;  // Тип учреждения (кафе, ресторан и т.д.)
    string kitchenType;      // Тип кухни
    int seatingCapacity;     // Вместимость
    double averageCheck;     // Средний чек

public:

    PublicCatering(string instType, string cuisType, int capacity, double avgCheck) {
        institutionType = instType;
        kitchenType = cuisType;
        seatingCapacity = capacity;
        averageCheck = avgCheck;
    }

    void outputInfo() {
        cout << "Тип учреждения: " << institutionType << endl;
        cout << "Тип кухни: " << kitchenType << endl;
        cout << "Вместимость: " << seatingCapacity << " человек" << endl;
        cout << "Средний чек: " << averageCheck << " руб." << endl;
        cout << "----------------------------------------" << endl;
    }

    string getInstitutionType() {
        return institutionType;
    }

    string getCuisineType() {
        return kitchenType;
    }

    int getSeatingCapacity() {
        return seatingCapacity;
    }

    double getAverageCheck() {
        return averageCheck;
    }

    void setInstitutionType(string instType) {
        institutionType = instType;
    }

    void setKitchenType(string kitchType) {
        kitchenType = kitchType;
    }

    void setSeatingCapacity(int capacity) {
        seatingCapacity = capacity;
    }

    void setAverageCheck(double avgCheck) {
        averageCheck = avgCheck;
    }
};

int main() {
    
    PublicCatering cafe("Кафе", "Китайская", 50, 1200.0);
    PublicCatering *restaurant = new PublicCatering("Ресторан", "Итальянская", 100, 2500.0);

    cout << "=== Исходные данные ===" << endl;
    cafe.outputInfo();
    restaurant->outputInfo();

    
    cafe.setAverageCheck(1500.0);
    cafe.setSeatingCapacity(60);
    
    restaurant->setKitchenType("Французская");
    restaurant->setAverageCheck(3000.0);

    cout << "=== После изменений ===" << endl;
    cafe.outputInfo();
    restaurant->outputInfo();

    
    cout << "=== Дополнительная информация ===" << endl;
    cout << "Тип кафе: " << cafe.getInstitutionType() << endl;
    cout << "Вместимость ресторана: " << restaurant->getSeatingCapacity() << " человек" << endl;
    cout << "Средний чек в ресторане: " << restaurant->getAverageCheck() << " руб." << endl;

    
    return 0;
}
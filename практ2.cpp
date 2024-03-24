#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <iomanip>

class Time {
private:
    std::chrono::time_point<std::chrono::system_clock> start_time;

public:
    Time(std::chrono::system_clock::time_point initial_time) : start_time(initial_time) {
    }

    ~Time() {
        auto end_time = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        std::cout << "Час, що пройшов з моменту створення об'єкта: " << duration << " мс" << std::endl;
    }
    //Функція, що обчислює гіпотенузу за теормою Піфагора
    void PythagoreanTheorem() {
        double a, b;
        std::cout << "Введіть значення катета a: ";
        std::cin >> a;
        std::cout << "Введіть значення катета b: ";
        std::cin >> b;

        double c = std::sqrt(a * a + b * b);
        //обмеження до 2 знаків після коми
        std::cout << std::fixed << std::setprecision(2) << "Гіпотенуза за теоремою Піфагора: " << c << std::endl;
    }
};

int main() {
    std::chrono::system_clock::time_point initial_time = std::chrono::system_clock::now();
    {
        Time timer(initial_time);// Виклик функцій
        timer.PythagoreanTheorem();
    }

    return 0;
}

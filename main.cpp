#include <iostream>
#include <cmath>
#include <windows.h>
#include <limits>
#include <numeric>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    /* Проверка ввода данных (справочно)
    while(true)
    {
        float value; // попробуйте разные типы данных
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Ошибка ввода данных\n";

            // Данные две строки необходимы для очистки буфера ввода, без них, при последующем вводе данных, произойдёт зацикливание:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Если нужно прервать программу:
            // return 1; // выход из функции main, соответственно и из программы
            // exit(1); // а так можно выйти из программы в любом месте
            // цифры - это номера ошибок передаваемые программой в ОС,
            // 0 - всё хорошо, не 0 - какой-то код, который разработчик устанавливает сам...
        }
        else
            std::cout << value << '\n';
    }

    return 0;
     */
    float x;
    float d;
    float dmax;
    float xmax;
    float xmin;
    while (true) {
        xmin=0.0f;
        x=0.0f;
        d=10.0f;
        std::cout<<"Аналитическое исследование функции показывает, что \n";
        std::cout<<"функция отрицательна на отрезке -1+sqrt(3)..4 и  \n";
        std::cout<<"функция убывающая на отрезке 0..-1+sqrt(3) \n";
        std::cout<<"Введите максимально допустимый уровень опасности (>0): ";
        xmax=-1.0f+sqrt(3.0f);
        std::cin>>dmax;
        if (dmax<0 || std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Ошибка ввода данных\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            while (fabs((d-dmax))>0.001) {
                x = (xmax+xmin) / 2.0f;
                d = x * x * x - 3.0f * x * x - 12.0f * x + 10.0f;
                if (d>dmax) {
                    xmin=x;
                } else {
                    xmax=x;
                }
                std::cout<<x<<"\n";
            }
            std::cout<<"Приблизительная глубина безопасной кладки: "<<x<<"\n";
        }

    }
}
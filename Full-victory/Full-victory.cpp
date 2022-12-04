// 14. Полная победа. Армия сопротивления захватывает города (всего надо захватить 20 городов).
// После захвата каждого города во все города, принадлежащие армии сопротивления, рассылается часть
// секретного шифра, найденная во вновь захваченном городе, через столицу (первый город). 
// Необходимо получить в каждом городе полный шифр.

#include <iostream>
#include <mpi.h>
#include <vector>

const int CITY_AMOUNT = 20;

class City {
private:
    char code[6];
    char character;

public:
    City() {        
        for (int i = 0; i < sizeof(code); i++)
        {
            character = 97 + rand() % 25;
            code[i] = character;
        }
    }
    ~City() { }

    char* get_code() {
        return code;
    }
    void recieve_code() {

    }
};

int main()
{
    srand(time(0));
    std::vector<City*> sities;

    for (int i = 0; i < CITY_AMOUNT; i++)
    {
        sities.push_back(new City());
    }

    for (int j = 0; j < CITY_AMOUNT; j++)
    {
        for (int i = 0; i < sizeof(sities[j]->get_code()) - 2; i++)
        {
            std::cout << sities[j]->get_code()[i];
        }
        std::cout << "\n\n";
    }

}


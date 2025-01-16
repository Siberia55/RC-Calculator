// RC-Calculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string.h>
#include <math.h>

using namespace std;

float Csnub{}, Rsnub{}, Iload{}, dVdt_max{}, Lload{}, V_Load_max{}, F{}, cap{}, Wres{};
string SI{};

float CalcCapacitor(float Iload, float dVdt_max)
{
    Csnub = Iload / (dVdt_max * 1000000);
    Csnub *= pow(10, 3);
      return Csnub;
}
float CalcResistor(float Lload, float Csnub)
{
    if (SI=="uH")
    {
        Lload *= pow(10, -6);
    }
    if (SI=="mH")
    {
        Lload *= pow(10, -3);
    }
    Rsnub = sqrt(Lload / Csnub);
    return Rsnub;
}
float CalcWres(float V_Load_max, float F, float Csnub)
{
    Wres = (0.5 * Csnub) * (V_Load_max * V_Load_max) * F ;
    return Wres;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int funConsole();
    {
        //ввод/вывод данных
        while (true)
        {
            cin >> SI;
            if (SI == "uH" || SI == "mH")
                break;
            else {
                cout << "не корректный ввод единиц измерения\n"; //return false;
            }

        }
        cout << "ведите по очереди или через пробел: рабочее напряжене (V), ток нагрузки(Imax)\n";
        cin >> V_Load_max;
        cin >> Iload;
        cout << "Vmax = " << V_Load_max << " V\n";
        cout << "Iload = " << Iload << " A\n";
        cout << "введите значения индуктивности нагрузки "/*и единици измерения(uH, mH)"*/;
        cin >> Lload;
        cout << "введите единици измерения (uH или mH)"; 
 /*       while (true)
        {
            cin >> SI;
            if (SI == "uH" || SI == "mH")
                break;
            else {
                cout << "не корректный ввод единиц измерения\n"; //return false;
            }

        }*/
        cout << "Lload = " << Lload << "uH\n";
        cout << "выедите dV/dt (v/uS) (см. datasheet)";
        cin >> dVdt_max;
        cout << "dV/dt = " << dVdt_max << "V/uS\n";
        cout << "введите частоту переключения (Hz)";
        cin >> F;
        cout << "F = " << F << "Hz\n";
            
        
    }
    CalcCapacitor(Iload, dVdt_max);
    CalcResistor(Lload, Csnub);
    CalcWres(V_Load_max, F, Csnub);
   
        cout << "емкость конденсатора снаббера = " << Csnub << SI <<"\n";
        cout << "сопративление резистора снаббера = " << Rsnub <<" Ohm\n";
        cout << "мощность резистора снаббера = " << Wres << " W\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

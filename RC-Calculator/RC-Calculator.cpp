// RC-Calculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<string.h>
#include <math.h>
#include <limits.h>


using namespace std;

float Csnub{}, Rsnub{}, Iload{}, dVdt_max{}, Lload{}, V_Load_max{}, F{}, Ccap{}, Wres{};

string SIInduction,  SICap{};

static float CalcCapacitor(float Iload, float dVdt_max)
{
    Csnub = Iload / (dVdt_max * 1000000);// (dVdt_max * 1000000) перевод из микросекунд в секунды
      
    return Csnub; 
}
static float CalcResistor(float Lload, float Csnub, string SIInduction)
{
    if (SIInduction=="uH")
    {
        Lload *= (1*pow(10, -6));
    }
    if (SIInduction=="mH")
    {
        Lload *=(1* pow(10, -3));
    }
    Rsnub = sqrt(Lload / Csnub);
    return Rsnub;
}
static float CalcWres(float V_Load_max, float F, float Csnub)
{
    Wres = (Csnub/2) * pow(V_Load_max,2) * F ;
    return Wres;
}

static string setvariable(float Csnub, float &Ccap)
{
    if ((Csnub >= (1 * pow(10, -7))) && (Csnub <= (1 * pow(10, -2))))
    {
        SICap = "uF";
        Ccap = Csnub * pow(10, 6);
    }
    else if ((Csnub >= (1 * pow(10, -10))) && (Csnub <= (1 * pow(10, -5))))
    {
        SICap = "nF";
        Ccap = Csnub * pow(10, 9);
    }
    else if ((Csnub >= (1 * pow(10, -13))) && (Csnub <= (1 * pow(10, -8))))
    {
        SICap = "pF";
        Ccap = Csnub * pow(10, 12);
    }
    else
    SICap = "not unit";

    return SICap;
}

int main()
{
 
    setlocale(LC_ALL, "Russian");

    while (true)
    {
            
        
        int funConsole();
        {
            //cout << "ведите по очереди или через пробел: рабочее напряжене (в V), ток (Imax, А)\n";

            while (true)
            {
                cout << "ведите по очереди или через пробел: рабочее напряжене (в V), ток (Imax, А)\n";
                cin >> V_Load_max >> Iload;
                if (cin.fail())//функция проверки на ошибки ввода
                {
                    cin.clear();//сброс состояния ошибки
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//очистка буффера
                    cout << "УПС! НЕ КОРРЕКТНЫЙ ВВОД!ПОВТОРИТЕ СНАЧАЛА!\n";

                }
                else {
                    cout << "введите частоту переключения в Гц\n";
                    cin >> F;

                    if (cin.fail())
                    {

                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "УПС! НЕ КОРРЕКТНЫЙ ВВОД!ПОВТОРИТЕ СНАЧАЛА!\n";

                    }
                    else {
                        cout << "введите dV/dt (v/uS) (см. datasheet симистора)\n";
                        cin >> dVdt_max;

                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "ОЙ! НЕ КОРРЕКТНЫЙ ВВОД!ПОВТОРИТЕ СНАЧАЛА!\n";

                        }
                        else {
                            cout << "dV/dt = " << dVdt_max << " V/uS\n" << "введите значение индуктивности\n";
                            cin >> Lload;

                            if (cin.fail())
                            {
                                cin.clear();
                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                cout << "ОЙ! НЕ КОРРЕКТНЫЙ ВВОД!ПОВТОРИТЕ СНАЧАЛА!\n";

                            }
                            else
                            {
                                cout << "L= " << Lload << "\n";

                                if (cin.fail())
                                {
                                    cin.clear(); 
                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cout << "УПС! НЕ КОРРЕКТНЫЙ ВВОД!ПОВТОРИТЕ СНАЧАЛА!\n";

                                }
                                else
                                {
                                    cout << "введите единици измерения индуктивности (uH или mH)\n";
                                    while (true)
                                    {
                                        cin >> SIInduction;
                                        if (SIInduction == "uH" || SIInduction == "mH")
                                            break;
                                        else {
                                            cout << "не корректный ввод единиц измерения\n";
                                        }

                                    }


                                    break;
                                }
                            }
                        }
                    }
                }


            }

        }


        CalcCapacitor(Iload, dVdt_max);
        CalcResistor(Lload, Csnub, SIInduction);
        CalcWres(V_Load_max, F, Csnub);
        
        setvariable(Csnub, Ccap);

        cout << "емкость конденсатора снаббера = " << Csnub << "  " <<Ccap << SICap << "\n";
        cout << "сопротивление резистора снаббера = " << Rsnub << " Ohm\n";
        cout << "мощность резистора снаббера = " << Wres << " W\n";
        cout << "Повторить расчет? Да - 'y', Нет - 'n'\n";

       
        while (true)
        {
            char action{};
            if (cin >> action)
                 
                if (action == 'y')
                {
                    break;
                }
                else if (action == 'n')
                {
                   return false;
                }
                else if ((action != 'y') && (action != 'n'))
                    while (true)
                    {
                        cout << "НЕ КОРРЕКТНЫЙ ВВОД!\n";
                        break;
                    }

        }
    }
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

#include <iostream>
#include <string>
#include <fstream>

#include "src/complex.hpp"

using namespace std;

int main()
{
    // Блок зчитування данних з файлу
    int Real1, Real2, Imag1, Imag2;
    string path = "Data.txt";
    fstream file;
    file.open(path, fstream::app|fstream::in|fstream::out);

    if (file.is_open()) // якщо файл відкритий
    {
        int i = 0;
        string msg= "", msg2, Real_str, Imag_str;
        string arr_Real[2], arr_Imag[2];

        while (!file.eof()) // Поки не кінець файлу
        {
            file>>msg;
            msg2=msg;
            int j = msg.find_first_of(':'); // Розділяєм строку на перше число і друге, які розділені двокрапкою
            Real_str += msg.erase(j,msg.length()); // Записуємо в стрінг перше число
            Imag_str += msg2.erase(0,j+1); // Записуємо в стрінг 2 число

            arr_Real[i] = Real_str; // Перезаписуємо в масив
            arr_Imag[i] = Imag_str;

            msg = ""; // Обнуляємо змінні для наступного проходу
            Real_str = "";
            Imag_str = "";
            i++;
        }
        int arr_Real_db[2], arr_Imag_db[2];

        for ( int j = 0; j < 2; j++ )
        {
            arr_Real_db[j]=atoi(arr_Real[j].c_str()); // Перетворюємо str в int
            arr_Imag_db[j]=atoi(arr_Imag[j].c_str());
        }
        Real1 = arr_Real_db[0];
        Real2 = arr_Real_db[1];
        Imag1 = arr_Imag_db[0];
        Imag2 = arr_Imag_db[1];
    }
    else
    {
        cout << "Немає доступу до файлу!" <<endl;
    }
    cout << "Sum: " <<endl;
    cout << Complex(Real1, Imag1) + Complex(Real2, Imag2) << "\n";
    cout << "Subtraction: " <<endl;
    cout << Complex(Real1, Imag1) - Complex(Real2, Imag2) << "\n";
    cout << "Multiply: " <<endl;
    cout << Complex(Real1, Imag1) * Complex(Real2, Imag2) << "\n";
    cout << "Divide: " <<endl;
    cout << Complex(Real1, Imag1) / Complex(Real2, Imag2) << "\n";
    return 0;
}

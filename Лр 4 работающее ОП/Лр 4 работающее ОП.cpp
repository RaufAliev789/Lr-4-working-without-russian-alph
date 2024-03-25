/* Дана строка. Слово есть любая
последовательность букв,
разделенных пробелом. Удалить в
этой строке все слова,
начинающиеся на заданную букву без
учета регистра этой буквы. */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    string stroka;
    string res = "";
    char pred = ' ';
    bool add = false;
    cout << "Введите строку: " << endl;
    getline(cin, stroka);
    cout << "Введите букву, благодаря которой исчезнут слова, начинающиеся с этой буквы: ";
    char letter;
    cin >> letter;

    for (int i = 0; i < stroka.size(); i++)
    {
        if (pred == ' ')
        {
            bool isletter = false;
            if (tolower(stroka[i]) == tolower(letter))
            {
                isletter = true;
            }
            if (!isletter)
            {
                add = true;
            }
            else
            {
                add = false;
            }
        }
        if (add)
        {
            res += stroka[i];
        }
        pred = res[i];
    }
    cout << res;

    return 0;
}

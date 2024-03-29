/* Дана строка. Слово есть любая
последовательность букв,
разделенных пробелом. Удалить в
этой строке все слова,
начинающиеся на заданную букву без
учета регистра этой буквы. */

#include <iostream>
#include <string>

char toLowerFunc(char symbol)
{
    if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= 'А' && symbol <= 'Я'))
    {
        symbol += 32;
    }
    return symbol;
}

int main()
{
    setlocale(LC_ALL, "ru");

    std::string stroka;
    std::string res = "";
    char pred = ' ';
    bool add = false;

    std::cout << "Введите строку: " << std::endl;
    std::getline(std::cin, stroka);

    std::cout << "Введите букву, на основе которой будут удаляться слова: ";
    char letter;
    std::cin >> letter;

    char lower = toLowerFunc(letter);

    for (int i = 0; i < stroka.size(); i++)
    {
        if (pred == ' ' && toLowerFunc(stroka[i]) == lower)
        {
            add = false;
        }
        else if (stroka[i] == ' ')
        {
            add = true;
        }

        if (add)
        {
            res += stroka[i];
        }
        pred = stroka[i];
    }
    std::cout << res;

    return 0;
}
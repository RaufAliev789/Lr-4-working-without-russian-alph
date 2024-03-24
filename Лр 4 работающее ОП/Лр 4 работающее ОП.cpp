#include <iostream>
#include <string>

std::string Remove_words(std::string stroka, char letter) {
    setlocale(LC_ALL, "ru");
    int i = 0;
    while (i < stroka.size()) {
        if ((stroka[i] == letter) || (stroka[i] == letter + 32) || (stroka[i] == letter - 32)) {
            int j = i;
            while ((i < stroka.size()) && stroka[i] != ' ') {
                i++;
            }
            stroka.erase(j, i - j);
            i = j; // Обновляем индекс после удаления слова
        }
        else {
            i++;
        }
    }

    return stroka;
}

int main() {
    setlocale(LC_ALL, "ru");

    char letter;
    std::string stroka;

    std::cout << "Введите строку: " << std::endl;
    std::getline(std::cin, stroka);

    std::cout << "Введите букву, благодаря которой исчезнут слова, начинающиеся с нее: " << std::endl;
    std::cin >> letter;

    std::string result = Remove_words(stroka, letter);
    std::cout << "Слова без буквы " << letter << " : " << result << std::endl;

    return 0;
}
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::string name; // Инициальзируем переменную name типа string
    std::cout << "Input user_name"; // Просим ввести имя пользователя
    std::cin >> name; // Запрашиваем значение переменной name из потока ввода вывода
    std::cout << "Hello world from " << name << std::endl; // Выводим преветствие
    return 0;
}


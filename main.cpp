#include <iostream>
#include <windows.h>

std::string input(std::string promt) {
    std::string value;
    std::cout << promt;
    std::getline(std::cin, value);
    return value;

}
void print(std::string promt) {
    std::cout << promt;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    std::string pass;
    while (true) {
        pass = input("Ваш пароль:");
        // print("Вы ввели: " + pass);
        if (pass.empty()) {
            print("Вы ничего не ввели!\n");
            continue;
        }

        break;
    }
    print("Вы ввели: " + pass);
    return 0;
}
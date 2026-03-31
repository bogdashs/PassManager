#include <fstream>
#include <iostream>
#include <windows.h>

std::string input(std::string promt) {
    std::string value;
    std::cout << promt;
    std::getline(std::cin, value);
    return value;

}
void print(std::string promt) {
    std::cout << promt << std::endl;
}

void showmenu() {
    print("[+] ==== PASS MANAGER ====");
    print("[+] 1.Записать новый пароль");
    print("[+] 2.Изменить пароль");
    print("[+] 3.Посмотреть пароль");
    print("[+] 4.Выход");
}

std::string enc(std::string data,char key) {

    std::string output = data;

    for (int i = 0; i < output.size(); i++) {
        output[i] = data[i] ^ key;
    }

    return output;
}

void add_to_db(std::string name,std::string pass) {
    std::ofstream file("database.txt",std::ios::app);
    if (file.is_open()) {
        char key = 35;
        std::string ENCpass = enc(pass,key);

        file << name << "\n";
        file << ENCpass << "\n";
        file.close();
        print("Данные успешно сохраненны!");
    } else {
        print("Проверьте состояние database.txt !");
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    std::string pass;
    std::string name;
    std::string choice;
    while (true) {

        showmenu();

        choice = input("Выберите действие: ");

        if (choice == "1") {
            name = input("Название соцсети: ");
            pass = input("Ваш пароль: ");

            if (pass.empty() || name.empty()) {
                print("Вы ничего не ввели!");
                continue;
            }
        }


        print("Успешно сохранено! ");
        break;
    }
    // print("Вы ввели: " + name);
    // print("Вы ввели: " + pass);
    // std::string ENCpass = enc(pass,35);
    // print("Enc: " + ENCpass);
    // std::string DECpass = enc(ENCpass,35);
    // print("Dec " + DECpass);
    add_to_db(name,pass);

    return 0;
}
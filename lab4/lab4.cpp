#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

// Банк
class Bank {
public:
    string name;
    int MFO;

    Bank(string name, int MFO) {
        this->name = name;
        this->MFO = MFO;
    }
};

// клас Клієнт
class Client : public Bank {
public:
    string accountNumber;
    string firstName;
    string lastName;

    Client(string accountNumber, string firstName, string lastName, Bank* bank) : Bank(bank->name, bank->MFO) {
        this->accountNumber = accountNumber;
        this->firstName = firstName;
        this->lastName = lastName;
    }

    void printStatement() {
        SetConsoleOutputCP(1251);

        cout << "**Виписка з рахунку**" << endl;
        cout << "Банк: " << name << endl;
        cout << "МФО: " << MFO << endl;
        cout << "Номер рахунку: " << accountNumber << endl;
        cout << "Ім'я та прізвище: " << firstName << " " << lastName << endl;
    }
};

int main() {
    SetConsoleOutputCP(1251);

    bool continueLoop = true;
    while (continueLoop) {
        string bankName;
        cout << "Введіть назву банку: ";
        cin >> bankName;

        Bank* bank;
        if (bankName == "Monobank") {
            bank = new Bank("Monobank", 305470);
        }
        else if (bankName == "Privat24") {
            bank = new Bank("Privat24", 305299);
        }
        else if (bankName == "PUMB") {
            bank = new Bank("PUMB", 334851);
        }
        else {
            cout << "Невідомий банк!" << endl;
            continue;
        }

        // введення інформації про клієнта
        string accountNumber;
        string firstName;
        string lastName;
        cout << "Введіть номер рахунку: ";
        cin >> accountNumber;
        cout << "Введіть ім'я: ";
        cin >> firstName;
        cout << "Введіть прізвище: ";
        cin >> lastName;

        // створення об'єкта клієнта
        Client client(accountNumber, firstName, lastName, bank);

        // виписка з рахунку
        client.printStatement();

        // звільнення пам'яті для об'єкта 
        delete bank;

        // запит на зміну банку
        char choice;
        cout << "Ви дійсно хочете змінити банк? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            continueLoop = false;
        }
    }

    return 0;
}

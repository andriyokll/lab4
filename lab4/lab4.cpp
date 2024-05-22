#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

// ����
class Bank {
public:
    string name;
    int MFO;

    Bank(string name, int MFO) {
        this->name = name;
        this->MFO = MFO;
    }
};

// ���� �볺��
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

        cout << "**������� � �������**" << endl;
        cout << "����: " << name << endl;
        cout << "���: " << MFO << endl;
        cout << "����� �������: " << accountNumber << endl;
        cout << "��'� �� �������: " << firstName << " " << lastName << endl;
    }
};

int main() {
    SetConsoleOutputCP(1251);

    bool continueLoop = true;
    while (continueLoop) {
        string bankName;
        cout << "������ ����� �����: ";
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
            cout << "�������� ����!" << endl;
            continue;
        }

        // �������� ���������� ��� �볺���
        string accountNumber;
        string firstName;
        string lastName;
        cout << "������ ����� �������: ";
        cin >> accountNumber;
        cout << "������ ��'�: ";
        cin >> firstName;
        cout << "������ �������: ";
        cin >> lastName;

        // ��������� ��'���� �볺���
        Client client(accountNumber, firstName, lastName, bank);

        // ������� � �������
        client.printStatement();

        // ��������� ���'�� ��� ��'���� 
        delete bank;

        // ����� �� ���� �����
        char choice;
        cout << "�� ����� ������ ������ ����? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            continueLoop = false;
        }
    }

    return 0;
}

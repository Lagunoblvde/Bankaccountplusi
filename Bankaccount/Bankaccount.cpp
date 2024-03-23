// Bankaccount.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdexcept>
#include <Windows.h>
#pragma execution_character_set("utf-8")

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
   
    BankAccount(int accNumber, double initialBalance, double intRate) {
        accountNumber = accNumber;
        balance = initialBalance;
        interestRate = intRate;
    }

    
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Депозит на сумму " << amount << " выполнен успешно.\n";
        }
        else {
            std::cout << "Ошибка: сумма депозита должна быть положительной.\n";
        }
    }

  
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Снятие на сумму " << amount << " выполнено успешно.\n";
        }
        else {
            std::cout << "Ошибка: недостаточно средств на счете.\n";
        }
    }

    
    double getBalance() {
        return balance;
    }

    
    double getInterest() {
        return balance * interestRate * (1.0 / 12.0);
    }

    
    void setInterestRate(double newRate) {
        interestRate = newRate;
    }

    
    int getAccountNumber() {
        return accountNumber;
    }

    
    friend bool transfer(BankAccount& fromAccount, BankAccount& toAccount, double amount);
};


bool transfer(BankAccount& fromAccount, BankAccount& toAccount, double amount) {
    if (amount > 0 && amount <= fromAccount.balance) {
        fromAccount.balance -= amount;
        toAccount.balance += amount;
        std::cout << "Перевод на сумму " << amount << " выполнен успешно.\n";
        return true;
    }
    else {
        std::cout << "Ошибка: недостаточно средств на счете для перевода.\n";
        return false;
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    BankAccount account1(12345, 1000.0, 0.05);
    BankAccount account2(54321, 2000.0, 0.05);

    std::cout << "Текущий баланс на счете 1: " << account1.getBalance() << std::endl;
    std::cout << "Текущий баланс на счете 2: " << account2.getBalance() << std::endl;

    
    transfer(account1, account2, 500.0);

    std::cout << "Текущий баланс на счете 1 после перевода: " << account1.getBalance() << std::endl;
    std::cout << "Текущий баланс на счете 2 после перевода: " << account2.getBalance() << std::endl;

    return 0;
}

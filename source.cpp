#include <iostream>
#include <string>

using namespace std;

struct Game {
    string name;
    double price;
    int stock;
};

const int n = 10;
Game games[n];
int gameCount = 0;

void add(string name, double price, int stock) {
    if (gameCount < n) {
        games[gameCount].name = name;
        games[gameCount].price = price;
        games[gameCount].stock = stock;
        gameCount++;
    } else {
        cout << "The store capacity is full." << endl;
    }
}

void remove(string name) {
    for (int i = 0; i < gameCount; ++i) {
        if (games[i].name == name) {
            for (int j = i; j < gameCount - 1; ++j) {
                games[j] = games[j + 1];
            }
            gameCount--;
            return;
        }
    }
    cout << "The specified game was not found." << endl;
}

void search(string name) {
    for (int i = 0; i < gameCount; ++i) {
        if (games[i].name == name) {
            cout << "Game name: " << games[i].name << ", Price: " << games[i].price << ", Stock: " << games[i].stock << endl;
            return;
        }
    }
    cout << "The specified game was not found." << endl;
}

void displayall() {
    for (int i = 0; i < gameCount; ++i) {
        cout << "Game name: " << games[i].name << ", Price: " << games[i].price << ", Stock: " << games[i].stock << endl;
    }
}

double calcvalue() {
    double totalValue = 0;
    for (int i = 0; i < gameCount; ++i) {
        totalValue += games[i].price * games[i].stock;
    }
    return totalValue;
}

void menu() {
    while (true) {
        cout << "-------------------------" << endl;
        cout << "1. Add Game" << endl;
        cout << "2. Remove Game" << endl;
        cout << "3. Search Game" << endl;
        cout << "4. Display All Games" << endl;
        cout << "5. Calculate Total Value" << endl;
        cout << "6. Exit" << endl;
        
        int choice;
        cin >> choice;

        string name;
        double price;
        int stock;
        
        switch (choice) {
            case 1:
                cout << "Game name: ";
                cin >> name;
                cout << "Price: ";
                cin >> price;
                cout << "Stock: ";
                cin >> stock;
                add(name, price, stock);
                break;
            case 2:
                cout << "Game name: ";
                cin >> name;
                remove(name);
                break;
            case 3:
                cout << "Game name: ";
                cin >> name;
                search(name);
                break;
            case 4:
                displayall();
                break;
            case 5:
                cout << "Total value of games: " << calcvalue() << endl;
                break;
            case 6:
                return;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}

int main() {
    menu();
    return 0;
}
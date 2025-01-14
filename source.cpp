#include <iostream>
#include <string>

using namespace std;

struct Game {
    string name;
    double price;
    int stock;
};

const int n = 10;
Game* games = new Game[n];
int gameCount = 0;

void add(const string& name, const double& price, const int& stock) {
    if (gameCount < n) {
        games[gameCount].name = name;
        games[gameCount].price = price;
        games[gameCount].stock = stock;
        gameCount++;
    } else {
        cout << "The store capacity is full." << endl;
    }
}

void remove(const string& name) {
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

void search(const string& name) {
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

string password (const string& pass){
    if (pass == "admin1admin"){
        return "correct";
    }
    else {
        return "wrong";
    }
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

        cin.ignore();

        string name;
        double price;
        int stock;
        
        switch (choice) {
            case 1:
                cout << "Game name: ";
                getline(cin,name);
                cout << "Price: ";
                cin >> price;
                cout << "Stock: ";
                cin >> stock;
                add(name, price, stock);
                break;
            case 2:
                cout << "Game name: ";
                getline(cin,name);
                remove(name);
                break;
            case 3:
                cout << "Game name: ";
                getline(cin,name);
                search(name);
                break;
            case 4:
                displayall();
                break;
            case 5:
                cout << "Total value of games: " << calcvalue() << endl;
                break;
            case 6:
                delete[] games;
                return;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}

int main() {
    int opr;
    string status,pass;
    label1:
    cout << "Select access type:" << endl;
    cout << "1. Adminstrator" << endl << "2. Customer" << endl;
    cin >> opr;
    switch (opr)
    {
    case 1:
        cout << "Please enter the password :" << endl;
        cin >> pass;
        status = password(pass);
        if (status == "correct"){
            //admin_menu();
            goto label1;
        }
        else {
            cout << "Wrong password." << endl << "-------------------------" << endl;
            goto label1;
        } 
        break;
    
    case 2:
        //customer_menu();
        goto label1;
        break;
    default:
        cout << "Please select available choice.";
        break;
    }
    return 0;
}
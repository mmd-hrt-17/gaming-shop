#include <iostream>
#include <string>

using namespace std;

struct Game {
    string name;
    double price;
    int stock;
    string category;
};

const int n = 10;
Game* games = new Game[n];
int gameCount = 0;
string PASSWORD = "admin1admin";

void add(const string& name, const double& price, const int& stock, const string& cat) {
    if (gameCount < n) {
        games[gameCount].name = name;
        games[gameCount].price = price;
        games[gameCount].stock = stock;
        games[gameCount].category = cat;
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

void stockStatus () {
    if (gameCount != 0){
        for (int i = 0; i < gameCount; ++i) {
            cout << "Game name: " << games[i].name << ", Stock: " << games[i].stock << endl;
        }
    }
    else {
        cout << "The stock is empty." << endl;
    }
}

void displayall() {
    if (gameCount != 0){
        for (int i = 0; i < gameCount; ++i) {
            cout << "Game name: " << games[i].name << ", Price: " << games[i].price;
            cout << ", Stock: " << games[i].stock << ", Category: " << games[i].category << endl;
        }
    }
    else{
        cout << "The stock is empty." << endl;
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
    if (pass == PASSWORD){
        return "correct";
    }
    else {
        return "wrong";
    }
}

void changepass (){
    cout << "Your current password: " << PASSWORD << endl;
    cout << "Please enter the new password: " << endl;
    getline(cin,PASSWORD);
    cout << "Your password successfully changed." << endl;
}

int cont (){
    int cmd;
    cout << "If you want to continue, enter (1), otherwise press any number: ";
    cin >> cmd;
    if (cmd == 1){
        return 1;
    }
    else{
        return 2;
    }
}

void admin_menu() {
    while (true) {
        cout << "-------------------------" << endl;
        cout << "(Adminstrator menu)" << endl;
        cout << "1. Add Game" << endl;
        cout << "2. Remove Game" << endl;
        cout << "3. Search Game" << endl;
        cout << "4. Display All Games" << endl;
        cout << "5. Calculate Total Value" << endl;
        cout << "6. Stock Status" << endl;
        cout << "7. Change Password" << endl;
        cout << "8. Exit" << endl;
        
        int choice, command;
        cin >> choice;

        cin.ignore();

        string name;
        double price;
        int stock;
        string category;
        
        switch (choice) {
            case 1:
                label1:
                cout << "Game name: ";
                cin.ignore();
                getline(cin,name);
                cout << "Price: ";
                cin >> price;
                cout << "Stock: ";
                cin >> stock;
                cout << "Category: ";
                cin >> category;
                add(name, price, stock, category);
                command = cont();
                if (command == 1){
                    goto label1;
                }
                else{
                    break;
                }

            case 2:
                label2:
                cout << "Game name: ";
                getline(cin,name);
                remove(name);
                command = cont();
                if (command == 1){
                    goto label2;
                }
                else{
                    break;
                }
            case 3:
                label3:
                cout << "Game name: ";
                getline(cin,name);
                search(name);
                command = cont();
                if (command == 1){
                    goto label3;
                }
                else{
                    break;
                }
            case 4:
                displayall();
                break;
            case 5:
                cout << "Total value of games: " << calcvalue() << endl;
                break;
            case 6:
                cout << "The status of game stock: " << endl ;
                stockStatus(); 
                break;
            case 7:
                changepass();
                break;
            case 8:
                return;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}

void customer_menu() {
    while (true) {
        cout << "-------------------------" << endl;
        cout << "(Customer menu)" << endl;
        cout << "1. Search Game" << endl;
        cout << "2. Display All Games" << endl;
        cout << "3. Stock Status" << endl;
        cout << "4. Exit" << endl;
        
        int choice, command;
        cin >> choice;

        cin.ignore();

        string name;
        double price;
        int stock;
        
        switch (choice) {
            case 1:
                label1:
                cout << "Game name: ";
                getline(cin,name);
                search(name);
                command = cont();
                if (command == 1){
                    goto label1;
                }
                else{
                    break;
                }
            case 2:
                displayall();
                break;
            case 3:
                cout << "The status of game stock: " << endl ;
                stockStatus(); 
                break;
            case 4:
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
    cout << "1. Adminstrator" << endl << "2. Customer" << endl << "3. Turn off" << endl;
    cin >> opr;
    switch (opr)
    {
    case 1:
        cout << "Please enter the password :" << endl;
        cin >> pass;
        status = password(pass);
        if (status == "correct"){
            admin_menu();
            goto label1;
        }
        else {
            cout << "Wrong password." << endl << "-------------------------" << endl;
            goto label1;
        } 
        break;
    
    case 2:
        customer_menu();
        goto label1;
        break;
    case 3:
        return 0;
    default:
        cout << "Please select available choice.";
        break;
    }
}
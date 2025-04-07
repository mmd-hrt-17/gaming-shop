#include <iostream>
#include <string>
#include <vector>
using namespace std;

class game
{
    string name;
    double price;
    int stock;
    string category;

    game(string n, double p, int s, string c)
    {
        name = n;
        price = p;
        stock = s;
        category = c;
    }

};
class item
{
public:
    string name;
    int count;
    double fee;
    item (string n = "", int c = 0, double f = 0.0)
    {
        name = n;
        count = c;
        fee = f;
    }

};
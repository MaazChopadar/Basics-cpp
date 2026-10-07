#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    int productID;
    string productName;
    double price;
    string category;
    int stock;

public:

    Product(int id, string name, double p, string cat, int s)
    {
        productID = id;
        productName = name;
        price = p;
        category = cat;
        stock = s;
    }

    void displayProduct()
    {
        cout << "Product ID: " << productID << endl;
        cout << "Name: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "Category: " << category << endl;
        cout << "Stock: " << stock << endl;
    }
};

int main()
{
    Product p1(101, "Wireless Mouse", 599, "Electronics", 20);

    p1.displayProduct();

    return 0;
}
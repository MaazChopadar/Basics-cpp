

#include <iostream>
#include <string>
using namespace std;

class Product
{
protected:
    int productId;
    string productName;
    float productPrice;

public:
    void getProductDetails()
    {
        cout << "Enter Product ID: ";
        cin >> productId;

        cout << "Enter Product Name: ";
        getline(cin >> ws, productName);

        cout << "Enter Product Price: ";
        cin >> productPrice;
    }

    void displayProductDetails()
    {
        cout << "Product ID: " << productId << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Product Price: " << productPrice << endl;
    }
};

class Electronic : public Product
{
private:
    int warranty;

public:
    void getElectronicDetails()
    {
        getProductDetails();

        cout << "Enter Warranty (years): ";
        cin >> warranty;
    }

    void displayElectronicDetails()
    {
        cout << "\n--- Electronic Product ---" << endl;
        displayProductDetails();
        cout << "Warranty: " << warranty << " years" << endl;
    }
};

class Clothing : public Product
{
private:
    string size;
    string fabric;

public:
    void getClothingDetails()
    {
        getProductDetails();

        cout << "Enter Size: ";
        cin >> size;

        cout << "Enter Fabric: ";
        getline(cin >> ws, fabric);
    }

    void displayClothingDetails()
    {
        cout << "\n--- Clothing Product ---" << endl;
        displayProductDetails();
        cout << "Size: " << size << endl;
        cout << "Fabric: " << fabric << endl;
    }
};

int main()
{
    Electronic e;
    Clothing c;

    cout << "Enter Electronic Product Details\n";
    e.getElectronicDetails();

    cout << "\nEnter Clothing Product Details\n";
    c.getClothingDetails();

    e.displayElectronicDetails();
    c.displayClothingDetails();

    return 0;
}

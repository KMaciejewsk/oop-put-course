#ifdef PRODUCT_H
#define PRODUCT_H

using namespace std;

class Product {
    public:
        float price;
        string name;
        int quantity;
        Product(string name, float price, int quantity) { this->name = name; this->price = price; this->quantity = quantity;}
};

#endif
void addEmployee(Employee employee) {
    employees.push_back(employee);
}
void addProduct(Product product) {
    products.push_back(product);
}
void shipProduct(string product, int n, bool gamePhase) {
    for (int i = 0; i < products.size(); i++) {
        if (products[i].name == product) {
            if(gamePhase==false) {
                cout << "Shipped " << n << " " << product << " from " << location << endl;
            }
            if(gamePhase==true) {
                cout << "Sold " << n << " " << product << " for " << products[i].price*n << "PLN" << endl;
                for (int j = 0; j < employees.size(); j++) {
                    if (employees[j].name == "You") {
                           employees[j].money += products[i].price*n;
                    }
                }
            }
            products[i].quantity -= n;
        }
    }
}
void receiveProduct(string product, int n) {
    for (int i = 0; i < products.size(); i++) {
        if (products[i].name == product) {
            cout << "Received " << n << " " << product << " at " << location << endl;
            products[i].quantity += n;
        }
    }
}
int printMaxValue(string product) {
    for (int i = 0; i < products.size(); i++) {
        if (products[i].name == product) {
            return products[i].quantity;
        }
    }
}
void printProducts() {
    for (int i = 0; i < products.size(); i++) {
        cout << location << ": " << products[i].name << " " << products[i].quantity << endl;
    }
}
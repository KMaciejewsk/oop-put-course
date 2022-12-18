#ifdef WAREHOUSE_H
#define WAREHOUSE_H

using namespace std;

class Warehouse {
    private:
        vector<Product> products;
        vector<Employee> employees;
    public:
        string location;
        Warehouse(string location) { this->location = location; }
        void addEmployee(Employee employee);
        void addProduct(Product product);
        void shipProduct(string product, int n, bool gamePhase);
        void receiveProduct(string product, int n);
        int printMaxValue(string product);
        void printProducts();
};

#endif
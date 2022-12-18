#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

class Employee {
    private:
        int id;
    public:
        float money;
        string name;
        int salary;
        Employee(int id, string name, int salary) { this->id = id; this->name = name; this->salary = salary; }
};

class Product {
    public:
        float price;
        string name;
        int quantity;
        Product(string name, float price, int quantity) { this->name = name; this->price = price; this->quantity = quantity;}
};

class Staff : public Employee {
    public:
        Staff(int id, string name, int salary) : Employee(id, name, salary) {}
};

class Motorist : public Employee {
    public:
        Motorist(int id, string name, int salary) : Employee(id, name, salary) {}
};

class Boss : public Employee {
    public:
        int drivers;
        Boss(int id, string name, int salary) : Employee(id, name, salary) {}
        void PaySalary(Staff &employee) {
            employee.money += employee.salary;
            money -= employee.salary;
            cout << "Paid " << employee.name << " " << employee.salary << "PLN" << endl;
        }
        void PaySalary(Motorist &employee) {
            employee.money += employee.salary;
            money -= employee.salary;
            cout << "Paid " << employee.name << " " << employee.salary << "PLN" << endl;
        }
        void getRicher() {
            money += salary;
            cout << "You got " << salary << "PLN" << endl;
        }
};

class Warehouse {
    private:
        vector<Product> products;
        vector<Employee> employees;
    public:
        string location;
        Warehouse(string location) { this->location = location; }
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
};

class Event {
    private:
        int mode;
        int probability;
    public:
        Event(int mode) { this->mode = mode; probability = mode*20; }
        void IRS(Boss &manager) {
            if (rand() % 100 + 1 <= probability) {
                cout << "Skarbowka came to your warehouse and took 5000PLN. Next time do your taxes" << endl;
                manager.money -= 5000;
            }
        }
        void fire(Boss &manager) {
            if (rand() % 100 + 1 <= probability) {
                cout << "There was a fire in your warehouse, you lost 1000PLN" << endl;
                manager.money -= 1000;
            }
        }
        void bialystokMoment(Boss &manager) {
            if (rand() % 100 + 1 <= probability) {
                cout << "You got robbed by bialystokian mafia, you lost 3000PLN" << endl;
                manager.money -= 3000;
            }
        }
};

void Transport(string product, int n, Warehouse &from, Warehouse &to) {
    from.shipProduct(product, n, false);
    to.receiveProduct(product, n);
}

void Sell(string product, int n, Warehouse &from, Boss &manager) {
    from.shipProduct(product, n, true);
    manager.money += n * 100;
}

void clear() {
    _sleep(2000);
    system("CLS");
}

int roll(int difficulty) {
    srand (time(NULL));
    switch (difficulty) 
    {
    case 1:
        return rand() % 200 + 50;
        break;
    
    case 2:
        return rand() % 100 + 25;
        break;

    case 3:
        return rand() % 50 + 12;
        break;
    }
}

int main() {
    srand (time(NULL));
    string c;
    cout << "Welcome to Five nights at Amazon!" << endl;
    clear();
    cout << "Select difficulty (1, 2, 3): " << endl;
    int a;
    string where;
    cin >> a;
    if (a == 1) {
        cout << "You selected easy difficulty" << endl;
        where = "Warszawa";
    } else if (a == 2) {
        cout << "You selected medium difficulty" << endl;
        where = "Poznan";
    } else if (a == 3) {
        cout << "You selected hard difficulty" << endl;
        where = "Bialystok";
    } else {
        cout << "You selected invalid difficulty" << endl;
    }
    clear();

    cout << "Welcome to the " << where << " warehouse!" << endl;
    clear();
    
    Staff worker1(151868, "Adam", roll(a)*10);
    Staff worker2(151867, "Ewa", roll(a)*10);
    Staff worker3(151866, "Krzysztof", roll(a)*10);
    Motorist driver1(151869, "Jan", roll(a)*15);
    Motorist driver2(151870, "Anna", roll(a)*15);
    Boss manager1(2137, "You", roll(a)*30);
    manager1.money = 100;
    manager1.drivers = 1;

    Warehouse warehouse1(where);
    warehouse1.addProduct(Product("Chair", 99.99, roll(a)));
    warehouse1.addProduct(Product("Toaster", 499.99, roll(a)));
    warehouse1.addProduct(Product("Lamp", 99.99, roll(a)));
    warehouse1.addProduct(Product("Pet", 499.99, roll(a)));
    warehouse1.addProduct(Product("Lawnmower", 599.99, roll(a)));
    warehouse1.addProduct(Product("Bike", 399.99, roll(a)));
    warehouse1.addProduct(Product("Book", 299.99, roll(a)));
    warehouse1.addEmployee(worker1);
    warehouse1.addEmployee(worker2);
    warehouse1.addEmployee(worker3);
    warehouse1.addEmployee(driver1);
    warehouse1.addEmployee(manager1);

    Warehouse warehouse2("Berlin");
    warehouse2.addProduct(Product("Chair", 99.99, 10000));
    warehouse2.addProduct(Product("Toaster", 499.99, 10000));
    warehouse2.addProduct(Product("Lamp", 99.99, 10000));
    warehouse2.addProduct(Product("Pet", 499.99, 10000));
    warehouse2.addProduct(Product("Lawn mower", 599.99, 10000));
    warehouse2.addProduct(Product("Bike", 399.99, 10000));
    warehouse2.addProduct(Product("Book", 299.99, 10000));

    Event event1(a);

    bool game = true;
    int day = 1;

    while(game==true) {
        bool loop = true;
        int order = manager1.drivers;
        while(loop==true) {
            if(day==2){
                event1.IRS(manager1);
            }
            if(day==3){
                event1.fire(manager1);
            }
            if(day==4&&where=="Bialystok"){
                event1.bialystokMoment(manager1);
            }
            cout << "Day " << day << endl;
            cout << "You have " << manager1.money << " PLN" << endl;
            cout << "You have " << manager1.drivers << " driver(s)" << endl;
            cout << "Your warehouse has: " << endl;
            warehouse1.printProducts();
            cout << "What do you want to do?" << endl;
            cout << "1. Make an order (max once per driver)" << endl;
            cout << "2. Hire a driver for 5000 PLN (max two drivers)" << endl;
            cout << "3. End day" << endl;
            int b;
            cin >> b;
            switch (b)
            {
            case 1:
                if(order==0) {
                    cout << "You can't make more orders" << endl;
                    clear();
                    break;
                }
                cout << "What do you want to order?" << endl;
                cin >> c;
                Transport(c, roll(a), warehouse2, warehouse1);
                order--;
                clear();
                break;
            case 2:
                if(manager1.drivers==2) {
                    cout << "You can't hire more drivers" << endl;
                    clear();
                    break;
                }
                manager1.money -= 5000;
                cout << "You hired a driver" << endl;
                warehouse1.addEmployee(driver2);
                manager1.drivers++;
                clear();
                break;
            case 3:
                Sell("Chair", rand()%warehouse1.printMaxValue("Chair")+0, warehouse1, manager1);
                Sell("Toaster", rand()%warehouse1.printMaxValue("Toaster")+0, warehouse1, manager1);
                Sell("Lamp", rand()%warehouse1.printMaxValue("Lamp")+0, warehouse1, manager1);
                Sell("Pet", rand()%warehouse1.printMaxValue("Pet")+0, warehouse1, manager1);
                Sell("Lawnmower", rand()%warehouse1.printMaxValue("Lawnmower")+0, warehouse1, manager1);
                Sell("Bike", rand()%warehouse1.printMaxValue("Bike")+0, warehouse1, manager1);
                Sell("Book", rand()%warehouse1.printMaxValue("Book")+0, warehouse1, manager1);
                manager1.PaySalary(worker1);
                manager1.PaySalary(worker2);
                manager1.PaySalary(worker3);
                manager1.PaySalary(driver1);
                manager1.getRicher();
                if(manager1.drivers==2) {
                    manager1.PaySalary(driver2);
                }
                loop = false;
                day++;
                clear();
                break;
            default:
                cout << "Wrong number" << endl;
                clear();
                break;
            }
        }
        if(manager1.money<0) {
            game = false;
        }
        if(day==6) {
            game = false;
        }
        if(manager1.money>=60000&&day==6) {
            game = false;
        }
    }

    if(game==false&&manager1.money<0) {
        cout << "Game over!" << endl;
    }
    if(game==false&&day==6) {
        cout << "You successfully retired!" << endl;
    }
    if(game==false&&day==6&&manager1.money>=60000) {
        cout << "You won the game!" << endl;
    }
    if(game==false) {
        cout << "You earned " << manager1.money << " PLN" << endl;
        cout << worker1.money << " PLN went to worker1" << endl;
        cout << worker2.money << " PLN went to worker2" << endl;
        cout << worker3.money << " PLN went to worker3" << endl;
        cout << driver1.money << " PLN went to driver1" << endl;
        if(manager1.drivers==2) {
            cout << driver2.money << " PLN went to driver2" << endl;
        }
    }
    int endGame;
    cin >> endGame;
    return 0;
}

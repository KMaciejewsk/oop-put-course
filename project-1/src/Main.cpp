#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include "../include/content/Employee.h"
#include "../include/content/Boss.h"
#include "../include/content/Staff.h"
#include "../include/content/Motorist.h"
#include "../include/content/Product.h"
#include "../include/content/Warehouse.h"
#include "../include/content/Event.h"
#include "../src/content/Employee.cpp"
#include "../src/content/Boss.cpp"
#include "../src/content/Staff.cpp"
#include "../src/content/Motorist.cpp"
#include "../src/content/Product.cpp"
#include "../src/content/Warehouse.cpp"
#include "../src/content/Event.cpp"

using namespace std;

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
        if(manager1.money>=100000&&day==6) {
            game = false;
        }
    }

    if(game==false&&manager1.money<0) {
        cout << "Game over!" << endl;
    }
    if(game==false&&day==6) {
        cout << "You successfully retired!" << endl;
    }
    if(game==false&&day==6&&manager1.money>=100000) {
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
    return 0;
}

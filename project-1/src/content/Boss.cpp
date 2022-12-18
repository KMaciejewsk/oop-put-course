#include "../../include/content/Staff.h"
#include "../../include/content/Motorist.h"
#include "../../include/content/Boss.h"

using namespace std;

void Boss::PaySalary(Staff &employee) {
    employee.money += employee.salary;
    money -= employee.salary;
    cout << "Paid " << employee.name << " " << employee.salary << "PLN" << endl;
}
void Boss::PaySalary(Motorist &employee) {
    employee.money += employee.salary;
    money -= employee.salary;
    cout << "Paid " << employee.name << " " << employee.salary << "PLN" << endl;
}
void Boss::getRicher() {
    money += salary;
    cout << "You got " << salary << "PLN" << endl;
}
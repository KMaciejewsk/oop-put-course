#ifdef EMPLOYEE_H
#define EMPLOYEE_H

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

#endif
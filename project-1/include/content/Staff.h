#ifdef STAFF_H
#define STAFF_H

using namespace std;

class Staff : public Employee {
    public:
        Staff(int id, string name, int salary) : Employee(id, name, salary) {}
};

#endif

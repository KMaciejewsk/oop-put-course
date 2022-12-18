#ifdef Motorist_H
#define Motorist_H

using namespace std;

class Motorist : public Employee {
    public:
        Motorist(int id, string name, int salary) : Employee(id, name, salary) {}
};

#endif
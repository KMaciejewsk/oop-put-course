#ifdef BOSS_H
#define BOSS_H

using namespace std;

class Boss : public Employee {
    public:
        int drivers;
        Boss(int id, string name, int salary) : Employee(id, name, salary) {}
    void PaySalary(Motorist driver);
    void PaySalary(Staff worker);
    void getRicher();
};

#endif
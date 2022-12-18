#ifdef EVENT_H
#define EVENT_H

using namespace std;

class Event {
    private:
        int mode;
        int probability;
    public:
        Event(int mode) { this->mode = mode; probability = mode*20; }
        void IRS(Boss &manager);
        void fire(Boss &manager);
        void bialystokMoment(Boss &manager);
};

#endif
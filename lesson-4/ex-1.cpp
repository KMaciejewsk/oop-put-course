 
#include <iostream>
#include <string>
using namespace std;

class Item {
	public:
		virtual int worth();
};

class Coal: public Item {
	private:
		int quantity;
		int value;
	public:
		Coal(int quantity, int value){this->quantity=quantity;this->value=value;}
		Coal Addition(int supply){
			return Coal(supply+quantity, value);
		}
		int worth() {
			return quantity*value;
		}
};

int main() {
	Coal fiveTons(5,3);
	Coal sevenTons = fiveTons.Addition(2);
	cout << sevenTons.worth();
}

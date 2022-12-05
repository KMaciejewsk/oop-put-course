#include <iostream>
using namespace std;

class food
{
	private:
		int value;
		int maxValue;
		int calories;
		int elfNumA;
		int elfNumB;
	public:
		food(int value, int maxValue)
		{
			this->value=value;
			this->maxValue=maxValue;
		}
		void findFood() 
		{
			elfNumA = 1;
			while(!cin.eof())
			{
				cin >> calories;
				value += calories;
				char c1 = cin.get();
        			char c2 = cin.peek();
        			if (c2 == '\n')	
    				{
        		  		if(value > maxValue)
        		   		{
        		   			maxValue = value;
						elfNumB = elfNumA;
        				}
					elfNumA++;
        				value = 0;
    				}
			}
        		if(value > maxValue)
        		{
        			maxValue = value;
				elfNumB = elfNumA;
        		}
			cout << maxValue << ", " << elfNumB << endl;
		}
};

int main() {
	food a(0,0);
	a.findFood();
	return 0;
}

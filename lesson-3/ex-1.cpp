#include <iostream>
#include <string>
using namespace std;

class Body {
	public:
		int Limbs;
		int Eyes;
		Body()
		{
			this->Limbs=0;
			this->Eyes=0;
		}
		Body(int Limbs, int Eyes)
		{
			this->Limbs=Limbs;
			this->Eyes=Eyes;
		}
		void display()
		{
			cout << "\n" << "Number of limbs: " << Limbs << "	Number of eyes: " << Eyes << "\n";
		}
};

class Animal {
	private:
		string Name;
		string Animal_Name;
		int Age;
	public:
		Animal()
		{
			this->Name="";
			this->Animal_Name="";
			this->Age=0;
		}
		Animal(string Name, string Animal_Name, int Age)
		{
			this->Name=Name;
			this->Animal_Name=Animal_Name;
			this->Age=Age;
		}
		
		void display()
		{
			cout << "Name: " << Name << "	Animal: " << Animal_Name << "	Age: " << Age;
		}
};

int main() {
	Body camel(4,2);
	Animal a("imie","wielblad",15);
	a.display();
	camel.display();
}

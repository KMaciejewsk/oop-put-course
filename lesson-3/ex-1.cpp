#include <iostream>
#include <string>
using namespace std;

class Cialo {
	public:
		int Limbs;
		int Eyes;
		//Cialo(){this->Limbs=0;this->Eyes=0;}
		Cialo(int Limbs, int Eyes){this->Limbs=Limbs;this->Eyes=Eyes;}
};

class Animal {
	private:
		string Name;
		string Animal_Name;
		int Age;
		Cialo &cialo;
	public:
		//Animal(){this->Name="";this->Animal_Name=A"";this->Age=0;this->cialo=0;}
		Animal(string Name, string Animal_Name, int Age, Cialo &cialo){this->Name=Name;this->Animal_Name=Animal_Name;this->Age=Age;this->&cialo=&cialo;}
		
		void display()
		{
			cout << "\n" << Animal_Name << " ma na imie " << Name << ". Ma " << Age << " lat i ma " << a.Limbs << " nogi.\n";
		}
};

int main() {
	Cialo wielblad(4,2);
	Animal a("imie","wielblad",15,wielblad);
	a.display();
}

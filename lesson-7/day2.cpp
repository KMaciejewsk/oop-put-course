#include <iostream>
using namespace std;

class game
{
	private:
		char opponent;
		char player;
		int points;
	public:
		void Score() 
		{
			points = 0;
			while(!cin.eof())
			{
				cin >> opponent;
				cin >> player;
				
				if(player=='X')
				{
					points+=1;
				}
				if(player=='Y')
				{
					points+=2;
				}
				if(player=='Z')
				{
					points+=3;
				}
				if(play(opponent,player)==0)
				{
					points+=0;
				}
				if(play(opponent,player)==1)
				{
					points+=6;
				}
				if(play(opponent,player)==2)
				{
					points+=3;
				}
				cout << opponent << " " << player << " runda: " << points << endl;
			}
			cout << points << endl;
		}
		int play(char a, char b)
		{
			// 1-win 0-lose 2-draw
			if(a=='A'&&b=='X')
			{
				return 2;
			}
			if(a=='A'&&b=='Y')
			{
				return 1;
			}
			if(a=='A'&&b=='Z')
			{
				return 0;
			}
			if(a=='B'&&b=='X')
			{
				return 0;
			}
			if(a=='B'&&b=='Y')
			{
				return 2;
			}
			if(a=='B'&&b=='Z')
			{
				return 1;
			}
			if(a=='C'&&b=='X')
			{
				return 0;
			}
			if(a=='C'&&b=='Y')
			{
				return 1;
			}
			if(a=='C'&&b=='Z')
			{
				return 2;
			}
		}
};

int main() {
	game a;
	a.Score();
	return 0;
}

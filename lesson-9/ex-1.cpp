#include <iostream>
#include <string>

using namespace std;

class Game {
    public:
        string team1;
        string team2;
        Game(string team1, string team2) {
            this->team1 = team1;
            this->team2 = team2;
        }
        virtual void result(int a,int b) = 0;
};

class FakeFootballGame : public Game {
    public:
        int team1_score;
        int team2_score;
        FakeFootballGame(string team1, string team2) : Game(team1, team2) {}
        virtual void result(int a, int b) {
            team1_score = a;
            team2_score = b;
        }
};

int main() {
    FakeFootballGame game("Team1", "Team2");
    int a = 3;
    int b = 4;
    game.result(a, b);
    if(game.team1_score==a && game.team2_score==b) {
        cout << "Success!" << endl;
    }
    else {
        cout << "Failure!" << endl;
    }
}

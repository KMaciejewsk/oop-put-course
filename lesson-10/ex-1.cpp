//nie bylo mnie na zajeciach wiec wysylam najnowsze zadanie z githuba

#include <iostream>
#include <string>

using namespace std;

class Shiritori {
    private:
        bool game_over = false;
        int len = 0;
    public:
        string words[100];
        void play(string word)
        {
            if(len==0)
            {
                game_over = false;
                words[len] = word;
                len++;
                cout << "[" << word << "]" << endl;
            }
            else
            {
                bool found = false;
                for(int i=0; i<len; i++)
                {
                    if(words[i] == word)
                    {
                        found = true;
                        cout << "game over " << word << " already used" << endl;
                        game_over = true;
                        break;
                    }
                }
                if(words[len-1][words[len-1].length()-1]==word[0] && found==false)
                {
                    words[len] = word;
                    len++;
                    cout << "[";
                    for(int i=0; i<len; i++)
                    {
                        cout << words[i];
                        if(i!=len-1)
                        {
                            cout << ", ";
                        }
                    }
                    cout << "]" << endl;
                }
                else if(found==false)
                {
                    game_over = true;
                    cout << "game over" << endl;
                }
            }
        }
        void restart()
        {
            game_over = false;
            len = 0;
            cout << "game restarted" << endl;
        }
        void printWords()
        {
            cout << "[";
            for(int i=0; i<len; i++)
            {
                cout << words[i];
                if(i!=len-1)
                {
                    cout << ", ";
                }
            }
            cout << "]" << endl;
        }
};

int main() {
    Shiritori game;
    game.play("apple");
    game.play("ear");
    game.play("rhino");
    game.play("corn");
    game.printWords();
    game.restart();
    game.printWords();
    game.play("hostess");
    game.play("stash");
    game.play("hostess");
    return 0;
}

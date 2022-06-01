#include<iostream>
#include<cstdlib>
using namespace std;

class Player{
public:
    virtual int getGuess() =0;
};

class ComputerPlayer : public Player{
    public:
        ComputerPlayer();
        int getGuess();
};

ComputerPlayer::ComputerPlayer():Player(){}

int ComputerPlayer::getGuess(){
    int guess=rand()%100;
    cout<<"The computer guesses "<<guess<<endl;
    return guess;
}

class HumanPlayer : public Player{
    public:
        HumanPlayer();
        int getGuess();
};

HumanPlayer::HumanPlayer():Player(){}

int HumanPlayer::getGuess(){
    int guess;
    cin>>guess;
    return guess;
}

bool checkForWin(int guess, int answer){
    if (answer == guess)  {
        cout << "You're right! You win!" << endl;
        return true;
    }  
    else if (answer < guess)  
        cout << "Your guess is too high." << endl;
    else     
        cout << "Your guess is too low." << endl;
    return false;
}

void play(Player &player1, Player &player2){
    int answer = 0, guess = 0;
    answer = rand() % 100;
    bool win = false;
    while(!win){
        cout << "Player 1's turn to guess." << endl;
        guess = player1.getGuess();
        win = checkForWin(guess, answer);
        if (win) return;
        cout << "Player 2's turn to guess." << endl;
        guess = player2.getGuess();
        win = checkForWin(guess, answer);
    }
}

int main(void){
    HumanPlayer player1;
    ComputerPlayer player2;
    play(player1,player2);
    cout<<"Enter a character to exit."<<endl;
    char wait;
    cin>>wait;
    return 0;
}


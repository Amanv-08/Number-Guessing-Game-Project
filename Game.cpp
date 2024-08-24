#include<iostream>

using namespace std;

/* Task is implementing a simple number guessing game in C++ involving a Guesser, three Players, and an Umpire. The game operates as follows:

Guesser: This entity will guess a number . x
Player: Each of three players will guess a number. 3 Players 
Umpire: This entity will collect the guesses from the Guesser and the Players and determine which Players, if any, have guessed the same number as the Guesser.


p1->2 p2->4 p3->2  x->4

Umpire
p1 -> 2 4 lost the game 
p2 -> 4 4 won the game 
p3 -> 2 4 lose the game

p2 won the game !!

Umpire
p1 -> 2 4 lost the game 
p2 -> 2 4 won the game 
p3 -> 2 4 lose the game

All lose the game !!

classes ->  Guesser
            Umpire
            Player


main fuctions -> 1. Create a umpire
                 2. get the number from the guesser
                 3. get the number from all the three Players
                 4. Print the result of game 
                 5. End the game
*/

class Guesser{
    int guessednum;

    public:
    int takeguesserinput(){
        int x;
        cout<<"Give the number for the guesser : ";
        cin>>x;
        guessednum = x;
        return guessednum;
    }
};
class Player{
    int playernum;
    public:
    int takeplayerinput(){
        int p;
        cin>>p;
        playernum=p;
        return playernum;
    }
};

class Umpire{
    public:
    int g;
    int p1num;
    int p2num;
    int p3num;

    void GetTheNumberFromGuesser(){
        Guesser g1;
        g = g1.takeguesserinput();
        cout<<"Number guessed by the Guesser: "<<g<<endl;
    }
    void GetTheNumberFromPlayers(){
        Player p1;
        Player p2;
        Player p3;

        cout<<"Give the number for the Player 1: ";
        p1num=p1.takeplayerinput();
        cout<<"Give the number for the Player 2: ";
        p2num=p2.takeplayerinput();
        cout<<"Give the number for the Player 3: ";
        p3num=p3.takeplayerinput();
    }
    void PrintTheResult(){
        // g p1num p2num p3num
        if(g==p1num){
            // p1 has won
            // p2? p3?
            if(g==p2num){
                // p1 and p2 has won 
                // p3?
                if(g==p3num){
                    cout<<"All has won the game";
                }
                else{
                    // p1 and p2 has won p3 has
                    cout<<"Player 1 and Player 2 has won the game"<<endl;
                }
            }
            else{
                // p1 has won and p2 has lost
                if(g==p3num){
                    cout<<"Player 1 and Player 3 has won the game"<<endl;
                }
                else{
                    // p1 and p2 has won p3 has
                    cout<<"Player 1has won the game"<<endl;
                }

            }
        }
        else if(g==p2num){
            // p1 has not won p2 has won -> already know
            if(g==p3num){
                // p1 has lost p2 won and p3 won -> already know
                cout<<"Player 2 and Player 3 has won the game"<<endl;
            }
            else {
                cout<<"The players 2 has won the game"<<endl;
            }
        }
        else if(g==p3num){
            // p1 has not won p2 has not won p3 has won -> already know
            cout<<"The player 3 has won the game: ";
            
        }
        else{
            // p1 lost, p2 has lost p3 has lost -> already know
            cout<<"All the players has lost the game: "<<endl;

        }
    }

};

int main(){
    cout<<"-------Let's start the Game-------"<<endl;
    // Umpire object
    Umpire u;
    u.GetTheNumberFromGuesser();
    u.GetTheNumberFromPlayers();
    u.PrintTheResult();
    
    cout<<"-------End the Game-------"<<endl;
    
    return 0;
}
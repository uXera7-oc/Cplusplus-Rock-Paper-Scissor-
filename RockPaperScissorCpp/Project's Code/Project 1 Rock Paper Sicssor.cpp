// ******************** This code demonstrates CODE REUSABILITY through modular functions and clean structure. ********************
// ******************** Each function has a single responsibility, making the code EASY TO READ and MAINTAIN. ********************


#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib> //For "system()" (Colors)
#include <ctime> //For Random Function

// Enum to represent the three possible choices in the game
enum enChoice { Rock = 1, Paper , Scissor }; 

// Structure to store game results (wins for Player, Computer, and Draws)
struct stResult { int Player = 0; int Computer = 0; int Draw = 0; };


using namespace std;

// You will Need it For Random Choices from Computer
int Random(int From, int To) 
{
    // Function To Generate Random Number

    int Rands = rand() % (To - From + 1) + From;
    return Rands;

    // rand() % (To - From + 1) → gives the number of values you need, always starting from 0.
    // + From → shifts these values from 0 to the actual start of the range.



}  

// To Get the player's choice from user input & Converts it to its enum
enChoice UserChoice()
{
    int ChoiceNumber;

    cout << "Please Enter Your Choice: " << " [1] Rock " << " [2] Paper " <<" [3] Scissor " << endl;
    cin >> ChoiceNumber;

    return (enChoice)ChoiceNumber;
}

// Converts enChoice enum to its string name
string ChoiceName(enChoice Choice)
{
    switch (Choice)
    {
    case Rock:    return "Rock";
    case Paper:    return "Paper";
    case Scissor:    return "Scissor";
    default: return "Unknown";
    }
}

// Generates a random choice for the computer as we said previously :)
enChoice ComputerChoice()
{
    int ChoiceNumber = Random(1, 3);

    return enChoice(ChoiceNumber);
}

// Determines the winner of a round and updates the result with some effects
string RoundMessage(enChoice ComputerChoice, enChoice PlayerChoice,stResult &Result)
{
   

    if ((PlayerChoice == enChoice::Rock && ComputerChoice == enChoice::Scissor) || (PlayerChoice == enChoice::Paper && ComputerChoice == enChoice::Rock) || (PlayerChoice == enChoice::Scissor && ComputerChoice == enChoice::Paper))
    {
        Result.Player++;
        system("color 2F");
        return "Player";
    }
    else if ((ComputerChoice == enChoice::Rock && PlayerChoice == enChoice::Scissor) || (ComputerChoice == enChoice::Paper && PlayerChoice == enChoice::Rock) || (ComputerChoice == enChoice::Scissor && PlayerChoice == enChoice::Paper))
    {
        Result.Computer++;
        cout << "\a";
        system("color 4F");
        return "Computer ";
    }
    else 
    { 
        Result.Draw++;
        system("color 6F");
        return "Draw ";
    }
}

// Display this message at the start of the game
void Welcome()
{
    cout << "\n*************************************************" << endl;
    cout << "       WELCOME TO ROCK PAPER SCISSOR GAME        " << endl;
    cout << "*************************************************" << endl << endl;
} 

// To ask user for number of rounds to play (1-10)
int ReadHowRoundsToPlay(int RoundsNumber) 
{
        
    do
    {

        cout << "How Many Rounds You Want To Play ? 1 To 10 ?" << endl;
        cin >> RoundsNumber;

    } while (RoundsNumber < 1 || RoundsNumber > 10);

    return RoundsNumber;
}

// To Store the number of rounds int Length variable
void AddRoundsNumberToArray(int& Length)
{
    Length = ReadHowRoundsToPlay(Length);
}

// Display "Game Over" message
void GameOver()
{
    cout << "\n\t \t \t          -------------------------------------------------------    \t \t \t ";
    cout << "\t \t \t \t\t                            +++ G a m e   O v e r +++                       ";
    cout << "\n\t \t \t          -------------------------------------------------------    \t \t \t ";

    cout << endl << endl;

}

// To Display the final results panel with statistics
void ResultPanel(int Length , stResult Result)
{


    cout << "\n \t \t \t __________________________ [Game Results] __________________________\t \t \t \n";
    cout << "\t \t \t \n                            Game Rounds : " << Length ;
    cout << "\t \t \t \n                            Player Won Times : " << Result.Player ;
    cout << "\t \t \t \n                            Computer Won Times : " << Result.Computer ;
    cout << "\t \t \t \n                            Draw Times : " << Result.Draw ;
    if(Result.Player > Result.Computer)
        cout << "\t \t \t \n                            Final Winner : " << "Player";
    else if(Result.Player < Result.Computer)
        cout << "\t \t \t \n                            Final Winner : " << "Computer";
    else if(Result.Player == Result.Computer)
        cout << "\t \t \t \n                            Final Winner : " << "Draw";

    cout << "\n \t \t \t _____________________________________________________________________\t \t \t \n";
   

}

// The Main game loop : Plays all rounds and displays results
void PlayRoundsInArray(int RoundsArr[10], int Length)
{
    Welcome();

    int Counter = 1; // Round counter for display
    stResult Result; // Initialize result structure

    // Loop through each round
    for (int i = 0; i < Length; i++)
    {

        cout << "Round [" << Counter << "] Begins : " << endl << endl;

        // Get player's choice
        enChoice PlayerChoice = UserChoice();
        cout << endl;


        // Display round header
        cout << "----------ROUND [" << Counter << "]----------" << endl;
        cout << "Player Choice : " << ChoiceName(PlayerChoice) << endl;


        // Get and display computer's choice
        enChoice MachineChoice = ComputerChoice();
        cout << "Computer Choice : " << ChoiceName(MachineChoice) << endl;

        // Determine and display round winner
        cout << "Round Winner : " << RoundMessage(MachineChoice, PlayerChoice,Result) << endl;



        cout << "\n-------------------------\n";
     
        Counter++;
    }

    cout << endl;

    // Display game over message and final results
    GameOver();
    ResultPanel(Length, Result);


    



}


// Ask user if he wants to play again Yes or No
char AskToReplay()
{
    char Response;
    cout << "                           Do You Want To Play Again ? Y/N ? " << endl;
    cin >> Response;

    return Response;
}

// Main replay loop : Allows multiple game sessions
void Replay()
{
    int Round[10];
    int Length;
    char Response;

    do
    {
        system("cls");        // Clear screen 
        system("color 0F");  // Reset to default colors (black bg, white text)

        // Get number of rounds and play the game
        AddRoundsNumberToArray(Length);
        PlayRoundsInArray(Round, Length);

        // Ask if user wants to play again
        Response = AskToReplay();



    } while (Response == 'y' || Response == 'Y' );  // Continue if user says yes
}

// Entry point to start the game
void StartGame()
{
    Replay();
}



// Program entry point
int main()
{
    // Seed the random number generator with the current time - Called Only Once ! -
    srand((unsigned)time(NULL));

    StartGame();


    return 0;
}


// Development time : 4h



#include <iostream>
#include <ctime>

using namespace std;

enum enChoise { Stone = 1 , Paper = 2  , Scissors = 3 };

struct stRoundResult
{
    string PlayerChoise;
    string ComputerChoise;
    string RoundWinner;
};

struct stGameResult
{
    short GameRounds;
    short Player1WonTimes;
    short ComputereWonTimes;
    short DrawTimes;
    string FinalWinner;
};

int ReadRoundsNumber()
{
    int RoundsNumber;
    do
    {
        cout << "How Many Rounds 1 To 10 ? " << endl;
        cin >> RoundsNumber;
    } while (RoundsNumber <= 0 || RoundsNumber >10);
    cout << "\n\n";
        return RoundsNumber;
}

int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

string EnumToString(enChoise choise)
{
    switch (choise)
    {
    case enChoise::Stone:
        return "Stone";

    case enChoise::Paper:
        return "Paper";

    case enChoise::Scissors:
        return "Scissors";


    default:
        return "UNKOWN";
    }
}

short PlayerChoise()
{
    short choise = 0;
    cout << "Your choise : [1]:Stone , [2]:Paper , [3]:Scissors ? " ;
    cin >> choise;
    cout << "\n\n";
    return choise;

}

enChoise IntToEnum(short Choise)
{
    return (enChoise)Choise;
}

string RoundsWinner( string PLchoise , string Cmpchoise )
{
    if (PLchoise == "Stone")
    {
        if (Cmpchoise == "Paper")
            return "Computer Won";
        else if (Cmpchoise == "Scissors")
            return "You Won";
        else
            return "No Winner";      
    }
    else if (PLchoise == "Paper")
    {
        if (Cmpchoise == "Scissors")
            return "Computer Won";
        else if (Cmpchoise == "Stone")
            return "You Won";
        else
            return "No Winner";
    }
    else
    {
        if (Cmpchoise == "Stone")
            return "Computer Won";
        else if (Cmpchoise == "Paper")
            return "You Won";
        else
            return "No Winner";
    }
}

stGameResult FinalResult(stRoundResult result , stGameResult &Gameresult )
{
    if (result.RoundWinner == "You Won")
        Gameresult.Player1WonTimes++;
    else if (result.RoundWinner == "Computer Won")
        Gameresult.ComputereWonTimes++;
    else Gameresult.DrawTimes++;
    return Gameresult;
}

void RoundResult( int Round , stGameResult &Gameresult)
{
    //int choise;
    stRoundResult result;

     result.PlayerChoise = EnumToString(IntToEnum(PlayerChoise()));
     result.ComputerChoise = EnumToString(IntToEnum(RandomNumber(1, 3)));
     result.RoundWinner = RoundsWinner(result.PlayerChoise, result.ComputerChoise);

    cout << "----------------Round[" << Round << "]-----------------" << endl;
    cout << "Player1  choise : " << result.PlayerChoise << endl;
    cout << "Computer Choise : " << result.ComputerChoise << endl;
    cout << "Round Winner    : " << result.RoundWinner << endl ;
    cout << "----------------------------------------- " << endl;

    FinalResult(result, Gameresult);
    
}

void GameOverTable(stGameResult gameresult)
{
    cout << "\t\t" << "----------------------------------------------------" << "\n\n";
    cout << "\t\t" << "----------------++ G a m e  O v e r ++--------------" << "\n\n";
    cout << "\t\t" << "----------------------------------------------------" << "\n\n";
    cout << "\t\t" << "-------------------[ Game Result ]------------------" << "\n\n";
    cout << "\t\t" << "Game Rounds  :" << gameresult.GameRounds << endl;
    cout << "\t\t" << "Player1 won Times : " << gameresult.Player1WonTimes << endl;
    cout << "\t\t" << "Computer Won Times:" << gameresult.ComputereWonTimes << endl;
    cout << "\t\t" << "Draw Times        :" << gameresult.DrawTimes << endl;
    cout << "\t\t" << "Final Winner      :" << gameresult.FinalWinner << endl;
    cout << "\t\t" << "----------------------------------------------------" << "\n\n";
}

void Rounds(int RounNUmber , stGameResult gameresult)
{
    gameresult.GameRounds = RounNUmber;
    gameresult.Player1WonTimes = 0;
    gameresult.ComputereWonTimes = 0;
    gameresult.DrawTimes = 0;
    gameresult.FinalWinner = "";

    for (int i = 1; i <= RounNUmber; i++)
    {
        cout << "Rounds [" << i << "] begins :" << "\n\n";
        RoundResult(i , gameresult);
        cout << "\n\n";
    }

    if (gameresult.ComputereWonTimes > gameresult.Player1WonTimes)
        gameresult.FinalWinner = "Computer Won";
    else if (gameresult.ComputereWonTimes < gameresult.Player1WonTimes)
        gameresult.FinalWinner = "You Won";
    else gameresult.FinalWinner = "No winner ";

   GameOverTable(gameresult);
}

int main()
{
    stGameResult gameresult;
    char next;
    do
    {
        Rounds(ReadRoundsNumber(), gameresult);
        cout << "Do You want To Play Again ?? [y/n] " << endl;
        cin >> next;
    } while (next == 'y');

    return 0;
}


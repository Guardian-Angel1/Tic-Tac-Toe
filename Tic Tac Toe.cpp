// Program By:
// Prakhar Punj
// 220150011
// Data Science and AI
//Intro to AI LAB Assignment 2: TIC TAC TOE 

#include <bits/stdc++.h>
using namespace std::chrono;
using namespace std;


    struct Move
    {
        int row, col;
    };

    int ct=0;
    char player, computer;
    int maxDepth;


    vector<vector<char>> board(3, vector<char>(3, ' '));


    void printBoard() 
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++)
            {
                cout<<board[i][j]<<"|";
            }
            cout<<board[i][2]<<endl;
            cout<<"------";
            cout<<endl;
        }


        // for (auto &row : board) 
        // {
        //     for (auto &cell : row) 
        //     {      
        //         cout<< cell << " ";
        //     }
        //     cout<<"\n";
        // }
    }


    bool isMovesLeft() 
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ')
                    return true;
        return false;
    }




    int evaluate() 
    {
        for (int row = 0; row < 3; row++) 
        {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) 
            {
                if (board[row][0] == computer)
                {
                        return +10;
                }
                else if (board[row][0] == player)
                {
                        return -10;
                }
            }
        }

            for (int col = 0; col < 3; col++) 
            {
                if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                    if (board[0][col] == computer)
                    {
                        return +10;
                    }
                    else if (board[0][col] == player)
                    {
                       return -10;
                    }
              }
         }

         if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
            {
                if (board[0][0] == computer)
                {
                    return +10;
                }
                else if (board[0][0] == player)
                {
                   return -10;
                }
            }

          if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
          {
              if (board[0][2] == computer)
              {
                 return +10;
              }
              else if (board[0][2] == player)
              {
                  return -10;
              }
         }

         return 0;
    }




int minimax(int depth, bool isMax) 
{
    ct++;
    int score = evaluate();

    if (score == 10 || score == -10)
        return score;

    if (!isMovesLeft())
        return 0;

    if (depth == maxDepth)
        return 0;

    if (isMax) 
    {
        int best = -1000;

        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (board[i][j] == ' ') 
                {
                    board[i][j] = computer;

                    best = max(best, minimax(depth + 1, !isMax));

                    board[i][j] = ' ';
                }
            }
        }
        return best;
    } 
    else 
    {
        int best = 1000;

        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (board[i][j] == ' ') 
                {
                    board[i][j] = player;

                    best = min(best, minimax(depth + 1, !isMax));

                    board[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

Move findBestMove() 
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] == ' ') 
            {
                board[i][j] = computer;

                int moveVal = minimax(0, false);

                board[i][j] = ' ';

                if (moveVal > bestVal) 
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}

void computerMove() 
{
    Move bestMove = findBestMove();
    board[bestMove.row][bestMove.col] = computer;
    cout << "\nComputer has made its move.\n" << endl;
}



int abminimax(int depth, bool isMax, int alpha, int beta) 
{
    int score = evaluate();
    ct++;
    if (score == 10 || score == -10)
        return score;

    if (!isMovesLeft())
        return 0;

    if (depth == maxDepth)
        return 0;

    if (isMax) {
        int best = -1000;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = computer;

                    best = max(best, abminimax(depth + 1, !isMax, alpha, beta));
                    alpha = max(alpha, best);

                    board[i][j] = ' ';

                    if (beta <= alpha)
                        break;
                }
            }
        }
        return best;
    } 
    else 
    {
        int best = 1000;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = player;

                    best = min(best, abminimax(depth + 1, !isMax, alpha, beta));
                    beta = min(beta, best);

                    board[i][j] = ' ';

                    if (beta <= alpha)
                        break;
                }
            }
        }
        return best;
    }
}

Move abfindBestMove() {
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') 
            {
                board[i][j] = computer;

                int moveVal = abminimax(0, false, -1000, 1000);

                board[i][j] = ' ';

                if (moveVal > bestVal) {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}

void playerMove() 
{
    int x, y;
    do {
        cout<<"Enter Row for your move:";
        cin>>x;cout<<endl;
        cout << "Enter Column for your move:";
        cin>>y;cout<<endl;
        } while (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != ' ');

    board[x][y] = player;
}

void abcomputerMove() 
{
    Move bestMove = abfindBestMove();
    board[bestMove.row][bestMove.col] = computer;
    cout << "\nComputer has made its move.\n" << endl;
}

bool checkWin(char player) 
{
    if (evaluate() == (player == computer ? 10 : -10))
        return true;
    return false;
}

bool checkTie() 
{
    if (!isMovesLeft())
        return true;
    return false;
}





//Driver Code
int main()
{
    auto start = high_resolution_clock::now();
    int ch1=0;
    while(ch1!=1 ||ch1!=2 || ch1!=3)
    {
        cout<<"\n====================================================\n";     
        cout<<"Welcome to Prakhar\'s Implementation of Tic Tac Toe\n";
        cout<<"====================================================\n";
        cout<<"                      MENU 1                          \n";
        cout<<"     Press 1 to use MINIMAX Algorithm\n";
        cout<<"     Press 2 to use MINIMAX with ALPHA - BETA PRUNING\n";
        cout<<"     Press 3 to Quit\n";
        cout<<"     Enter your choice:";
        cin>>ch1; 
        cout<<"====================================================\n";
        cout<<"\n\n";

        if(ch1==3)
        {
            cout<<"====================================================\n";
            cout<<"Exiting the Tic Tac Toe Game!!!\n";
            cout<<"Goodbye!\n";
            cout<<"Have a Nice Day!\n";
            cout<<"====================================================\n";
            break;
        }

        else if(ch1==2)
        {
            cout << "Choose your player (X/O): ";
            cin >> player;
            cout<<endl;
            computer = (player == 'X') ? 'O' : 'X';

            cout << "Enter the maximum depth for the Minimax algorithm using Alpha-Beta Pruning: ";
            cin >> maxDepth;
            cout<<endl;

            char turn;
            cout << "Do you want to play first? (y/n): ";
            cin >> turn;
            cout<<endl;
            bool playerTurn = (turn == 'y');

            while (true) 
            {
                        cout<<"=======\n";
                        printBoard();
                        cout<<"=======\n";
                     if (playerTurn) 
                    {
                        playerMove();
                        if (checkWin(player)) 
                        {
                        cout << "\nResult: Congratulations! You have won.\n" << endl;
                        break;
                        }
                        if (checkTie()) 
                        {
                        cout << "\nResult: It's a tie!\n" << endl;
                        break;
                        }
                    } 
                else 
                {
                    abcomputerMove();
                    if (checkWin(computer)) 
                    {
                        cout << "\nResult: Computer wins!\n" << endl;
                        break;
                    }
                    if (checkTie()) 
                    {
                        cout << "\nResult: It's a tie!\n" << endl;
                        break;
                    }
                }
                playerTurn = !playerTurn;
            }
            cout<<"=======\n";
            printBoard();
            cout<<"=======\n";
            cout<<"Count:"<<ct<<endl;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout<<"Time:"<<duration.count()<<" microseconds"<<endl;
            break;
        }
        else if(ch1==1)
        {
            cout << "Choose your player (X/O): ";
            cin >> player;
            cout<<endl;
            computer = (player == 'X') ? 'O' : 'X';

            cout << "Enter the maximum depth for the Minimax algorithm: ";
            cin >> maxDepth;
            cout<<endl;

            char turn;
            cout << "Do you want to play first? (y/n): ";
            cin >> turn;
            cout<<endl;
            bool playerTurn = (turn == 'y');

            while (true) 
            {
            cout<<"=======\n";
            printBoard();
            cout<<"=======\n";                   
             if (playerTurn) 
                    {
                        playerMove();
                        if (checkWin(player)) 
                        {
                        cout << "\nResult: Congratulations! You have won.\n" << endl;
                        break;
                        }
                        if (checkTie()) 
                        {
                        cout << "\nResult: It's a tie!\n" << endl;
                        break;
                        }
                    } 
                else 
                {
                    computerMove();
                    if (checkWin(computer)) 
                    {
                        cout << "\nResult: Computer wins!\n" << endl;
                        break;
                    }
                    if (checkTie()) 
                    {
                        cout << "\nResult: It's a tie!\n" << endl;
                        break;
                    }
                }
                playerTurn = !playerTurn;
            }

            cout<<"=======\n";
            printBoard();
            cout<<"=======\n";
            cout<<"Count:"<<ct<<endl;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout<<"Time:"<<duration.count()<<" microseconds"<<endl;
            break;
        }
        else
        {
            cout<<"Invalid Input!\n";
            break;
        }
    }

}
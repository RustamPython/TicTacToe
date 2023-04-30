#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);
int v = 4;

string board;
int progB[9];
string movS = "XO";
char moveN = 'X';

int move(char mov)
{
    // 0.7 - защита
    // 1   - атака1
    // 2   - атака2
    // 10  - поражение
    // 15  - победа

    for (int i = 0; i < 9; i++)
    {
        if (board[i] != ' ')
        {
            progB[i] = -100;
        }
    }

    {
        if (board[0] == mov && board[1] == mov) { progB[2] += 15; }
        if (board[0] == mov && board[2] == mov) { progB[1] += 15; }
        if (board[1] == mov && board[2] == mov) { progB[0] += 15; }

        if (board[3] == mov && board[4] == mov) { progB[5] += 15; }
        if (board[3] == mov && board[5] == mov) { progB[4] += 15; }
        if (board[4] == mov && board[5] == mov) { progB[3] += 15; }

        if (board[6] == mov && board[7] == mov) { progB[8] += 15; }
        if (board[6] == mov && board[8] == mov) { progB[7] += 15; }
        if (board[7] == mov && board[8] == mov) { progB[6] += 15; }


        if (board[0] == mov && board[3] == mov) { progB[6] += 15; }
        if (board[0] == mov && board[6] == mov) { progB[3] += 15; }
        if (board[3] == mov && board[6] == mov) { progB[0] += 15; }

        if (board[1] == mov && board[4] == mov) { progB[7] += 15; }
        if (board[1] == mov && board[7] == mov) { progB[4] += 15; }
        if (board[4] == mov && board[7] == mov) { progB[1] += 15; }

        if (board[2] == mov && board[5] == mov) { progB[8] += 15; }
        if (board[2] == mov && board[8] == mov) { progB[5] += 15; }
        if (board[5] == mov && board[8] == mov) { progB[2] += 15; }


        if (board[0] == mov && board[4] == mov) { progB[8] += 15; }
        if (board[0] == mov && board[8] == mov) { progB[4] += 15; }
        if (board[4] == mov && board[8] == mov) { progB[0] += 15; }

        if (board[2] == mov && board[4] == mov) { progB[6] += 15; }
        if (board[2] == mov && board[6] == mov) { progB[4] += 15; }
        if (board[4] == mov && board[6] == mov) { progB[2] += 15; }
    } // победа
    {
        if (board[0] == movS[(mov - 70) / 9 - 1] && board[1] == movS[(mov - 70) / 9 - 1]) { progB[2] += 10; }
        if (board[0] == movS[(mov - 70) / 9 - 1] && board[2] == movS[(mov - 70) / 9 - 1]) { progB[1] += 10; }
        if (board[1] == movS[(mov - 70) / 9 - 1] && board[2] == movS[(mov - 70) / 9 - 1]) { progB[0] += 10; }

        if (board[3] == movS[(mov - 70) / 9 - 1] && board[4] == movS[(mov - 70) / 9 - 1]) { progB[5] += 10; }
        if (board[3] == movS[(mov - 70) / 9 - 1] && board[5] == movS[(mov - 70) / 9 - 1]) { progB[4] += 10; }
        if (board[4] == movS[(mov - 70) / 9 - 1] && board[5] == movS[(mov - 70) / 9 - 1]) { progB[3] += 10; }

        if (board[6] == movS[(mov - 70) / 9 - 1] && board[7] == movS[(mov - 70) / 9 - 1]) { progB[8] += 10; }
        if (board[6] == movS[(mov - 70) / 9 - 1] && board[8] == movS[(mov - 70) / 9 - 1]) { progB[7] += 10; }
        if (board[7] == movS[(mov - 70) / 9 - 1] && board[8] == movS[(mov - 70) / 9 - 1]) { progB[6] += 10; }


        if (board[0] == movS[(mov - 70) / 9 - 1] && board[3] == movS[(mov - 70) / 9 - 1]) { progB[6] += 10; }
        if (board[0] == movS[(mov - 70) / 9 - 1] && board[6] == movS[(mov - 70) / 9 - 1]) { progB[3] += 10; }
        if (board[3] == movS[(mov - 70) / 9 - 1] && board[6] == movS[(mov - 70) / 9 - 1]) { progB[0] += 10; }

        if (board[1] == movS[(mov - 70) / 9 - 1] && board[4] == movS[(mov - 70) / 9 - 1]) { progB[7] += 10; }
        if (board[1] == movS[(mov - 70) / 9 - 1] && board[7] == movS[(mov - 70) / 9 - 1]) { progB[4] += 10; }
        if (board[4] == movS[(mov - 70) / 9 - 1] && board[7] == movS[(mov - 70) / 9 - 1]) { progB[1] += 10; }

        if (board[2] == movS[(mov - 70) / 9 - 1] && board[5] == movS[(mov - 70) / 9 - 1]) { progB[8] += 10; }
        if (board[2] == movS[(mov - 70) / 9 - 1] && board[8] == movS[(mov - 70) / 9 - 1]) { progB[5] += 10; }
        if (board[5] == movS[(mov - 70) / 9 - 1] && board[8] == movS[(mov - 70) / 9 - 1]) { progB[2] += 10; }


        if (board[0] == movS[(mov - 70) / 9 - 1] && board[4] == movS[(mov - 70) / 9 - 1]) { progB[8] += 10; }
        if (board[0] == movS[(mov - 70) / 9 - 1] && board[8] == movS[(mov - 70) / 9 - 1]) { progB[4] += 10; }
        if (board[4] == movS[(mov - 70) / 9 - 1] && board[8] == movS[(mov - 70) / 9 - 1]) { progB[0] += 10; }

        if (board[2] == movS[(mov - 70) / 9 - 1] && board[4] == movS[(mov - 70) / 9 - 1]) { progB[6] += 10; }
        if (board[2] == movS[(mov - 70) / 9 - 1] && board[6] == movS[(mov - 70) / 9 - 1]) { progB[4] += 10; }
        if (board[4] == movS[(mov - 70) / 9 - 1] && board[6] == movS[(mov - 70) / 9 - 1]) { progB[2] += 10; }
    } // поражение
    {
        if (board[0] == ' ' && board[1] == ' ') { progB[2] += 1; }
        if (board[0] == ' ' && board[2] == ' ') { progB[1] += 1; }
        if (board[1] == ' ' && board[2] == ' ') { progB[0] += 1; }

        if (board[3] == ' ' && board[4] == ' ') { progB[5] += 1; }
        if (board[3] == ' ' && board[5] == ' ') { progB[4] += 1; }
        if (board[4] == ' ' && board[5] == ' ') { progB[3] += 1; }

        if (board[6] == ' ' && board[7] == ' ') { progB[8] += 1; }
        if (board[6] == ' ' && board[8] == ' ') { progB[7] += 1; }
        if (board[7] == ' ' && board[8] == ' ') { progB[6] += 1; }


        if (board[0] == ' ' && board[3] == ' ') { progB[6] += 1; }
        if (board[0] == ' ' && board[6] == ' ') { progB[3] += 1; }
        if (board[3] == ' ' && board[6] == ' ') { progB[0] += 1; }

        if (board[1] == ' ' && board[4] == ' ') { progB[7] += 1; }
        if (board[1] == ' ' && board[7] == ' ') { progB[4] += 1; }
        if (board[4] == ' ' && board[7] == ' ') { progB[1] += 1; }

        if (board[2] == ' ' && board[5] == ' ') { progB[8] += 1; }
        if (board[2] == ' ' && board[8] == ' ') { progB[5] += 1; }
        if (board[5] == ' ' && board[8] == ' ') { progB[2] += 1; }


        if (board[0] == ' ' && board[4] == ' ') { progB[8] += 1; }
        if (board[0] == ' ' && board[8] == ' ') { progB[4] += 1; }
        if (board[4] == ' ' && board[8] == ' ') { progB[0] += 1; }

        if (board[2] == ' ' && board[4] == ' ') { progB[6] += 1; }
        if (board[2] == ' ' && board[6] == ' ') { progB[4] += 1; }
        if (board[4] == ' ' && board[6] == ' ') { progB[2] += 1; }
    } // атака1
    {
        if (board[0] == ' ' && board[1] == mov) { progB[2] += 2; }
        if (board[0] == ' ' && board[2] == mov) { progB[1] += 2; }
        if (board[1] == ' ' && board[2] == mov) { progB[0] += 2; }

        if (board[3] == ' ' && board[4] == mov) { progB[5] += 2; }
        if (board[3] == ' ' && board[5] == mov) { progB[4] += 2; }
        if (board[4] == ' ' && board[5] == mov) { progB[3] += 2; }

        if (board[6] == ' ' && board[7] == mov) { progB[8] += 2; }
        if (board[6] == ' ' && board[8] == mov) { progB[7] += 2; }
        if (board[7] == ' ' && board[8] == mov) { progB[6] += 2; }


        if (board[0] == ' ' && board[3] == mov) { progB[6] += 2; }
        if (board[0] == ' ' && board[6] == mov) { progB[3] += 2; }
        if (board[3] == ' ' && board[6] == mov) { progB[0] += 2; }

        if (board[1] == ' ' && board[4] == mov) { progB[7] += 2; }
        if (board[1] == ' ' && board[7] == mov) { progB[4] += 2; }
        if (board[4] == ' ' && board[7] == mov) { progB[1] += 2; }

        if (board[2] == ' ' && board[5] == mov) { progB[8] += 2; }
        if (board[2] == ' ' && board[8] == mov) { progB[5] += 2; }
        if (board[5] == ' ' && board[8] == mov) { progB[2] += 2; }


        if (board[0] == ' ' && board[4] == mov) { progB[8] += 2; }
        if (board[0] == ' ' && board[8] == mov) { progB[4] += 2; }
        if (board[4] == ' ' && board[8] == mov) { progB[0] += 2; }

        if (board[2] == ' ' && board[4] == mov) { progB[6] += 2; }
        if (board[2] == ' ' && board[6] == mov) { progB[4] += 2; }
        if (board[4] == ' ' && board[6] == mov) { progB[2] += 2; }



        if (board[0] == mov && board[1] == ' ') { progB[2] += 2; }
        if (board[0] == mov && board[2] == ' ') { progB[1] += 2; }
        if (board[1] == mov && board[2] == ' ') { progB[0] += 2; }

        if (board[3] == mov && board[4] == ' ') { progB[5] += 2; }
        if (board[3] == mov && board[5] == ' ') { progB[4] += 2; }
        if (board[4] == mov && board[5] == ' ') { progB[3] += 2; }

        if (board[6] == mov && board[7] == ' ') { progB[8] += 2; }
        if (board[6] == mov && board[8] == ' ') { progB[7] += 2; }
        if (board[7] == mov && board[8] == ' ') { progB[6] += 2; }


        if (board[0] == mov && board[3] == ' ') { progB[6] += 2; }
        if (board[0] == mov && board[6] == ' ') { progB[3] += 2; }
        if (board[3] == mov && board[6] == ' ') { progB[0] += 2; }

        if (board[1] == mov && board[4] == ' ') { progB[7] += 2; }
        if (board[1] == mov && board[7] == ' ') { progB[4] += 2; }
        if (board[4] == mov && board[7] == ' ') { progB[1] += 2; }

        if (board[2] == mov && board[5] == ' ') { progB[8] += 2; }
        if (board[2] == mov && board[8] == ' ') { progB[5] += 2; }
        if (board[5] == mov && board[8] == ' ') { progB[2] += 2; }


        if (board[0] == mov && board[4] == ' ') { progB[8] += 2; }
        if (board[0] == mov && board[8] == ' ') { progB[4] += 2; }
        if (board[4] == mov && board[8] == ' ') { progB[0] += 2; }

        if (board[2] == mov && board[4] == ' ') { progB[6] += 2; }
        if (board[2] == mov && board[6] == ' ') { progB[4] += 2; }
        if (board[4] == mov && board[6] == ' ') { progB[2] += 2; }
    } // атака2
    {
        if (board[0] == movS[(mov - 70) / 9 - 1] && board[1] == ' ') { progB[2] += 0.7; }
        if (board[0] == movS[(mov - 70) / 9 - 1] && board[2] == ' ') { progB[1] += 0.7; }
        if (board[1] == movS[(mov - 70) / 9 - 1] && board[2] == ' ') { progB[0] += 0.7; }

        if (board[3] == movS[(mov - 70) / 9 - 1] && board[4] == ' ') { progB[5] += 0.7; }
        if (board[3] == movS[(mov - 70) / 9 - 1] && board[5] == ' ') { progB[4] += 0.7; }
        if (board[4] == movS[(mov - 70) / 9 - 1] && board[5] == ' ') { progB[3] += 0.7; }

        if (board[6] == movS[(mov - 70) / 9 - 1] && board[7] == ' ') { progB[8] += 0.7; }
        if (board[6] == movS[(mov - 70) / 9 - 1] && board[8] == ' ') { progB[7] += 0.7; }
        if (board[7] == movS[(mov - 70) / 9 - 1] && board[8] == ' ') { progB[6] += 0.7; }


        if (board[0] == movS[(mov - 70) / 9 - 1] && board[3] == ' ') { progB[6] += 0.7; }
        if (board[0] == movS[(mov - 70) / 9 - 1] && board[6] == ' ') { progB[3] += 0.7; }
        if (board[3] == movS[(mov - 70) / 9 - 1] && board[6] == ' ') { progB[0] += 0.7; }

        if (board[1] == movS[(mov - 70) / 9 - 1] && board[4] == ' ') { progB[7] += 0.7; }
        if (board[1] == movS[(mov - 70) / 9 - 1] && board[7] == ' ') { progB[4] += 0.7; }
        if (board[4] == movS[(mov - 70) / 9 - 1] && board[7] == ' ') { progB[1] += 0.7; }

        if (board[2] == movS[(mov - 70) / 9 - 1] && board[5] == ' ') { progB[8] += 0.7; }
        if (board[2] == movS[(mov - 70) / 9 - 1] && board[8] == ' ') { progB[5] += 0.7; }
        if (board[5] == movS[(mov - 70) / 9 - 1] && board[8] == ' ') { progB[2] += 0.7; }


        if (board[0] == movS[(mov - 70) / 9 - 1] && board[4] == ' ') { progB[8] += 0.7; }
        if (board[0] == movS[(mov - 70) / 9 - 1] && board[8] == ' ') { progB[4] += 0.7; }
        if (board[4] == movS[(mov - 70) / 9 - 1] && board[8] == ' ') { progB[0] += 0.7; }

        if (board[2] == movS[(mov - 70) / 9 - 1] && board[4] == ' ') { progB[6] += 0.7; }
        if (board[2] == movS[(mov - 70) / 9 - 1] && board[6] == ' ') { progB[4] += 0.7; }
        if (board[4] == movS[(mov - 70) / 9 - 1] && board[6] == ' ') { progB[2] += 0.7; }



        if (board[0] == ' ' && board[1] == movS[(mov - 70) / 9 - 1]) { progB[2] += 0.7; }
        if (board[0] == ' ' && board[2] == movS[(mov - 70) / 9 - 1]) { progB[1] += 0.7; }
        if (board[1] == ' ' && board[2] == movS[(mov - 70) / 9 - 1]) { progB[0] += 0.7; }

        if (board[3] == ' ' && board[4] == movS[(mov - 70) / 9 - 1]) { progB[5] += 0.7; }
        if (board[3] == ' ' && board[5] == movS[(mov - 70) / 9 - 1]) { progB[4] += 0.7; }
        if (board[4] == ' ' && board[5] == movS[(mov - 70) / 9 - 1]) { progB[3] += 0.7; }

        if (board[6] == ' ' && board[7] == movS[(mov - 70) / 9 - 1]) { progB[8] += 0.7; }
        if (board[6] == ' ' && board[8] == movS[(mov - 70) / 9 - 1]) { progB[7] += 0.7; }
        if (board[7] == ' ' && board[8] == movS[(mov - 70) / 9 - 1]) { progB[6] += 0.7; }


        if (board[0] == ' ' && board[3] == movS[(mov - 70) / 9 - 1]) { progB[6] += 0.7; }
        if (board[0] == ' ' && board[6] == movS[(mov - 70) / 9 - 1]) { progB[3] += 0.7; }
        if (board[3] == ' ' && board[6] == movS[(mov - 70) / 9 - 1]) { progB[0] += 0.7; }

        if (board[1] == ' ' && board[4] == movS[(mov - 70) / 9 - 1]) { progB[7] += 0.7; }
        if (board[1] == ' ' && board[7] == movS[(mov - 70) / 9 - 1]) { progB[4] += 0.7; }
        if (board[4] == ' ' && board[7] == movS[(mov - 70) / 9 - 1]) { progB[1] += 0.7; }

        if (board[2] == ' ' && board[5] == movS[(mov - 70) / 9 - 1]) { progB[8] += 0.7; }
        if (board[2] == ' ' && board[8] == movS[(mov - 70) / 9 - 1]) { progB[5] += 0.7; }
        if (board[5] == ' ' && board[8] == movS[(mov - 70) / 9 - 1]) { progB[2] += 0.7; }


        if (board[0] == ' ' && board[4] == movS[(mov - 70) / 9 - 1]) { progB[8] += 0.7; }
        if (board[0] == ' ' && board[8] == movS[(mov - 70) / 9 - 1]) { progB[4] += 0.7; }
        if (board[4] == ' ' && board[8] == movS[(mov - 70) / 9 - 1]) { progB[0] += 0.7; }

        if (board[2] == ' ' && board[4] == movS[(mov - 70) / 9 - 1]) { progB[6] += 0.7; }
        if (board[2] == ' ' && board[6] == movS[(mov - 70) / 9 - 1]) { progB[4] += 0.7; }
        if (board[4] == ' ' && board[6] == movS[(mov - 70) / 9 - 1]) { progB[2] += 0.7; }
    } // защита

    int max_ = -10;
    int max_index = 0;
    for (int i = 0; i < 9; i++)
    {
        if (progB[i] > max_)
        {
            max_ = progB[i];
            max_index = i;
        }
    }
    return max_index;
}

void out_()
{
    for (int i = 0; i < 4; i++)
    { 
        for (int p = 0; p < 3; p++)
        {
            SetConsoleTextAttribute(hc, 2 * (int)((v % 3 == p || v % 3 == p - 1) && ((((v - v % 3) / 3 == i) || ((v - v % 3) / 3 == i - 1)))) + 7);
            cout << "+";
            SetConsoleTextAttribute(hc, 2 * (int)((v % 3 == p) && (((((v - v % 3) / 3 == i) || ((v - v % 3) / 3 == i - 1))))) + 7);
            cout << "---";
        }
        cout << "+\n";
        if (i != 3)
        {
            for (int j = 0; j < 4; j++)
            {
                SetConsoleTextAttribute(hc, 2 * (int)((v % 3 == j || v % 3 == j - 1) && (((v - v % 3) / 3 == i))) + 7);
                cout << "| ";
                SetConsoleTextAttribute(hc, 2 * (int)((v % 3 == j) && (((v - v % 3) / 3 == i))) + 7);
                if (j != 3)
                {
                    cout << board[i * 3 + j];
                }
                cout << " ";
            }
            cout << "\n";
        }
    }
    cout << "\b";
}

bool full_board()
{
    int full_board_var = 0;
    for (int i = 0; i < 9; i++)
    {
        if (board[i] != ' ')
        {
            full_board_var++;
        }
    }
    if (full_board_var == 9)
    {
        return true;
    }
    return false;
}

bool finish()
{
    SetConsoleTextAttribute(hc, 7);
    if ((board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
     || (board[0] == 'X' && board[3] == 'X' && board[6] == 'X')
     || (board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
     || (board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
     || (board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
     || (board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
     || (board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
     || (board[6] == 'X' && board[7] == 'X' && board[8] == 'X'))
    {
        SetConsoleCursorPosition(hc, { 0, 10 });
        cout << "X wins!";
        return true;
    }
    else if ((board[0] == 'O' && board[1] == 'O' && board[2] == 'O')
          || (board[0] == 'O' && board[3] == 'O' && board[6] == 'O')
          || (board[0] == 'O' && board[4] == 'O' && board[8] == 'O')
          || (board[1] == 'O' && board[4] == 'O' && board[7] == 'O')
          || (board[2] == 'O' && board[4] == 'O' && board[6] == 'O')
          || (board[2] == 'O' && board[5] == 'O' && board[8] == 'O')
          || (board[3] == 'O' && board[4] == 'O' && board[5] == 'O')
          || (board[6] == 'O' && board[7] == 'O' && board[8] == 'O'))
    {
        SetConsoleCursorPosition(hc, { 0, 10 });
        cout << "O wins!";
        return true;
    }
    else if (full_board())
    {
        SetConsoleCursorPosition(hc, { 0, 10 });
        cout << "Draw!";
        return true;
    }
    return false;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        board += ' ';
    }
    char pl = ' ';
    while (pl != 'X' && pl != 'O')
    {
        cout << "Choose: X or O. ";
        cin >> pl;
        pl = toupper(pl);
    }
    system("cls");
    while (!finish())
    {
        HANDLE s_in = GetStdHandle(STD_INPUT_HANDLE);
        DWORD dr;
        INPUT_RECORD  rec;
        ReadConsoleInput(s_in, &rec, sizeof(INPUT_RECORD), &dr);
        FlushConsoleInputBuffer(s_in);
        if (rec.EventType == KEY_EVENT) {
            if (rec.Event.KeyEvent.bKeyDown) {
                switch (rec.Event.KeyEvent.wVirtualKeyCode) {
                case VK_LEFT:
                    v -= 1 * (int)(v % 3 != 0);
                    break;
                case VK_RIGHT:
                    v += 1 * (int)(v % 3 != 2);
                    break;
                case VK_UP:
                    v -= 3 * (int)(v > 2);
                    break;
                case VK_DOWN:
                    v += 3 * (int)(v < 6);
                    break;
                case VK_RETURN:
                    if (board[v] == ' ')
                    {
                        board[v] = pl;
                        moveN = movS[(moveN - 70) / 9 - 1];
                    }
                    break;
                }
            }
        }
        SetConsoleCursorPosition(hc, { 0, 0 });
        if (moveN != pl && !finish())
        {
            board[move(movS[(pl - 70) / 9 - 1])] = movS[(pl - 70) / 9 - 1];
            moveN = pl;
        }
        if (!finish())
        {
            out_();
        }
    }
    SetConsoleCursorPosition(hc, { 0, 0 });
    v = 100;
    out_();
    SetConsoleCursorPosition(hc, { 0, 15 });
    std::system("pause");
}
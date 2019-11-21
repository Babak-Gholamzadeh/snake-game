#include <iostream>
#include <conio.h>
#include <windows.h>
#include <process.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void gotoxy(int x,int y)
{
    COORD pos;
    HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );

    if (INVALID_HANDLE_VALUE != hConsole)
    {
        pos.X = x;
        pos.Y = y;

        SetConsoleCursorPosition( hConsole, pos );
    }
}

char x = 39, y = 12;
char sn[2][500] = {{39, 38, 37, 36}, {12, 12, 12, 12}};
int l = 4;
char key = 77;
char a = 1;
int s = 300;

void sharr()
{
    for (int i = l; i > 0; i--)
    {
        sn[0][i] = sn[0][i - 1];
        sn[1][i] = sn[1][i - 1];
    }
    sn[0][0] = x;
    sn[1][0] = y;
}

void mv(void *dummy)
{
    char t = 1;
    char xf, yf;

    srand(time(0));
    xf = rand() % 80;
    yf = rand() % 25;

    while(t)
    {
        if (l > 400)
        {
            system("cls");
            gotoxy(35, 12);
            system("color 1e");
            cout << "YOU WIN! :)";
            getch();
            exit(0);
        }
        gotoxy(xf, yf);
        cout << "@";

        Sleep(s);
        switch(key)
        {
        case 75:
            if (a != 1)
                a = 3;
            break;
        case 80:
            if (a != 2)
                a = 4;
            break;
        case 77:
            if (a != 3)
                a = 1;
            break;
        case 72:
            if (a != 4)
                a = 2;
            break;
        }
        switch(a)
        {
        case 1:
            x++;
            break;
        case 2:
            y--;
            break;
        case 3:
            x--;
            break;
        case 4:
            y++;
            break;
        }
        sharr();
        gotoxy(x, y);
        cout << "#";
        if ((x == xf) && (y == yf))
        {
            l++;
            l++;
            l++;
            xf = rand() % 80;
            yf = rand() % 25;
        }
        gotoxy(sn[0][l], sn[1][l]);
        cout << " ";
        for (int i = 1; i < l; i++)
            if ((x == sn[0][i]) && (y == sn[1][i]))
                t = 0;
        if ((x > 79) || (x < 0) || (y > 24) || (y < 0))
            t = 0;
    }
    gotoxy(0, 0);
    for (int i = 0; i < 160; i++)
    {
        Sleep(20L);
        system("color c");
        cout << "GAME OVER!!!!";
    }
    return;
}

int main()
{
    system("Color e");

    for (int i = 0; i < l; i++)
    {
        gotoxy(sn[0][i], sn[1][i]);
        cout << "#";
    }

    _beginthread(mv, 0, NULL );

    while(1)
    {
        key = getch();
        if (key == 'f')
        {
            if (s == 300)
                s = 70;
            else
                s = 300;
        }
        else
            key = getch();
    }
    return 0;
}

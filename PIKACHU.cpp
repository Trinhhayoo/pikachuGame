#include <bits/stdc++.h>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <string>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <thread>
#include <chrono>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std::chrono;
using namespace std;
#define STD_OUTPUT_HANDLE ((DWORD)-11)
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
struct Board
{
    string HaiBen;
    string TrenDuoi;
};
struct Point
{
    int x;
    int y;
};
void WaitKey()
{
    while (_kbhit())
        _getch(); // Empty the input buffer
    _getch();     // Wait for a key
    while (_kbhit())
        _getch(); // Empty the input buffer (some keys sends two messages)
}
void taochu(string**& character, int row, int col)
{
    srand((int)time(0));
    int DemSoluongCharacter = 0;
    int a = row + 2;
    int b = col + 2;
    int SoLuongLoaiKyTu = row * col / 2;
    string *loaichu=new string[SoLuongLoaiKyTu];
    string kyTuSoSanh = "0";

    for (int i = 0; i < (row * col) / 2; i++)
    {
        loaichu[i] = rand() % 26 + 'A';
        // cout << loaichu[i] << " ";
    }

    for (int i = 0;; i++)
    {
        while (true)
        {

            int ToaDoHang = 1 + rand() % row;
            int ToaDoCot = 1 + rand() % col;

            // cout << ToaDoCot << " " << ToaDoHang << endl;

            // cout << ToaDoChar << endl;

            if (character[ToaDoCot][ToaDoHang] == kyTuSoSanh)
            {
                character[ToaDoCot][ToaDoHang] = loaichu[i];

                // cout << character[ToaDoCot][ToaDoHang];
                DemSoluongCharacter++;

                break;
            }
        }
        while (true)
        {

            int ToaDoHang = 1 + rand() % (row + 1);
            int ToaDoCot = 1 + rand() % (col + 1);

            if (character[ToaDoCot][ToaDoHang] == kyTuSoSanh)
            {
                character[ToaDoCot][ToaDoHang] = loaichu[i];

                // cout << character[ToaDoCot][ToaDoHang] << endl;

                DemSoluongCharacter++;

                break;
            }
        }
        if (DemSoluongCharacter == row * col)
        {
            break;
        }
    }
}
void CreateBoard(struct Board**& board, int row, int col)
{
    board = new Board * [col];
    for (int i = 0; i < col; i++)
    {
        board[i] = new Board[row];
    }
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            board[i][j].HaiBen = "|";
            board[i][j].TrenDuoi = "---------------";
        }
    }
}
void CreateMangSo(int**& MangSo, int row, int col)
{
    for (int i = 0; i < col + 2; i++)
    {
        for (int j = 0; j < row + 2; j++)
        {

            if (i == 0 || i == col + 1 || j == 0 || j == row + 1)
            {
                MangSo[i][j] = 0;
            }
            else
            {
                MangSo[i][j] = 2;
            }
        }
    }
}
void CreatCharacter(string**& character, int row, int col)
{
    for (int i = 0; i < col + 2; i++)
    {
        for (int j = 0; j < row + 2; j++)
        {
            if (i == 0 || i == col + 1 || j == 0 || j == row + 1)
            {
                character[i][j] = "2";
            }
            else
            {
                character[i][j] = "0";
            }
        }
    }
}
void CreateToaDoIn(string**& ToaDoIn, int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            std::string ChuyenDoiToaDoHang = std::to_string(j + 1);
            std::string ChuyenDoiToaDoCot = std::to_string(i + 1);

            ToaDoIn[i][j] = ChuyenDoiToaDoCot + ChuyenDoiToaDoHang;
        }
    }
}
void RemoveToaDoIn(string**& ToaDoIn, Point p1, Point p2)
{
    ToaDoIn[p1.y - 1][p1.x - 1] = "  ";
    ToaDoIn[p2.y - 1][p2.x - 1] = "  ";
}
void PainBoard(string** character, struct Board** board, int row, int col, string** ToaDoIn, Point p1, Point p2, int checkToMau)
{
    cout << "GAME PIKACHU" << endl;
    for (int i = 0; i < col; i++)
    {

        for (int j = 0; j < row; j++)
        {

            cout << board[i][j].TrenDuoi;

            cout << " ";
        }

        cout << endl;
        for (int h = 0; h < row; h++)
        {
            if ((p1.x - 1 == h && p1.y - 1 == i) || (p2.x - 1 == h && p2.y - 1 == i))
            {
                int y;
                if (checkToMau != 0)
                {

                    y = 240; // 240 = white background, black foreground
                }
                else
                {
                    y = 100;
                }
                // start 3 down, 2 tabs, right

                SetConsoleTextAttribute(console, y); // set color for the next print
                cout << board[i][h].HaiBen << ToaDoIn[i][h];
                cout << "           ";
                cout << board[i][h].HaiBen;
                // add 1 to y, for a new color
                // if y > 254, start colors back at white background, black chars
                // Pause between letters

                SetConsoleTextAttribute(console, 15); // set color to black background, white chars
                // WaitKey();
                cout << " ";
                // Program over, wait for a keypress to close program
            }

            else
            {
                cout << board[i][h].HaiBen << ToaDoIn[i][h];
                cout << "           ";
                cout << board[i][h].HaiBen;
                cout << " ";
            }
        }
        cout << endl;
        for (int h = 0; h < row; h++)
        {
            if ((p1.x - 1 == h && p1.y - 1 == i) || (p2.x - 1 == h && p2.y - 1 == i))
            {
                int y;
                if (checkToMau != 0)
                {

                    y = 240; // 240 = white background, black foreground
                }
                else
                {
                    y = 100;
                } // 240 = white background, black foreground

                // start 3 down, 2 tabs, right

                SetConsoleTextAttribute(console, y); // set color for the next print
                cout << board[i][h].HaiBen;
                cout << "      ";
                cout << character[i + 1][h + 1];
                cout << "      ";
                cout << board[i][h].HaiBen;
                // add 1 to y, for a new color
                // if y > 254, start colors back at white background, black chars
                // Pause between letters

                SetConsoleTextAttribute(console, 15); // set color to black background, white chars
                // WaitKey();
                cout << " ";
                // Program over, wait for a keypress to close program
            }
            else
            {
                cout << board[i][h].HaiBen;
                cout << "      ";
                cout << character[i + 1][h + 1];
                cout << "      ";
                cout << board[i][h].HaiBen;
                cout << " ";
            }
        }

        cout << endl;
        for (int h = 0; h < row; h++)
        {
            if ((p1.x - 1 == h && p1.y - 1 == i) || (p2.x - 1 == h && p2.y - 1 == i))
            {
                int y;
                if (checkToMau != 0)
                {

                    y = 240; // 240 = white background, black foreground
                }
                else
                {
                    y = 100;
                } // 240 = white background, black foreground

                // start 3 down, 2 tabs, right

                SetConsoleTextAttribute(console, y); // set color for the next print
                cout << board[i][h].HaiBen;
                cout << "             ";
                cout << board[i][h].HaiBen;
                // add 1 to y, for a new color
                // if y > 254, start colors back at white background, black chars
                // Pause between letters

                SetConsoleTextAttribute(console, 15); // set color to black background, white chars
                // WaitKey();
                cout << " ";
                // Program over, wait for a keypress to close program
            }
            else
            {
                cout << board[i][h].HaiBen;
                cout << "             ";
                cout << board[i][h].HaiBen;
                cout << " ";
            }
        }

        cout << endl;
        for (int j = 0; j < row; j++)
        {
            cout << board[i][j].TrenDuoi;
            cout << " ";
        }
        cout << endl;
    }
}
int checkMin(int num1, int num2)
{
    if (num1 > num2)
    {
        return num2;
    }
    return num1;
}
int checkMax(int num1, int num2)
{
    if (num1 < num2)
    {
        return num2;
    }
    return num1;
}
void RemovePoint(string**& character, int**& MangSo, int row, int col, struct Board**& board, int x1, int x2, int y1, int y2)

{
    character[y1][x1] = " ";
    character[y2][x2] = " ";

    board[y1 - 1][x1 - 1].HaiBen = " ";
    board[y1 - 1][x1 - 1].TrenDuoi = "               ";

    board[y2 - 1][x2 - 1].HaiBen = " ";
    board[y2 - 1][x2 - 1].TrenDuoi = "               ";
    MangSo[y1][x1] = 0;
    MangSo[y2][x2] = 0;
}
bool IMatching1(int y1, int y2, int x, string** character, int row, int col, int** MangSo)
{
    // find point have column max and min
    int barrier = 2;
    int min = checkMin(y1, y2);
    int max = checkMax(y1, y2);
    // run column
    for (int y = min; y <= max; y++)
    {
        // if (x == 2 || x == row + 1)
        // {
        //     return true;
        // }
        if (MangSo[y][x] == barrier)
        { // if see barrier then die
            // System.out.println("die: " + x + "" + y);
            return false;
        }
        // System.out.println("ok: " + x + "" + y);
    }

    // not die -> success
    return true;
}
bool IMatching2(int x1, int x2, int y, string** character, int row, int col, int** MangSo)
{
    int barrier = 2;
    int min = checkMin(x1, x2);
    int max = checkMax(x1, x2);
    // run column
    for (int x = min; x <= max; x++)
    {
        // if (y == 2 || y == col + 1)
        // {

        //     return true;
        // }
        if (MangSo[y][x] == barrier)
        { // if see barrier then die
            // System.out.println("die: " + x + "" + y);
            return false;
        }
        // System.out.println("ok: " + x + "" + y);
    }

    // not die -> success
    return true;
}
bool ZMatching1(Point p1, Point p2, string** character, int row, int col, int** MangSo)
{
    // find point have y min and max
    Point pMinY = p1, pMaxY = p2;
    if (p1.y > p2.y)
    {
        pMinY = p2;
        pMaxY = p1;
    }
    for (int y = pMinY.y + 1; y < pMaxY.y; y++)
    {
        // check three line
        if (IMatching1(pMinY.y, y, pMinY.x, character, row, col, MangSo) && IMatching2(pMinY.x, pMaxY.x, y, character, row, col, MangSo) && IMatching1(y, pMaxY.y, pMaxY.x, character, row, col, MangSo))
        {

            // if three line is true return column y
            return true;
        }
    }
    // have a line in three line not true then return -1
    return false;
}
bool ZMatching2(Point p1, Point p2, string** character, int row, int col, int** MangSo)
{
    // find point have y min
    Point pMinX = p1, pMaxX = p2;
    if (p1.x > p2.x)
    {
        pMinX = p2;
        pMaxX = p1;
    }
    // find line and y begin
    for (int x = pMinX.x + 1; x < pMaxX.x; x++)
    {
        if (IMatching2(pMinX.x, x, pMinX.y, character, row, col, MangSo) && IMatching1(pMinX.y, pMaxX.y, x, character, row, col, MangSo) && IMatching2(x, pMaxX.x, pMaxX.y, character, row, col, MangSo))
        {

            return true;
        }
    }
    return false;
}
int L_UMatching1(Point p1, Point p2, int type, int** MangSo, string** character, int row, int col)
{
    // find point have y min
    int barrier = 2;

    Point pMinY = p1, pMaxY = p2;
    if (p1.y > p2.y)
    {
        pMinY = p2;
        pMaxY = p1;
    }
    // find line and y begin
    int y = pMaxY.y;
    int hang = pMinY.x;
    if (type == -1)
    {
        y = pMinY.y;
        hang = pMaxY.x;
    }
    // check more
    if (IMatching1(pMinY.y, pMaxY.y, hang, character, row, col, MangSo))
    {
        while (MangSo[y][pMinY.x] != barrier && MangSo[y][pMaxY.x] != barrier)
        {
            if (IMatching2(pMinY.x, pMaxY.x, y, character, row, col, MangSo))
            {
                return y;
            }

            y += type;
        }
    }
    return -1;
}
int L_UMatching2(Point p1, Point p2, int type, string** character, int** MangSo, int row, int col)
{
    int barrier = 2;

    Point pMinX = p1, pMaxX = p2;

    if (p1.x > p2.x)
    {
        pMinX = p2;
        pMaxX = p1;
    }
    int x = pMaxX.x;
    int cot = pMinX.y;
    if (type == -1)
    {
        x = pMinX.x;
        cot = pMaxX.y;
    }
    if (IMatching2(pMinX.x, pMaxX.x, cot, character, row, col, MangSo))
    {
        while (MangSo[pMinX.y][x] != barrier && MangSo[pMaxX.y][x] != barrier)
        {
            if (IMatching1(pMinX.y, pMaxX.y, x, character, row, col, MangSo))
            {

                return x;
            }
            x += type;
        }
    }
    return -1;
}
int CheckMoveSuggestion(string** character, struct Board** board, int row, int col, struct Point p1, struct Point p2, int** MangSo, string** ToaDoIn, int checkToMau, int& KiemTraTrung)
{
    KiemTraTrung = 0;
    int checkReturn = 1;

    int x1 = p1.x;
    int y1 = p1.y;
    int x2 = p2.x;
    int y2 = p2.y;

    MangSo[y1][x1] = 1;
    MangSo[y2][x2] = 1;
    // PrintMaTran(MangSo, row, col);
    if (character[y1][x1] != character[y2][x2])
    {
        MangSo[y1][x1] = 2;
        MangSo[y2][x2] = 2;
        return -1;
    }
    if (x1 == x2)
    {
        if (IMatching1(y1, y2, x1, character, row, col, MangSo))
        {
            KiemTraTrung = 1;
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(450);
            system("cls");

            return 0;
        }
        else if ((checkReturn = L_UMatching2(p1, p2, 1, character, MangSo, row, col)) != -1)
        {
            KiemTraTrung = 1;
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(450);
            system("cls");

            return 0;
        }

        else if ((checkReturn = L_UMatching2(p1, p2, -1, character, MangSo, row, col)) != -1)
        {
            KiemTraTrung = 1;
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(450);
            system("cls");

            return 0;
        }
    }
    else if (y1 == y2)
    {
        if (IMatching2(x1, x2, y1, character, row, col, MangSo))
        {
            KiemTraTrung = 1;
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(450);
            system("cls");

            return 0;
        }
        else if ((checkReturn = L_UMatching1(p1, p2, 1, MangSo, character, row, col)) != -1)
        {
            KiemTraTrung = 1;
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(450);
            system("cls");

            return 0;
        }

        else if ((checkReturn = L_UMatching1(p1, p2, -1, MangSo, character, row, col)) != -1)
        {
            KiemTraTrung = 1;
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(450);
            system("cls");

            return 0;
        }
    }
    else
    {
        if (ZMatching1(p1, p2, character, row, col, MangSo))
        {
            KiemTraTrung = 1;
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(450);
            system("cls");

            return 0;
        }
        else if (ZMatching2(p1, p2, character, row, col, MangSo))
        {
            KiemTraTrung = 1;
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(450);
            system("cls");

            return 0;
        }

        else if ((checkReturn = L_UMatching1(p1, p2, 1, MangSo, character, row, col)) != -1)
        {
            KiemTraTrung = 1;
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(450);
            system("cls");

            return 0;
        }

        else if ((checkReturn = L_UMatching1(p1, p2, -1, MangSo, character, row, col)) != -1)
        {
            KiemTraTrung = 1;
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(450);
            system("cls");

            return 0;
        }

        else if ((checkReturn = L_UMatching2(p1, p2, 1, character, MangSo, row, col)) != -1)
        {
            KiemTraTrung = 1;
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(450);
            system("cls");

            return 0;
        }

        else if ((checkReturn = L_UMatching2(p1, p2, -1, character, MangSo, row, col)) != -1)
        {
            KiemTraTrung = 1;
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(450);
            system("cls");

            return 0;
        }
    }

    MangSo[y1][x1] = 2;
    MangSo[y2][x2] = 2;

    return -1;
}
int MoveSuggestion(string** character, int** MangSo, Point p1, Point p2, string** ToaDoIn, int checkToMau, int row, int col, Board** board, int KiemTraTrung)
{
    int checkReturn = 1;
    int SoLanDoi = 0;
    for (int i = 1; i < col + 1; i++)
    {
        p1.y = i;
        for (int j = 1; j < row + 1; j++)
        {

            p1.x = j;
            if (MangSo[p1.y][p1.x] != 2)
            {
                continue;
            }
            for (int h = 1; h < col + 1; h++)
            {
                p2.y = h;

                for (int k = 1; k < row + 1; k++)
                {
                    p2.x = k;
                    if (MangSo[p2.y][p2.x] != 2)
                    {
                        SoLanDoi++;
                        continue;
                    }
                    if (i == h && j == k)
                    {

                        continue;
                    }
                    CheckMoveSuggestion(character, board, row, col, p1, p2, MangSo, ToaDoIn, checkToMau, KiemTraTrung);
                    if (KiemTraTrung == 1)
                    {
                        MangSo[p1.y][p1.x] = 2;
                        MangSo[p2.y][p2.x] = 2;
                        return 0;
                    }
                    else
                    {
                        MangSo[p1.y][p1.x] = 2;
                        MangSo[p2.y][p2.x] = 2;
                        SoLanDoi++;
                    }
                }
            }
        }
    }

    cout << "Sorry, run out of moves!" << endl;
    exit(1);
    return SoLanDoi;
}
int check(string**& character, struct Board**& board, int row, int col, struct Point p1, struct Point p2, int**& MangSo, string**& ToaDoIn, int checkToMau, int KiemTraTrung)
{
    string help;
    int checkReturn = 1;
    do
    {
        cout << "Enter the coordinates of the x1 row you want to select: ";
        cin >> p1.x;
        cout << "Enter the coordinates of the y1 column you want to select: ";
        cin >> p1.y;

    } while (MangSo[p1.y][p1.x] != 2);
    // PlaySound("TEXT("MusicName.wav")", NULL, SND_SYNC);
    system("cls");

    PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
    Sleep(250);

    do
    {

        cout << "Enter the coordinates of the x1 row you want to select: ";
        cin >> p2.x;
        cout << "Enter the coordinates of the y1 column you want to select: ";
        cin >> p2.y;

    } while (MangSo[p1.y][p1.x] != 2);
    system("cls");

    PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
    Sleep(250);
    system("cls");

    int x1 = p1.x;
    int y1 = p1.y;
    int x2 = p2.x;
    int y2 = p2.y;
    MangSo[y1][x1] = 1;
    MangSo[y2][x2] = 1;
    // PrintMaTran(MangSo, row, col);
    if (character[y1][x1] != character[y2][x2])
    {
        MangSo[y1][x1] = 2;
        MangSo[y2][x2] = 2;
        cout << "Do you want to help? press y/n" << endl;
        cin >> help;
        if (help == "y" || help == "Y")
        {
            MoveSuggestion(character, MangSo, p1, p2, ToaDoIn, checkToMau, row, col, board, KiemTraTrung);
        }

        // PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
        return -1;
    }
    if (x1 == x2)
    {
        if (IMatching1(y1, y2, x1, character, row, col, MangSo))
        {
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(250);
            system("cls");

            // cout << "lineXTRUE" << endl;

            RemovePoint(character, MangSo, row, col, board, x1, x2, y1, y2);
            RemoveToaDoIn(ToaDoIn, p1, p2);

            // PrintMaTran(MangSo, row, col);
            return 0;
        }
        else if ((checkReturn = L_UMatching2(p1, p2, 1, character, MangSo, row, col)) != -1)
        {
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(250);
            system("cls");
            // cout << "L_UMatching2" << endl;

            RemovePoint(character, MangSo, row, col, board, x1, x2, y1, y2);
            RemoveToaDoIn(ToaDoIn, p1, p2);

            return 0;
        }

        else if ((checkReturn = L_UMatching2(p1, p2, -1, character, MangSo, row, col)) != -1)
        {
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(250);
            system("cls");
            // cout << "L_UMatching2" << endl;

            RemovePoint(character, MangSo, row, col, board, x1, x2, y1, y2);
            RemoveToaDoIn(ToaDoIn, p1, p2);

            return 0;
        }
    }
    else if (y1 == y2)
    {
        if (IMatching2(x1, x2, y1, character, row, col, MangSo))
        {
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(250);
            system("cls");
            // cout << "lineYTRUE" << endl;

            RemovePoint(character, MangSo, row, col, board, x1, x2, y1, y2);
            RemoveToaDoIn(ToaDoIn, p1, p2);

            // PrintMaTran(MangSo, row, col);
            return 0;
        }
        else if ((checkReturn = L_UMatching1(p1, p2, 1, MangSo, character, row, col)) != -1)
        {
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(250);
            system("cls");
            // cout << "L_UMatching1" << endl;

            RemovePoint(character, MangSo, row, col, board, x1, x2, y1, y2);
            RemoveToaDoIn(ToaDoIn, p1, p2);

            return 0;
        }

        else if ((checkReturn = L_UMatching1(p1, p2, -1, MangSo, character, row, col)) != -1)
        {
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(250);
            system("cls");
            // cout << "L_UMatching1" << endl;
            RemovePoint(character, MangSo, row, col, board, x1, x2, y1, y2);
            RemoveToaDoIn(ToaDoIn, p1, p2);

            return 0;
        }
    }
    else
    {
        if (ZMatching1(p1, p2, character, row, col, MangSo))
        {
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(250);
            system("cls");
            // cout << "lineRECTXTRUE" << endl;

            RemovePoint(character, MangSo, row, col, board, x1, x2, y1, y2);
            RemoveToaDoIn(ToaDoIn, p1, p2);

            return 0;
        }
        else if (ZMatching2(p1, p2, character, row, col, MangSo))
        {
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(250);
            system("cls");
            // cout << "lineRectYTRUE" << endl;
            RemovePoint(character, MangSo, row, col, board, x1, x2, y1, y2);
            RemoveToaDoIn(ToaDoIn, p1, p2);

            return 0;
        }

        else if ((checkReturn = L_UMatching1(p1, p2, 1, MangSo, character, row, col)) != -1)
        {
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(250);
            system("cls");
            // cout << "L_UMatching1" << endl;

            RemovePoint(character, MangSo, row, col, board, x1, x2, y1, y2);
            RemoveToaDoIn(ToaDoIn, p1, p2);

            return 0;
        }

        else if ((checkReturn = L_UMatching1(p1, p2, -1, MangSo, character, row, col)) != -1)
        {
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(250);
            system("cls");
            // cout << "L_UMatching1" << endl;
            RemovePoint(character, MangSo, row, col, board, x1, x2, y1, y2);
            RemoveToaDoIn(ToaDoIn, p1, p2);

            return 0;
        }

        else if ((checkReturn = L_UMatching2(p1, p2, 1, character, MangSo, row, col)) != -1)
        {
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(250);
            system("cls");
            // cout << "L_UMatching2" << endl;

            RemovePoint(character, MangSo, row, col, board, x1, x2, y1, y2);
            RemoveToaDoIn(ToaDoIn, p1, p2);

            return 0;
        }

        else if ((checkReturn = L_UMatching2(p1, p2, -1, character, MangSo, row, col)) != -1)
        {
            checkToMau = 0;
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            Sleep(250);
            system("cls");
            // cout << "L_UMatching2" << endl;

            RemovePoint(character, MangSo, row, col, board, x1, x2, y1, y2);
            RemoveToaDoIn(ToaDoIn, p1, p2);

            return 0;
        }
    }

    MangSo[y1][x1] = 2;
    MangSo[y2][x2] = 2;

    return -1;
}

int FuncRun(string** character, int** MangSo, Board** board, int row, int col, Point p1, Point p2, string** ToaDoIn, int checkToMau, int KiemTraTrung)
{
    int demSoODaDuocChon = 0;
    while (true)
    {

        int CheckDung = 0;

        auto start = high_resolution_clock::now();

        check(character, board, row, col, p1, p2, MangSo, ToaDoIn, checkToMau, KiemTraTrung);
        PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        if (duration.count() >= 500000000)
        {
            // MoveSuggestion(character, MangSo, p1, p2, ToaDoIn, checkToMau, row, col, board, KiemTraTrung);

            // PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            cout << "You have run out of time" << endl;
            cout << "You loss!" << endl;
            exit(1);
        }

        // PrintMaTran(MangSo, row, col);
        for (int i = 1; i < col + 1; i++)
        {
            for (int j = 1; j < row + 1; j++)
            {
                if (MangSo[i][j] == 0)
                {
                    CheckDung += 1;
                }
            }
        }
        if (CheckDung == row * col)
        {
            break;
        }
    }

    cout << "You win!" << endl;
    Sleep(250);

    return 0;
}
void insertionSort(vector<string>& CopyBangXepHang)
{
    int i, j;

    double key;
    for (i = 1; i < CopyBangXepHang.size() - 1; i++)
    {

        string ItemBangXepHang = CopyBangXepHang[i];
        key = stod(ItemBangXepHang);
        j = i - 1;
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && std::stod(CopyBangXepHang[j]) > key)
        {
            CopyBangXepHang[j + 1] = CopyBangXepHang[j];
            j = j - 1;
        }
        CopyBangXepHang[j + 1] = std::to_string(key);
    }
}
void CopyMang(vector<string>& CopyBangXepHang)
{
    string ThoiGian;
    fstream FileThoiGian;
    FileThoiGian.open("BangXepHang.txt", ios::in);
    if (!FileThoiGian.is_open())
    {
        cout << "error" << endl;
        exit(1);
    }
    FileThoiGian.seekg(0, ios::beg);
    while (!FileThoiGian.eof())
    {
        getline(FileThoiGian, ThoiGian);
        CopyBangXepHang.push_back(ThoiGian);
    }

    FileThoiGian.close();
}
int SapXepBangXepHang(vector<string> CopyBangXepHang)
{
    fstream FileThoiGian;
    FileThoiGian.open("bangxephang.txt", ios::out);
    if (!FileThoiGian.is_open())
    {
        cout << "cannot open file" << endl;
        return 0;
    }
    FileThoiGian.seekg(0, ios::beg);
    for (int i = 0; i < CopyBangXepHang.size() - 1; i++)
    {
        FileThoiGian << CopyBangXepHang[i] << endl;
    }
    FileThoiGian.close();
    return 0;
}
int menu(int& chon)
{
    cout << "                                            ";
    SetConsoleTextAttribute(console, 90);

    cout << "              ";

    SetConsoleTextAttribute(console, 15);
    cout << "                                            ";
    cout << endl;
    cout << "                                            ";
    SetConsoleTextAttribute(console, 90);

    cout << "     MENU     ";

    SetConsoleTextAttribute(console, 15);
    cout << "                                            ";
    cout << endl;
    cout << "                                            ";
    SetConsoleTextAttribute(console, 90);

    cout << "              ";

    SetConsoleTextAttribute(console, 15);
    cout << "                                            ";
    // Menu
    cout << endl;
    cout << endl;

    cout << "                                      ";
    SetConsoleTextAttribute(console, 120);

    cout << "                           ";

    SetConsoleTextAttribute(console, 15);
    cout << "                                            ";

    cout << endl;

    cout << "                                      ";
    SetConsoleTextAttribute(console, 120);

    cout << "      1. Play              ";

    SetConsoleTextAttribute(console, 15);
    cout << "                                            ";

    cout << endl;

    cout << "                                      ";
    SetConsoleTextAttribute(console, 120);

    cout << "                           ";

    SetConsoleTextAttribute(console, 15);
    cout << "                                            ";
    // Choi game
    cout << endl;
    cout << endl;

    cout << endl;
    cout << endl;

    cout << "                                      ";
    SetConsoleTextAttribute(console, 120);

    cout << "                           ";

    SetConsoleTextAttribute(console, 15);
    cout << "                                            ";

    cout << endl;

    cout << "                                      ";
    SetConsoleTextAttribute(console, 120);

    cout << "      2. Leaderboard       ";

    SetConsoleTextAttribute(console, 15);
    cout << "                                            ";

    cout << endl;

    cout << "                                      ";
    SetConsoleTextAttribute(console, 120);

    cout << "                           ";

    SetConsoleTextAttribute(console, 15);
    cout << "                                            ";
    // Choi game
    cout << endl;
    cout << endl;

    cout << endl;
    cout << endl;

    cout << "                                      ";
    SetConsoleTextAttribute(console, 120);

    cout << "                           ";

    SetConsoleTextAttribute(console, 15);
    cout << "                                            ";

    cout << endl;

    cout << "                                      ";
    SetConsoleTextAttribute(console, 120);

    cout << "      3. Exit game         ";

    SetConsoleTextAttribute(console, 15);
    cout << "                                            ";

    cout << endl;

    cout << "                                      ";
    SetConsoleTextAttribute(console, 120);

    cout << "                           ";

    SetConsoleTextAttribute(console, 15);
    cout << "                                            ";
    // Choi game
    cout << endl;
    cout << endl;
    // SetConsoleTextAttribute(console, 15);
    // Thoat Game
    cout << "Your choice: ";

    cin >> chon;

    return 0;
}
int main()
{
    string** character;
    struct Board** board=nullptr;
    struct Point p1{}, p2{};
    string** ToaDoIn;
    vector<string> CopyBangXepHang;
    string pikachu;
    int** MangSo;

    int soloaipokemon;
    int soluongsokemon;
    int row, col;
    int toadoX, toadoY;
    int checkToMau = 1;
    int ChonMucDoGame;
    int mau = 120;
    int chon = 0;
    int KiemTraTrung = 0;
    // string ThoiGian;

    fstream FILE;
    FILE.open("pikachu.txt", ios::in);
    if (!FILE.is_open())
    {
        cout << "can not open file" << endl;
        exit(1);
    }
    while (!FILE.eof())
    {
        cout << "                                               ";
        getline(FILE, pikachu);
        cout << pikachu << endl;
    }
    Sleep(2000);
    system("cls");

    FILE.close();
    menu(chon);
    Sleep(1000);
    system("cls");
    while (chon != 3)
    {
        if (chon == 1)
        {
            SetConsoleTextAttribute(console, mau);

            for (int i = 0; i < 10; i++)
            {
                if (i == 0)
                {
                    cout << "--------------------------------------------------------------" << endl;
                }
                if (i == 1)
                {
                    cout << "|"
                        << "                Welcome to our Pikachu game                 "
                        << "|" << endl;
                }
                else if (i == 3)
                {
                    cout << "|"
                        << "                      "
                        << "   Mode  "
                        << "                             "
                        << "|" << endl;
                    cout << "|"
                        << "                       "
                        << "1.Easy"
                        << "                               "
                        << "|" << endl;
                    cout << "|"
                        << "                       "
                        << "2.Medium      "
                        << "                       "
                        << "|" << endl;
                    cout << "|"
                        << "                       "
                        << "3.Hard"
                        << "                               "
                        << "|" << endl;
                }
                cout << "|"
                    << "                                                            "
                    << "|" << endl;
                if (i == 9)
                {
                    cout << "--------------------------------------------------------------" << endl;
                }
            }

            SetConsoleTextAttribute(console, 15);
            cout << "Choose game mode:" << endl;

            cin >> ChonMucDoGame;
            if (ChonMucDoGame == 1)
            {

                row = 4;
                col = 4;
            }
            else if (ChonMucDoGame == 2)
            {
                row = 6;
                col = 6;
            }
            else if (ChonMucDoGame == 3)
            {
                row = 8;
                col = 8;
            }
            system("cls");

            MangSo = new int* [col + 2];
            for (int i = 0; i < col + 2; i++)
            {
                MangSo[i] = new int[row + 2];
            }
            ToaDoIn = new string * [row * col];
            for (int i = 0; i < col; i++)
            {

                ToaDoIn[i] = new string[row];
            }

            CreateMangSo(MangSo, row, col);
            CreateToaDoIn(ToaDoIn, row, col);
            int SoLuongCharacter = 2 * row * col + 4;

            character = new string * [col + 2];

            for (int i = 0; i < col + 2; i++)
            {
                character[i] = new string[row + 2];
            }
            CreatCharacter(character, row, col);
            CreateBoard(board, row, col);
            taochu(character, row, col);
            // PrintMatrix(character, row, col);
            // PrintMaTran(MangSo, row, col);
            PainBoard(character, board, row, col, ToaDoIn, p1, p2, checkToMau);
            std::cout << std::fixed << std::setprecision(9) << std::left;
            auto start = std::chrono::high_resolution_clock::now();
            // auto stop = high_resolution_clock::now();
            // auto duration = duration_cast<microseconds>(stop - start);

            FuncRun(character, MangSo, board, row, col, p1, p2, ToaDoIn, checkToMau, KiemTraTrung);
            auto stop = std::chrono::high_resolution_clock::now();

            // auto duration = duration_cast<microseconds>(stop - start);
            std::chrono::duration<double> duration = stop - start;
            cout << "Your play time: " << std::chrono::duration<double>(stop - start).count() << endl;
            // CopyMang(CopyBangXepHang);
            // insertSorted(CopyBangXepHang,duration.count()*0.000001);
            fstream FileThoiGian;
            FileThoiGian.open("bangxephang.txt", ios::app);
            if (!FileThoiGian.is_open())
            {
                cout << "cannot open file" << endl;
                return 0;
            }
            FileThoiGian.seekg(0, ios::end);
            FileThoiGian << std::chrono::duration<double>(stop - start).count() << endl;
            FileThoiGian.close();
            CopyMang(CopyBangXepHang);
            insertionSort(CopyBangXepHang);
            cout << "Highest current record: " << CopyBangXepHang[0] << endl;
            SapXepBangXepHang(CopyBangXepHang);
            free(character);
            free(MangSo);
            free(ToaDoIn);
        }
        else if (chon == 2)
        {
            cout << "Leaderboard" << endl;
            string time;
            fstream file;
            file.open("BangXepHang.txt", ios::in);
            if (!file.is_open())
            {
                cout << "error" << endl;
                exit(1);
            }
            file.seekg(0, ios::beg);
            while (file.peek() != EOF)
            {
                getline(file, time);
                cout << time << endl;
            }
            Sleep(5000);
            system("cls");
            file.close();
        }
        menu(chon);
    }
    cout << "Thank you for playing" << endl;
    cout << "See you again!" << endl;

    free(board);
    Sleep(5000);
    return 0;
}
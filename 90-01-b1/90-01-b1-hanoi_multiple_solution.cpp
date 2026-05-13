/* 2351577 大数据 张宸浩 */
#include<iostream>
#include<iomanip>
#include<conio.h>
#include"../include/cmd_console_tools.h"
#include<Windows.h>
using namespace std;
int count = 0;
int a[10] = { 0 };
int b[10] = { 0 };
int c[10] = { 0 };
int pa = 0, pb = 0, pc = 0;
#define OX 14
#define OY 19
#define length 21
#define height 11
#define len_of_str 25
#define another_OY 30
/* ----------------------------------------------------------------------------------

     本文件功能：
    1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
    1、不允许定义外部全局变量（const及#define不在限制范围内）
    2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
    3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
    4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */


   /***************************************************************************
     函数名称：
     功    能：
     输入参数：
     返 回 值：
     说    明：
   ***************************************************************************/
void end()
{
    while (1)
    {
        int x1, y1;
        cct_gotoxy(1, another_OY + 8);
        cout << "按回车键继续";
        cct_getxy(x1, y1);
        char ch;
        ch = _getche();
        if (int(ch) == 13)
        {
            return;
        }
        else
        {
            cct_showch(x1, y1, ' ');
        }
    }
}
void hanoi(int n, char src, char tmp, char dst, int choice, int timing = 6);
void move_right(int x, int y, int bg_color, int fg_color, int len)
{
    cct_showch(x, y, ' ', 0, 7, len);
    cct_showch(x + 1, y, ' ', bg_color, fg_color, len);
    Sleep(50);
}
void move_left(int x, int y, int bg_color, int fg_color, int len)
{
    cct_showch(x, y, ' ', 0, 7, len);
    cct_showch(x - 1, y, ' ', bg_color, fg_color, len);
    Sleep(50);
}
void move_up(int x, int y, int bg_color, int fg_color, int len)
{
    cct_showch(x, y, ' ', 14, 7, len);
    cct_showch(x, y, ' ', 0, 7, len / 2);
    cct_showch(x + 1 + len / 2, y, ' ', 0, 7, len / 2);
    cct_showch(x, y - 1, ' ', bg_color, fg_color, len);
    Sleep(50);
}
void move_down(int x, int y, int bg_color, int fg_color, int len)
{
    cct_showch(x, y, ' ', 14, 7, len);
    cct_showch(x, y, ' ', 0, 7, len / 2);
    cct_showch(x + 1 + len / 2, y, ' ', 0, 7, len / 2);
    cct_showch(x, y + 1, ' ', bg_color, fg_color, len);
    Sleep(50);
}
void move(int sx, int sy, int dx, int dy, int bg_color, int fg_color, int len)
{
    for (int i = 0; i < (sy - OY + height + 1); i++)
        move_up(sx, sy - i, bg_color, fg_color, len);
    if (sx > dx)
        for (int i = 0; i < (fabs(sx - dx)); i++)
            move_left(sx - i, OY - height - 1, bg_color, fg_color, len);
    else
        for (int i = 0; i < (fabs(sx - dx)); i++)
            move_right(sx + i, OY - height - 1, bg_color, fg_color, len);
    for (int i = 0; i < (dy - OY + height + 1); i++)
    {
        if (i == 0)
        {
            cct_showch(dx, OY - height - 1, ' ', 0, 7, len);
            cct_showch(dx, OY - height, ' ', bg_color, fg_color, len);
        }
        else
            move_down(dx, OY - height - 1 + i, bg_color, fg_color, len);
    }
}
void swi_time(int timing, int n, char scr, char dst)
{
    int an;
    an = pa + pb + pc;
    switch (timing)
    {
    case 0:
        char ch;
        int x, y;
        cct_getxy(x, y);
        while (1)
        {
            ch = _getch();
            if (ch == 13)
                break;
            else
            {
                cct_showch(x, y, ' ');
                cct_gotoxy(x, y);
            }
        }
        break;
    case 1:
        Sleep(1000);
        break;
    case 2:
        Sleep(800);
        break;
    case 3:
        Sleep(600);
        break;
    case 4:
        Sleep(400);
        break;
    case 5:
        Sleep(200);
        break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        if ((scr == 'A') && (dst == 'C'))
        {
            int sx, dx, sy, dy, color;
            sx = OX + length / 2 - c[pc - 1] + 1;
            dx = OX + (length + 4) * 2 + length / 2 - c[pc - 1] + 1;
            sy = OY - pa - 1;
            dy = OY - pc;
            color = an - c[pc - 1] + 2;
            move(sx, sy, dx, dy, color, 7, (2 * c[pc - 1] - 1));
        }
        if ((scr == 'A') && (dst == 'B'))
        {
            int sx, dx, sy, dy, color;
            sx = OX + length / 2 - b[pb - 1] + 1;
            dx = OX + (length + 4) + length / 2 - b[pb - 1] + 1;
            sy = OY - pa - 1;
            dy = OY - pb;
            color = an - b[pb - 1] + 2;
            move(sx, sy, dx, dy, color, 7, (2 * b[pb - 1] - 1));
        }
        if ((scr == 'B') && (dst == 'A'))
        {
            int sx, dx, sy, dy, color;
            sx = OX + (length + 4) + length / 2 - a[pa - 1] + 1;
            dx = OX + length / 2 - a[pa - 1] + 1;
            sy = OY - pb - 1;
            dy = OY - pa;
            color = an - a[pa - 1] + 2;
            move(sx, sy, dx, dy, color, 7, (2 * a[pa - 1] - 1));
        }
        if ((scr == 'B') && (dst == 'C'))
        {
            int sx, dx, sy, dy, color;
            sx = OX + (length + 4) + length / 2 - c[pc - 1] + 1;
            dx = OX + (length + 4) * 2 + length / 2 - c[pc - 1] + 1;
            sy = OY - pb - 1;
            dy = OY - pc;
            color = an - c[pc - 1] + 2;
            move(sx, sy, dx, dy, color, 7, (2 * c[pc - 1] - 1));
        }
        if ((scr == 'C') && (dst == 'B'))
        {
            int sx, dx, sy, dy, color;
            sx = OX + (length + 4) * 2 + length / 2 - b[pb - 1] + 1;
            dx = OX + (length + 4) + length / 2 - b[pb - 1] + 1;
            sy = OY - pc - 1;
            dy = OY - pb;
            color = an - b[pb - 1] + 2;
            move(sx, sy, dx, dy, color, 7, (2 * b[pb - 1] - 1));
        }
        if ((scr == 'C') && (dst == 'A'))
        {
            int sx, dx, sy, dy, color;
            sx = OX + (length + 4) * 2 + length / 2 + 1 - a[pa - 1];
            dx = OX + length / 2 - a[pa - 1] + 1;
            sy = OY - pc - 1;
            dy = OY - pa;
            color = an - a[pa - 1] + 2;
            move(sx, sy, dx, dy, color, 7, (2 * a[pa - 1] - 1));
        }
        break;
    case 11:
        if ((scr == 'A') && (dst == 'C'))
        {
            int sx, dx, sy, dy, color;
            sx = OX + length / 2 - c[pc - 1] + 1;
            dx = OX + (length + 4) * 2 + length / 2 - c[pc - 1] + 1;
            sy = OY - pa - 1;
            dy = OY - pc;
            color = an - c[pc - 1] + 2;
            move(sx, sy, dx, dy, color, 7, (2 * c[pc - 1] - 1));
        }
        if ((scr == 'A') && (dst == 'B'))
        {
            int sx, dx, sy, dy, color;
            sx = OX + length / 2 - b[pb - 1] + 1;
            dx = OX + (length + 4) + length / 2 - b[pb - 1] + 1;
            sy = OY - pa - 1;
            dy = OY - pb;
            color = an - b[pb - 1] + 2;
            move(sx, sy, dx, dy, color, 7, (2 * b[pb - 1] - 1));
        }
        if ((scr == 'B') && (dst == 'A'))
        {
            int sx, dx, sy, dy, color;
            sx = OX + (length + 4) + length / 2 - a[pa - 1] + 1;
            dx = OX + length / 2 - a[pa - 1] + 1;
            sy = OY - pb - 1;
            dy = OY - pa;
            color = an - a[pa - 1] + 2;
            move(sx, sy, dx, dy, color, 7, (2 * a[pa - 1] - 1));
        }
        if ((scr == 'B') && (dst == 'C'))
        {
            int sx, dx, sy, dy, color;
            sx = OX + (length + 4) + length / 2 - c[pc - 1] + 1;
            dx = OX + (length + 4) * 2 + length / 2 - c[pc - 1] + 1;
            sy = OY - pb - 1;
            dy = OY - pc;
            color = an - c[pc - 1] + 2;
            move(sx, sy, dx, dy, color, 7, (2 * c[pc - 1] - 1));
        }
        if ((scr == 'C') && (dst == 'B'))
        {
            int sx, dx, sy, dy, color;
            sx = OX + (length + 4) * 2 + length / 2 - b[pb - 1] + 1;
            dx = OX + (length + 4) + length / 2 - b[pb - 1] + 1;
            sy = OY - pc - 1;
            dy = OY - pb;
            color = an - b[pb - 1] + 2;
            move(sx, sy, dx, dy, color, 7, (2 * b[pb - 1] - 1));
        }
        if ((scr == 'C') && (dst == 'A'))
        {
            int sx, dx, sy, dy, color;
            sx = OX + (length + 4) * 2 + length / 2 + 1;
            dx = OX + length / 2 - a[pa - 1] + 1;
            sy = OY - pc - 1;
            dy = OY - pa;
            color = an - a[pa - 1] + 2;
            move(sx, sy, dx, dy, color, 7, (2 * a[pa - 1] - 1));
        }
        cct_getxy(x, y);
        while (1)
        {
            ch = _getch();
            if (ch == 13)
                break;
            else
            {
                cct_showch(x, y, ' ');
                cct_gotoxy(x, y);
            }
        }
        break;
    }
}
void three_pillar()
{
    cct_setconsoleborder(120, 40, 120, 9000);
    cct_showch(OX, OY, ' ', 14, 7, length);
    Sleep(100);
    cct_showch(OX + length + 4, OY, ' ', 14, 7, length);
    Sleep(100);
    cct_showch(OX + length + length + 8, OY, ' ', 14, 7, length);
    for (int i = 0; i < height; i++)
    {
        cct_showch(OX + length / 2, OY - 1 - i, ' ', 14, 7);
        Sleep(100);
        cct_showch(OX + length + 4 + length / 2, OY - 1 - i, ' ', 14, 7);
        Sleep(100);
        cct_showch(OX + length + length + 8 + length / 2, OY - 1 - i, ' ', 14, 7);
        Sleep(100);
    }
}
void p(int a[10], int b[10], int c[10], char scr, char dst, int px, int x[10])
{
    extern int count;
    cout << "第" << setw(4) << count << " 步(" << setw(2) << x[px - 1] << "): " << scr << "-->" << dst;
    cout << " A:";
    for (int i = 0; i < 10; i++)
    {
        if ((a[i] != 0) && a[i] != 10)
            cout << " " << a[i];
        else if (a[i] == 10)
            cout << "10";
        else
            cout << "  ";
    }
    cout << " B:";
    for (int i = 0; i < 10; i++)
    {
        if ((b[i] != 0) && b[i] != 10)
            cout << " " << b[i];
        else if (b[i] == 10)
            cout << "10";
        else
            cout << "  ";
    }
    cout << " C:";
    for (int i = 0; i < 10; i++)
    {
        if ((c[i] != 0) && c[i] != 10)
            cout << " " << c[i];
        else if (c[i] == 10)
            cout << "10";
        else
            cout << "  ";
    }
    cout << endl;
}
void print_row(int n, int a[10], int b[10], int c[10])
{
    for (int i = 0; i < 10; i++)
    {
        cct_gotoxy(OX + 2, another_OY - 1 - i);
        if (a[i] == 0)
            cout << " ";
        else
            cout << a[i];
        cct_gotoxy(OX + len_of_str / 2, another_OY - 1 - i);
        if (b[i] == 0)
            cout << " ";
        else
            cout << b[i];
        cct_gotoxy(OX + len_of_str - 3, another_OY - 1 - i);
        if (c[i] == 0)
            cout << " ";
        else
            cout << c[i];
    }
}
void hanoi_one(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        cout << " 1# " << src << "-->" << dst << endl;
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp, 1);
        cout << " " << n << "# " << src << "-->" << dst << endl;
        hanoi(n - 1, tmp, src, dst, 1);
    }
}
void hanoi_two(int n, char src, char tmp, char dst)
{
    extern int count;
    if (n == 1)
    {
        count++;
        cout << setw(5) << count << ":" << setw(3);
        cout << n << "# " << src << "-->" << dst << endl;
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp, 2);
        count++;
        cout << setw(5) << count << ":" << setw(3);
        cout << n << "# " << src << "-->" << dst << endl;
        hanoi(n - 1, tmp, src, dst, 2);
    }
}
void hanoi_three(int n, char scr, char tmp, char dst)
{
    extern int count;
    if ((scr == 'A') && (dst == 'C'))
    {
        if (n == 1)
        {
            count++;
            c[pc++] = a[--pa];
            a[pa] = 0;
            p(a, b, c, scr, dst, pc, c);
        }
        else
        {
            hanoi(n - 1, scr, dst, tmp, 3);
            count++;
            c[pc++] = a[--pa];
            a[pa] = 0;
            p(a, b, c, scr, dst, pc, c);
            hanoi(n - 1, tmp, scr, dst, 3);
        }
    }
    if ((scr == 'A') && (dst == 'B'))
    {
        if (n == 1)
        {
            count++;
            b[pb++] = a[--pa];
            a[pa] = 0;
            p(a, b, c, scr, dst, pb, b);
        }
        else
        {
            hanoi(n - 1, scr, dst, tmp, 3);
            count++;
            b[pb++] = a[--pa];
            a[pa] = 0;
            p(a, b, c, scr, dst, pb, b);
            hanoi(n - 1, tmp, scr, dst, 3);
        }
    }
    if ((scr == 'B') && (dst == 'C'))
    {
        if (n == 1)
        {
            count++;
            c[pc++] = b[--pb];
            b[pb] = 0;
            p(a, b, c, scr, dst, pc, c);
        }
        else
        {
            hanoi(n - 1, scr, dst, tmp, 3);
            count++;
            c[pc++] = b[--pb];
            b[pb] = 0;
            p(a, b, c, scr, dst, pc, c);
            hanoi(n - 1, tmp, scr, dst, 3);
        }
    }
    if ((scr == 'B') && (dst == 'A'))
    {
        if (n == 1)
        {
            count++;
            a[pa++] = b[--pb];
            b[pb] = 0;
            p(a, b, c, scr, dst, pa, a);
        }
        else
        {
            hanoi(n - 1, scr, dst, tmp, 3);
            count++;
            a[pa++] = b[--pb];
            b[pb] = 0;
            p(a, b, c, scr, dst, pa, a);
            hanoi(n - 1, tmp, scr, dst, 3);
        }
    }
    if ((scr == 'C') && (dst == 'A'))
    {
        if (n == 1)
        {
            count++;
            a[pa++] = c[--pc];
            c[pc] = 0;
            p(a, b, c, scr, dst, pa, a);
        }
        else
        {
            hanoi(n - 1, scr, dst, tmp, 3);
            count++;
            a[pa++] = c[--pc];
            c[pc] = 0;
            p(a, b, c, scr, dst, pa, a);
            hanoi(n - 1, tmp, scr, dst, 3);
        }
    }
    if ((scr == 'C') && (dst == 'B'))
    {
        if (n == 1)
        {
            count++;
            b[pb++] = c[--pc];
            c[pc] = 0;
            p(a, b, c, scr, dst, pb, b);
        }
        else
        {
            hanoi(n - 1, scr, dst, tmp, 3);
            count++;
            b[pb++] = c[--pc];
            c[pc] = 0;
            p(a, b, c, scr, dst, pb, b);
            hanoi(n - 1, tmp, scr, dst, 3);
        }
    }
}
void hanoi_four(int n, char scr, char tmp, char dst, int timing)
{
    extern int count;
    if ((scr == 'A') && (dst == 'C'))
    {
        if (n == 1)
        {
            count++;
            c[pc++] = a[--pa];
            a[pa] = 0;
            cct_showch(OX, another_OY - 1, ' ');
            print_row(n, a, b, c);
            cct_gotoxy(OX - 5, another_OY + 5);
            p(a, b, c, scr, dst, pc, c);
            swi_time(timing, n, 'A', 'C');
        }
        else
        {
            hanoi(n - 1, scr, dst, tmp, 4, timing);
            count++;
            c[pc++] = a[--pa];
            a[pa] = 0;
            cct_showch(OX, another_OY - 1, ' ');
            print_row(n, a, b, c);
            cct_gotoxy(OX - 5, another_OY + 5);
            p(a, b, c, scr, dst, pc, c);
            swi_time(timing, n, 'A', 'C');
            hanoi(n - 1, tmp, scr, dst, 4, timing);
        }
    }
    if ((scr == 'A') && (dst == 'B'))
    {
        if (n == 1)
        {
            count++;
            b[pb++] = a[--pa];
            a[pa] = 0;
            cct_showch(OX, another_OY - 1, ' ');
            print_row(n, a, b, c);
            cct_gotoxy(OX - 5, another_OY + 5);
            p(a, b, c, scr, dst, pb, b);
            swi_time(timing, n, 'A', 'B');
        }
        else
        {
            hanoi(n - 1, scr, dst, tmp, 4, timing);
            count++;
            b[pb++] = a[--pa];
            a[pa] = 0;
            cct_showch(OX, another_OY - 1, ' ');
            print_row(n, a, b, c);
            cct_gotoxy(OX - 5, another_OY + 5);
            p(a, b, c, scr, dst, pb, b);
            swi_time(timing, n, 'A', 'B');
            hanoi(n - 1, tmp, scr, dst, 4, timing);
        }
    }
    if ((scr == 'B') && (dst == 'C'))
    {
        if (n == 1)
        {
            count++;
            c[pc++] = b[--pb];
            b[pb] = 0;
            cct_showch(OX, another_OY - 1, ' ');
            print_row(n, a, b, c);
            cct_gotoxy(OX - 5, another_OY + 5);
            p(a, b, c, scr, dst, pc, c);
            swi_time(timing, n, 'B', 'C');
        }
        else
        {
            hanoi(n - 1, scr, dst, tmp, 4, timing);
            count++;
            c[pc++] = b[--pb];
            b[pb] = 0;
            cct_showch(OX, another_OY - 1, ' ');
            print_row(n, a, b, c);
            cct_gotoxy(OX - 5, another_OY + 5);
            p(a, b, c, scr, dst, pc, c);
            swi_time(timing, n, 'B', 'C');
            hanoi(n - 1, tmp, scr, dst, 4, timing);
        }
    }
    if ((scr == 'B') && (dst == 'A'))
    {
        if (n == 1)
        {
            count++;
            a[pa++] = b[--pb];
            b[pb] = 0;
            cct_showch(OX, another_OY - 1, ' ');
            print_row(n, a, b, c);
            cct_gotoxy(OX - 5, another_OY + 5);
            p(a, b, c, scr, dst, pa, a);
            swi_time(timing, n, 'B', 'A');
        }
        else
        {
            hanoi(n - 1, scr, dst, tmp, 4, timing);
            count++;
            a[pa++] = b[--pb];
            b[pb] = 0;
            cct_showch(OX, another_OY - 1, ' ');
            print_row(n, a, b, c);
            cct_gotoxy(OX - 5, another_OY + 5);
            p(a, b, c, scr, dst, pa, a);
            swi_time(timing, n, 'B', 'A');
            hanoi(n - 1, tmp, scr, dst, 4, timing);
        }
    }
    if ((scr == 'C') && (dst == 'A'))
    {
        if (n == 1)
        {
            count++;
            a[pa++] = c[--pc];
            c[pc] = 0;
            cct_showch(OX, another_OY - 1, ' ');
            print_row(n, a, b, c);
            cct_gotoxy(OX - 5, another_OY + 5);
            p(a, b, c, scr, dst, pa, a);
            swi_time(timing, n, 'C', 'A');
        }
        else
        {
            hanoi(n - 1, scr, dst, tmp, 4, timing);
            count++;
            a[pa++] = c[--pc];
            c[pc] = 0;
            cct_showch(OX, another_OY - 1, ' ');
            print_row(n, a, b, c);
            cct_gotoxy(OX - 5, another_OY + 5);
            p(a, b, c, scr, dst, pa, a);
            swi_time(timing, n, 'C', 'A');
            hanoi(n - 1, tmp, scr, dst, 4, timing);
        }
    }
    if ((scr == 'C') && (dst == 'B'))
    {
        if (n == 1)
        {
            count++;
            b[pb++] = c[--pc];
            c[pc] = 0;
            cct_showch(OX, another_OY - 1, ' ');
            print_row(n, a, b, c);
            cct_gotoxy(OX - 5, another_OY + 5);
            p(a, b, c, scr, dst, pb, b);
            swi_time(timing, n, 'C', 'B');
        }
        else
        {
            hanoi(n - 1, scr, dst, tmp, 4, timing);
            count++;
            b[pb++] = c[--pc];
            c[pc] = 0;
            cct_showch(OX, another_OY - 1, ' ');
            print_row(n, a, b, c);
            cct_gotoxy(OX - 5, another_OY + 5);
            p(a, b, c, scr, dst, pb, b);
            swi_time(timing, n, 'C', 'B');
            hanoi(n - 1, tmp, scr, dst, 4, timing);
        }
    }
}
void hanoi(int n, char src, char tmp, char dst, int choice, int timing) {
    switch (choice) {
    case 1:
        hanoi_one(n, src, tmp, dst);
        break;
    case 2:
        hanoi_two(n, src, tmp, dst);
        break;
    case 3:
        hanoi_three(n, src, tmp, dst);
        break;
    case 4:
        hanoi_four(n, src, tmp, dst, timing);
    }
}
void scan(int* nc, char* scrc, char* tmpc, char* dstc)
{
    int n;
    char scr, tmp, dst;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (n >= 1 && n <= 10)
        {
            cin.clear();
            cin.ignore(65536, '\n');
            break;
        }
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(65536, '\n');
    }
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> scr;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        if (scr == 'A' || scr == 'B' || scr == 'C' || scr == 'a' || scr == 'b' || scr == 'c')
        {
            cin.clear();
            cin.ignore(65536, '\n');
            break;
        }
        cin.clear();
        cin.ignore(65536, '\n');
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        if ((dst == 'A' || dst == 'B' || dst == 'C' || dst == 'a' || dst == 'b' || dst == 'c') && (dst != scr && dst != char(scr - 32) && dst != char(scr + 32)))
        {
            cin.clear();
            cin.ignore(65536, '\n');
            break;
        }
        if ((dst == 'A' || dst == 'a') && (scr == 'A' || scr == 'a'))
        {
            cout << "目标柱(A)不能与起始柱(A)相同" << endl;
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        if ((dst == 'B' || dst == 'b') && (scr == 'B' || scr == 'b'))
        {
            cout << "目标柱(B)不能与起始柱(B)相同" << endl;
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        if ((dst == 'C' || dst == 'c') && (scr == 'C' || scr == 'c'))
        {
            cout << "目标柱(C)不能与起始柱(C)相同" << endl;
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(65536, '\n');
    }
    if (scr == 'A' || scr == 'a')
    {
        if (dst == 'B' || dst == 'b')
        {
            tmp = 'C';
        }
        else if (dst == 'C' || dst == 'c')
        {
            tmp = 'B';
        }
    }
    else if (scr == 'B' || scr == 'b')
    {
        if (dst == 'A' || dst == 'a')
        {
            tmp = 'C';
        }
        else if (dst == 'C' || dst == 'c')
        {
            tmp = 'A';
        }
    }
    else
    {
        if (dst == 'A' || dst == 'a')
        {
            tmp = 'B';
        }
        else if (dst == 'B' || dst == 'b')
        {
            tmp = 'A';
        }
    }
    if (scr == 'a')
        scr = 'A';
    if (scr == 'b')
        scr = 'B';
    if (scr == 'c')
        scr = 'C';
    if (dst == 'a')
        dst = 'A';
    if (dst == 'b')
        dst = 'B';
    if (dst == 'c')
        dst = 'C';
    *nc = n;
    *scrc = scr;
    *tmpc = tmp;
    *dstc = dst;
}
void game1()
{
    cout << endl;
    cout << endl;
    cout << endl;
    int n;
    char scr, tmp, dst;
    scan(&n, &scr, &tmp, &dst);
    hanoi(n, scr, tmp, dst, 1);
    end();
}
void game2()
{
    extern int count;
    cout << endl;
    cout << endl;
    cout << endl;
    int n;
    char scr, tmp, dst;
    scan(&n, &scr, &tmp, &dst);
    hanoi(n, scr, tmp, dst, 2);
    count = 0;
    end();
}
void game3()
{
    cout << endl;
    cout << endl;
    cout << endl;
    int n;
    char scr, tmp, dst;
    scan(&n, &scr, &tmp, &dst);
    if (scr == 'A')
    {
        for (int i = 0; i < n; i++)
            a[pa++] = n - i;
    }
    if (scr == 'B')
    {
        for (int i = 0; i < n; i++)
            b[pb++] = n - i;
    }
    if (scr == 'C')
    {
        for (int i = 0; i < n; i++)
            c[pc++] = n - i;
    }
    hanoi(n, scr, tmp, dst, 3);
    extern int count;
    count = 0;
    a[10] = { 0 };
    b[10] = { 0 };
    c[10] = { 0 };
    pa = 0;
    pb = 0;
    pc = 0;
    end();
}
void game4()
{
    cct_setcolor(0, 7);
    extern int count;
    cout << endl;
    cout << endl;
    cout << endl;
    int n;
    char scr, tmp, dst;
    scan(&n, &scr, &tmp, &dst);
    if (scr == 'A')
    {
        for (int i = 0; i < n; i++)
            a[pa++] = n - i;
    }
    if (scr == 'B')
    {
        for (int i = 0; i < n; i++)
            b[pb++] = n - i;
    }
    if (scr == 'C')
    {
        for (int i = 0; i < n; i++)
            c[pc++] = n - i;
    }
    int timing;
    while (1)
    {
        cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短)";
        cin >> timing;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        if (timing >= 0 && timing < 6)
        {
            break;
        }
        else
        {
            cin.ignore(65536, '\n');
            continue;
        }
    }
    cct_setconsoleborder(120, 40, 120, 9000);
    cout << "从" << setw(2) << scr << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << timing << endl;
    cct_showch(OX, another_OY, '=', 0, 7, len_of_str);
    cct_gotoxy(OX + 2, another_OY + 1);
    cout << "A         B         C" << endl;
    hanoi(n, scr, tmp, dst, 4, timing);
    cct_gotoxy(1, another_OY + 8);
    count = 0;
    for (int i = 0; i < n; i++)
        a[i] = 0;
    for (int i = 0; i < n; i++)
        b[i] = 0;
    for (int i = 0; i < n; i++)
        c[i] = 0;
    pa = 0;
    pb = 0;
    pc = 0;
    end();
}
void game5()
{
    three_pillar();
    cct_gotoxy(1, OY + 10);
    cct_setcolor();
    end();
}
void game6()
{
    cout << endl;
    cout << endl;
    cout << endl;
    int n;
    char scr, tmp, dst;
    scan(&n, &scr, &tmp, &dst);
    three_pillar();
    if (scr == 'A')
        for (int i = 0; i < n; i++)
        {
            cct_showch(OX + length / 2 - ((n - i) - 1), OY - i - 1, ' ', i + 2, 7, 2 * (n - i) - 1);
            Sleep(100);
        }
    if (scr == 'B')
        for (int i = 0; i < n; i++)
        {
            cct_showch(OX + length + 4 + length / 2 - ((n - i) - 1), OY - i - 1, ' ', i + 2, 7, 2 * (n - i) - 1);
            Sleep(100);
        }
    if (scr == 'C')
        for (int i = 0; i < n; i++)
        {
            cct_showch(OX + (length + 4) * 2 + length / 2 - ((n - i) - 1), OY - i - 1, ' ', i + 2, 7, 2 * (n - i) - 1);
            Sleep(100);
        }
    cct_gotoxy(1, OY + 10);
    cct_setcolor();
    end();
}
void game7()
{
    cout << endl;
    cout << endl;
    cout << endl;
    int n;
    char scr, tmp, dst;
    scan(&n, &scr, &tmp, &dst);
    three_pillar();
    int i = 0;
    if (scr == 'A')
        for (i; i < n; i++)
        {
            cct_showch(OX + length / 2 - ((n - i) - 1), OY - i - 1, ' ', i + 2, 7, 2 * (n - i) - 1);
            Sleep(100);
        }
    if (scr == 'B')
        for (i; i < n; i++)
        {
            cct_showch(OX + length + 4 + length / 2 - ((n - i) - 1), OY - i - 1, ' ', i + 2, 7, 2 * (n - i) - 1);
            Sleep(100);
        }
    if (scr == 'C')
        for (i; i < n; i++)
        {
            cct_showch(OX + (length + 4) * 2 + length / 2 - ((n - i) - 1), OY - i - 1, ' ', i + 2, 7, 2 * (n - i) - 1);
            Sleep(100);
        }
    i--;
    if (scr == 'A' && dst == 'B')
        move(OX + length / 2, OY - n, OX + length + 4 + length / 2, OY - 1, n + 1, 7, 1);
    if (scr == 'A' && dst == 'C')
        move(OX + length / 2, OY - n, OX + (length + 4) * 2 + length / 2, OY - 1, n + 1, 7, 1);
    if (scr == 'B' && dst == 'A')
        move(OX + length + 4 + length / 2, OY - n, OX + length / 2, OY - 1, n + 1, 7, 1);
    if (scr == 'B' && dst == 'C')
        move(OX + length + 4 + length / 2, OY - n, OX + (length + 4) * 2 + length / 2, OY - 1, n + 1, 7, 1);
    if (scr == 'C' && dst == 'A')
        move(OX + (length + 4) * 2 + length / 2, OY - n, OX + length / 2, OY - 1, n + 1, 7, 1);
    if (scr == 'C' && dst == 'B')
        move(OX + (length + 4) * 2 + length / 2, OY - n, OX + length + 4 + length / 2, OY - 1, n + 1, 7, 1);
    cct_gotoxy(1, OY + 10);
    cct_setcolor();
    end();
}
void game8()
{
    extern int count;
    cout << endl;
    cout << endl;
    cout << endl;
    int n;
    char scr, tmp, dst;
    scan(&n, &scr, &tmp, &dst);
    if (scr == 'A')
    {
        for (int i = 0; i < n; i++)
            a[pa++] = n - i;
    }
    if (scr == 'B')
    {
        for (int i = 0; i < n; i++)
            b[pb++] = n - i;
    }
    if (scr == 'C')
    {
        for (int i = 0; i < n; i++)
            c[pc++] = n - i;
    }
    int timing;
    while (1)
    {
        cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短)";
        cin >> timing;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        if (timing >= 0 && timing < 6)
        {
            break;
        }
        else
        {
            cin.ignore(65536, '\n');
            continue;
        }
    }
    cct_setconsoleborder(120, 40, 120, 9000);
    cout << "从" << setw(2) << scr << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << timing << endl;
    three_pillar();
    int i = 0;
    if (scr == 'A')
        for (i; i < n; i++)
        {
            cct_showch(OX + length / 2 - ((n - i) - 1), OY - i - 1, ' ', i + 2, 7, 2 * (n - i) - 1);
            Sleep(100);
        }
    if (scr == 'B')
        for (i; i < n; i++)
        {
            cct_showch(OX + length + 4 + length / 2 - ((n - i) - 1), OY - i - 1, ' ', i + 2, 7, 2 * (n - i) - 1);
            Sleep(100);
        }
    if (scr == 'C')
        for (i; i < n; i++)
        {
            cct_showch(OX + (length + 4) * 2 + length / 2 - ((n - i) - 1), OY - i - 1, ' ', i + 2, 7, 2 * (n - i) - 1);
            Sleep(100);
        }
    cct_showch(OX, another_OY, '=', 0, 7, len_of_str);
    cct_gotoxy(OX + 2, another_OY + 1);
    cout << "A         B         C" << endl;
    hanoi(n, scr, tmp, dst, 4, 11 - timing);
    count = 0;
    for (int i = 0; i < n; i++)
        a[i] = 0;
    for (int i = 0; i < n; i++)
        b[i] = 0;
    for (int i = 0; i < n; i++)
        c[i] = 0;
    pa = 0;
    pb = 0;
    pc = 0;
    cct_showch(OX, another_OY - 1, ' ');
    cct_gotoxy(1, another_OY + 8);
    end();
}
void game9()
{
    extern int count;
    cout << endl;
    cout << endl;
    cout << endl;
    int n;
    char scr, tmp, dst;
    scan(&n, &scr, &tmp, &dst);
    if (scr == 'A')
    {
        for (int i = 0; i < n; i++)
            a[pa++] = n - i;
    }
    if (scr == 'B')
    {
        for (int i = 0; i < n; i++)
            b[pb++] = n - i;
    }
    if (scr == 'C')
    {
        for (int i = 0; i < n; i++)
            c[pc++] = n - i;
    }
    cct_setconsoleborder(120, 40, 120, 9000);
    three_pillar();
    if (scr == 'A')
        for (int i = 0; i < n; i++)
        {
            cct_showch(OX + length / 2 - ((n - i) - 1), OY - i - 1, ' ', i + 2, 7, 2 * (n - i) - 1);
            Sleep(100);
        }
    if (scr == 'B')
        for (int i = 0; i < n; i++)
        {
            cct_showch(OX + length + 4 + length / 2 - ((n - i) - 1), OY - i - 1, ' ', i + 2, 7, 2 * (n - i) - 1);
            Sleep(100);
        }
    if (scr == 'C')
        for (int i = 0; i < n; i++)
        {
            cct_showch(OX + (length + 4) * 2 + length / 2 - ((n - i) - 1), OY - i - 1, ' ', i + 2, 7, 2 * (n - i) - 1);
            Sleep(100);
        }
    cct_showch(OX, another_OY, '=', 0, 7, len_of_str);
    cct_gotoxy(OX + 2, another_OY + 1);
    cout << "A         B         C" << endl;
    print_row(n, a, b, c);
    cct_gotoxy(1, another_OY + 4);
    cout << "请输入指令(Q退出)";
    int X, Y;
    cct_getxy(X, Y);
    while (1) {
        cct_showch(OX, another_OY - 1, ' ');
        cct_gotoxy(X, Y);
        char cht;
        char chs, chd;
        while (1) {
            cin >> chs >> chd;
            if (chs == 'A' && chd == 'B')
                if ((pa != 0) && ((a[pa - 1] < b[pb - 1]) || (pb == 0)))
                    break;
            if (chs == 'A' && chd == 'C')
                if ((pa != 0) && ((a[pa - 1] < c[pc - 1]) || (pc == 0)))
                    break;
            if (chs == 'B' && chd == 'A')
                if ((pb != 0) && ((b[pb - 1] < a[pa - 1]) || (pa == 0)))
                    break;
            if (chs == 'B' && chd == 'C')
                if ((pb != 0) && ((b[pb - 1] < c[pc - 1]) || (pc == 0)))
                    break;
            if (chs == 'C' && chd == 'A')
                if ((pc != 0) && ((c[pc - 1] < a[pa - 1]) || (pa == 0)))
                    break;
            if (chs == 'C' && chd == 'B')
                if ((pc != 0) && ((c[pc - 1] < b[pb - 1]) || (pb == 0)))
                    break;
            if (chs == 'Q' || chd == 'Q' || chs == 'q' || chd == 'q')
                break;
            cct_showch(1, another_OY + 6, ' ');
            cct_gotoxy(2, another_OY + 6);
            cout << "指令错误";
            Sleep(500);
            cct_showch(X, Y, ' ', 0, 7, 10);
            cct_gotoxy(X, Y);
        }
        if (chs == 'Q' || chd == 'Q' || chs == 'q' || chd == 'q')
            break;
        if (chs == 'A' || chs == 'a')
        {
            if (chd == 'B' || chd == 'b')
            {
                cht = 'C';
            }
            else if (chd == 'C' || chd == 'c')
            {
                cht = 'B';
            }
        }
        else if (chs == 'B' || chs == 'b')
        {
            if (chd == 'A' || chd == 'a')
            {
                cht = 'C';
            }
            else if (chd == 'C' || chd == 'c')
            {
                cht = 'A';
            }
        }
        else
        {
            if (chd == 'A' || chd == 'a')
            {
                tmp = 'B';
            }
            else if (chd == 'B' || chd == 'b')
            {
                cht = 'A';
            }
        }
        if (chs == 'a')
            chs = 'A';
        if (chs == 'b')
            chs = 'B';
        if (chs == 'c')
            chs = 'C';
        if (chd == 'a')
            chd = 'A';
        if (chd == 'b')
            chd = 'B';
        if (chd == 'c')
            chd = 'C';
        hanoi_four(1, chs, cht, chd, 6);
        if ((dst == 'B') && (b[n - 1] == 1))
        {
            cct_showch(10, another_OY + 7, ' ');
            cct_gotoxy(1, another_OY + 7);
            cout << "游戏结束" << endl;
            break;
        }
        if ((dst == 'A') && (a[n - 1] == 1))
        {
            cct_showch(10, another_OY + 7, ' ');
            cct_gotoxy(1, another_OY + 7);
            cout << "游戏结束" << endl;
            break;
        }
        if ((dst == 'C') && (c[n - 1] == 1))
        {
            cct_showch(10, another_OY + 7, ' ');
            cct_gotoxy(1, another_OY + 7);
            cout << "游戏结束" << endl;
            break;
        }
        cct_showch(X, Y, ' ', 0, 7, 10);
    }
    count = 0;
    for (int i = 0; i < n; i++)
        a[i] = 0;
    for (int i = 0; i < n; i++)
        b[i] = 0;
    for (int i = 0; i < n; i++)
        c[i] = 0;
    pa = 0;
    pb = 0;
    pc = 0;
    cct_showch(OX, another_OY - 1, ' ');
    cct_gotoxy(1, another_OY + 8);
    end();
}
void select(int choice)
{
    switch (choice - int('0'))
    {
    case 1:
        game1();
        break;
    case 2:
        game2();
        break;
    case 3:
        game3();
        break;
    case 4:
        game4();
        break;
    case 5:
        game5();
        break;
    case 6:
        game6();
        break;
    case 7:
        game7();
        break;
    case 8:
        game8();
        break;
    case 9:
        game9();
        break;
    }
}
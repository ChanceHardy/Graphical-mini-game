#include<iostream>
#include<Windows.h>
#include"../include/cmd_console_tools.h"
#include"../include/include_tools.h"
using namespace std;
void create_base_balls(int row, int col, int ball[][12], int num) {       //创建数组形式的矩阵
	int x, y;
	cct_getxy(x, y);
	cout << "  ";
	cout << "|";
	for (int i = 1; i <= col; i++)
		cout << "  " << i;
	cout << endl;
	cout << "--+";
	cct_getxy(x, y);
	cct_showch(x, y, '-', 0, 7, 3 * col + 1);
	cout << endl;
	for (int i = 0; i < row; i++) {
		cout << char('A' + i) << " |";
		for (int j = 1; j <= col; j++) 
			cout << "  " << ball[i + 1][j] % 10;
		cout << endl;
	}
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if ((ball[i][j] > num) || (ball[i][j] == 0)) 
				cct_showch(x - 1 + j * 3, y + i, (char)('0' + (ball[i][j] % 10)), 0, 5);           //打印不同颜色
	cct_setcolor(0, 7);
	cct_gotoxy(0, y + row + 2);
}
void print_end() {                               //打印是否输入end来结束
	cout << endl;
	cout << "本小题结束，请输入End继续";
	char a, b, c;
	int count;
	while (1) {
		count = 0;
		cin >> a >> b >> c;
		if ((a == 'E') || (a == 'e'))
			count++;
		if ((b == 'n') || (b == 'N'))
			count++;
		if ((c == 'd') || (c == 'D'))
			count++;
		if (count == 3) {
			return;
			break;
		}
		else
			cout << "输入错误，请重新输入";
	}
}
void create_outside(int row, int col) {                   //规定屏幕大小（动态）并生成外边框
	cct_setconsoleborder(col * 6 + 12, row * 3 + 8);
	cct_cls();
	cct_gotoxy(0, 0);
	cout << "当前屏幕设置为" << (row * 3 + 8) << "行" << (col * 6 + 12) << "列";
	for (int i = 1; i <= row; i++)
		cct_showch(start_graph_x - 3, start_graph_y + i * 3 - 1, (char)('A' + i - 1));
	for (int j = 1; j <= col; j++) {
		cct_gotoxy(start_graph_x + j * 6 - 1, start_graph_y - 1);
		cout << j;
	}
	cct_showstr(start_graph_x, start_graph_y, "╔", 15, 0);
	Sleep(1);
	for (int j = 1; j <= (col * 3); j++) {
		cct_showstr(start_graph_x + j * 2, start_graph_y, "═", 15, 0);
		Sleep(1);
	}
	cct_showstr(start_graph_x + 2 + col * 6, start_graph_y, "╗", 15, 0);
	Sleep(1);
	for (int i = 1; i <= (row * 3); i++) {
		cct_showstr(start_graph_x, start_graph_y + i, "║", 15, 0);
		Sleep(1);
		for (int j = 1; j <= (col * 3); j++) {
			cct_showstr(start_graph_x + j * 2, start_graph_y + i, "  ", 15, 0);
			Sleep(1);
		}
		cct_showstr(start_graph_x + 2 + col * 6, start_graph_y + i, "║", 15, 0);
		Sleep(1);
	}
	cct_showstr(start_graph_x, start_graph_y + row * 3 + 1, "╚", 15, 0);
	Sleep(1);
	for (int j = 1; j <= (col * 3); j++) {
		cct_showstr(start_graph_x + j * 2, start_graph_y + row * 3 + 1, "═", 15, 0);
		Sleep(1);
	}
	cct_showstr(start_graph_x + 2 + col * 6, start_graph_y + row * 3 + 1, "╝", 15, 0);
	return;
}
void create_one_piece(int back_color, int start_x, int start_y, int fron_clor) {               //给出颜色和初始位置后创建一个色块
	cct_showstr(start_x, start_y, "╔", back_color, fron_clor);
	cct_showstr(start_x + 2, start_y, "═", back_color, fron_clor);
	cct_showstr(start_x + 4, start_y, "╗", back_color, fron_clor);
	cct_showstr(start_x, start_y + 1, "║", back_color, fron_clor);
	cct_showstr(start_x + 2, start_y + 1, "★", back_color, fron_clor);
	cct_showstr(start_x + 4, start_y + 1, "║", back_color, fron_clor);
	cct_showstr(start_x, start_y + 2, "╚", back_color, fron_clor);
	cct_showstr(start_x + 2, start_y + 2, "═", back_color, fron_clor);
	cct_showstr(start_x + 4, start_y + 2, "╝", back_color, fron_clor);
	cct_setcolor(0, 7);
	return;
}
void create_outside_plus(int row, int col) {                                                   
	cct_setconsoleborder(col * 8 + 12, row * 4 + 9);
	cct_cls();
	cct_gotoxy(0, 0);
	cout << "当前屏幕设置为" << (row * 4 + 9) << "行" << (col * 8 + 12) << "列";
	for (int i = 1; i <= row; i++)
		cct_showch(start_graph_x - 3, start_graph_y + i * 4 - 2, (char)('A' + i - 1));
	for (int j = 1; j <= col; j++) {
		cct_gotoxy(start_graph_x + j * 8 - 3, start_graph_y - 1);
		cout << j;
	}
	cct_showstr(start_graph_x, start_graph_y, "╔", 15, 0);
	Sleep(1);
	for (int j = 1; j <= (col - 1); j++) {
		for (int k = 1; k <= 3; k++) {
			cct_showstr(start_graph_x + j * 8 + k * 2 - 8, start_graph_y, "═", 15, 0);
			Sleep(1);
		}
		cct_showstr(start_graph_x + j * 8, start_graph_y, "╦", 15, 0);
		Sleep(1);
	}
	for (int k = 1; k <= 3; k++) {
		cct_showstr(start_graph_x + k * 2 + (col - 1) * 8, start_graph_y, "═", 15, 0);
		Sleep(1);
	}
	cct_showstr(start_graph_x + col * 8, start_graph_y, "╗", 15, 0);
	Sleep(1);                                                                                    //到此为止是第一行，后面的输出都依据第一行输出的x坐标，只更改了输出的符号和y坐标
	for (int i = 1; i <= (row - 1); i++) {
		for (int m = 0; m < 3; m++) {
			cct_showstr(start_graph_x, start_graph_y + i * 4 + m - 3, "║", 15, 0);
			Sleep(1);
			for (int j = 1; j <= (col - 1); j++) {
				for (int k = 1; k <= 3; k++) {
					cct_showstr(start_graph_x + j * 8 + k * 2 - 8, start_graph_y + i * 4 + m - 3, "  ", 15, 0);
					Sleep(1);
				}
				cct_showstr(start_graph_x + j * 8, start_graph_y + i * 4 + m - 3, "║", 15, 0);
				Sleep(1);
			}
			for (int k = 1; k <= 3; k++) {
				cct_showstr(start_graph_x + k * 2 + (col - 1) * 8, start_graph_y + i * 4 + m - 3, "  ", 15, 0);
				Sleep(1);
			}
			cct_showstr(start_graph_x + col * 8, start_graph_y + i * 4 + m - 3, "║", 15, 0);
			Sleep(1);
		}
		cct_showstr(start_graph_x, start_graph_y + i * 4, "╠", 15, 0);
		Sleep(1);
		for (int j = 1; j <= (col - 1); j++) {
			for (int k = 1; k <= 3; k++) {
				cct_showstr(start_graph_x + j * 8 + k * 2 - 8, start_graph_y + i * 4, "═", 15, 0);
				Sleep(1);
			}
			cct_showstr(start_graph_x + j * 8, start_graph_y + i * 4, "╬", 15, 0);
			Sleep(1);
		}
		for (int k = 1; k <= 3; k++) {
			cct_showstr(start_graph_x + k * 2 + (col - 1) * 8, start_graph_y + i * 4, "═", 15, 0);
			Sleep(1);
		}
		cct_showstr(start_graph_x + col * 8, start_graph_y + i * 4, "╣", 15, 0);
		Sleep(1);
	}
	for (int m = 1; m <= 3; m++) {
		cct_showstr(start_graph_x, start_graph_y + (row - 1) * 4 + m, "║", 15, 0);
		Sleep(1);
		for (int j = 1; j <= (col - 1); j++) {
			for (int k = 1; k <= 3; k++) {
				cct_showstr(start_graph_x + j * 8 + k * 2 - 8, start_graph_y + (row - 1) * 4 + m, "  ", 15, 0);
				Sleep(1);
			}
			cct_showstr(start_graph_x + j * 8, start_graph_y + (row - 1) * 4 + m, "║", 15, 0);
			Sleep(1);
		}
		for (int k = 1; k <= 3; k++) {
			cct_showstr(start_graph_x + k * 2 + (col - 1) * 8, start_graph_y + (row - 1) * 4 + m, "  ", 15, 0);
			Sleep(1);
		}
		cct_showstr(start_graph_x + col * 8, start_graph_y + (row - 1) * 4 + m, "║", 15, 0);
		Sleep(1);
	}
	cct_showstr(start_graph_x, start_graph_y + row * 4, "╚", 15, 0);
	Sleep(1);
	for (int j = 1; j <= (col - 1); j++) {
		for (int k = 1; k <= 3; k++) {
			cct_showstr(start_graph_x + j * 8 + k * 2 - 8, start_graph_y + row * 4, "═", 15, 0);
			Sleep(1);
		}
		cct_showstr(start_graph_x + j * 8, start_graph_y + row * 4, "╩", 15, 0);
		Sleep(1);
	}
	for (int k = 1; k <= 3; k++) {
		cct_showstr(start_graph_x + k * 2 + (col - 1) * 8, start_graph_y + row * 4, "═", 15, 0);
		Sleep(1);
	}
	cct_showstr(start_graph_x + col * 8, start_graph_y + row * 4, "╝", 15, 0);
	Sleep(1);
}
void down(int ball[][12], int graph_row, int graph_col, int plus) {
	create_one_piece(15, start_graph_x + graph_col * (6 + plus * 2) - 4 - plus * 2, start_graph_y + (graph_row + 1) * (3 + plus) - 2 - plus, 15);
	for (int k = 1; k <= (3 + plus); k++) {
		create_one_piece(ball[graph_row][graph_col], start_graph_x + graph_col * (6 + plus * 2) - 4 - plus * 2, start_graph_y + graph_row * (3 + plus) - 2 - plus + k, 0);
		cct_showch(start_graph_x + graph_col * (6 + plus * 2) - 4 - plus * 2, start_graph_y + graph_row * (3 + plus) - 3 - plus + k, ' ', 15, 0, 6);
		Sleep(10);
	}
	if (plus)
		cct_showstr(start_graph_x + graph_col * (6 + plus * 2) - 4 - plus * 2, start_graph_y + graph_row * (3 + plus) + 1 - plus, "═", 15, 0, 3);
	cct_setcolor(0, 7);
	return;
}
void left(int ball[][12], int graph_row, int graph_col, int plus) {
	create_one_piece(15, start_graph_x + (graph_col - 1) * (6 + plus * 2) - 4 - plus * 2, start_graph_y + graph_row * (3 + plus) - 2 - plus, 15);
	for (int k = 1; k <= (3 + plus) * 2; k++) {
		if (ball[graph_row][graph_col]) {
			create_one_piece(ball[graph_row][graph_col], start_graph_x + graph_col * (6 + plus * 2) - 4 - plus * 2 - k, start_graph_y + graph_row * (3 + plus) - 2 - plus, 0);
			for (int m = 1; m <= 3; m++)
				cct_showch(start_graph_x + graph_col * (6 + plus * 2) + 2 - plus * 2 - k, start_graph_y + graph_row * (3 + plus) - 3 - plus + m, ' ', 15, 0);
			Sleep(10);
		}
	}
	for (int k = 0; k < 3; k++)
		cct_showstr(start_graph_x + graph_col * (6 + plus * 2) - 6 - plus * 2, start_graph_y + graph_row * (3 + plus) - 2 - plus + k, "║", 15, 0);
	cct_setcolor(0, 7);
	return;
}
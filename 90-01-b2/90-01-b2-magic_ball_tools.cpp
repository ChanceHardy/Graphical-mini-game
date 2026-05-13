/* 2351577 大数据 张宸浩 */
#include<iostream>
#include<ctime>
#include<Windows.h>
#include<cmath>
#include "../include/cmd_console_tools.h"
#define X 0
#define Y 1
using namespace std;
void input_row(int* row) {
	while (1) {
		cout << "请输入行数(5-9)：" << endl;
		cin >> *row;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\0');
			continue;
		}
		if (*row >= 5 && *row <= 9)
			break;
	}
	return;
}
void input_col(int* col) {
	while (1) {
		cout << "请输入列数(5-9)：" << endl;
		cin >> *col;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\0');
			continue;
		}
		if (*col >= 5 && *col <= 9)
			break;
	}
	return;
}
int judge(int sum, int row, int col, int ball[][12]) {
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++) {
			if ((ball[i - 1][j] == ball[i][j]) && (ball[i][j] == ball[i + 1][j])) {
				ball[i - 1][j] += 10;
				ball[i][j] += 10;
				ball[i + 1][j] += 10;
				sum++;
			}
			if ((ball[i][j - 1] == ball[i][j]) && (ball[i][j] == ball[i][j + 1])) {
				ball[i][j - 1] += 10;
				ball[i][j] += 10;
				ball[i][j + 1] += 10;
				sum++;
			}
		}
	return sum;
}
void judge_change(int row, int col, int ball[][12]) {
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			ball[i][j] = ball[i][j] % 10;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++) {
			int t, sum = 0;
			t = ball[i][j];
			ball[i][j] = ball[i - 1][j];
			ball[i - 1][j] = t;
			if (judge(sum, row, col, ball)) {
				ball[i][j] += 100;
				ball[i - 1][j] += 100;
			}
			t = ball[i][j];
			ball[i][j] = ball[i - 1][j];
			ball[i - 1][j] = t;
			sum = 0;
			t = ball[i][j];
			ball[i][j] = ball[i + 1][j];
			ball[i + 1][j] = t;
			if (judge(sum, row, col, ball)) {
				ball[i][j] += 100;
				ball[i + 1][j] += 100;
			}
			t = ball[i][j];
			ball[i][j] = ball[i + 1][j];
			ball[i + 1][j] = t;
			sum = 0;
			t = ball[i][j];
			ball[i][j] = ball[i][j - 1];
			ball[i][j - 1] = t;
			if (judge(sum, row, col, ball)) {
				ball[i][j] += 100;
				ball[i][j - 1] += 100;
			}
			t = ball[i][j];
			ball[i][j] = ball[i][j - 1];
			ball[i][j - 1] = t;
			sum = 0;
			t = ball[i][j];
			ball[i][j] = ball[i][j + 1];
			ball[i][j + 1] = t;
			if (judge(sum, row, col, ball)) {
				ball[i][j] += 100;
				ball[i][j + 1] += 100;
			}
			t = ball[i][j];
			ball[i][j] = ball[i][j + 1];
			ball[i][j + 1] = t;
		}
}
void create_graph_balls(int row, int col, int ball[][12], int n) {
	int x, y;
	x = X;
	y = Y;
	if (n == 1) {
		cct_showstr(x, y, "╔", 15, 0);
		cct_showstr(x + 2, y, "═", 15, 0, col);
		for (int i = 1; i <= (row + 1); i++) {
			cct_showstr(x, y + i, "║", 15, 0);
			cct_showstr(x + col * 2 + 2, y + i, "║", 15, 0);
		}
		cct_showstr(x, y + row + 1, "╚", 15, 0);
		cct_showstr(x + col * 2 + 2, y + row + 1, "╝", 15, 0);
		cct_showstr(x + col * 2 + 2, y, "╗", 15, 0);
		cct_showstr(x + 2, y + row + 1, "═", 15, 0, col);
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++) {
				if (ball[i][j] > 10)
					cct_showstr(x + j * 2, y + i, "●", ball[i][j] % 10, 0);
				else
					cct_showstr(x + j * 2, y + i, "〇", ball[i][j], 0);
			}
	}
	else {
		cct_showstr(x, y, "╔", 15, 0);
		cct_showstr(x + 2, y, "═╦", 15, 0, col - 1);
		cct_showstr(x - 2 + 4 * col, y, "═╗", 15, 0);
		for (int i = 1; i <= (row - 1); i++) {
			cct_showstr(x, y + i * 2 - 1, "║  ", 15, 0, col);
			cct_showstr(x + col * 4, y + i * 2 - 1, "║", 15, 0);
			cct_showstr(x, y + i * 2, "╠", 15, 0);
			cct_showstr(x + 2, y + i * 2, "═╬", 15, 0, col - 1);
			cct_showstr(x + col * 4 - 2, y + i * 2, "═╣", 15, 0);
		}
		cct_showstr(x, y + row * 2 - 1, "║  ", 15, 0, col);
		cct_showstr(x + col * 4, y + row * 2 - 1, "║", 15, 0);
		cct_showstr(x, y + row * 2, "╚", 15, 0);
		cct_showstr(x + 2, y + row * 2, "═╩", 15, 0, col - 1);
		cct_showstr(x - 2 + 4 * col, y + row * 2, "═╝", 15, 0);
		for (int i = 1; i <= row; i++)
			for (int j = 1; j <= col; j++) {
				if (n == 2) {
					if (ball[i][j] > 10)
						cct_showstr(x + j * 4 - 2, y + i * 2 - 1, "●", ball[i][j] % 10, 0);
					if (ball[i][j] < 10)
						cct_showstr(x + j * 4 - 2, y + i * 2 - 1, "〇", ball[i][j], 0);
				}
				if (n == 3) {
					if (ball[i][j] < 100)
						cct_showstr(x + j * 4 - 2, y + i * 2 - 1, "〇", ball[i][j] % 10, 0);
					if (ball[i][j] > 100)
						cct_showstr(x + j * 4 - 2, y + i * 2 - 1, "◎", ball[i][j] % 10, 0);
				}
			}
	}
	cct_setcolor(0, 7);
	cct_gotoxy(0, y + row * 2);
}
void eraser(int row, int col, int ball[][12]) {
	srand((unsigned int)(time(0)));
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++) {
			if (ball[i][j] > 10) {
				cct_showch(X + j * 4 - 2, Y + i * 2 - 1, ' ', 15, 0, 2);
				Sleep(50);
				ball[i][j] = rand() % 9 + 51;
			}
		}
	for (int j = 1; j <= col; j++)
		for (int k = 0; k < row; k++)
			for (int i = 1; i <= row; i++) {
				if (ball[i][j] < 50 && ball[i + 1][j] > 50) {
					int t;
					t = ball[i][j];
					ball[i][j] = ball[i + 1][j];
					ball[i + 1][j] = t;
					cct_showstr(X + j * 4 - 2, Y + (i + 1) * 2 - 1, "〇", ball[i + 1][j] % 10, 0);
					cct_showch(X + j * 4 - 2, Y + i * 2 - 1, ' ', 15, 0, 2);
					Sleep(50);
				}

			}
	cct_setcolor(0, 7);
	cct_gotoxy(0, Y + row * 2 + 1);
	return;
}
void fill_graph(int row, int col, int ball[][12]) {
	srand((unsigned int)(time(0)));
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (ball[i][j] > 50) {
				ball[i][j] = rand() % 9 + 1;
				cct_showstr(X + j * 4 - 2, Y + i * 2 - 1, "〇", ball[i][j], 0);
				Sleep(50);
			}
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			ball[i][j] = ball[i][j] % 10;
	cct_setcolor();
	return;
}
int printMouseCoordinates(int row, int col, int ball[][12], int* record_i, int* record_j) {
	cct_enable_mouse();
	int MX = 0, MY = 0, MAction, keycode1, keycode2;
	while (true) {
		int event = cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
		if (event == CCT_MOUSE_EVENT) {
			cct_gotoxy(X, Y + row * 2 + 1);
			char hang;
			int lie;
			if (MX > X && MX<(X + col * 4 + 1) && MY>Y && MY < (Y + row * 2 + 1))
				if (((MX - X) % 4 == 2 || (MX - X) % 4 == 3) && ((MY - Y) % 2 == 1)) {
					hang = (MY - Y) / 2 + 'A';
					lie = 1 + (MX - X) / 4;
					cout << "当前位置  " << hang << "行" << "  " << lie << "列";
				}
				else
					cout << "当前位置  " << "位置非法";
			else
				cout << "当前位置  " << "位置非法";
			switch (MAction) {
			case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
				if ((MX > X && MX<(X + col * 4 + 1) && MY>Y && MY < (Y + row * 2 + 1)) && (((MX - X) % 4 == 2 || (MX - X) % 4 == 3) && ((MY - Y) % 2 == 1)) && (ball[(MY - Y) / 2 + 1][1 + (MX - X) / 4] > 100)) {
					*record_i = (MY - Y) / 2 + 1;
					*record_j = 1 + (MX - X) / 4;
					cct_gotoxy(X, Y + row * 2 + 1);
					cout << "当前选择  ";
					return 0;
				}
				else
					cct_showstr(X, Y + row * 2 + 1, "不能选择");
				break;
			case MOUSE_RIGHT_BUTTON_CLICK:			//按下右键
				return 1;
				break;
			}
		}
	}
	return 0;
}
int end_of_game(int row, int col, int ball[][12]) {
	judge_change(row, col, ball);
	int sum = 0;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (ball[i][j] > 100)
				sum++;
	if (!sum)
		return 1;
	else
		return 0;
}
void choose_the_ball(int row, int col, int ball[][12]) {
	int record_i1, record_i2, record_j1, record_j2;
	printMouseCoordinates(row, col, ball, &record_i1, &record_j1);
	cct_showstr(X + record_j1 * 4 - 2, Y + record_i1 * 2 - 1, "  ", 15, 0);
	cct_setcolor();
	while (1) {
		printMouseCoordinates(row, col, ball, &record_i2, &record_j2);
		if ((record_i1 == record_i2 && fabs(record_j1 - record_j2) == 1) || (record_j1 == record_j2 && fabs(record_i1 - record_i2) == 1))
			break;
	}
	int t;
	t = ball[record_i1][record_j1];
	ball[record_i1][record_j1] = ball[record_i2][record_j2];
	ball[record_i2][record_j2] = t;
	ball[record_i1][record_j1] = ball[record_i1][record_j1] % 10;
	ball[record_i2][record_j2] = ball[record_i2][record_j2] % 10;
	cct_showstr(X + record_j1 * 4 - 2, Y + record_i1 * 2 - 1, "〇", ball[record_i1][record_j1] % 10, 0);
	cct_showstr(X + record_j2 * 4 - 2, Y + record_i2 * 2 - 1, "〇", ball[record_i2][record_j2] % 10, 0);
	cct_setcolor();
	cct_disable_mouse();
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			ball[i][j] = ball[i][j] % 10;
	return;
}
/* 2351577 大数据 张宸浩 */
#include<iostream>
#include<ctime>
#include<conio.h>
#include"90-01-b2-magic_ball.h"
#include "../include/cmd_console_tools.h"
#include"../include/include_tools.h"
#define X 0
#define Y 1
using namespace std;
void game45(int n) {
	srand((unsigned int)(time(0)));
	int col, row;
	cct_cls();
	input_row(&row);
	input_col(&col);
	int ball[11][12] = { 0 };
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			ball[i][j] = rand() % 9 + 1;
	cout << endl;
	cout << "初始数组：" << endl;
	create_base_balls(row, col, ball, 10);
	cout << "按回车键显示图形...";
	char ch1;
	ch1 = _getche();
	if (ch1 == 13) {
		if (n == 4) {
			cct_setconsoleborder(40, row + 6);
			cout << "屏幕：" << (row + 6) << "行40列" << endl;
			create_graph_balls(row, col, ball, 1);
		}
		else {
			cct_setconsoleborder(40, row * 2 + 5);
			cout << "屏幕：" << (row * 2 + 5) << "行40列" << endl;
			create_graph_balls(row, col, ball, 2);
		}
	}
	print_end();
}
void game6() {
	srand((unsigned int)(time(0)));
	int col, row;
	cct_cls();
	input_row(&row);
	input_col(&col);
	int ball[11][12] = { 0 };
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			ball[i][j] = rand() % 9 + 1;
	cct_setconsoleborder(40, row + 6);
	cout << "屏幕：" << (row + 6) << "行40列";
	int sum = 0;
	if (judge(sum, row, col, ball)) {
		cout << endl;
		create_graph_balls(row, col, ball, 1);
	}
	else {
		cout << " 初始无可消项" << endl;
		create_graph_balls(row, col, ball, 1);
	}
	cout << endl;
	print_end();
}
void game7() {
	srand((unsigned int)(time(0)));
	int col, row;
	cct_cls();
	input_row(&row);
	input_col(&col);
	int ball[11][12] = { 0 };
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			ball[i][j] = rand() % 9 + 1;
	cct_setconsoleborder(40, row * 2 + 5);
	cout << "屏幕：" << (row * 2 + 5) << "行40列";
	int sum;
	while (1) {
		sum = 0;
		if (judge(sum, row, col, ball)) {
			cout << endl;
			create_graph_balls(row, col, ball, 2);
			cct_gotoxy(X, Y + row * 2 + 1);
			cout << "按回车键进行消除以及下落除零操作...";
			char ch1;
			ch1 = _getche();
			if (ch1 == 13)
				eraser(row, col, ball);
			cct_showch(X, Y + row * 2 + 1, ' ', 0, 7, 40);
			cct_gotoxy(X, Y + row * 2 + 1);
			cout << "按回车键进行新值填充...";
			char ch2;
			ch2 = _getche();
			if (ch2 == 13)
				fill_graph(row, col, ball);
		}
		else {
			cct_gotoxy(20, 0);
			cout << " 无可消除项" << endl;
			break;
		}
	}
	cct_showch(X, Y + row * 2 + 1, ' ', 0, 7, 40);
	cct_gotoxy(X, Y + row * 2 + 1);
	cout << "显示可消除提示...";
	char ch3;
	ch3 = _getche();
	if (ch3 == 13) {
		judge_change(row, col, ball);
		create_graph_balls(row, col, ball, 3);
	}
	cout << endl;
	print_end();
}
void game89(int n) {
	srand((unsigned int)(time(0)));
	int col, row;
	cct_cls();
	input_row(&row);
	input_col(&col);
	int ball[11][12] = { 0 };
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			ball[i][j] = rand() % 9 + 1;
	cct_setconsoleborder(40, row * 2 + 5);
	cout << "屏幕：" << (row * 2 + 5) << "行40列";
	int sum;
	while (1) {
		sum = 0;
		if (judge(sum, row, col, ball)) {
			cout << endl;
			create_graph_balls(row, col, ball, 2);
			eraser(row, col, ball);
			fill_graph(row, col, ball);
		}
		else {
			cct_gotoxy(20, 0);
			cout << " 无可消除项" << endl;
			break;
		}
	}
	judge_change(row, col, ball);
	create_graph_balls(row, col, ball, 3);
	cct_gotoxy(15, 0);
	cout << "当前分数：0（右键退出）";
	if (n == 1) {
		int record_i1, record_i2;
		printMouseCoordinates(row, col, ball, &record_i1, &record_i2);
		print_end();
		return;
	}
	else {
		while (1) {
			int i1, i2;
			if (printMouseCoordinates(row, col, ball, &i1, &i2))
				break;
			if (end_of_game(row, col, ball)) {
				cct_showstr(X, Y + row * 2 + 1, "       游戏结束        ");
				print_end();
				return;
				break;
			}
			choose_the_ball(row, col, ball);
			int c = 0;
			while (1) {
				if (judge(c, row, col, ball)) {
					eraser(row, col, ball);
					fill_graph(row, col, ball);
				}
				else
					break;
			}
			judge_change(row, col, ball);
			create_graph_balls(row, col, ball, 3);
		}
		cct_gotoxy(X, Y + row * 2 + 2);
		print_end();
		return;
	}
}
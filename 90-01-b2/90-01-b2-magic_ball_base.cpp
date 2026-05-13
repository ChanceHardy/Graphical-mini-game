/* 2351577 大数据 张宸浩 */
#include<iostream>
#include<ctime>
#include<conio.h>
#include "../include/cmd_console_tools.h"
#include"90-01-b2-magic_ball.h"
#include"../include/include_tools.h"
using namespace std;
void game1() {
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
	cout << "按回车键进行寻找初始可消除项的操作...";
	char ch;
	ch = _getche();
	if (ch == 13) {
		int sum = 0;
		sum = judge(sum, row, col, ball);
		if (!sum) {
			cout << endl;
			cout << "初始已无可消项" << endl;
		}
		else {
			cout << endl;
			cout << "初始可消除项（不同颜色标注）" << endl;
			create_base_balls(row, col, ball, 10);
		}
	}
	print_end();
	return;
}
void game23(int n) {
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
	cout << "按回车键进行寻找初始可消除项的操作...";
	char ch;
	ch = _getche();
	if (ch == 13) {
		while (1) {
			int sum = 0;
			sum = judge(sum, row, col, ball);
			if (!sum) {
				cout << endl;
				cout << "初始已无可消项" << endl;
				break;
			}
			else {
				cout << endl;
				cout << "初始可消除项（不同颜色标注）" << endl;
				create_base_balls(row, col, ball, 10);
				cout << endl;
				cout << "按回车键进行数组下落0的操作..." << endl;
				char ch2;
				ch2 = _getche();
				if (ch2 == 13) {
					for (int i = 1; i <= row; i++)
						for (int j = 1; j <= col; j++)
							if (ball[i][j] > 10)
								ball[i][j] = 0;
					cout << "下落除0后的数组（不同颜色标记）" << endl;
					create_base_balls(row, col, ball, 10);
					cout << "按回车进行新值填充..." << endl;
					char ch3;
					ch3 = _getche();
					if (ch3 == 13) {
						for (int i = 1; i <= row; i++)
							for (int j = 1; j <= col; j++)
								if (!ball[i][j])
									ball[i][j] = rand() % 9 + 11;
						cout << "新值填充后的数组" << endl;
						create_base_balls(row, col, ball, 10);
					}
				}
			}
		}
		if (n == 3) {
			judge_change(row, col, ball);
			cout << endl;
			cout << "可选择的消除提示" << endl;
			create_base_balls(row, col, ball, 100);
		}
	}
	print_end();
}
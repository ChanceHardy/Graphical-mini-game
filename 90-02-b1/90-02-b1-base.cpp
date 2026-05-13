#include<iostream>
#include<ctime>
#include<conio.h>
#include"../include/cmd_console_tools.h"
#include"../include/include_tools.h"
#include"90-02-b1-star.h"
using namespace std;
void star_game12(int n_choice) {
	int score = 0;
	cct_cls();
	srand((unsigned int)(time(0)));
	int col, row;
	input_row(&row);
	input_col(&col);
	int ball[12][12] = { 0 };
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			ball[i][j] = rand() % color_num + 1;
	cout << "初始数组：" << endl;
	create_base_balls(row, col, ball, 10);
	cout << endl;
	char coordinate[10];
	input_coordinate(coordinate, col, row, ball);
	cout << "当前数组：（不同颜色标识）" << endl;
	create_base_balls(row, col, ball, 10);
	if (n_choice == 1) {
		print_end();
		return;
	}
	if (n_choice == 2) {
		cout << "请确认是否将" << coordinate[0] << coordinate[1] << "周围相同项消除（Y/N/Q）";
		while (1) {
			int ynq_x, ynq_y;
			cct_getxy(ynq_x, ynq_y);
			char choose_ynq;
			choose_ynq = _getche();
			cout << endl;
			if (choose_ynq == 'y' || choose_ynq == 'Y') {
				clear_and_fall(ball, row, col, &score);
				break;
			}
			else if (choose_ynq == 'n' || choose_ynq == 'N' || choose_ynq == 'q' || choose_ynq == 'Q')
				break;
			else
				cct_showch(ynq_x, ynq_y, ' ');
		}
		print_end();
		return;
	}
}
void star_game3() {
	int score = 0;
	cct_cls();
	srand((unsigned int)(time(0)));
	int col, row;
	input_row(&row);
	input_col(&col);
	int ball[12][12] = { 0 };
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			ball[i][j] = rand() % color_num + 1;
	cout << endl;
	while (1) {
		cout << "当前数组：" << endl;
		create_base_balls(row, col, ball, 10);                                 //生成基础版
		char coordinate[10];
		input_coordinate(coordinate, col, row, ball);                           //周围+10  并生成0和*版
		cout << "当前数组：（不同颜色标识）" << endl;
		create_base_balls(row, col, ball, 10);                               //生成周围+10版
		cout << "请确认是否将" << coordinate[0] << coordinate[1] << "周围相同项消除（Y/N/Q）";
		while (1) {
			int ynq_x, ynq_y;
			cct_getxy(ynq_x, ynq_y);
			char choose_ynq;
			choose_ynq = _getche();
			cout << endl;
			if (choose_ynq == 'y' || choose_ynq == 'Y') {
				clear_and_fall(ball, row, col, &score);                       //消10以上为0  生成消10    按回车生成下落版
				if (if_this_is_end(ball, row, col)) {
					cout << "无可消除项，游戏结束" << endl;
					print_end();
					return;
					break;
					break;
				}
				else {
					cout << "本次消除结束，按回车键进行新一轮消除";
					reverse_over_num(ball, row, col, 10);
					choose_enter();
				}
				break;
			}
			else if (choose_ynq == 'n' || choose_ynq == 'N') {
				reverse_over_num(ball, row, col, 10);
				break;
			}
			else if (choose_ynq == 'q' || choose_ynq == 'Q')
				break;
			else
				cct_showch(ynq_x, ynq_y, ' ');
		}
	}
}
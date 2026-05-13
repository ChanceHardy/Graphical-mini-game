#include<iostream>
#include<ctime>
#include<Windows.h>
#include"../include/cmd_console_tools.h"
#include"../include/include_tools.h"
#include"90-02-b1-star.h"
using namespace std;
void star_game45(int n) {
	int count = 0;
	cct_cls();
	srand((unsigned int)(time(0)));
	int col, row;
	input_row(&row);
	input_col(&col);
	int ball[12][12] = { 0 };
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			ball[i][j] = rand() % color_num + 1;
	if (n == 4)
		create_outside(row, col);
	if (n == 5)
		create_outside_plus(row, col);
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++) {
			create_one_piece(ball[i][j], start_graph_x + j * (2 * n - 2) + 4 - 2 * n, start_graph_y + i * (n - 1) + 2 - n, 0);            //参数控制输出位置
			Sleep(1);
		}
	cct_gotoxy(start_graph_x, start_graph_y + row * (n - 1) + 3);
	cout << "用键盘或鼠标移动，回车或左键单击选择并结束";
	int record_row, record_col;
	int white_row = 1, white_col = 1;
	print_mouse_coordinate(ball, row, col, &record_row, &record_col, n - 4, &white_row, &white_col, 0, &count);
	cout << endl;
	cct_gotoxy(start_graph_x, start_graph_y + row * (n - 1) + 4);
	print_end();
}
void star_game6(int n) {
	int score = 0;
	int count = 0;
	cct_cls();
	srand((unsigned int)(time(0)));
	int col, row;
	input_row(&row);
	input_col(&col);
	int ball[12][12] = { 0 };
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			ball[i][j] = rand() % color_num + 1;
	if (n == 4)
		create_outside(row, col);
	if (n == 5)
		create_outside_plus(row, col);
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++) {
			create_one_piece(ball[i][j], start_graph_x + j * (2 * n - 2) + 4 - 2 * n, start_graph_y + i * (n - 1) + 2 - n, 0);            //参数控制输出位置
			Sleep(1);
		}
	cct_gotoxy(start_graph_x, start_graph_y + row * (n - 1) + 2);
	cout << "用键盘或鼠标移动，回车或左键单击选择,Q或右键单击退出";
	int record_row, record_col;
	int white_row = 1, white_col = 1;
	int exit;
	while (1) {                                                                 //此循环完成找出消除项的任务
		exit = print_mouse_coordinate(ball, row, col, &record_row, &record_col, n - 4, &white_row, &white_col, 1, &count);
		if (exit)
			break;
		if (judge_only_neighbor(ball, col, row, (char)('A' + record_row - 1), (char)('1' + record_col - 1))) {                  //找出连坐的亮块
			for (int i = 1; i <= row; i++)
				for (int j = 1; j <= col; j++)
					if (ball[i][j] > 10) 
						create_one_piece(ball[i][j] % 10, start_graph_x + j * (2 * n - 2) + 4 - 2 * n, start_graph_y + i * (n - 1) + 2 - n, 7);           //是否需要，存疑，将星星的值重置为小于10
			cct_gotoxy(start_graph_x, start_graph_y + row * ((n - 4) + 3) + 2);
			cout << "箭头键或鼠标移动取消当前选择，回车或左键单击合成";
		}
		else {
			cct_gotoxy(start_graph_x, start_graph_y + row * ((n - 4) + 3) + 2);
			cout << "周围无相同值，请重新选择";
		}
		int num = if_there_none(ball, row, col);
		if (num) {
			score += (num * num * 5);
			cct_gotoxy(0, 0);
			cout << "总得分： " << score << "   本轮得分： " << (num * num * 5);
			break;
		}
	}
	if (!exit)
		disappear_fall(ball, row, col, n - 4);
	cct_gotoxy(start_graph_x, start_graph_y + row * (n - 1) + 4);
	print_end();
}
void star_game7(int n) {
	int score = 0;
	int count = 0;
	cct_cls();
	srand((unsigned int)(time(0)));
	int col, row;
	input_row(&row);
	input_col(&col);
	int ball[12][12] = { 0 };
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			ball[i][j] = rand() % color_num + 1;
	if (n == 4)
		create_outside(row, col);
	if (n == 5)
		create_outside_plus(row, col);
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++) {
			create_one_piece(ball[i][j], start_graph_x + j * (2 * n - 2) + 4 - 2 * n, start_graph_y + i * (n - 1) + 2 - n, 0);            //参数控制输出位置
			Sleep(1);
		}
	cct_gotoxy(start_graph_x, start_graph_y + row * (n - 1) + 2);
	cout << "用键盘或鼠标移动，回车或左键单击选择,Q或右键单击退出";
	int record_row, record_col;
	int white_row = 1, white_col = 1;
	int exit;
	while (1) {
		while (1) {                                                                 //此循环完成找出消除项的任务
			count = 0;
			exit = print_mouse_coordinate(ball, row, col, &record_row, &record_col, n - 4, &white_row, &white_col, 1, &count);
			if (exit)                                                                    //用来判断是否按右键或者q退出的
				break;
			if (judge_only_neighbor(ball, col, row, (char)('A' + record_row - 1), (char)('1' + record_col - 1))) {                  //找出连坐的亮块
				for (int i = 1; i <= row; i++)
					for (int j = 1; j <= col; j++)
						if (ball[i][j] > 10)
							create_one_piece(ball[i][j] % 10, start_graph_x + j * (2 * n - 2) + 4 - 2 * n, start_graph_y + i * (n - 1) + 2 - n, 7);
				cct_gotoxy(start_graph_x, start_graph_y + row * ((n - 4) + 3) + 2);
				cout << "箭头键或鼠标移动取消当前选择，回车或左键单击合成";
			}
			else {
				cct_gotoxy(start_graph_x, start_graph_y + row * ((n - 4) + 3) + 2);
				cout << "周围无相同值，请重新选择";
			}
			if (count) {
				score += (count * count * 5);
				cct_gotoxy(0, 0);
				cout << "总得分： " << score << "   本轮得分： " << (count * count * 5);
				break;
			}
		}
		if (!exit)
			disappear_fall(ball, row, col, n - 4);
		if (if_this_is_end(ball, row, col)) {
			cct_gotoxy(start_graph_x, start_graph_y + row * ((n - 4) + 3) + 2);
			cout << "无可消除项，游戏结束                            ";
			cct_gotoxy(start_graph_x, start_graph_y + row * (n - 1) + 4);
			print_end();
			return;
			break;
		}
		else
			reverse_over_num(ball, row, col, 10);
	}
}
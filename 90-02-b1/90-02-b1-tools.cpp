#include<iostream>
#include<conio.h>
#include<Windows.h>
#include"../include/cmd_console_tools.h"
#include"../include/include_tools.h"
#include"90-02-b1-star.h"
using namespace std;
void input_row(int* row) {
	while (1) {
		cout << "请输入行数(8-10)：" << endl;
		cin >> *row;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\0');
			continue;
		}
		if (*row >= 8 && *row <= 10)
			break;
	}
	return;
}
void input_col(int* col) {
	while (1) {
		cout << "请输入列数(8-10)：" << endl;
		cin >> *col;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\0');
			continue;
		}
		if (*col >= 8 && *col <= 10)
			break;
	}
	return;
}
void input_coordinate(char coordinate[], int col, int row, int ball[][12]) {     //输入矩阵坐标及其处理
	cout << "请以字母+数字形式输入矩阵坐标： ";
	int x, y;
	cct_getxy(x, y);
	while (1) {
		while (1) {
			cct_gotoxy(x, y);
			cin >> coordinate;
			bool judge_1 = coordinate[0] >= 'a' && coordinate[0] < (char)('a' + row);
			bool judge_2 = coordinate[0] >= 'A' && coordinate[0] < (char)('A' + row);
			bool judge_3 = coordinate[1] >= '1' && coordinate[1] < (char)('1' + col);
			if ((judge_1 || judge_2) && judge_3) {
				if (judge_1)
					coordinate[0] = (char)(coordinate[0] - ('a' - 'A'));
				break;
			}
			else {
				cct_showch(x, y, ' ', 0, 7, 10);
				cct_showstr(0, y + 1, "输入错误");
				cct_gotoxy(x, y);
			}
		}
		cct_showstr(0, y + 1, "您的选择是");
		cout << coordinate[0] << coordinate[1] << endl;
		cout << endl;
		if (judge_only_neighbor(ball, col, row, coordinate[0], coordinate[1])) {
			cct_showch(0, y + 2, ' ', 0, 7, 30);
			cout << endl;
			show_zero_star(ball, row, col);
			break;
		}
		else {
			cct_showstr(0, y + 2, "该位置无法消除，请重新输入");
			cct_showch(x, y, ' ', 0, 7, 5);
		}
	}
	return;
}
bool judge_only_neighbor(int ball[][12], int col, int row, char x, char y) {         //判断是否有连坐位置并以10为底标记，若有相同返回1，反之则0
	int coordinate_x, coordinate_y, count_judge;
	count_judge = 0;
	coordinate_x = (int)(x - 'A' + 1);
	coordinate_y = (int)(y - '1' + 1);
	if (((ball[coordinate_x][coordinate_y] % 10) == (ball[coordinate_x - 1][coordinate_y] % 10)) && (ball[coordinate_x - 1][coordinate_y] < 10) && (ball[coordinate_x][coordinate_y] != 0)) {
		ball[coordinate_x][coordinate_y] += 10;
		ball[coordinate_x - 1][coordinate_y] += 10;
		count_judge++;
		judge_only_neighbor(ball, col, row, (char)(x - 1), y);
	}
	if (((ball[coordinate_x][coordinate_y] % 10) == (ball[coordinate_x + 1][coordinate_y] % 10)) && (ball[coordinate_x + 1][coordinate_y] < 10) && (ball[coordinate_x][coordinate_y] != 0)) {
		ball[coordinate_x][coordinate_y] += 10;
		ball[coordinate_x + 1][coordinate_y] += 10;
		count_judge++;
		judge_only_neighbor(ball, col, row, (char)(x + 1), y);
	}
	if (((ball[coordinate_x][coordinate_y] % 10) == (ball[coordinate_x][coordinate_y - 1] % 10)) && (ball[coordinate_x][coordinate_y - 1] < 10) && (ball[coordinate_x][coordinate_y] != 0)) {
		ball[coordinate_x][coordinate_y] += 10;
		ball[coordinate_x][coordinate_y - 1] += 10;
		count_judge++;
		judge_only_neighbor(ball, col, row, x, (char)(y - 1));
	}
	if (((ball[coordinate_x][coordinate_y] % 10) == (ball[coordinate_x][coordinate_y + 1] % 10)) && (ball[coordinate_x][coordinate_y + 1] < 10) && (ball[coordinate_x][coordinate_y] != 0)) {
		ball[coordinate_x][coordinate_y] += 10;
		ball[coordinate_x][coordinate_y + 1] += 10;
		count_judge++;
		judge_only_neighbor(ball, col, row, x, (char)(y + 1));
	}
	return count_judge;
}
void show_zero_star(int ball[][12], int row, int col) {           //生成只含0和*的数组
	cout << "查找结果数组：" << endl;
	int copy_ball[12][12] = { 0 };
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (ball[i][j] > 10)
				copy_ball[i][j] = 2;
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
		for (int j = 1; j <= col; j++) {
			if (copy_ball[i + 1][j] == 0)
				cout << "  " << copy_ball[i + 1][j] % 10;
			else
				cout << "  " << "*";
		}
		cout << endl;
	}
	cct_setcolor(0, 7);
	cct_gotoxy(0, y + row + 2);
	return;
}
int clear_over_num(int ball[][12], int row, int col, int num) {            //将数组中大于num的全清零   并返回大于num的数量
	int count = 0;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (ball[i][j] > 10) {
				ball[i][j] = 0;
				count++;
			}
	return count;
}
void arrange_base_inorder(int ball[][12], int row, int col) {               //数组下落
	for(int j=1;j<=col;j++)
		for(int k=1;k<row;k++)
			for(int i=(row-1);i>=1;i--)
				if (!ball[i + 1][j]) {
					int t;
					t = ball[i][j];
					ball[i][j] = ball[i + 1][j];
					ball[i + 1][j] = t;
				}
	for (int j = 1; j <= col; j++) {
		int sum = 0;
		for (int i = 1; i <= row; i++)
			sum += ball[i][j];
		if(sum==0)
			for (int i = 1; i <= row; i++) {
				int t;
				t = ball[i][j];
				ball[i][j] = ball[i][j + 1];
				ball[i][j + 1] = t;
			}
	}
	return;
}
void clear_and_fall(int ball[][12], int row, int col, int* score) {                     //清除相同项矩阵和下落后矩阵的合集
	int count;
	count = clear_over_num(ball, row, col, 10);
	cout << "相同值归并后的数组（不同颜色标识）" << endl;
	create_base_balls(row, col, ball, 10);
	*score += (count * count * 5);
	cout << "本次得分：" << (count * count * 5) << "  总得分：" << *score << endl;
	cout << "按回车进行数组下落操作";
	while (1) {
		int enter_x, enter_y;
		cct_getxy(enter_x, enter_y);
		char choose_enter;
		choose_enter = _getche();
		cout << endl;
		if (choose_enter == 13) {
			cout << "下落后的数组：" << endl;
			arrange_base_inorder(ball, row, col);
			create_base_balls(row, col, ball, 10);
			break;
		}
		else
			cct_showch(enter_x, enter_y, ' ');
	}
}
bool if_this_is_end(int ball[][12], int row, int col) {
	int sum = 0;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (ball[i][j])
				sum += judge_only_neighbor(ball, col, row, (char)('A' + i - 1), (char)('1' + j - 1));
	return (sum == 0);
}
void choose_enter() {
	while (1) {
		int enter_x, enter_y;
		cct_getxy(enter_x, enter_y);
		char choose_enter;
		choose_enter = _getche();
		cout << endl;
		if (choose_enter == 13)
			break;
		else
			cct_showch(enter_x, enter_y, ' ');
	}
}
void reverse_over_num(int ball[][12], int row, int col, int num) {                        //大于num的数都%10
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (ball[i][j] > num)
				ball[i][j] = ball[i][j] % 10;
	return;
}
int print_mouse_coordinate(int ball[][12], int row, int col, int* record_row, int* record_col, int plus, int* white_row, int* white_col, int choice, int* count) {               //除下落外的鼠标和键盘的操作都在这
	cct_enable_mouse();
	int MX = 0, MY = 0, MAction, keycode1, keycode2;
	int black_row, black_col;
	bool over_10 = if_there_over_num(ball, row, col, 10);                                                        //保证两次点击才能确定的过程
	if (!ball[*white_row][*white_col])
		create_one_piece(15, start_graph_x + *white_col * (6 + plus * 2) - 4 - plus * 2, start_graph_y + *white_row * (3 + plus) - 2 - plus, 15);
	else
		create_one_piece(ball[*white_row][*white_col] % 10, start_graph_x + *white_col * (6 + plus * 2) - 4 - plus * 2, start_graph_y + *white_row * (3 + plus) - 2 - plus, 7);
	cct_setcursor(CURSOR_INVISIBLE);
	while (1) {
		int event = cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
		if (event == CCT_MOUSE_EVENT) {
			cct_gotoxy(start_graph_x, start_graph_y + row * (plus + 3) + 2);
			bool boarder = (MX >= (start_graph_x + 2) && MX < (start_graph_x + col * (6 + plus * 2) + 2) && MY >= (start_graph_y + 1) && MY < (start_graph_y + row * (3 + plus) + 1));
			bool not_a_barrier = ((MX - start_graph_x - 2) % 8 != 6) && ((MX - start_graph_x - 2) % 8 != 7) && ((MY - start_graph_y - 1) % 3 != 4);
			if ((boarder && plus && not_a_barrier) || (!plus && boarder)) {
				if (choice && MAction == MOUSE_RIGHT_BUTTON_CLICK) {
					return 1;
					break;
				}
				black_row = *white_row;
				black_col = *white_col;
				*white_row = (MY - start_graph_y + 2 + plus) / (3 + plus);
				*white_col = (MX - start_graph_x + 4 + plus * 2) / (6 + plus * 2);
				if (over_10 && (*record_row != *white_row || *record_col != *white_col)) {                                     //如果移开目标位置，则将原先反显位置消除
					clear_graph_over_num(ball, row, col, 10, plus);
					clear_to_num(ball, row, col);                                                        //大于10的变为小于10
					*record_row = 0;
					*record_col = 0;
					return 0;
					break;
				}
				if (MAction == MOUSE_LEFT_BUTTON_CLICK) {		//按下左键
					if (over_10 && *record_row == *white_row && *record_col == *white_col) {               //消除和下落操作放一个函数
						*count = clear_over_num(ball, row, col, 10);                                                //大于10的变为0
					}
					*record_row = *white_row;
					*record_col = *white_col;
					cct_setcursor(CURSOR_VISIBLE_NORMAL);
					return 0;
					break;
				}
				if ((*white_row == black_row) && (*white_col == black_col))
					continue;
				cout << "当前鼠标  " << (char)('A' + *white_row - 1) << "行" << *white_col << "列                                 ";
				if (!ball[black_row][black_col])
					create_one_piece(15, start_graph_x + black_col * (6 + plus * 2) - 4 - plus * 2, start_graph_y + black_row * (3 + plus) - 2 - plus, 15);
				else
					create_one_piece(ball[black_row][black_col] % 10, start_graph_x + black_col * (6 + plus * 2) - 4 - plus * 2, start_graph_y + black_row * (3 + plus) - 2 - plus, 0);
				if (!ball[*white_row][*white_col])
					create_one_piece(15, start_graph_x + *white_col * (6 + plus * 2) - 4 - plus * 2, start_graph_y + *white_row * (3 + plus) - 2 - plus, 15);
				else
					create_one_piece(ball[*white_row][*white_col] % 10, start_graph_x + *white_col * (6 + plus * 2) - 4 - plus * 2, start_graph_y + *white_row * (3 + plus) - 2 - plus, 7);
			}
			else
				cout << "当前鼠标  非法                                            ";
		}
		else if (event == CCT_KEYBOARD_EVENT) {
			cct_gotoxy(start_graph_x, start_graph_y + row * (plus + 3) + 2);
			cout << "当前键盘  ";
			int current_x, current_y;
			cct_getxy(current_x, current_y);
			black_row = *white_row;
			black_col = *white_col;
			if (!ball[black_row][black_col])
				create_one_piece(15, start_graph_x + black_col * (6 + plus * 2) - 4 - plus * 2, start_graph_y + black_row * (3 + plus) - 2 - plus, 15);
			else
				create_one_piece(ball[black_row][black_col] % 10, start_graph_x + *white_col * (6 + plus * 2) - 4 - plus * 2, start_graph_y + *white_row * (3 + plus) - 2 - plus, 0);
			if (over_10 && (*record_row != *white_row || *record_col != *white_col)) {                                     //如果移开目标位置，则将原先反显位置消除
				clear_graph_over_num(ball, row, col, 10, plus);
				clear_to_num(ball, row, col);                                                        //大于10的变为小于10
				*record_row = 0;
				*record_col = 0;
				return 0;
				break;
			}
			if (keycode1 == 224) {
				switch (keycode2) {
				case KB_ARROW_UP:
					if (*white_row != 1)
						(*white_row)--;
					else
						*white_row = row;
					cct_gotoxy(current_x, current_y);
					cout << (char)('A' + *white_row - 1) << "行" << *white_col << "列";
					break;
				case KB_ARROW_DOWN:
					if (*white_row != row)
						(*white_row)++;
					else
						*white_row = 1;
					cct_gotoxy(current_x, current_y);
					cout << (char)('A' + *white_row - 1) << "行" << *white_col << "列";
					break;
				case KB_ARROW_LEFT:
					if (*white_col != 1)
						(*white_col)--;
					else
						*white_col = col;
					cct_gotoxy(current_x, current_y);
					cout << (char)('A' + *white_row - 1) << "行" << *white_col << "列";
					break;
				case KB_ARROW_RIGHT:
					if (*white_col != col)
						(*white_col)++;
					else
						*white_col = 1;
					cct_gotoxy(current_x, current_y);
					cout << (char)('A' + *white_row - 1) << "行" << *white_col << "列";
					break;
				}
				if (!ball[*white_row][*white_col])
					create_one_piece(15, start_graph_x + *white_col * (6 + plus * 2) - 4 - plus * 2, start_graph_y + *white_row * (3 + plus) - 2 - plus, 15);
				else
					create_one_piece(ball[*white_row][*white_col] % 10, start_graph_x + *white_col * (6 + plus * 2) - 4 - plus * 2, start_graph_y + *white_row * (3 + plus) - 2 - plus, 7);
			}
			if (keycode1 == 13 || keycode2 == 13) {
				if (over_10 && *record_row == *white_row && *record_col == *white_col) {               //消除和下落操作放一个函数
					*count = clear_over_num(ball, row, col, 10);                                                //大于10的变为0
				}
				*record_row = *white_row;
				*record_col = *white_col;
				cct_setcursor(CURSOR_VISIBLE_NORMAL);
				return 0;
				break;
			}
			if (choice && (keycode1 == (int)('q') || keycode2 == (int)('Q'))) {
				return 1;
				break;
			}
		}
	}
	return 0;
}
bool if_there_over_num(int ball[][12], int row, int col, int num) {
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (ball[i][j] > num)
				return true;
	return false;
}
void clear_graph_over_num(int ball[][12], int row, int col, int num, int plus) {
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (ball[i][j] > num) 
				create_one_piece(ball[i][j] % 10, start_graph_x + j * (6 + plus * 2) - 4 - plus * 2, start_graph_y + i * (3 + plus) - 2 - plus, 0);
	return;
}
int if_there_none(int ball[][12], int row, int col) {
	int sum = 0;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (ball[i][j] == 0)
				sum++;
	return sum;
}
void clear_to_num(int ball[][12], int row, int col) {
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (ball[i][j] > 10)
				ball[i][j] = ball[i][j] % 10;
	return;
}
void disappear_fall(int ball[][12], int row, int col, int plus) {
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			if (ball[i][j] == 0) {
				create_one_piece(15, start_graph_x + j * (6 + plus * 2) - 4 - plus * 2, start_graph_y + i * (3 + plus) - 2 - plus, 15);
				Sleep(5);
			}
	if (!plus)
		enter_to_fall(row, plus);
	for (int j = 1; j <= col; j++)
		for (int k = 1; k < row; k++)
			for (int i = (row - 1); i >= 1; i--)
				if (!ball[i + 1][j] && ball[i][j]) {
					down(ball, i, j, plus);
					int t;
					t = ball[i][j];
					ball[i][j] = ball[i + 1][j];
					ball[i + 1][j] = t;
				}
	for (int j = 1; j <= col; j++) {
		int sum = 0, sum2 = 0;
		for (int i = 1; i <= row; i++)
			sum += ball[i][j];
		for (int i = 1; i <= row; i++)
			sum2 += ball[i][j + 1];
		if (!sum&&sum2)
			for (int i = 1; i <= row; i++) {
				left(ball, i, j + 1, plus);
				int t;
				t = ball[i][j];
				ball[i][j] = ball[i][j + 1];
				ball[i][j + 1] = t;
			}
	}
	return;
}
void enter_to_fall(int row, int plus) {
	cct_gotoxy(start_graph_x, start_graph_y + row * (plus + 3) + 2);
	cout << "合成完成，按回车键或单击左键下落" << endl;
	cct_setcursor(CURSOR_INVISIBLE);
	cct_enable_mouse();
	int MX = 0, MY = 0, MAction, keycode1, keycode2;
	while (1) {
		int event = cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
		if (event == CCT_MOUSE_EVENT)
			if (MAction == MOUSE_LEFT_BUTTON_CLICK)
				break;
		if (event == CCT_KEYBOARD_EVENT)
			if (keycode1 == 13 || keycode2 == 13)
				break;
	}
	return;
}
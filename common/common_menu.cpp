/* 2351577 大数据 张宸浩 */
#include<iostream>
#include<conio.h>
#include<cstring>
#include"../include/cmd_console_tools.h"
#include"../90-01-b2/90-01-b2-magic_ball.h"
using namespace std;
char menu(const char* sentence[], const char* choice, int num_of_sentence) {
	unsigned int length_of_sentence = 0;
	for (int i = 0; i < num_of_sentence; i++)
		length_of_sentence = (strlen(sentence[i]) > length_of_sentence ? strlen(sentence[i]) : length_of_sentence);
	for (unsigned int i = 0; i < length_of_sentence; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < num_of_sentence; i++)
		cout << sentence[i] << endl;
	for (unsigned int i = 0; i < length_of_sentence; i++)
		cout << "-";
	cout << endl;
	cout << "[请选择:] ";
	char ch;
	while (1) {
		int count = 0;
		ch = _getche();
		for (unsigned int i = 0; i < strlen(choice); i++)
			if (choice[i] == ch)
				count++;
		if (count)
			return ch;
		else {
			int X, Y;
			cct_getxy(X, Y);
			cct_showch(X - 1, Y, ' ');
			cct_gotoxy(X - 1, Y);
		}

	}
}
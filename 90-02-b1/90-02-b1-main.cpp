/* 2351577 大数据 张宸浩 */
#include <iostream>
#include "../include/cmd_console_tools.h"
#include"../include/include_menu.h"
#include"90-02-b1-star.h"
using namespace std;
int main()
{
	while (1) {
		char choice;
		const char* sentence[] = { "A.命令行找出可消除项并标识" ,"B.命令行完成一次消除（分步骤显示）" ,"C.命令行完成一关（分步骤显示）" ,"D.伪图形界面下用鼠标选择一个色块（无分隔线）" ,
		"E.伪图形界面下用鼠标选择一个色块（有分隔线）" ,"F.伪图形界面完成一次消除（分步骤）" ,"G.伪图形界面完整版" ,"Q.退出" };
		char choice_1[] = "abcdefgqABCDEFGQ";
		choice = menu(sentence, choice_1, 8);
		if ((choice == 'q') || (choice == 'Q')) {
			return 0;
			break;
		}
		if ((choice == 'a') || (choice == 'A'))
			star_game12(1);
		if ((choice == 'b') || (choice == 'B'))
			star_game12(2);
		if ((choice == 'c') || (choice == 'C'))
			star_game3();
		if ((choice == 'd') || (choice == 'D'))
			star_game45(4);
		if ((choice == 'e') || (choice == 'E'))
			star_game45(5);
		if ((choice == 'f') || (choice == 'F'))
			star_game6(4);
		if ((choice == 'g') || (choice == 'G'))
			star_game7(5);
	}
	return 0;
}

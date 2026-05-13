/* 2351577 大数据 张宸浩 */
#include<iostream>
#include"90-01-b2-magic_ball.h"
#include"../include/include_menu.h"
using namespace std;
int main() {
	while (1) {
		char choice;
		const char* sentence[] = { " 1.内部数组，生成初始状态，寻找是否有初始可消除项" ," 2.内部数组，消除初始可消除项后非0项下落并用0填充" ," 3.内部数组，消除初始可消除项后查找消除提示" ,
		" 4.n*n的框架(无分隔线)，显示初始状态" ," 5.n*n的框架(有分隔线)，显示初始状态" ," 6.n*n的框架(无分隔线)，显示初始状态及初始可消除项" ," 7.n*n的框架(有分隔线)，消除初始可消除项后显示消除提示" ,
		" 8.cmd图形界面完整版(有分隔线，鼠标移动时显示坐标，右键退出)" ," 9.cmd图形界面完整版(尚未完成，会尽快补发)" ," 0.退出" };
		char choice_1[] = "0123456789";
		choice = menu(sentence, choice_1, 10);
		if (choice == '0') {
			return 0;
			break;
		}
		if (choice == '1')
			game1();
		if (choice == '2')
			game23(2);
		if (choice == '3')
			game23(3);
		if (choice == '4')
			game45(4);
		if (choice == '5')
			game45(5);
		if (choice == '6')
			game6();
		if (choice == '7')
			game7();
		if (choice == '8')
			game89(1);
		if (choice == '9')
			game89(2);
	}
	return 0;
}

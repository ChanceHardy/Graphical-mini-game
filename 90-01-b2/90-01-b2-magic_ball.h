/* 2351577 大数据 张宸浩 */
#pragma once
void game1();
void input_row(int* row);
void input_col(int* col);
void print_end();
void game23(int n);
int judge(int sum, int row, int col, int ball[][12]);
void judge_change(int row, int col, int ball[][12]);
void game45(int n);
void create_graph_balls(int row, int col, int ball[][12], int n);
void game6();
void game7();
void eraser(int row, int col, int ball[][12]);
void fill_graph(int row, int col, int ball[][12]);
void game89(int n);
int printMouseCoordinates(int row, int col, int ball[][12], int* record_i, int* record_j);
int end_of_game(int row, int col, int ball[][12]);
void choose_the_ball(int row, int col, int ball[][12]);
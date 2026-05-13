#pragma once
#define color_num 5
void star_game12(int n_choice);
void input_row(int* row);
void input_col(int* col);
void input_coordinate(char coordinate[], int col, int row, int ball[][12]);
bool judge_only_neighbor(int ball[][12], int col, int row, char x, char y);
int clear_over_num(int ball[][12], int row, int col, int num);
void show_zero_star(int ball[][12], int row, int col);
void arrange_base_inorder(int ball[][12], int row, int col);
void clear_and_fall(int ball[][12], int row, int col, int* score);
void star_game3();
bool if_this_is_end(int ball[][12], int row, int col);
void choose_enter();
void reverse_over_num(int ball[][12], int row, int col, int num);
void star_game45(int n);
int print_mouse_coordinate(int ball[][12], int row, int col, int* record_row, int* record_col, int plus, int* white_row, int* white_col, int choice, int* count);
void star_game6(int n);
bool if_there_over_num(int ball[][12], int row, int col, int num);
void clear_graph_over_num(int ball[][12], int row, int col, int num, int plus);
int if_there_none(int ball[][12], int row, int col);
void clear_to_num(int ball[][12], int row, int col);
void disappear_fall(int ball[][12], int row, int col, int plus);
void enter_to_fall(int row, int plus);
void star_game7(int n);
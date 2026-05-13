#pragma once
#define start_graph_x 4
#define start_graph_y 2
void create_base_balls(int row, int col, int ball[][12], int num);
void print_end();
void create_outside(int row, int col);
void create_one_piece(int back_color, int start_x, int start_y, int fron_color);
void create_outside_plus(int row, int col);
void down(int ball[][12], int graph_row, int graph_col, int plus);
void left(int ball[][12], int graph_row, int graph_col, int plus);
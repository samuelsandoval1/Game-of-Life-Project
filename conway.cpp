//Samuel Sandoval Section 17
#include <chrono>
#include <ctime>
#include <curses.h>
#include <chrono>
#include <ctime>
#include <curses.h>
#include <iostream>
#include <stdlib.h>
#include <thread>
using namespace std;

const int ROWS = 48;
const int COLUMNS = 160;
const char ALIVE = '*';
const char DEAD = ' ';


void InitializeCurses() {
  initscr();
  cbreak();
  noecho();
  clear();
}

void PrintExitInstructions() {
  mvaddstr(ROWS + 1, 0, "Press ctrl+c to quit ");
  refresh();
}

void PrintRow(string row_to_print, int row) {
  mvaddstr(row, 0, row_to_print.c_str());
  refresh();
  int neighbors = 0;


  // Optional: Use the following line to create a short delay between each
  // tick if you want to watch your population grow/shrink more slowly:
  // this_thread::sleep_for(chrono::milliseconds(1));
}

void set_world(int current_gen[ROWS][COLUMNS]){
  for(int row = 0; row < ROWS; row++){
    for(int col = 0; col < COLUMNS; col++){
      current_gen[row][col] = 0;
    }
  }
}
void init_glider(int current_gen[ROWS][COLUMNS]){
  current_gen[23][80] = 1;
  current_gen[24][81] = 1;
  for(int col = 79; col < 82; col++) {
    current_gen[25][col] = 1;
  }
}
void build_world(int current_gen[ROWS][COLUMNS]){
  for(int row = 0; row < ROWS; row++) {
    string row_string;
    for(int col = 0; col < ROWS; col++) {
      if(current_gen[row][col] == 0) {
        row_string+= DEAD;
      }
      else{
        row_string +=ALIVE;
      }
    }
  PrintRow(row_string, row);
  }
}

int col_neigh(int board[ROWS][COLUMNS], int row, int column){
  int neighbor_total;
  if(board[row][column+1] == 1) {
    neighbor_total += 1;
  }
  if(board[row][column-1] == 1){
    neighbor_total += 1;
  }
  return neighbor_total;
}

int row_neigh(int board[ROWS][COLUMNS], int row, int column){
  int neighbor_total;
  if(board[row+1][column] == 1) {
    neighbor_total += 1;
  }
  if(board[row-1][column] == 1){
    neighbor_total += 1;
  }
  return neighbor_total;
}
int diag_neigh(int board[ROWS][COLUMNS], int row, int column){
  int neighbor_total;
  if(board[row-1][column-1] == 1) {
    neighbor_total += 1;
  }
  if(board[row+1][column-1] == 1) {
    neighbor_total += 1;
  }
  if(board[row-1][column+1] == 1) {
    neighbor_total += 1;
  }
  if(board[row+1][column+1] == 1) {
    neighbor_total += 1;
  }
  return neighbor_total;
}
void Determine_Cell_Status(int board[ROWS][COLUMNS], int neighbor_total, int row, int column) {
  if(neighbor_total < 2) {
    board[row][column] = 0;
  }
  else if(neighbor_total > 3) {
    board[row][column] = 0;
  }
  else if(neighbor_total == 3) {
    board[row][column] = 1;
  }
}

void check_neighbors(int read_board[ROWS][COLUMNS], int write[ROWS][COLUMNS]) {
  for(int row = 0; row < ROWS; row++){
    for(int col = 0; col < COLUMNS; col++){
      int neighbor_total = 0;
        neighbor_total += col_neigh(read_board, row, col);
        neighbor_total += row_neigh(read_board, row, col);
        neighbor_total += diag_neigh(read_board, row, col);
        Determine_Cell_Status(read_board, neighbor_total, row, col);
    }
  }
}

void copy_world(int read_board[ROWS][COLUMNS], int write[ROWS][COLUMNS]) {
  for(int row = 0; row < ROWS; row++) {
    for(int col = 0; col < COLUMNS; col++) {
      write[row][col] = read_board[row][col];
    }
  }
}





int main(int argc, char* argv[]) {
  InitializeCurses();
  PrintExitInstructions();
  int current_gen[ROWS][COLUMNS];
  int next_gen[ROWS][COLUMNS];

  set_world(current_gen);
  init_glider(current_gen);

  // TODO: Implement Conway's Game of Life.
  while (true) {
    build_world(current_gen);
    copy_world(current_gen, next_gen);
    check_neighbors(current_gen, next_gen);
    copy_world(current_gen, next_gen);
  }

  endwin();
  return 0;
}

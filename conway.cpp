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


int main(int argc, char* argv[]) {
  InitializeCurses();
  PrintExitInstructions();
  char current_gen[ROWS][COLUMNS];
  char next_gen[ROWS][COLUMNS];

  // TODO: Implement Conway's Game of Life.
  while (true) {
    // PrintRow(row_print, rows);
  }

  endwin();
  return 0;
}

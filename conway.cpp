#include <chrono>
#include <ctime>
#include <curses.h>
#include <iostream>
#include <stdlib.h>
#include <thread>
using namespace std;

const int ROWS = 48;
const int COLUMNS = 160;


void InitializeCurses() {
  // Initialize curses to control where to output to the terminal. No need to
  // modify this function, but make sure it is called in main at the beginning.
  initscr();
  cbreak();
  noecho();
  clear();
}


void PrintExitInstructions() {
  // Prints instructions near the bottom of the screen for how to exit. No need
  // to modify this function.
  mvaddstr(ROWS + 1, 0, "Press ctrl+c to quit ");
  refresh();
}


void PrintRow(string row_to_print, int row) {
  mvaddstr(row, 0, row_to_print.c_str());
  refresh();

  // Optional: Use the following line to create a short delay between each
  // tick if you want to watch your population grow/shrink more slowly:
  // this_thread::sleep_for(chrono::milliseconds(1));
}


int main(int argc, char* argv[]) {
  InitializeCurses();
  PrintExitInstructions();

  // TODO: Implement Conway's Game of Life.
  while (true) {
    
  }

  endwin();
  return 0;
}

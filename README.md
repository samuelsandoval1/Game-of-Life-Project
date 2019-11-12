# Project 3 - Conway's Game of Life
<b>Due Date: Monday December 2, 2019, 11:59pm</b>

The universe of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) is an infinite, two-dimensional orthogonal grid of cells, each of which is in one of two possible states: alive or dead. Every cell interacts with its eight neighbors, which are the cells that are horizontally, vertically, or diagonally adjacent (upper left, top, upper right, right, lower right, bottom, bottom left, left). At each step in time, the following transitions occur:
* Any live cell with fewer than two live neighbors dies due to under-population.
* Any live cell with two or three live neighbors lives on to the next generation (no change).
* Any live cell with more than three live neighbors dies due to overpopulation.
* Any dead cell with exactly three live neighbors becomes a live cell by reproduction.

The initial pattern constitutes the seed if the system (starts it off). The first generation is created by applying the above rules simultaneously to every cell in the seed; births and deaths occur simultaneously, and the discrete moment at which this happens is called a "tick". Each generation is a pure function of the preceding one, and the rules continue to be applied repeatedly to create further generations.

## Objective
This project will involve <i>substantial</i> coding. Think 10x harder than the hardest lab you've done so far. <b>Start early, get lost early, get help early</b> or you'll be miserable all of Thanksgiving weekend and still have nothing to show for it at the end. I'm really not kidding. Start, like, right now.

* To gain a deep understanding of how to get and set values in 2-D arrays.
* To gain a deep understanding of iterating over arrays using `for` and nested `for` loops.
* To gain a deep understanding of creating and calling functions from `main` that pass a variety of parameters, including statically-allocated 2D arrays.
* To practice recognizing repeated code and breaking down code into functions
* Practice using `string` building/concatenation
* To gain skills in ad-hoc code development, testing, and debugging techniques

## Instructions
Create your own version of Conway's Game of Life that runs in the terminal, according to the rules in the description. An example executable `demo_conway` has been provided for you. To run, maximize your terminal window and run `./demo_conway`. Press `ctrl+c` to make it stop.

Criteria
* Your program can run in some default mode just by typing `./` and the name of your program, or even just `./a.out` or `./conway` or whatever program name of your choosing.
* You may use any fixed-size universe that can fit on a computer screen. For example, the terminal commonly defaults to 24 rows and 80 columns. The example executable provided runs with 48 rows and 160 columns.
* Your code supports a round world where cells that go off the edge come back on the other side. For example, the left edge wraps around back to the right edge and vice versa, and the top edge wraps around to the bottom edge and vice versa.
* Your code creates an initial state of the universe that exhibits some kind of growth/death over many ticks/generations for an initial shape of your choosing. The [wikipedia article](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) provides several examples of starting configurations that make cool shapes. I recommend using one that is described to grow infinitely or lives on for many generations, such as one of the spaceships.
  * <b>Extra Credit</b> Add support for at least 1 additional starting shape and/or a random configuration, specifiable in the terminal:
    * `./conway random`
    * `./conway spaceship`
    * `./conway glider`
    * etc.
    * Demo your code to your instructor with the default and additional starting shape for the extra credit point.
* Your code differentiates clearly between a "dead" cell, such as a space `' '`, and a "live" cell, such as `'*'`.
* Your code should run infinitely (e.g. `while (true) {...}`), but can be terminated by using `ctrl+c`. You don't need to code anything special to make `ctrl+c` work, as you've observed when debugging your previous labs that ran into infinite loops.

### Compiling your code
```
$ g++ conway.cpp
/usr/bin/ld: /tmp/ccRHspaQ.o: in function `InitializeCurses()':
conway.cpp:(.text+0x5): undefined reference to `initscr'
/usr/bin/ld: conway.cpp:(.text+0xa): undefined reference to `cbreak'
/usr/bin/ld: conway.cpp:(.text+0xf): undefined reference to `noecho'
/usr/bin/ld: conway.cpp:(.text+0x14): undefined reference to `clear'
collect2: error: ld returned 1 exit status
```
BWAH? In order to be able to print anything to the terminal, `conway.cpp` imports a special header called `curses.h`. Compiling with `g++ conway.cpp` will not work! Instead, use `-lncurses` in your command to `g++`, for example:
```
$ g++ conway.cpp -lncurses -o game_of_life
```

### Printing the "world"
`#include <curses.h>` provides you with all sorts of goodies that let you print to any row/column in the terminal. In the interest of performance and making the universe look like its updating all at once instead of character by character, parse your world/universe row by row, and print 1 row at a time. A function to print a `string` to any row (0 being the upper most row) has been provided for you in `PrintRow(int row, string row_to_print)`. You will need to specify row and what the `string` version of that row looks like.

For example, if your current 2D array representing world/universe, assuming `0` means dead and `1` means alive, looks like:
```
0100110011
1001010110
0001010001
```
You would need to read it row by row and translate your representation into
```
0100110011 -> " *  **  **"
1001010110 -> "*  * * ** "
0001010001 -> "   * *   *"
```
And make a call to the `PrintRow` function provided for you for each of those rows, specifying which row in the terminal to print that row to (remember, the top-most row is 0) so that after 1 tick/cycle your terminal displays as:
```
 *  **  **
*  * * **
   * *   *
```

## Grading
Submissions that is missing a name and/or lab section, or does not compile cannot be graded, and will receive a score of 0.

* (1 point): Your code uses a 2D array to represent the world.
* (1 point): Your world wraps around correctly: The top edge connects to the bottom and vice versa, the left edge connects to the right edge and vice versa.
* (4 points): Your code correctly calculates the next generation based on the current generation according to the rules specified, using a function outside of `main`
* (1 point): Your code prints generation after generation the alive/dead states of each cell in your world
* (1 point): Your code makes use of multiple functions to break down the various pieces necessary to get the project working, aside from the ones provided in the starter code.
* (1 point): Your code utilizes multiple non-trivial commits in Github. A non-trivial commit can be something such as:
  * Add a new function, such as determining what the universe/world looks like in the next tick/cycle, or a way to print the world.
  * Fixes a bug, such as detecting and repairing an off-by-1 error or incorrectly calculating the number of alive neighbors
  * Refactors (reorganizes) existing code, such as uses moving a large chunk of code into a function, or adjusting the input parameters to a function
  * Basically, just `git commit` and `git push` each time you have a small piece working that you're happy with.
* (1 point): Your code runs and calculates/displays new generations indefinitely, until `ctrl + c`
* (1 point extra credit): Your program supports various starting states, specifiable in the commandline via `argv`. In order to earn the extra credit point, demo your code to your instructor.


## Hints:
### I'm pretty sure I'm reading each cell's neighbors correctly, why isn't it displaying the right way?
Trying to both determine and set each cell in your world's alive or dead state in the same loop while operating on the same 2D array can lead to problems: If you look at a cell, determine if it should be alive or dead, set it as such, then move on to the next cell (which is likely a neighbor), the neighboring cell would be checking its previous neighbor incorrectly (the previous cell has been updated prematurely). One way to solve this is to use a <i>second</i> 2D array: use one 2D array represents the present state of the world that gets read from only, and the second 2D array that gets written to only. After the first 2D array is fully processed and the second 2D array is fully written to, the second array will contain the correct state of the next tick.

### How do I convert my 2D array into `string` to print them?
Use a `for` loop to build your `string`, character by character. Remember from lab 3, you had to build a single `string` variable using concatenation. You can do something similar. Below are examples of `string` concatenation if you need a refresher:
```
string a = "";   // Start off as an empty string with no characters.
a = a + "hello"; // Concatenate whatever is currently in a with "hello" and set it back to a.
a += " ";        // Shorthand concatenation using += instead of a = a + " " to append a space to the end of a.
a += " world!";  // Append " world" to a as well.
cout << a << endl;

> hello world!
```

In your case, you may consider using a `for` loop and using either `+= "*"` or `+= " "` depending if a cell in that row is alive or dead. After the row has been processed, whatever is left in your string builder has that row's `string` representation. Conceptually this is similar to `CalculateTotal` from Lab-09, where you added each value into a running sum/total.

### I'm completely lost and nothing works and my dog ate my github and life is terrible right now
You can do this! Try your best, but don't spend forever (e.g. more than a couple hours) being stuck with no leads. In the work place, this will happen almost daily. Your instructor is your teammate! Ask for help, but most importantly, ask early. If you're failing, fail loudly, fail harder, fail differently. By trying different things and failing at them differently each time, you will learn quickly, but also acknowledge what you tried that didn't work so when you ask for help you can exmplain it clearly unblock yourself.

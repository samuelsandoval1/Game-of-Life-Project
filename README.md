# Conway's Game of Life

The universe of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) is an infinite, two-dimensional orthogonal grid of cells, each of which is in one of two possible states: alive or dead. Every cell interacts with its eight neighbors, which are the cells that are horizontally, vertically, or diagonally adjacent (upper left, top, upper right, right, lower right, bottom, bottom left, left). At each step in time, the following transitions occur:
* Any live cell with fewer than two live neighbors dies due to under-population.
* Any live cell with two or three live neighbors lives on to the next generation (no change).
* Any live cell with more than three live neighbors dies due to overpopulation.
* Any dead cell with exactly three live neighbors becomes a live cell by reproduction.

The initial pattern constitutes the seed if the system (starts it off). The first generation is created by applying the above rules simultaneously to every cell in the seed; births and deaths occur simultaneously, and the discrete moment at which this happens is called a "tick". Each generation is a pure function of the preceding one, and the rules continue to be applied repeatedly to create further generations.

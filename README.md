# jane-street-puzzle-202501

This repository is to solve Jane Street's puzzle (2025/01).

## Versions

### dfs.c

Solving with a DFS-based brute force algorithm.  Since {0,2,5} are fixed showing numbers, we can enumerate {1,3,4,6,7,8,9} as the skip number.

Btw, I can't get any results after 12hours running.

* `-d 1`: Show matrix during specific iterating position.  Requires `-v` to be enabled.
* `-v`: Verbose.

### dfs-optimize1.c

Still solving with the previous DFS-based brute force algorithm, but add some optimization to bypass unnecessary recursive calls.

It runs ~6mins on my Intel 8300T.  Benchmark can be obtained from [dfs-optimize1.txt](https://github.com/gslin/jane-street-puzzle-202501/blob/main/dfs-optimize1.txt).

* `-d 1`: Show matrix during specific iterating position.  Requires `-v` to be enabled.
* `-v`: Verbose.

## Links

* https://www.janestreet.com/puzzles/somewhat-square-sudoku-index/

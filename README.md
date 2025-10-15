# How to Run the Exercises Source Code

Each exercise is implemented in separate source files (.c) and header files (.h), located in `./Core/Src/` and `./Core/Inc/` directories respectively.

If you clone this project to your local device, you only need to modify the `RUN_EXERCISE` macro in `./Core/Src/main.c` to specify which exercise you want to execute (choose from exercises 1 to 10).

```c
#define RUN_EXERCISE 10

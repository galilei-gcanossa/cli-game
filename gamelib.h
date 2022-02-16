#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys\timeb.h> 

typedef struct input {
  char keyPressed;
} GameInput;

long getTime();
GameInput* getInput();
void game(void (*initFn)(), void (*loopFn)(GameInput*), long frameRate);
#include "gamelib.h"

void game(void (*initFn)(), void (*loopFn)(GameInput*), long frameRate){

  if(initFn != NULL)
    (*initFn)();

  long currentFrameTime = 0;
  for(;;){

    GameInput* input = getInput();
    long tickTime = getTime() / (1000 / frameRate);
    if(input!=NULL || currentFrameTime < tickTime){
      clearScreen();
      (*loopFn)(input);
      currentFrameTime = tickTime;
    }
    if(input!=NULL)
      free(input);
  }
}

long getTime(){  
  struct timeb start;
  ftime(&start);
  return start.time*1000+start.millitm;
}

GameInput* getInput(){
  if(kbhit()){
    GameInput* result = (GameInput*)malloc(sizeof(GameInput));
    result->keyPressed = getch();

    return result;
  }

  return NULL;
}

void clearScreen() {
  if(system("cls") == -1)
    system("clear");
}
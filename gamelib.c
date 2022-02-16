#include "gamelib.h"

void game(void (*initFn)(), void (*loopFn)(GameInput*), long frameRate){

  if(initFn != NULL)
    (*initFn)();

  long currentFrameTime = 0;
  for(;;){
    system("clear");

    GameInput* input = getInput();
    long tickTime = getTime() / (1000 / frameRate);
    if(input!=NULL || currentFrameTime < tickTime){
      (*loopFn)(input);
      currentFrameTime = tickTime;
    }
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
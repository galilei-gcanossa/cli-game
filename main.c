#include "gamelib.h"

void loop(GameInput*);
void init();

int main(int argc, char** argv){

  int frameRate = argc == 2 ? atoi(argv[1]) : 30;

  game(init, loop, frameRate);

  return 0;
}

void init(){

}

void loop(GameInput* input){

  printf("ciao %c\n", input == NULL ? '\0' : input->keyPressed);
}
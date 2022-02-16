#include "gamelib.h"

void loop(GameInput*);
void init();

int main(){

  game(init, loop, 30);

  return 0;
}

void init(){

}

void loop(GameInput* input){

  printf("ciao %c\n", input == NULL ? '\0' : input->keyPressed);
}
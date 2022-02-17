#include "gamelib.h"

void loop(GameInput*);
void init();

int main(int argc, char** argv){

  int frameRate = argc == 2 ? atoi(argv[1]) : 30;

  game(init, loop, frameRate);

  return 0;
}

void fillWorld(char* world, int width, int height, char fillChar);
void printWorld(char* world, int width, int height);

void init(){

}

void loop(GameInput* input){

  int width=50;
  int height=10;
  char* world = (char*)malloc(sizeof(char)*width*height);

  fillWorld(world, width, height, 'a');
  printWorld(world, width, height);

  free(world);
}

void fillWorld(char* world, int width, int height, char fillChar){
  for(int y=0;y<height;y++){
    for(int x=0;x<width;x++){
      *(world + x + y*width) = fillChar;
    }
  }
}

void printWorld(char* world, int width, int height){
  for(int y=0;y<height;y++){
    for(int x=0;x<width;x++){
      printf("%c", *(world + x + y*width));
    }
    printf("\n");
  }
}
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
void drawShip(char* world, int width, int height, int x, int y);

void init(){

}

void loop(GameInput* input){

  static int shipX = 0;
  static int shipY = 0;

  int width=50;
  int height=10;
  char* world = (char*)malloc(sizeof(char)*width*height);

  fillWorld(world, width, height, ' ');
  if(input!=NULL){
    if(input->keyPressed=='d' && shipX < width)
      shipX++;
      
    if(input->keyPressed=='a' && shipX > 0)
      shipX--;

    if(input->keyPressed=='s' && shipY < height)
      shipY++;
      
    if(input->keyPressed=='w' && shipY > 0)
      shipY--;
  }
  drawShip(world, width, height, shipX, shipY);
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

void drawShip(char* world, int width, int height, int x, int y){
  x = x < 0 ? 0 : x;
  x = x >= width - 1 ? width - 1 : x;
  y = y < 0 ? 0 : y;
  y = y >= height - 1 ? height - 1 : y;

  *(world + (x + 0) + (y + 0)*width) = 'V';
  *(world + (x + 0) + (y + 1)*width) = 'V';
  *(world + (x + 1) + (y + 1)*width) = 'V';
}
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
void drawString(char* world, int width, int height, int x, int y, char* string);
void drawMenu(char* world, int width, int height, int x, int y, int selected);

void init(){

}

void loop(GameInput* input){

  static int screen = 0; //0 menu, 1 game 
  static int selectedMenu = 0;
  static int shipX = 0;
  static int shipY = 0;

  int width=50;
  int height=10;
  char* world = (char*)malloc(sizeof(char)*width*height);

  if(screen == 0){
    fillWorld(world, width, height, ' ');
    if(input!=NULL){
      if(input->keyPressed=='s')
        selectedMenu = (selectedMenu+1)%2;
        
      if(input->keyPressed=='w')
        selectedMenu = (selectedMenu-1)%2;
        
      if(input->keyPressed=='\n' || input->keyPressed=='\r'){
        if(selectedMenu == 0)
          screen = 1;

        if(selectedMenu == 1){
          exit(0);
        }
      }
    }
    drawMenu(world, width, height, 0, 0, selectedMenu);

    printWorld(world, width, height);
  }
  else {
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
  }

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

void drawString(char* world, int width, int height, int x, int y, char* s){
  for(int i=0; s[i]!='\0';i++)
    *(world + (x + i) + y*width) = s[i];
}

void drawMenu(char* world, int width, int height, int x, int y, int selected){
  drawString(world, width, height, x+10, y+3, "START");
  drawString(world, width, height, x+10, y+5, "EXIT");

  if(selected == 0){
    drawString(world, width, height, x+8, y+3, "*");
  }
  else {
    drawString(world, width, height, x+8, y+5, "*");
  }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h> 

void add_turtle(int* turtles, int turtle[9], bool* animation_mode, char* anim_grid) {
  if (*turtles < 3) {
    turtle[*turtles * 3 + 0] = 0;
    turtle[*turtles * 3 + 1] = 0;
    turtle[*turtles * 3 + 2] = 1;
    (*turtles)++;
    if (*animation_mode) {
      anim_grid[0] = 'z';
    }
  }
}

void turn_turtle(int* turtles, int *turtle, int direction){
  for(int i = 0; i < *turtles; i++){
    turtle[i * 3 + 2] = (turtle[i * 3 + 2] + direction + 4) % 4;
  }
}

void move_turtle(int* turtles, int *turtle, int* rows, int* cols, char* grid, bool* animation_mode, char* anim_grid){
  for(int i = 0; i < *turtles; i++){
    if(anim_grid[(turtle[i * 3 + 0] * (*cols)) + turtle[i * 3 + 1]] == 'z' && *animation_mode){
      anim_grid[(turtle[i * 3 + 0] * (*cols)) + turtle[i * 3 + 1]] = ' ';
    }
    if(turtle[i * 3 + 2] == 0) { 
      if (turtle[i * 3 + 0] > 0) {
        if (grid[((turtle[i * 3 + 0] - 1) * (*cols)) + turtle[i * 3 + 1]] != '#') {
          turtle[i * 3 + 0] -= 1;
        }
      } else {
        if (grid[((*rows - 1) * (*cols)) + turtle[i * 3 + 1]] != '#') {
          turtle[i * 3 + 0] = *rows - 1; 
        }
      }
    }
    else if(turtle[i * 3 + 2] == 1) { 
      if (turtle[i * 3 + 1] < *cols - 1) {
        if (grid[(turtle[i * 3 + 0] * (*cols)) + turtle[i * 3 + 1] + 1] != '#') {
          turtle[i * 3 + 1] += 1;
        }
      } else {
        if (grid[(turtle[i * 3 + 0] * (*cols)) + 0] != '#') {
          turtle[i * 3 + 1] = 0;
        }
      }
    }
    else if(turtle[i * 3 + 2] == 2) { 
      if (turtle[i * 3 + 0] < *rows - 1) {
        if (grid[((turtle[i * 3 + 0] + 1) * (*cols)) + turtle[i * 3 + 1]] != '#') {
          turtle[i * 3 + 0] += 1;
        }
      } else {
        if (grid[(0 * (*cols)) + turtle[i * 3 + 1]] != '#') {
          turtle[i * 3 + 0] = 0;
        }
      }
    }
    else if(turtle[i * 3 + 2] == 3) {   
      if (turtle[i * 3 + 1] > 0) {
        if (grid[(turtle[i * 3 + 0] * (*cols)) + turtle[i * 3 + 1] - 1] != '#') {
          turtle[i * 3 + 1] -= 1;
        }
      } else {
        if (grid[(turtle[i * 3 + 0] * (*cols)) + (*cols - 1)] != '#') {
          turtle[i * 3 + 1] = *cols - 1;
        }
      }
    }
    if(*animation_mode){
      anim_grid[(turtle[i * 3 + 0] * (*cols)) + turtle[i * 3 + 1]] = 'z';
    }
  }
}

void paint_turtle(int* turtles, int *turtle, char* grid, int *rows, int *cols){
  for(int i = 0; i < *turtles; i++){
    if(grid[(turtle[i * 3 + 0] * (*cols)) + turtle[i * 3 + 1]] == 'o'){
      grid[(turtle[i * 3 + 0] * (*cols)) + turtle[i * 3 + 1]] = '.';
    }else{
      grid[(turtle[i * 3 + 0] * (*cols)) + turtle[i * 3 + 1]] = 'o';
    }
  }
}

void random_obstacles(int rows, int cols, char* grid) {
  int timer = (int) time(NULL);
  srand(timer);
  int count = rand() % (rows * cols / 4);
  for (int i = 0; i < count; ) {
    int r = rand() % rows;
    int c = rand() % cols;
    if (grid[r * cols + c] == '.') {
      grid[r * cols + c] = '#';
      i++;
    }
  }
}

void display_grid(int rows, int cols, char* grid, char* anim_grid, bool animation_mode) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if(anim_grid[i * cols + j] == 'z' && animation_mode == true){
        printf("z");
      } else {
        printf("%c", grid[i * cols + j]);
      }
    }
    printf("\n");
  }
}

void fill_grid_animation(int rows, int cols, char* grid, char* anim_grid) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      grid[i * cols + j] = ' ';
      anim_grid[i * cols + j] = ' ';
    }
  }
  anim_grid[0] = 'z';
}

void show_animation(int *rows, int *cols, char* grid, char* anim_grid, bool animation_mode) {
  printf("\x1b[2J\x1b[H");
  usleep(400000);
  display_grid(*rows, *cols, grid, anim_grid, animation_mode);
}

int main() {
  int rows = 0, cols = 0, turtles = 0;
  bool animation_mode = false;
  //odkomentovat pre animaciuuu 
  //bool animation_mode = true;
  char c;
  scanf("%d %d", &rows, &cols);
  char* grid = (char*) malloc(rows * cols * sizeof(char));
  int turtle[9] = {0};
  turtle[2] = 1;
  char* anim_grid = (char*) malloc(rows * cols * sizeof(char));
  
  if(animation_mode) {
    fill_grid_animation(rows, cols, grid, anim_grid);
  } else {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        grid[i * cols + j] = '.';
        anim_grid[i * cols + j] = '.';
      }
    }
  }
  add_turtle(&turtles, turtle, &animation_mode, anim_grid);
  // random prekazky na mriezke
  // random_obstacles(rows, cols, grid);
  while(scanf("%c", &c) == 1) {
    if(c == 'x') {
      break;
    }
    else if(c == 'r'){
      turn_turtle(&turtles, turtle, 1);
    }
    else if(c == 'l'){
      turn_turtle(&turtles, turtle, -1);
    }
    else if(c == 'm'){
      move_turtle(&turtles, turtle, &rows, &cols, grid, &animation_mode, anim_grid);
      if(animation_mode){
        show_animation(&rows, &cols, grid, anim_grid, animation_mode);
      }
    }
    else if(c == 'o'){
      paint_turtle(&turtles, turtle, grid, &rows, &cols);
      if(animation_mode){
        show_animation(&rows, &cols, grid, anim_grid, animation_mode);
      }
    }
    else if(c == 'f'){
      if(turtles < 3){ 
        add_turtle(&turtles, turtle, &animation_mode, anim_grid); 
        if(animation_mode){
          show_animation(&rows, &cols, grid, anim_grid, animation_mode);
        }
      }
    }
  }
  if(animation_mode){
    show_animation(&rows, &cols, grid, anim_grid, animation_mode);
  }
  animation_mode = false;
  display_grid(rows, cols, grid, anim_grid, animation_mode);
  free(grid);
  free(anim_grid);
  
  return 0;
}
#include "drawing.h"

void line(int lenght, int color){
  for(int i = 0; i < lenght; i++){
    if(color == 1){
      set_red_color();
    }else if(color == 2){
      set_green_color();
    }else if(color == 3){
      set_blue_color();
    }else if(color == 4){
      set_white_color();
    }else if(color == 5){
      set_yellow_color();
    }
    draw_pixel(); 
    move_right();
    move_right();
  }
}

void vertical_line(int lenght, int color){
  for(int i = 0; i < lenght; i++){
    if(color == 1){
      set_red_color();
    }else if(color == 2){
      set_green_color();
    }else if(color == 3){
      set_blue_color();
    }else if(color == 4){
      set_white_color();
    }else if(color == 5){
      set_yellow_color();
    }
    draw_pixel();
    move_down();
  }
}

void horizontal_line(int lenght, int color){
  for(int i = 0; i < lenght; i++){
    if(color == 1){
      set_red_color();
    }else if(color == 2){
      set_green_color();
    }else if(color == 3){
      set_blue_color();
    }else if(color == 4){
      set_white_color();
    }else if(color == 5){
      set_yellow_color();
    }
    draw_pixel();
    move_right();
  }
}

void stairs(int steps, int lenght , int color){
  for(int i = 0; i < steps; i++){
    horizontal_line(lenght, color);
    vertical_line(lenght, color);
  }
}

void flower(int height, int width){
  int half_height = height / 2;
  int half_width = width / 2;
  vertical_line(height, 2);
  for(int h = 0; h < half_width; h++){
    move_left();
  }
  for(int g = 0; g < height; g++){
    move_up();
  }
  for(int i = 0; i < half_height; i++){
    for(int j = 0; j < width; j++){
      if(j == half_width && i == half_height / 2 || j == half_width - 1 && i == half_height / 2 && width % 2 == 0 || j == half_width && i == (half_height / 2) - 1 && half_height % 2 == 0){
        set_white_color();
      }else{
        set_yellow_color();
      }
      draw_pixel();
      move_right();
    }
    for(int h = 0; h < width; h++){
      move_left();
    }
    move_down();
  }
}

void flag(){
  // vykreslenie vlajky - cisto pasov
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 5; j++){
      for(int k = 0; k < 50; k++){
        if(i == 0){
          set_white_color();
        }else if(i == 1){
          set_blue_color();
        }else{
          set_red_color();
        }
        draw_pixel();
        move_right();
      }
      for(int k = 0; k < 50; k++){
        move_left();
      }
      move_down();
    }
  }
  for(int i = 0; i < 12; i++){
    move_up();
  }
  for(int i = 0; i < 7; i++){
    move_right();
  }
  //prvy riadok znaku
  set_red_color();
  for(int i = 0; i < 12; i++){
    draw_pixel();
    move_right();
  }
  move_down();
  //druhy riadok znaku
  set_white_color();
  draw_pixel();
  move_left();
  set_red_color();
  for(int i = 0; i < 5; i++){
    draw_pixel();
    move_left();
  }
  set_white_color();
  draw_pixel();
  move_left();
  draw_pixel();
  move_left();
  set_red_color();
  for(int i = 0; i < 5; i++){
    draw_pixel();
    move_left();
  }
  set_white_color();
  draw_pixel();
  move_down();
  //treti riadok znaku
  draw_pixel();
  move_right();
  set_red_color();
  for(int i = 0; i < 3; i++){
    draw_pixel();
    move_right();
  }
  set_white_color();
  for(int i = 0; i < 6; i++){
    draw_pixel();
    move_right();
  }
  set_red_color();
  for(int i = 0; i < 3; i++){
    draw_pixel();
    move_right();
  }
  set_white_color();
  draw_pixel();
  move_down();
  //stvrty riadok znaku
  draw_pixel();
  move_left();
  set_red_color();
  for(int i = 0; i < 5; i++){
    draw_pixel();
    move_left();
  }
  set_white_color();
  draw_pixel();
  move_left();
  draw_pixel();
  move_left();
  set_red_color();
  for(int i = 0; i < 5; i++){
    draw_pixel();
    move_left();
  }
  set_white_color();
  draw_pixel();
  move_down();
  //piaty riadok znaku
  draw_pixel();
  move_right();
  set_red_color();
  draw_pixel();
  move_right();
  draw_pixel();
  move_right();
  set_white_color();
  for(int i = 0; i < 8; i++){
    draw_pixel();
    move_right();
  }
  set_red_color();
  draw_pixel();
  move_right();
  draw_pixel();
  move_right();
  set_white_color();
  draw_pixel();
  move_down();
  //siesty riadok znaku
  draw_pixel();
  move_left();
  set_red_color();
  for(int i = 0; i < 5; i++){
    draw_pixel();
    move_left();
  }
  set_white_color();
  draw_pixel();
  move_left();
  draw_pixel();
  move_left();
  set_red_color();
  for(int i = 0; i < 5; i++){
    draw_pixel();
    move_left();
  }
  set_white_color();
  draw_pixel();
  move_down();
  //siedmy riadok znaku
  draw_pixel();
  move_right();
  for(int i = 0; i < 3; i++){
    move_right();
  }
  set_red_color();
  for(int i = 0; i < 2; i++){
    draw_pixel();
    move_right();
  }
  for(int i = 0; i < 2; i++){
    move_right();
  }
  for(int i = 0; i < 2; i++){
    draw_pixel();
    move_right();
  }
  for(int i = 0; i < 3; i++){
    move_right();
  }
  set_white_color();
  draw_pixel();
  move_down();
  //osmy riadok znaku
  move_left();
  draw_pixel();
  move_left();
  draw_pixel();
  set_blue_color();
  for(int i = 0; i < 9; i++){
    move_left();
    draw_pixel();
  }
  set_white_color();
  draw_pixel();
  move_left();
  draw_pixel();
  move_down();  
  //deviaty riadok znaku
  move_right();
  move_right();
  draw_pixel();
  move_right();
  draw_pixel();
  set_blue_color();
  for(int i = 0; i < 5; i++){
    move_right();
    draw_pixel();
  }
  set_white_color();
  draw_pixel();
  move_right();
  draw_pixel();
  move_down();
  //posledny riadok znaku
  move_left();
  move_left();
  set_white_color();
  for(int i = 0; i < 4; i++){
    draw_pixel();
    move_left();
  }
}

int main() {
  clear_screen();
  int drawing = 0;
  scanf("%d", &drawing);
  switch(drawing){
    case 0:
      line(5, 1);
      move_to(3,13);
      line(10, 2);
      move_to(5, 20);
      line(20, 3);
      move_to(11, 28);
      line(2, 4);
      move_to(17, 15);
      line(15, 5);
      break;
    case 1:
      stairs(2, 8, 1);  
      move_to(8,42);
      stairs(2,3,2);
      move_to(2,20);
      stairs(8,2,3);
      move_to(3,30);
      stairs(14,1,4);
      move_to(9,21);
      stairs(3,4,5);
      break;
    case 2:
      move_to(6,18);
      flower(10,4);
      move_to(5,40);
      flower(14,7);
      move_to(2,33);
      flower(8,3);
      move_to(10,6);
      flower(9,5);
      break;
    case 3:
      move_to(3,3);
      for(int i = 0; i < 2; i++){
        for(int j = 0; j < 13; j++){
          flower(7,3);
          for(int k = 0; k < 3 + 2; k++){
            move_right();
          }
          for(int k = 0; k < 7 / 2; k++){
            move_up();
          }
        }
        move_to(3 + (8 * (i + 1)), 3);
      }
      break;
    case 4:
      for(int i = 2; i < 6; i++){
        clear_screen();
        move_to(i,i);
        flag();
        animate();
      }
      for(int i = 6; i >= 2; i--){
        clear_screen();
        move_to(i,i);
        flag();
        animate();
      }
      break;
  }
  end_drawing();
  return 0;
}
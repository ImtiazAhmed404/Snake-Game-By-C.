//Snake game

   //
   //  ###########
   //  #      *  #
   //  # *   0oo #
   //  #       o #
   //  #   *   o #
   //  #         #
   //  ###########



#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

   #define WIDTH 40
   #define HEIGHT 20
   #define MAX_SNAKE_LENGTH 100
   #define INITIAL_SNAKE_LENGTH 5
   #define FOOD_COUNT 3
   #define WALL_COUNT 5
   #define EMPTY ' '
   #define SNAKE_HEAD 'O'
   #define SNAKE_BODY 'o'
   #define FOOD '*'
   #define KEY_UP 'w'
   #define KEY_DOWN 's'
   #define KEY_LEFT 'a'
   #define KEY_RIGHT 'd'
   #define KEY_PAUSE 'p'
   #define KEY_RESUME 'r'
   #define KEY_RESTART 'n'
   #define KEY_QUIT 'q'
   #define PAUSE_MESSAGE "Game Paused. Press 'r' to resume."
   #define GAME_OVER_MESSAGE "Game Over! Press 'n' to restart or 'q' to quit."
   #define SCORE_MESSAGE "Score: %d"
   #define UP 1
   #define DOWN 2
   #define LEFT 3
   #define RIGHT 4
   #define STOP 0
   #define DELAY 100 // milliseconds
   #define TRUE 1
   #define FALSE 0


   // field cols= length; rows= width (size)
   #define cols 10
   #define rows 10


   //field area similar to (length x width)
   char board [cols*rows];

   //drawing the board function
   void fill_board ()
   {
       int x,y;
       for (y=0; y<rows; y++)
       {
           for (x=0; x<cols; x++)
           {
               if (x=0 || y==0 || x==cols-1 || y== rows-1)
               {
                   board[y*cols +x]= '#';
               }
           }
       }
   }

   //printing the field function
   void print_board ()
   {
       int x,y;
       for (y=0; y<rows; y++)
       {
           for (x=0; x<cols; x++)
           {
               putch (board[y*cols +x]);
           }
           putch('\n');
       }
   }

   int snakeX = 5;
   int snakeY = 5;

   void draw_snake ()
   {
       board[snakeY*cols +snakeX]= '0';

   }

   void move_snake(int deltaX, int deltaY)
   {
       snakeX += deltaX;
       snakeY += deltaY;
   }

   void clear_screen ()
   {
      //Windows setting to clear screen garbage display
      system("cls");
   }

   //user input readings (w,a,s,d)
   void read_keyboard ()
   {
       int ch= getch();
       switch (ch)
       {
           case 'w' : move_snake (0,1); break;     //one step up in y coordinate   (0, +y)
           case 's' : move_snake (0,-1); break;   //one step down in y coordinate  (0, -y)
           case 'a' : move_snake (-1,0); break;  //one step left in x coordinate   (-x, 0)
           case 'd' : move_snake (1,0); break;  //one step right in x coordinate   (+x, 0)

       }
   }

   int main (int argc, char **argv)
   {
       fill_board();
       draw_snake ();

       print_board();


       return 0;
   }



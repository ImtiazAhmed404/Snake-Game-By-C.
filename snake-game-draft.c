//Snake game

   //
   //  ###########
   //  #      +  #
   //  # +   @** #
   //  #       * #
   //  #   +   * #
   //  #         #
   //  ###########

 #include <stdio.h>
    #include <stdlib.h>
    #include <conio.h>
    #include <time.h>

    #define cols 25
    #define rows 25
    #define foods 50

    char board[cols * rows];

    //initializing Flag isGameOver
    int isGameOver = 0;

    //game board design
     void fill_board()
     {
       int x,y;

        for(y=0; y<rows; y++)
            {
           for(x=0; x<cols; x++)
           {
            if(x==0||y==0||x==cols-1||y==rows-1)
             {
                board[y*cols + x] = '#';
            }
        else
              {
                board[y*cols + x] = ' ';
              }
        }
    }
 }

     //screen buffer remove
     void clear_screen()
      {

    system("cls");

    // system("clear");
   }

   //displaying the board
    void print_board()
     {
       int x,y;

         for(y=0; y<rows; y++)
        {
        for(x=0; x<cols; x++)
            {
            putch(board[y*cols + x]);
        }
        putch('\n');
    }
  }
         //defining snakes max length
         #define SNAKE_MAX_LEN 256

      //snake x and y variable body
      struct SnakePart
       {
         int x, y;
     };
         //inputing the snake max length value in "SnakePart" structure
         struct Snake
          {
           int length;
            struct SnakePart part[SNAKE_MAX_LEN];
         };
       //food structure
       struct Snake snake;

       struct Food
     {
      //food x and y variable
       int x, y;
      int consumed;
   };
         struct Food
         //struct of array foods from constant (foods)
         food[foods];

         //designing the snake body and head
         void draw_snake()
        {
      int i;

    for(i=snake.length-1; i>0; i--)
        {
        board[snake.part[i].y*cols + snake.part[i].x] = '*';
        }
       board[snake.part[0].y*cols + snake.part[0].x] = '@';
     }

       //snake movement X and Y coordinate
        void move_snake(int movX, int movY)
        {
           int i;

          for(i=snake.length-1; i>0; i--)
            {
               snake.part[i] = snake.part[i-1];
            }
            //moving snake body by x and y variable interchanging
              snake.part[0].x += movX;
              snake.part[0].y += movY;
         }

          //user input readings (movement)
          void read_keyboard()
         {
             int ch = getch();

            switch(ch)
        {
         case 'w': move_snake( 0,-1); break;
         case 's': move_snake( 0,1); break;
         case 'a': move_snake(-1, 0); break;
         case 'd': move_snake( 1, 0); break;
       }
     }





   int main (int argc, char **argv)
   {
       fill_board();
       draw_snake ();

       print_board();


       return 0;
   }





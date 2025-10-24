
#include"c.h"
int  sleepSecond = 800;
void intwall()
{
    for (size_t i = 0; i <= height; i++)
    {
        for (size_t j = 0; j <= wide; j++)
        {
            if (j == wide)
            {
                printf("|");
            }
            else if (i == height)
            {
                printf("_");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
void intsnake(void)
{
    snake.body[0].x = wide / 2;
    snake.body[0].y = height / 2;
    snake.body[1].x = wide / 2 - 1;
    snake.body[1].y = height / 2;
    snake.size = 2;
}

void intfood(void)
{
    food.x = rand() % wide-1;
    food.y = rand() % height;
}
 void draw(void)
{
      COORD coord = { 0 };

    for (size_t i = 0; i < snake.size; i++)
    {
        coord.X = snake.body[i].x;
        coord.Y = snake.body[i].y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        if (i == 0) {
            putchar('7');
        }
        else {
            putchar('0');
        }


    }
    coord.X = lastx;
    coord.Y = lasty;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    putchar(' ');

    
    coord.X = food.x;
    coord.Y = food.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    putchar('#');
    coord.X =0 ;
    coord.Y = height+2;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
   
}
 
 void playgame(void)
 {
     
     char key = 'd';
     while(snake.body[0].x>=0&& snake.body[0].x<wide
         && snake.body[0].y>=0&&snake.body[0].y<height)
     {
         
        
        
         
         draw();
        
         
         if (_kbhit()) {
              key = _getch();
         }

         switch (key) {
         case'w':ky = -1; kx = 0; break;
         case'a':ky = 0; kx = -1; break;
         case's':ky = 1; kx = 0; break;
         case'd':ky = 0; kx = 1; break;
         default:break;
         }
         for (int i = 1; i < snake.size; i++) 
         {   //蛇头和身体碰撞
             if (snake.body[0].x==snake.body[i].x&&snake.body[0].y==snake.body[i].y)
             {
                 return;
             }
             
             }
         if (snake.body[0].x == food.x && snake.body[0].y == food.y)
         {
             intfood();
             snake.size++;
             sleepSecond -= 10;
             

         }
         lastx = snake.body[snake.size - 1].x;
         lasty = snake.body[snake.size - 1].y;
         for (int i =snake.size-1; i >0; i--)
         {
             snake.body[i].x = snake.body[i - 1].x;
             snake.body[i].y = snake.body[i - 1].y;
         }
         snake.body[0].x += kx;
         snake.body[0].y += ky;

         

             //蛇头和食物碰撞
         Sleep(sleepSecond);
         
         }


     return;




     }


 
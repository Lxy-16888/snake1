#ifndef __SNAKE_H__
#define __SNAKE_H__
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<Windows.h>
#include<conio.h>
#define wide 40
#define height 20
  struct BODY
{
    int x;
    int y;

}body;
  struct SNAKE
{
    struct BODY body[wide * height];//蛇身，蛇头

    int size;//蛇的大小
}snake;
 struct FOOD//食物
{
    int x;
    int y;
}food;
  typedef struct COORD{
    int X;
    int Y;
}coord;
void intsnake();
void intfood(); 
 int kx;
int ky;
int lastx;
int lasty;
 
#endif
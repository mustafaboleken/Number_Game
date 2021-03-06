#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"

#define MAXINPUT 5

char number[MAXINPUT]; /* buffer for number inputs */

/* suggestions: print the valid inputs */
static void suggestions(int n)
{
  printf("Possible movements: ");
  if(n>2)
    printf("%d %d %d\n", n-1, n-2, n-3);
  else if(n==2)
    printf("%d %d\n", n-1, n-2);
  else
    printf("%d\n", n-1);
}

/* magic_num: main algorithm */
static void magic_num(int n)
{
  int user_input;
  /* k is the coefficient of 4k+1 */
  int k = (n-1)/4;
  while(1){
    suggestions(n);
    scanf("%5[0123456789]", number); /* only number input permitted */
    while(getchar() !='\n'); /* flushing the input stream */
    user_input = atoi(number);
    /* Checking the input */
    if(!(user_input==(n-1) || user_input==(n-2) || user_input==(n-3)) || user_input<0){
      printf("Invalid input!\n");
      continue;
    }
    break;
  }
  if (user_input==0) {
    printf("\n\nI win :]\n\n");
    exit(0);
  }
  /* no matter what user input we keep say next magic numbers[4k+1] within the rules */
  printf("-I say %d.\n", (k-1)*4+1);
  magic_num((k-1)*4+1);
}

/* first_move: take magic number */
static void first_move(int n)
{
  printf("-I start..\n");
  int temp = (n-1)%4;
  printf("-I say %d.\n", n-temp);
  magic_num(n-temp);
}

/* play: start the game */
void play(void)
{
  int n;
  /* ignoring the '/n' after 'p' typed */
  getchar();
  printf("#Enter the initial number:\n");
  scanf("%5[0123456789]", number); /* only number input permitted */
  while(getchar() !='\n'); /* flushing the input stream */
  n = atoi(number);
  while(n < 0){
    printf("You cannot enter negative number!\n");
    break;
    scanf("%5[0123456789]", number); /* only number input permitted */
    while(getchar() !='\n'); /* flushing the input stream */
    n = atoi(number);
  }
  /* being first for say magic number */
  if ((n-1)%4!=0)
    first_move(n);
  /* being second for say the magic number */
  else {
    printf("-You start..\n");
    magic_num(n);
  }
}

/* help: print the user manual */
void help(void)
{
  printf("-> After entering the initial number,\n");
  printf("-> sides decrease the number by 1, 2 or 3 respectively.\n");
  printf("-> The person who says ZERO lose the game.\n");
  printf(" Note: Entering negative number is forbidden!\n");
  printf("\nEnter 'p' to start.\n");
}

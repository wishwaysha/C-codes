#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char colours[12][10] = {"Black","Brown","Red","Orange","Yellow","Green","Blue","Violet","Grey","White","Gold","Silver"};
char a;   
float table[12][2];
int i = 0,v1,v2,v3,m,t,score;


int main()
{  srand(time(NULL));
   for (i = 0; i < 10; i++)
   {
      table[i][0] = i;
      table[i][1] = pow(10,i);
      //printf("%f  %f\n",table[i][0],table[i][1]);
    
   }
   
   table[10][0] = pow(10,-1);
   table[10][1] = 0.05;
   table[11][0] = pow(10,-2);
   table[11][1] = 0.1;
  // printf("%f  %f\n%f  %f\n",table[10][0],table[10][1],table[11][0],table[11][1]);
   printf("\n\n\n\n__________ Type * to START/STOP the game_________\n");
   scanf(" %c",&a);
   if( a  =='*')
   {
       while(1)
       {
           printf("its my life");
           scanf(" %c",&a);
           if( a  =='*')
           {
               printf("Score = %d \n\n GAME TERMINATED",score); 
               return 0;
           }
       }
   }
   else printf("Inavalid start sequence, game terminated\n");
   return 0;
}

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char colours[12][10] = {"Black","Brown","Red","Orange","Yellow","Green","Blue","Violet","Grey","White","Gold","Silver"};
char a;   
float table[12][2];
int i = 0,v1,v2,v3,m,t,score;
char value[12];
float res,actual_res,tolerance;

int s_i(char x[12])
{   int decimal=0;
    for (int z = 0;z<strlen(x);z++)
    {
        int r = pow(10,strlen(x) - z - 1);
        decimal+= ((int)x[z] - 48)*r;
    }
    return decimal;
}


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
   if( a  == '*')
   {   i = 0;score= 0;
       printf("Guess the value of the resistor using the colour code\nType the value in the format <value> <tolerance>\t EG. 1000 5\n");
       while(1)
       {   i++;
           printf("Question no.%d\n",i);
           v1 = rand()%10;
           v2 = rand()%10;
           v3 = rand()%10;
           m = rand()%12;
           t = (rand()%3) + 9;
           printf("t = %d\n",t);
           actual_res = ((v1*100)+(v2*10)+v3)*table[m][1];
           tolerance = table[t][1]*100.0;
           printf("table[t][1] = %f, table[t][1]*100.0= %d\n",table[t][1],table[t][1]*100.0);
           printf("%s %s %s %s %s\n",colours[v1],colours[v2],colours[v3],colours[m],colours[t]);
           printf("actual_res = %f, tolerance = %d",actual_res,tolerance);
           scanf(" %s",&value);
           if( value[0]  == '*')
           {
               printf("Score = %d \n\n GAME TERMINATED",score); 
               return 0;
           }
           else res = s_i(value);
       }
   }
   else printf("Inavalid start sequence, game terminated\n");
   return 0;
}

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char colours[12][10] = {"Black","Brown","Red","Orange","Yellow","Green","Blue","Violet","Grey","White","Gold","Silver"};
char a;   
long long int table[12][2];
int i = 0,v1,v2,v3,m,t,score,tolerance,tol;
char value[12];
unsigned long long int actual_res,res;

long long int s_i(char x[12])
{   long long int decimal=0;
    for (int z = 0;z<strlen(x);z++)
    {
        long long int r = pow(10,strlen(x) - z - 1);
        decimal+= ((int)x[z] - 48)*r;
    }
    //printf("returning decimal %lld\n",decimal);
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
   
  // table[10][0] = (float)pow(10,-1);
   table[10][1] = 5.0;
  // table[11][0] = (float)pow(10,-2);
   table[11][1] = 10.0;
  // printf("%f  %f\n%f  %f\n",table[10][0],table[10][1],table[11][0],table[11][1]);
   printf("\n\n\n\n\t\t______________ Type * to START/STOP the game_________\n");
   scanf(" %c",&a);
   if( a  == '*')
   {   i = 0;score= 0;
       printf("\t\t\tGuess the value of the resistor using the colour code\n\t\t\tType the value in the format <value> <tolerance>\n\n\t\t\tEG. 1000 5   for 1k +- 5%\n");
       while(1)
       {   i++;
           printf("\n\n\nQuestion no.%d\n",i);
           v1 = rand()%10;
           v2 = rand()%10;
           v3 = rand()%10;
           m = rand()%10;
           t = (rand()%2) + 10;
         //  printf("t = %d\n",t);
           actual_res = (long int)(((v1*100)+(v2*10)+v3)*(long long int)table[m][1]);
         //  printf ("DEBUGGING-->(v1*100)+(v2*10)+v3) = %d,  (int)table[m][1]) = %lld \n ",(v1*100)+(v2*10)+v3,table[m][1]);
           tolerance = (int)table[t][1];
         //  printf("table[t][1] = %d\n",(int)table[t][1]);
           printf("%s %s %s %s %s\n",colours[v1],colours[v2],colours[v3],colours[m],colours[t]);
         //  printf("actual_res = %lld, tolerance = %d\n",actual_res,tolerance);
           scanf(" %s",&value);
           if( value[0]  == '*')
           {
               printf("\t\tScore = %d \n\n GAME TERMINATED",score); 
               return 0;
           }
           else res = s_i(value);
           //printf("resistance is %lld\n",res);
           scanf(" %d",&tol);
           if(actual_res==res && tol == tolerance)
           {
               printf("\n________HURRRAAAYYY___________________________________________!!!!!\n");
               score++;
           }
           else
           {    
               printf ("\n\tBBBBEEEEEPPPSSS, Wrong answer\n");
               printf ("Actual answer --> RESISTANCE = %lld, TOLERANCE = %d\n",actual_res,tolerance);
               printf("\t\tScore = %d \n\n GAME TERMINATED",score); 
               return 0;
           }
       }
   }
   else printf("\tInavalid start sequence, game terminated\n");
   return 0;
}

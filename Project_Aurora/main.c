#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
# include <windows.h>


int main()
{
 int i;
 int j;
 double value = 0;
 double  Temp1 = 0;
 double  Temp2 = 0;
 double  Temp3 = 0;
 double  Temp4 = 0;
 double  Temp5 = 0;
 double  TotalTemp = 0;
 int avgCount = 0;
// scanf("%d",&value);
 double arrTemp[120];
 double arrAvgTemp[120];
 double avgTemp = 0;
 int count = 0;
 char temp[120]; // 120 bytes of memory
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 FILE* fptr;


 printf("Index\n");
 printf("Blue- Below\n");
 printf("Green- Normal\n");
 printf("Yellow - Above\n");
 printf("Red- Critical\n");
 printf("\n\n\n");
 //printf("\t");


 if ( fopen_s(&fptr, "Data_1.txt", "r") != 0) //checking if file avaliable Data_2 only has critical values  // "r" --> opens file in read mode;
 {
    printf("File No Avaliable");
 }
 else
 {
     while ((count < 120) && (fgets(temp, 120, fptr) != 0)) // fgets("varible location, character limit, location of values we are reading")

     {
         arrTemp[count] = atof(temp);

         count++;

     }

     fclose(fptr);
 }

 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// saving temp avarges to arrAVgTemp

 for (i = 5; i < count; i++)
 {
     Temp1 = arrTemp[i-4];
     Temp2 = arrTemp[i-3];
     Temp3 = arrTemp[i-2];
     Temp4 = arrTemp[i-1];
     Temp5 = arrTemp[i];

     TotalTemp = Temp1 + Temp2 + Temp3 +  Temp4+ Temp5;   // calulating and storing average Temps

     avgTemp = TotalTemp/5;

     arrAvgTemp[avgCount] = avgTemp;
     avgCount++;

 }

 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



  for (i = 0; i < avgCount; i++) // i < number of elements in array
  {
      //Sleep();
   value = (int)arrAvgTemp[i];


   if ( (value <= 70) && (value >= 0))
   {
    // colour = 11; // maybe just set the colur here already
     SetConsoleTextAttribute(hConsole, 11); // blue or cyan

   }
   else if ( (value > 70) && (value <= 105)) //
   {

       SetConsoleTextAttribute(hConsole, 10); // green
   }
   else if ( (value > 105) && (value <= 112))
   {

       SetConsoleTextAttribute(hConsole, 14); // yellow

   }
   else if (value < 0)
   {

       SetConsoleTextAttribute(hConsole, 12); // red
       // negative average temp goes is critical
   }
   else
   {
       SetConsoleTextAttribute(hConsole, 12); // red



   }
   /////////////////////////////////////////////

   for (j=0; j < (value/2); j++) // j < array value
      {
          printf("-");


      }


     printf("%.2f\n",value);
     SetConsoleTextAttribute(hConsole, 7); // white text
  }


    return 0;
}

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int main()
{
   FILE *fisier;
   char numar[100];
   fisier = fopen("ini.txt", "r");
   int nr_convert=0, suma=0;

   if (fisier == NULL) {
        perror("Eroare la deschiderea fisierului");
        return 1;
    }

   while(fgets(numar, sizeof(numar), fisier)!=NULL)
   {
       nr_convert=0;
       for(int i=0;i<strlen(numar);i++)
       {
        if(numar[i]=='0')
        {nr_convert=nr_convert*10;}
        if(numar[i]=='1')
        {nr_convert=nr_convert*10+1;}
        if(numar[i]=='2')
        {nr_convert=nr_convert*10+2;}
        if(numar[i]=='3')
        {nr_convert=nr_convert*10+3;}
        if(numar[i]=='4')
        {nr_convert=nr_convert*10+4;}
        if(numar[i]=='5')
        {nr_convert=nr_convert*10+5;}
        if(numar[i]=='6')
        {nr_convert=nr_convert*10+6;}
        if(numar[i]=='7')
        {nr_convert=nr_convert*10+7;}
        if(numar[i]=='8')
        {nr_convert=nr_convert*10+8;}
        if(numar[i]=='9')
        {nr_convert=nr_convert*10+9;}
       }
       suma=suma+nr_convert;
   }
   printf("%d", suma);
   fclose(fisier);
   return 0;
}
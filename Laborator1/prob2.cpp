#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   char cuvinte[256][256], prop[256];
   int nr=0;
   scanf("%[^\n]", &prop);
   char *p = strtok(prop, " ,.");
   while(p!=NULL)
   {
       strcpy(cuvinte[nr],p);
       nr++;
       p=strtok(NULL," ,.");
   }
   for(int i=0;i<nr-1;i++)
   {
    for(int j=i+1;j<nr;j++)
    {
        if(strlen(cuvinte[i])<strlen(cuvinte[j]))
        {
            swap(cuvinte[i], cuvinte[j]);
        }
        if(strlen(cuvinte[i])==strlen(cuvinte[j]))
        {
            if(strcmp(cuvinte[i], cuvinte[j])>0)
            {
                swap(cuvinte[i], cuvinte[j]);
            }
        }
    }
   }
   for(int i=0;i<nr; i++) 
   {
      printf("%s \n", cuvinte[i]);
   }
   return 0;
}
#include <stdio.h>
#include <string.h>
#include "library.h"

void clearBuffer(){
    int c;
    while ((c=getchar())!='\n' && c!=EOF);
}

int strInput(char* str,size_t size){
    if(fgets(str,size,stdin)==NULL) return 0;
    str[strcspn(str,"\n")] = '\0';
    return 1;
}

int intInput(int* value){
    char buffer[100],extraChr,extraStr[100];
    if (fgets(buffer,sizeof(buffer),stdin)==NULL) return 0;
    if (sscanf(buffer,"%d %c %s",value,&extraChr,extraStr)!=1) return 0;
    return 1;
}

int doubleInput(double* value){
    char buffer[100],extraChr,extraStr[100];
    if (fgets(buffer,sizeof(buffer),stdin)==NULL) return 0;
    if (sscanf(buffer,"%lf %c %s",value,&extraChr,extraStr)!=1) return 0;
    return 1;
}

void printErr(){
    printf("Invalid Input Try Again\n");
}

void comingSoon(){
    //* Will Add A Comment Saying If It's Next Commit Next To Each Feature
    printf("Coming Soon.\n");
}

// void saveData(Book* books,int*){

// }

//// void loadData(Book* books,int*){

// }
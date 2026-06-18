#include <stdio.h>

void clearBuffer(){
    int c;
    while ((c=getchar())!='\n' && c!=EOF);
}


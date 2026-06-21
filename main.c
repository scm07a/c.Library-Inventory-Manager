#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "ValidIO.h"

int main(){
    
    Book* books=(Book*)malloc(MAX_BOOKS*sizeof(*books));
    int bookCount=0;
    int isRunning=1;
    
    while(isRunning){
        int choice;
        printf("=====Library Inventory Manager=====\n");
        printf("0.Exit.\n");
        printf("1.Add Book.\n");
        printf("2.View Books.\n");
        printf("3.Search For A Book.\n");

        printf("Choice:");
        
        while(!intInput(&choice)){
            printErr();
            printf("Choice:");
        } 

        switch(choice){
            case 0:
                isRunning=0;
            case 1:
                addBook(books,&bookCount);
                break;
            case 2:
                viewAllBooks(books,bookCount);
                break;
            case 3:
                searchBook(books,bookCount);
                break;
            default:
                printErr();
                break;
        }
    }
    free(books);
    return 0;
}
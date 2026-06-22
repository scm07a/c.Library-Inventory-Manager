#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "ValidIO.h"

int main(){
    
    Book* books=(Book*)malloc(MAX_BOOKS*sizeof(*books));
    int bookCount=0;
    int isRunning=1;
    loadData(books,&bookCount);
    while(isRunning){
        int choice;
        printf("\n=====Library Inventory Manager=====\n");
        printf("0.Exit.\n");
        printf("1.Add Book.\n");
        printf("2.View Books.\n");
        printf("3.Search For A Book.\n");
        printf("4.View Deleted Books.\n");
        printf("5.Save Data.\n");
        printf("6.Reset Data\n");

        printf("Choice:");
        
        while(!intInput(&choice)){
            printErr();
            printf("Choice:");
        } 

        switch(choice){
            case 0:
                isRunning=0;
                break;
            case 1:
                addBook(books,&bookCount);
                saveData(books,bookCount);
                break;
            case 2:
                viewAllBooks(books,bookCount);
                break;
            case 3:
                if(searchBook(books,bookCount))
                    saveData(books,bookCount);
                break;
            case 4:
                viewDeletedBooks(books,bookCount);
                break;
            case 5:
                saveData(books,bookCount);
                break;
            case 6:
                resetData(books,&bookCount);
                break;

            default:
                printErr();
                break;
        }
    }
    free(books);
    return 0;
}
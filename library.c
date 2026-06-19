#include <stdio.h>
#include <stdlib.h>
#include "ValidIO.h"

#define MAX_BOOKS 100000
typedef struct{
    int id;
    char title[100];
    char author[50];
    double price;
    int avaliable;
} Book;


void addBook(Book* books, int* bookCount){
    if (*bookCount>=MAX_BOOKS){
        printf("The System Is Full.\n");
        return;
    }
    Book* b=&books[*bookCount];  
    printf("Enter Title Of The Book:");
    strInput(b->title,sizeof(b->title));

    printf("Enter Author Of The Book:");
    strInput(b->author,sizeof(b->author));

    printf("Enter Price Of The Book:");
    doubleInput(&b->price);

    b->id=*bookCount+1;
    (*bookCount)++;
    b->avaliable=1;
}

void printBook(Book* b){
    printf("Book ID: %d\n",b->id);
    printf("Title: %s\n",b->title);
    printf("Author: %s\n",b->author);
    printf("Price: %.2f\n",b->price);
    printf("Availability: %s\n",b->avaliable ? "Avaliable": "UnAvailable");
}

//TODO: Work On This Feature Next
void searchBook(Book* books, int bookChoice){
    
}
void viewAllBooks(Book* books, int bookCount){
    for (size_t i=0;i<bookCount;i++) printBook(&books[i]); 
}


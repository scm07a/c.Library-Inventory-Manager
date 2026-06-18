#include <stdio.h>
#include <stdlib.h>
#include "ValidIO.h"

#define MAX_BOOKS 100
typedef struct{
    int id;
    char title[100];
    char author[50];
    double price;
    int avaliable;
} Book;

Book books[MAX_BOOKS];
int bookCount=0;

void addBook(Book* books, int* bookCount){

    Book* b=&books[*bookCount];  
    printf("Enter Title Of The Book:");
    scanf("%[^\n]",b->title);
    clearBuffer();

    printf("Enter Author Of The Book:");
    scanf("%[^\n]",b->author);
    clearBuffer();

    printf("Enter Price Of The Book:");
    scanf("%lf",&b->price);
    clearBuffer();

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

void searchBook(Book* books, int bookChoice){
    
}
//Todo: Fix Function
void viewAllBooks(Book* books, int bookCount){
    for (int i=0;i<bookCount;i++) printBook(books); 
}
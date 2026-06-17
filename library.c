#include <stdio.h>
#include <stdlib.h>
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

    printf("Enter Author Of The Book:");
    scanf("%[^\n]",b->author);
    
    printf("Enter Price Of The Book:");
    scanf("%lf",&b->price);

    b->id=*bookCount+1;
    (*bookCount)++;
    b->avaliable=1;
    
}



void viewOneBook(Book* books, int bookChoice){
    Book* b=&books[bookChoice-1];
    printf("Title:%s\nAuthor:%s\nPrice:%.2f\nAvaliability:%s\n"
        ,b->title,b->author,b->avaliable ? "Avaliable": "UnAvailable");
}

void viewAllBooks(Book* books, int bookCount){
    for (int i=0;i<bookCount;i++){
        printf("Title:%s\nAuthor:%s\nPrice:%.2f\nAvaliability: %s\n"
        ,books[i].title,books[i].author,books[i].avaliable ? "Avaliable": "UnAvailable");
    }
}
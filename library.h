#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct{
    int id;
    char title[100];
    char author[50];
    double price;
    int avaliable;
} Book;

void addBook(Book* books, int* bookCount);
void viewOneBook(Book* books, int bookCount);
void viewBook(Book* books, int bookCount);


#endif
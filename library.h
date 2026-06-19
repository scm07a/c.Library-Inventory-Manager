#ifndef LIBRARY_H
#define LIBRARY_H
#define MAX_BOOKS 100

typedef struct{
    int id;
    char title[100];
    char author[50];
    double price;
    int avaliable;
} Book;
void addBook(Book* books, int* bookCount);
void printBook(Book* books);
void searchBook(Book* books, int bookChoice);
void viewAllBooks(Book* books, int bookCount);

#endif
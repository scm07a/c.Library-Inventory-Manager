#ifndef LIBRARY_H
#define LIBRARY_H
#define MAX_BOOKS 100

typedef struct{
    int id;
    char title[100];
    char author[50];
    double price;
    int avaliable;
    int isDeleted;
} Book;
void addBook(Book* books, int* bookCount);
void printBook(Book* books);
void searchBook(Book* books, int bookCount);
void viewAllBooks(Book* books, int bookCount);
void maxID(Book*b, int bookCount);
int binSearch(Book* books,int bookIndex,int targetID);
void bubSort(Book* books, int bookCount);
void deleteBook(Book* b);
void viewDeletedBooks(Book* books, int bookCount);

#endif
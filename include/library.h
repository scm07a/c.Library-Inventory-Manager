#ifndef LIBRARY_H
#define LIBRARY_H
#define MAX_BOOKS 100000

typedef struct{
    int id;
    char title[100];
    char author[50];
    double price;
    int available;
    int isDeleted;
} Book;

void addBook(Book* books, int* bookCount);
void printBook(Book* b);
int searchBook(Book* books, int bookCount);
void viewAllBooks(Book* books, int bookCount);
int nonDeletedSearch(Book* books,int bookIndex,int bookChoiceID);
int deletedSearch(Book* books,int bookCount,int bookChoiceID);
void deleteBook(Book* b);
void restoreBook(Book*b);
int viewDeletedBooks(Book* books, int bookCount);
void borrowBook(Book* b);
void returnBook(Book* b);
void editBook(Book* b);
#endif
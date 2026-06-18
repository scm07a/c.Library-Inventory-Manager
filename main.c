#include <stdio.h>
#include "library.h"

int main(){
    Book books[MAX_BOOKS];
    int bookCount=0;
    printf("Start Debug Mode...\n");
    addBook(books,&bookCount);
    addBook(books,&bookCount);
    viewAllBooks(books,bookCount);
    return 0;
}
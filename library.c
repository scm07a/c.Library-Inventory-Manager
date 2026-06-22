#include <stdio.h>
#include <stdlib.h>
#include "ValidIO.h"
#include "library.h"

//*Return Index Of A Book By Searching By ID
int linSearch(Book* books,int bookCount,int bookChoiceID){
    for (size_t i=0;i<bookCount;i++){
        if (books[i].id==bookChoiceID && !books[i].isDeleted) return i;
    }
    return -1;
}

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
    b->available=1;
    b->isDeleted=0;
}
void printBook(Book* b){
    printf("Book ID: %d\n",b->id);
    printf("Title: %s\n",b->title);
    printf("Author: %s\n",b->author);
    printf("Price: %.2f\n",b->price);
    printf("Availability: %s\n",b->available ? "Available": "UnAvailable");
}

void deleteBook(Book* b){
    b->isDeleted=1;
    printf("Book Deleted!\n");
}

void borrowBook(Book* b){
    b->available=0;
    printf("Status Logged UnAvailable...\n");
}

void returnBook(Book* b){
    b->available=1;
    printf("Status Logged Available....\n");
}

void editBook(Book* b){
    int choice;
    printf("1.Name.\n2.Author.\n3.Price.\n");
    printf("What Do You Want To Edit:");
    while(!intInput(&choice) || choice<=0 || choice>3){
        printErr();
        printf("What Do You Want To Edit:");
    }
    switch(choice){
        case 1:
            printf("Enter Title Of The Book:");
            strInput(b->title,sizeof(b->title));
            break;
        case 2:
            printf("Enter Author Of The Book:");
            strInput(b->author,sizeof(b->author));
            break;
        case 3:
            printf("Enter Price Of The Book:");
            doubleInput(&b->price);
            break;
        default:
            printErr();
            break;
    }

}

int searchBook(Book* books, int bookCount){
    int choice;
    int change=0;//* Flag for if any data changed
    if (bookCount==0){
        printf("There Aren't Any Books Logged Into The System!\n");
        return 0;
    }

    int bookChoiceID;
    
    printf("Search Book By ID:");
    while(!intInput(&bookChoiceID) || bookChoiceID<=0){
        printErr();
        printf("Search Book By ID:");
    }

    int bookIndex=linSearch(books,bookCount,bookChoiceID);

    if (bookIndex==-1){
        printf("Couldn't Find The Book\n");
        return 0;
    }

    printBook(&books[bookIndex]);
    printf("\n0.Return To Main Menu.\n1.Delete.\n2.%s\n3.Edit Details.\n",books[bookIndex].available ? "Borrow" : "Return");
    printf("Choice:");
    while(!intInput(&choice) || choice>3 || choice<0){
        printErr();
        printf("Choice:");
    }

    switch(choice){
        case 0:
            change=0;
            return change;
        case 1:
            deleteBook(&books[bookIndex]);
            change=1;
            break;
        case 2:
            if (books[bookIndex].available){
                borrowBook(&books[bookIndex]);
                change=1;
            }
            else{
                returnBook(&books[bookIndex]);
                change=1;
            }
            break;
        case 3:
            editBook(&books[bookIndex]);
            change=1;
            break;
        default:
            printErr();
            break;
    }
    return change;
}
void viewAllBooks(Book* books, int bookCount){
    if (bookCount==0){
        printf("There Aren't Any Books Logged Into The System!\n");
        return;
    }

    int found=0;
    for (size_t i=0;i<bookCount;i++){
        if (!books[i].isDeleted){
            printBook(&books[i]);
            printf("\n");
            found=1;
        }
    }
    if (!found)
        printf("Couldn't Find Any Books To Display\n");
}
void viewDeletedBooks(Book* books, int bookCount){
    if (bookCount==0){
        printf("There Aren't Any Books Logged Into The System!\n");
        return;
    }
    int found=0;
    for(size_t i=0;i<bookCount;i++){
        if (books[i].isDeleted){
            printBook(&books[i]);
            printf("\n");
            found=1;
        }
    }
    if(!found)
        printf("Couldn't Find Any Books To Display\n");
}

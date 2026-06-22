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
    int isDeleted;
} Book;

//* SafeGuard Incase IDs become unsorted
void bubSort(Book* books, int bookCount){
    for (size_t i=0;i<bookCount-1;i++){
        for (size_t j =0;j<bookCount-i-1;j++){
            if (books[j].id > books[j+1].id){
                Book temp=books[j];//* Swapping Whole Structs
                books[j]=books[j+1];
                books[j+1]=temp;
            }
        }
    }
}

//*Return Index Of A Book By Searching By ID
int binSearch(Book* books,int bookCount,int bookChoiceID){
    int left=0, right=bookCount-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(books[mid].id == bookChoiceID && books[mid].isDeleted == 0) return mid;
        else if (books[mid].id > bookChoiceID) right=mid-1;
        else if (books[mid].id < bookChoiceID) left= mid+1;
    }
    return -1;
}

int maxID(Book*b, int bookCount){
    int max=-999999;
    for (size_t i=0;i<bookCount;i++)
        if (b[i].id>max) max=b[i].id;
    return max;
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
    b->avaliable=1;
    b->isDeleted=0;
}
void printBook(Book* b){
    printf("Book ID: %d\n",b->id);
    printf("Title: %s\n",b->title);
    printf("Author: %s\n",b->author);
    printf("Price: %.2f\n",b->price);
    printf("Availability: %s\n",b->avaliable ? "Avaliable": "UnAvailable");
}

void deleteBook(Book* b){
    b->isDeleted=1;
    printf("Book Deleted!\n");
}

void searchBook(Book* books, int bookCount){
    int choice;
    if (bookCount==0){
        printf("There Aren't Any Books Logged Into The System!\n");
        return;
    }

    int bookChoiceID;
    int max_ID=maxID(books,bookCount);
    printf("Search Book By ID(1-%d):",max_ID);
    

    while(!intInput(&bookChoiceID) || bookChoiceID>max_ID || bookChoiceID<=0){
        printErr();
        printf("Search Book By ID(1-%d):",max_ID);
    }
    bubSort(books,bookCount);
    int bookIndex=binSearch(books,bookCount,bookChoiceID);

    if (bookIndex==-1){
        printf("Couldn't Find The Book\n");
        return;
    }
    printBook(&books[bookIndex]);
    printf("\n0.Delete.\n1.%s\n2.Edit Details.\n",books[bookIndex].avaliable ? "Borrow" : "Return"); //TODO: Borrow & Edit Option
    printf("Choice:");
    while(!intInput(&choice) || choice>2 || choice<0){
        printErr();
        printf("Choice:");
    }

    switch(choice){
        case 0:
            deleteBook(&books[bookIndex]);
            break;
        case 1:
            comingSoon();
            break;
    }
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

#ifndef VALIDIO_H
#define VALIDIO_H

void clearBuffer();
int strInput(char* str,size_t size);
int intInput(int* value);
int doubleInput(double* value);
void printErr();
void comingSoon();
void saveData(Book* books,int bookCount);
void loadData(Book* books,int* bookCount);
void resetData(Book* books,int* bookCount);
#endif
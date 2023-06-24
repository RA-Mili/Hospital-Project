#include<stdio.h>

void menu (void)
{
    printf("==> 1. Insert patient Information\n");
    printf("==> 2. Search patient Information \n");

    printf("==> 3. Exit\n");
}



void exit_program(void)
 {
    system("cls");
    printf("                ...Thank You For Using Our System...\n");
    sleep(1);
    exit(0); // Terminate the program with a status code of 0
 }


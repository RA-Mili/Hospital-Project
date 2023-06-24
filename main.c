#include <stdio.h>
#include <stdlib.h>
#include"splash.h"
#include"login.h"
#include"menu.h"
#define MAX_NAME_LENGTH 50
#define MAX_FILE_LINE_LENGTH 100

struct Patient {
    char fName[MAX_NAME_LENGTH];
    char lName[MAX_NAME_LENGTH];
    int  id,age;
    char address[MAX_NAME_LENGTH];
    char gender[MAX_NAME_LENGTH],bGroup[MAX_NAME_LENGTH],problem[MAX_NAME_LENGTH];
};



int main()
{
    recursiveLoading(0); //use of recursion
    splash();
    system("cls");
    login();
    int ch;

    while (1){  //loop for keep stay menu bar till type 3

        system("cls");
        menu();

        printf("Enter Your Choice>>\n");
        fflush(stdin);
        scanf("%d",&ch);

// Insert the patient Information
        if(ch==1){
        system("cls");
        struct Patient patient;

        printf("\n--- Insert Patient ---\n");
        printf("ID: ");
        scanf("%d", &patient.id);
        printf("First Name: ");
        scanf("%s", patient.fName);
        printf("Last Name: ");
        scanf("%s", patient.lName);
        printf("Age: ");
        scanf("%d", &patient.age);
        printf("Gender: ");
        scanf("%s", patient.gender);
        printf("Blood Group: ");
        scanf("%s", patient.bGroup);
        printf("problem: ");
        scanf("%s", patient.problem);
        printf("Address: ");
        scanf("%s", patient.address);

        FILE *file = fopen("patient_records.txt", "a");
        if (file == NULL)
        {
           printf("Failed to open patient records file. Exiting...\n");
           exit(1);
        }

        fprintf(file, "%d,%s,%s,%d,%s,%s,%s,%s\n",patient.id, patient.fName,patient.lName, patient.age, patient.gender,patient.bGroup,patient.problem, patient.address);
        printf("Patient record inserted successfully.\n");

        fclose(file);
        fflush(stdin);
        getchar();

    }


//Search and Showing patient Information
        else if(ch==2) //Showing bill
       {
         system("cls");

         int patientId;
         printf("\n--- Search Patient by ID ---\n");
         printf("Enter the ID of the patient to search: ");
         scanf("%d", &patientId);

         FILE *file = fopen("patient_records.txt", "r");
        if (file == NULL)
        {
            printf("Failed to open patient records file. Exiting...\n");
            exit(1);
        }

       char line[MAX_FILE_LINE_LENGTH];
       int found = 0;

       printf("\nSearch Results:\n");
       while (fgets(line, MAX_FILE_LINE_LENGTH, file) != NULL)
       {
        // Extract patient information from the line

        int id = atoi(strtok(line, ","));
        char *fName = strtok(NULL, ",");
        char *lName = strtok(NULL, ",");
        int age = atoi(strtok(NULL, ","));
        char *gender = strtok(NULL, ",");
        char *bGroup = strtok(NULL, ",");
        char *problem = strtok(NULL, ",");
        char *address = strtok(NULL, ",");

        // Compare patient id with search query
       if (id == patientId) {
            found = 1;
            printf("ID: %d\n", id);
            printf("Name: %s %s\n", fName,lName);
            printf("Age: %d\n", age);
            printf("Gender: %s\n", gender);
            printf("Blood Group: %s\n", bGroup);
            printf("Problem: %s\n", problem);
            printf("Address: %s\n", address);
            printf("\n\n");
            printf("\t\t\t~~~~~ patient Info ~~~~~\n\n\n");
            printf(" %-10s %-10s %-7s %-10s %-17s %-12s %-10s\n", "ID", "Name", "Age", "Gender", "Blood Group", "Problem", "Address" "");
            printf("-------------------------------------------------------------------------------------------------------\n\n");
            printf(" %-5d %-2s %-10s %-8d %-14s %-13s %-12s %-5s \n", id, fName, lName,age,gender,bGroup,problem,address);
        }
    }

       if (!found) {
           printf("Patient not found with the given name.\n");
       }

          fclose(file);
          printf("\n\n\n\n>>>>>>Enter any key to Return Main Menu>>>>>>>>\n");
          fflush(stdin);
          getchar();




    }

      else if (ch==3){
        exit_program();
         }


        else if(ch!=1||ch!=2||ch!=3){

        system("cls");
        printf("\n");
        printf("Invalid keyword\n\n");
        sleep(1);
       }
    }

    return 0;
}

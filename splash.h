#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<dos.h>


void recursiveLoading(int progress) {
    //Loading bar
    // Base case: stop recursion when progress reaches 100%
    if (progress > 100) {
        return;
    }

    // Code to be executed in each iteration
    printf("Project is Loading [%d%%]", progress);
    fflush(stdout);
    usleep(10000);
    printf("\r");

    // Recursive call to the function with an incremented progress value
    recursiveLoading(progress + 1);
}



void splash (void)
{

    system("cls");
    printf("Project Loading Complete!\n\n\n");
    sleep(1);
    //printf("-------------------Press any key to continue this project-------------\n");
    printf("Press any key to continue this project...\n");
    //getchar();
    //system("cls");

   FILE *sp;
   sp=fopen("image.txt","r");
   char img[1000];

   //reading image from text file

   while(!feof(sp))
   {
       fgets(img,sizeof(sp),sp);
       printf("%s",img);

   }
printf("\n\n\n\n");
   fclose(sp);
   printf("...............Press any key to go Login Page............\n");
   getchar();




}

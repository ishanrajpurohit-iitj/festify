#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void display_stalls() {
    system("cls");
    printf("\033[1;33m");
    FILE *file = fopen("text_files/stalls.txt","r");
    if (!file) {
        printf("Error opening file.\n");
        exit(1);
    }
    char line[100];
    printf("Stalls:\n");
    while (fgets(line, sizeof(line),file)) {
        printf("%s",line);
    }
    fclose(file);
    printf("\nPress \"Enter\" to continue.\n");
    fflush(stdin);
    getchar();
}

void book_stall() {
    system("cls");
    FILE *file = fopen("text_files/stalls.txt","r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    display_stalls();
    printf("\033[1;35m");
    fflush(stdin);
    int stall_number;
    char vendor_name[50];
    printf("Enter the stall number you want to book: ");
    scanf("%d", &stall_number);
    printf("Enter your name: ");
    fflush(stdin);
    fgets(vendor_name, sizeof(vendor_name), stdin);
    if(strlen(vendor_name)!=49){
        vendor_name[strlen(vendor_name) - 1] = '\0';
    } 

    FILE *tempFile = fopen("text_files/temp.txt", "w");
    if (tempFile==NULL) {
        printf("Error opening temp file.\n");
        fclose(file);
        return;
    }

    char str[10], status[50];
    int num,count=0;
    while (fscanf(file, "%s %d %49[^\n]\n",str,&num,status)!=EOF) {
        if (num == stall_number && strcmp(status, "unbooked")==0) {
            fprintf(tempFile,"%s %d %s\n",str,num,vendor_name);
        }
        else if (num == stall_number && strcmp(status, "unbooked")!=0) {
            fprintf(tempFile,"%s %d %s\n",str,num,status);
            count=1;
        } 
        else {
            fprintf(tempFile,"%s %d %s\n",str,num,status);
        }
    }
    if(count==1){
        printf("\033[1;31m");
        printf("\nStall is already booked. Please select another.\n\n");
    }
    else{
        printf("\033[1;32m");
        printf("\nStall has been successfully booked.\n\n");
        printf("\033[0m");
    }

    fclose(file);
    fclose(tempFile);
    remove("text_files/stalls.txt");
    rename("text_files/temp.txt","text_files/stalls.txt");
    printf("Press \"Enter\" to continue");
    fflush(stdin);
    getchar();
}
void un_book_stall(){
    system("cls");
    FILE *file = fopen("text_files/stalls.txt","r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    display_stalls();
    printf("\033[1;34m");
    fflush(stdin);
    int stall_number;
    printf("Enter the stall number you want to unbook: ");
    scanf("%d", &stall_number);
    FILE *tempFile = fopen("text_files/temp.txt", "w");
    if (tempFile==NULL) {
        printf("Error opening temp file.\n");
        fclose(file);
        return;
    }

    char str[10], status[50];
    int num,count=0;
    while (fscanf(file, "%s %d %49[^\n]\n",str,&num,status)!=EOF) {
        if (num == stall_number && strcmp(status, "unbooked")!=0) {
            fprintf(tempFile,"%s %d %s\n",str,num,"unbooked");
        }
        else if (num == stall_number && strcmp(status, "unbooked")==0) {
            fprintf(tempFile,"%s %d %s\n",str,num,status);
            count=1;
        } 
        else {
            fprintf(tempFile,"%s %d %s\n",str,num,status);
        }
    }
    if(count==1){
        printf("\033[1;31m");
        printf("\nStall is already Unbooked. Please select another stall to Unbook.\n\n");
    }
    else{
        printf("\033[1;32m");
        printf("\nStall has been successfully Unbooked.\n\n");
        printf("\033[0m");
    }

    fclose(file);
    fclose(tempFile);
    remove("text_files/stalls.txt");
    rename("text_files/temp.txt","text_files/stalls.txt");
    printf("Press \"Enter\" to continue");
    fflush(stdin);
    getchar();
}


void vendor_main() {
    while (1) {
        system("cls");
        printf("\033[0m");
        printf("\n1. Display Stalls\n");
        printf("2. Book Stall\n");
        printf("3. Un-book Stall\n");
        printf("4. Return to Main Menu\n");
        printf("\nEnter the corresponding number: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_stalls();
                break;
            case 2:
                book_stall();
                break;
            case 3:
                un_book_stall();
                break;
            case 4:
                return;
            default:
                printf("\033[1;31m");
                printf("Invalid choice. Please try again.\n");
                printf("\nPress \"Enter\" to continue.\n");
                fflush(stdin);
                getchar();
                break;

        }
    }
}

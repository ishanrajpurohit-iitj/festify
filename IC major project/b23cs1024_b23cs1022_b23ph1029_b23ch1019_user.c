#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct user{
    int id;
    char name[50];
    long long int mobile;
    char mail_id[30];
}Guest;
int random_id();
void pronite_ticket(){
    printf("\033[34m");
    Guest person; 
    FILE *fptr = fopen("text_files\\guests.txt","a");
    printf("Enter Name: ");
    fflush(stdin);
    fgets(person.name,50,stdin);
    if(strlen(person.name)!=49){
        person.name[strlen(person.name)-1] = '\0';
    }
    printf("Enter mobile: ");
    scanf("%lld",&person.mobile);
    printf("Enter Mail Id: ");
    scanf("%s",person.mail_id);
    person.id = random_id();
    fprintf(fptr,"%d,%s,%lld,%s",person.id,person.name,person.mobile,person.mail_id);
    fputc('\n',fptr);
    fclose(fptr);
    char ch;
    printf("Do you want to buy one more: \'y\' or \'no\'\nEnter choice: ");
    scanf("%c",&ch);
    if (ch=='y'){
        pronite_ticket();
    }
}
int random_id(){
    srand(time(0));
    return (rand() % 1000000) + 1;
}

void Event_Reg(){
    printf("\033[36m");
    char name[50],str[100];
    int num,flag=1;
    FILE *fptr = fopen("text_files\\guests.txt","r");
    FILE *fp = fopen("text_files\\registration.txt","a");
    printf("Enter Name: ");
    fflush(stdin);
    fgets(name,50,stdin);
    if(strlen(name)!=49){
        name[strlen(name) - 1] = '\0';
    }
    fflush(stdin);
    while(fgets(str,100,fptr)!=NULL){
        char d[] = ",";
        char *s = strtok(str,d);
        while(s!=NULL){
            if(strcmp(name,s)==0){
                flag = 0;
                int choice;
                printf("Please choose from the given commands:\n");
                printf("1. Solo Dancing.\n2. Stand-Up Comedy.\n3. Solo Singing.\n4. Mr and Mrs Ignus.\n5. Tshirt Painting.\n");
                printf("Enter the corresponding number: ");
                scanf("%d",&choice);
                switch (choice)
                {
                case 1:
                    fprintf(fp,"%s,%s",name,"Solo_Dancing");
                    fputc('\n',fp);
                    break;
                case 2:
                    fprintf(fp,"%s,%s",name,"Stand_Up_Comedy");
                    fputc('\n',fp);
                    break;
                case 3:
                    fprintf(fp,"%s,%s",name,"Solo_Singing");
                    fputc('\n',fp);
                    break;
                case 4:
                    fprintf(fp,"%s,%s",name,"Mr_and_Mrs_ignus");
                    fputc('\n',fp);
                    break;
                case 5:
                    fprintf(fp,"%s,%s",name,"Tshirt_Painting");
                    fputc('\n',fp);
                    break; 
                default:
                    printf("Invalid Input.\nPlease Enter any key to continue.");
                    getchar();
                    break;
                }
            }
            
            s = strtok(NULL,d);
        }

    }
    if(flag){
        printf("\033[1;31m\nName not in registration list.\nPls register first.\nPress \"Enter\" to continue.");
        getchar();
    }
    fclose(fptr);
    fclose(fp);
}

void user_main(){
    system("cls");
    printf("\033[1;32m");
    int choice;
    printf("Please choose from the given commands:\n");
    printf("1. Purchase Pronite Ticket.\n2. Event Registration.\n3. Return To Main Menu\n");
    printf("Enter the corresponding number: ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        pronite_ticket();
        user_main();
        break;
    case 2:
        Event_Reg();
        user_main();
        break;
    case 3:
        return; 
    default:
        printf("Invalid Input.\nPress \"Enter\" to continue.\n");
        fflush(stdin);
        getchar();
        user_main();
        break;
    }

}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include<mmsystem.h>
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

void displayWelcomeMessage()
{
    printf("=========================================\n");
    printf("Welcome to Ignus Chatbot!\n");
    printf("=========================================\n\n");
}

void playSound(const char *filename)
{
    PlaySound(filename, NULL, SND_ASYNC | SND_FILENAME);
}

void stopSound()
{
    PlaySound(NULL, NULL, 0);
}

int chatbot()
{
    fflush(stdin);
    char userInput[100];
    displayWelcomeMessage();

    while (1)
    {
        printf("You can ask for information or the event schedule.\n");
        printf("Enter your query: ");
        gets(userInput);

        stopSound(); // Stop any currently playing sound

        if (strstr(userInput, "info") != NULL || strstr(userInput, "information") != NULL)
        {
            printf("\nIGNUS, the much anticipated annual socio-cultural fest of IIT Jodhpur, is now back, after three years.\n");
            printf("Ignus celebrates art, culture, and pluralism. It provides a stage for the creative and intellectual minds from across the country to showcase their incredible talent and creativity through art and culture.\n");
            printf("For many years, the Indian Institute of Technology, Jodhpur has been a forerunner in technical education in Rajasthan. Since its inception in 2008, the institute has grown by leaps and bounds, constantly striving for excellence in academics and management.\n\n");
            playSound("ignusinfo.wav");
        }
        else if (strstr(userInput, "schedule") != NULL || strstr(userInput, "events") != NULL)
        {
            printf("\nHere's the event schedule for Ignus, the cultural fest at IIT Jodhpur:\n\n");

            printf("Day 1:\n"
                   "Morning: Registration for Mr. and Ms. Ignus starts at 9:00 AM.\n"
                   "Afternoon: Solo dance competition at 1:00 PM, singing competition at 3:00 PM.\n"
                   "Evening: T-shirt painting workshop from 5:00 PM to 7:00 PM.\n\n");

            printf("Day 2:\n"
                   "Morning: Mr. and Ms. Ignus preliminary rounds begin at 10:00 AM.\n"
                   "Afternoon: Group dance competition at 1:00 PM, instrumental music competition at 3:00 PM.\n"
                   "Evening: Cultural performances by guest artists from 5:00 PM onwards.\n\n");

            printf("Day 3:\n"
                   "Morning: Mr. and Ms. Ignus final rounds start at 10:00 AM.\n"
                   "Afternoon: Fashion show at 1:00 PM, stand-up comedy competition at 3:00 PM.\n"
                   "Evening: Award ceremony and closing ceremony at 6:00 PM, followed by a DJ night.\n");
            playSound("ignusschedule.wav");
        }
        else if (strstr(userInput, "guests") != NULL || strstr(userInput, "performers") != NULL)
        {
            printf("\nWe have an exciting lineup of guest artists and performers at Ignus this year!\n");
            printf("Stay tuned for announcements regarding the guest artists and their performances.\n\n");
            playSound("guest.wav");
        }
        else if (strstr(userInput, "workshops") != NULL || strstr(userInput, "workshop") != NULL)
        {
            printf("\nIgnus offers a variety of workshops to enhance your skills and creativity.\n");
            printf("Stay updated on our website or social media for workshop schedules and registration details.\n\n");
            playSound("workshop.wav");
        }
        else if (strstr(userInput, "tickets") != NULL || strstr(userInput, "pass") != NULL)
        {
            printf("\nYou can go to the ticket portal of this app from the user menu where you can book tickets.\n");
            playSound("tickets.wav");
        }
        else if (strstr(userInput, "register") != NULL || strstr(userInput, "participate") != NULL)
        {
            printf("\nWe welcome all the registrations and participants to be part of Ignus!\n");
            printf("You can register yourself for the events of the fest from the user menu.\n\n");
            playSound("event reg.wav");
        }
        else if (strstr(userInput, "accommodation") != NULL || strstr(userInput, "stay") != NULL)
        {
            printf("\nFor accommodation during Ignus, we have tie-ups with nearby hotels offering special rates for participants.\n");
            printf("Contact our accommodation team for booking and assistance.\n\n");
            playSound("accom.wav");
        }
        else if (strstr(userInput, "contact") != NULL || strstr(userInput, "reach") != NULL)
        {
            printf("\nYou can reach us via email at contact@ignus.co.in or call our helpline at +91-2876543210.\n");
            printf("Our team is available to assist you with any queries or information.\n\n");
            playSound("contact.wav");
        }
        else if (strstr(userInput, "sponsor") != NULL || strstr(userInput, "sponsorship") != NULL)
        {
            printf("\nIgnus offers various sponsorship opportunities for businesses and organizations.\n");
            printf("Contact our sponsorship team to explore partnership options and benefits.\n\n");
            playSound("sponsor.wav");
        }
        else if (strcmp(userInput, "exit") == 0)
        {
            break;
        }
        else if (strcmp(userInput, "stop") == 0)
        {
            stopSound();
        }
        else
        {
            printf("\nSorry, I didn't understand your query. Please try again or type 'exit' to end.\n");
        }
    }

    return 0;
}


void user_main(){
    system("cls");
    printf("\033[1;32m");
    int choice;
    printf("Please choose from the given commands:\n");
    printf("1. Purchase Pronite Ticket.\n2. Event Registration.\n3. Chat/Help\n4. Return To Main Menu\n");
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
        chatbot();
        user_main();
        break;
    case 4:
        return; 
    default:
        printf("Invalid Input.\nPress \"Enter\" to continue.\n");
        fflush(stdin);
        getchar();
        user_main();
        break;
    }

}



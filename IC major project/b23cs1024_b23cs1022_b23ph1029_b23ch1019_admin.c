#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
float initial_expense=0,budget = 1000000;
char host_name[100] = "Japneet Singh";
char fest_name[100] = "Ignus";
char customer_care[15] ="+918837856693"; 
char venue[100] = "IIT";
char start_date[100] = "19-04-2024";
char end_date[100] = "22-04-2024";
int event_count=0;

struct Sponsor {
    char company[100];
    long long int contactPerson;
    char email[50];
    float paymentAmount;
   
};

struct Expense {
    char category[50];
    float amount;
};

struct Event {
    char name[100];
    char date[20];
    char time[20];
    char performer[100];
};
 struct LHC_rooms{
    int room_no;
    bool in_use;
 };
 struct LHC_rooms rooms[10];
 int LHC_rooms[10];
int room_count =0;


struct Volunteer {
    char name[50];
    char mail_id[50];
    long long int mobile;    
    char preferredRole[100];
};
void displayVolunteers() {
    system("cls");
    printf("\033[33m");
    FILE *file = fopen("text_files/volunteers.txt","r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    char line[100];
    printf("Volunteers:\n");
    while (fgets(line, sizeof(line),file)) {
        printf("%s",line);
    }
    fclose(file);
    printf("\nPress \"Enter\" to continue.\n");
    fflush(stdin);
    getchar();
}
void registerVolunteer() {
    system("cls");
    struct Volunteer volunteer;
    printf("\033[34m"); 
    FILE *fptr = fopen("text_files\\volunteers.txt","a");
    printf("Enter Name: ");
    fflush(stdin);
    fgets(volunteer.name,50,stdin);
    if(strlen(volunteer.name)!=49){
        volunteer.name[strlen(volunteer.name)-1] = '\0';
    }
    printf("Enter mobile: ");
    scanf("%lld",&volunteer.mobile);
    printf("Enter Mail Id: ");
    scanf("%s",volunteer.mail_id);
    printf("Enter Preferred Role: ");
    scanf("%s",volunteer.preferredRole);
    fprintf(fptr,"%s,%lld,%s,%s",volunteer.name,volunteer.mobile,volunteer.mail_id,volunteer.preferredRole);
    fputc('\n',fptr);
    fclose(fptr);
}

void remaining_budget(){
 printf("Budget of the fest :%f",budget);
}

void displaySponsors() {
    system("cls");
    printf("\033[33m");
    FILE *file = fopen("text_files/sponsors.txt","r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    char line[100];
    printf("Sponsors:\n");
    while (fgets(line, sizeof(line),file)) {
        printf("%s",line);
    }
    fclose(file);
    printf("\nPress \"Enter\" to continue.\n");
    fflush(stdin);
    getchar();
}
void registerSponsor( ) {
   
    system("cls");
    struct Sponsor sponsor;
    printf("\033[34m"); 
    FILE *fptr = fopen("text_files\\sponsors.txt","a");
    printf("Enter Name: ");
    fflush(stdin);
    fgets(sponsor.company,100,stdin);
    if(strlen(sponsor.company)!=99){
        sponsor.company[strlen(sponsor.company)-1] = '\0';
    }
    printf("Enter mobile: ");
    scanf("%lld",&sponsor.contactPerson);
    printf("Enter Mail Id: ");
    scanf("%s",sponsor.email);
    printf("Enter Payment Amount: ");
    scanf("%f",&sponsor.paymentAmount);
    budget += sponsor.paymentAmount;
    fprintf(fptr,"%s,%lld,%s,%.2f",sponsor.company,sponsor.contactPerson,sponsor.email,sponsor.paymentAmount);
    fputc('\n',fptr);
    fclose(fptr);
}

void displayTickets() {
    system("cls");
    printf("\033[33m");
    FILE *file = fopen("text_files/guests.txt","r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    char line[100];
    printf("Tickets:\n");
    while (fgets(line, sizeof(line),file)) {
        printf("%s",line);
    }
    fclose(file);
    printf("\nPress \"Enter\" to continue.\n");
    fflush(stdin);
    getchar();
}


void displayparticipants(){
    system("cls");
    printf("\033[33m");
    FILE *file = fopen("text_files/registration.txt","r");
    if (!file) {
        printf("Error opening file.\n");
        getchar();
        return;
    }
    char line[100];
    printf("Tickets:\n");
    while (fgets(line, sizeof(line),file)) {
        printf("%s",line);
    }
    fclose(file);
    printf("\nPress \"Enter\" to continue.\n");
    fflush(stdin);
    getchar();
}
void display_budget() {
    system("cls");
    printf("\033[33m");
    FILE *file = fopen("text_files/BUDGET.txt","r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    char line[100];
    printf("Tickets:\n");
    while (fgets(line, sizeof(line),file)) {
        printf("%s",line);
    }
    fclose(file);
    printf("\nPress \"Enter\" to continue.\n");
    fflush(stdin);
    getchar();
}

int i=1;
void generateBudgetReport() {
    system("cls");
    printf("\033[36m");
    struct Expense expenses;
    printf("\nEnter the category of expense : ");
     fflush(stdin);
    fgets(expenses.category,100,stdin);
    if(strlen(expenses.category)!=99){
        expenses.category[strlen(expenses.category)-1] = '\0';
    }
    printf("Enter the  amount of expense :");
    scanf("%f",&expenses.amount);
    if(expenses.amount>budget){
        fflush(stdin);
        printf("Cannot spend more than BUDGET.\nPress \"Enter\" to continue.");
        getchar();
        return;
    }
    initial_expense += expenses.amount;

    system("cls");
    printf("               Budget Report               \n");
    printf("Initial Fest Budget: %f\n",budget); 
    printf("Expense Number: %d\nCategory: %s\nAmount: %f\n",i,expenses.category,expenses.amount);
    printf("Total Expenses: %f\n",initial_expense);
    printf("Remaining Budget: %f\n", budget - expenses.amount);
    fflush(stdin);
    printf("Successfully Saved.\nPress \"Enter\" to continue.");
    getchar();
    FILE *ptr;
    ptr =fopen("text_files\\BUDGET.txt","a");
    if (!ptr) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(ptr,"\n\n               Budget Report               \n");
    fprintf(ptr, "Starting Budget: %f\n",budget);
    fprintf(ptr, "Category of the expense : %s\n",expenses.category);
    fprintf(ptr ,"Amount of the expense : %f\n\n",expenses.amount);
    fprintf(ptr,"Total Expenses :%f\n",initial_expense);
    fprintf(ptr,"Remainig Budget : %f\n",budget - expenses.amount);
    fputc('\n',ptr);
    fclose(ptr);
    i++;
    budget = budget - expenses.amount;
}


void invitation(){
    system("cls");
    printf("\033[36m");
    FILE *ptr;
    ptr= fopen("invitation.txt","a");
    fprintf(ptr,"Invitation to Attend %s\n", fest_name);
    fprintf(ptr,"Venue: %s\n", venue);
    fprintf(ptr," Start Date: %s\n", start_date);
    fprintf(ptr,"End Date: %s\n" , end_date);
    fprintf(ptr,"Hosted by: %s\n", host_name);
    fprintf(ptr,"In case of any difficulty , please contact :%s\n", customer_care);
    
    fprintf(ptr,"You are cordially invited to join us for a fest of celebration and cultural activities.\n");

     fclose(ptr);
}
void display_events(){
    system("cls");
    printf("\033[36m");
    printf("          Events in The Fest          \n\n");
    FILE *fptr = fopen("text_files\\event.txt","r");
    if(fptr==NULL){
        perror("Error Opening File");
        return;
    }
    char ch=fgetc(fptr);
    while(ch!=EOF){
        printf("%c",ch);
        ch=fgetc(fptr);
    }
    fclose(fptr);
    printf("Press \"Enter\" to continue");
    fflush(stdin);
    getchar();
}
void add_events(){
    system("cls");
    printf("\033[36m");
    struct Event events;
    printf("     Enter Event Details :     ");
    printf("\nEnter name of the event : ");
    fflush(stdin);
    fgets(events.name,100,stdin);
    if(strlen(events.name)!=99){
        events.name[strlen(events.name)-1] = '\0';
    }
    printf("Enter date of the event(DD/MM/YYYY) : ");
    scanf("%s" ,events.date);
    printf("Enter the timings of the event(HH:MM:SS) : ");
    scanf("%s" ,events.time);
    printf("Enter performer of the event : " );
    fflush(stdin);
    fgets(events.performer,100,stdin);
    if(strlen(events.performer)!=99){
        events.performer[strlen(events.performer)-1] = '\0';
    }
    FILE * ptr;
    ptr= fopen("text_files\\event.txt","a");
    if(ptr==NULL){
        perror("Error Opening File");
        return;
    }
    fprintf(ptr,"%s,%s,%s,%s\n",events.name,events.date,events.time,events.performer);
    fclose(ptr);
}

void edit_events(){
    system("cls");
    display_events();
    printf("\033[36m");
    FILE *ptr = fopen("text_files\\temp.txt","w");
    FILE *fptr =fopen("text_files\\event.txt","r");
    if(fptr==NULL){
        perror("Error Opening File");
        return;
    }
    if(ptr==NULL){
        perror("Error Opening File");
        return;
    }
    char str[100];
    printf("Enter name of the event to edit :");
    fflush(stdin);
    fgets(str,100,stdin);
    if(strlen(str)!=99){
        str[strlen(str)-1] = '\0';
    }
    fflush(stdin);
    char new_event[100],new_date[20],new_time[20],new_performer[20];
    char str1[100]; 
    while(fgets(str1,150,fptr)!=NULL){
        char delim[] = ",";
        char *token = strtok(str1,delim);
            if (strcmp(token,str)==0){
                printf("Enter new event name:");
                fflush(stdin);
                fgets(new_event,100,stdin);
                if(strlen(new_event)!=99){
                    new_event[strlen(new_event)-1] = '\0';
                }
                printf("Enter new date(DD/MM/YYYY):");
                scanf("%s",new_date);
                printf("Enter new date(HH/MM/SS):");
                scanf("%s",new_time);
                fflush(stdin);
                printf("Enter new performer:");
                fgets(new_performer,100,stdin);
                if(strlen(new_performer)!=99){
                    new_performer[strlen(new_performer)-1] = '\0';
                }
                fprintf(ptr,"%s,%s,%s,%s\n",new_event,new_date,new_time,new_performer);
            }
            else{
                fprintf(ptr,"%s,%s",token,token + strlen(token)+1);
            }

    }
    fclose(fptr);fclose(ptr);
    remove("text_files\\event.txt");
    rename("text_files\\temp.txt","text_files\\event.txt");
    printf("Press \"Enter\" to continue");
    fflush(stdin);
    getchar();
}
void deleteEvent() {
    system("cls");
    display_events();
    printf("\033[36m");
    FILE *ptr = fopen("text_files\\temp.txt","w");
    FILE *fptr =fopen("text_files\\event.txt","r");
    if(fptr==NULL){
        perror("Error Opening File");
        return;
    }
    if(ptr==NULL){
        perror("Error Opening File");
        return;
    }
    printf("Enter name of the event to delete :");
    char str[100];
    fflush(stdin);
    fgets(str,100,stdin);
    if(strlen(str)!=99){
        str[strlen(str)-1] = '\0';
    }
    fflush(stdin);
    char str1[150]; 
    while(fgets(str1,150,fptr)!=NULL){
        char *delim = ",";
        char *token = strtok(str1,delim);
        // char c = "";
        if (strcmp(token,str)!=0){
            fprintf(ptr,"%s,%s",token,token +strlen(token)+1);
        }
        
    }
    fclose(fptr);fclose(ptr);
    remove("text_files\\event.txt");
    rename("text_files\\temp.txt","text_files\\event.txt");
    printf("Press \"Enter\" to continue");
    fflush(stdin);
    getchar();
    } 


void displayRooms() {
    system("cls");
    printf("\033[36m");
    printf("           Available Rooms:          \n");
    FILE *fptr = fopen("text_files\\rooms.txt","r");
    if(fptr==NULL){
        perror("Error Opening File");
        return;
    }
    char ch=fgetc(fptr);
    while(ch!=EOF){
        printf("%c",ch);
        ch=fgetc(fptr);
    }
    fclose(fptr);
    printf("Press \"Enter\" to continue");
    fflush(stdin);
    getchar();
}
void bookRoom() {
    system("cls");
    FILE *file = fopen("text_files/rooms.txt","r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    displayRooms();
    printf("\033[1;35m");
    fflush(stdin);
    int room_num;
    char event_name[50];
    printf("Enter the stall number you want to book: ");
    scanf("%d", &room_num);
    printf("Enter Event: ");
    fflush(stdin);
    fgets(event_name, sizeof(event_name), stdin);
    if(strlen(event_name)!=49){
        event_name[strlen(event_name) - 1] = '\0';
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
        if (num == room_num && strcmp(status, "unbooked")==0) {
            fprintf(tempFile,"%s %d %s\n",str,num,event_name);
        }
        else if (num == room_num && strcmp(status, "unbooked")!=0) {
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
    remove("text_files/rooms.txt");
    rename("text_files/temp.txt","text_files/rooms.txt");
    printf("Press \"Enter\" to continue");
    fflush(stdin);
    getchar();
}
void unbookRoom() {
    system("cls");
    FILE *file = fopen("text_files/rooms.txt","r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    displayRooms();
    printf("\033[1;35m");
    fflush(stdin);
    int room_num;
    char event_name[50];
    printf("Enter the stall number you want to Unbook: ");
    scanf("%d", &room_num);

    FILE *tempFile = fopen("text_files/temp.txt", "w");
    if (tempFile==NULL) {
        printf("Error opening temp file.\n");
        fclose(file);
        return;
    }

    char str[10], status[50];
    int num,count=0;
    while (fscanf(file, "%s %d %49[^\n]\n",str,&num,status)!=EOF) {
        if (num == room_num && strcmp(status, "unbooked")!=0) {
            fprintf(tempFile,"%s %d %s\n",str,num,"unbooked");
        }
        else if (num == room_num && strcmp(status, "unbooked")==0) {
            fprintf(tempFile,"%s %d %s\n",str,num,status);
            count=1;
        } 
        else {
            fprintf(tempFile,"%s %d %s\n",str,num,status);
        }
    }
    if(count==1){
        printf("\033[1;31m");
        printf("\nStall is already Un-booked. Please select another.\n\n");
    }
    else{
        printf("\033[1;32m");
        printf("\nStall has been successfully Un-booked.\n\n");
        printf("\033[0m");
    }

    fclose(file);
    fclose(tempFile);
    remove("text_files/rooms.txt");
    rename("text_files/temp.txt","text_files/rooms.txt");
    printf("Press \"Enter\" to continue");
    fflush(stdin);
    getchar();
}

int admin_main(){
    while (1) {
    system("cls");
    printf("\033[0m");
    int task = 0;   
    printf("                    Select Your Task:                     \n");
    printf("1. Register Volunteer\n");
    printf("2. Display Volunteers\n");
    printf("3. View Remaining Budget \n");
    printf("4. Register Sponsor\n");
    printf("5. Display Sponsors(On file)\n");
    printf("6. Display Tickets\n");
    printf("7. Display Participants\n");
    printf("8. Generate Budget Report\n");
    printf("9. Display Budget\n");
    printf("10. Create Invitation\n");
    printf("11. Add Event\n");
    printf("12. Edit Event\n");
    printf("13. Delete Event\n");
    printf("14. Display Events\n");
    printf("15. Display Rooms\n");
    printf("16. Book Room\n");
    printf("17. Unbook Room\n");
    printf("18. Exit\n");

    printf("\nEnter task number: ");
    scanf("%d", &task);
    switch (task) {
        case 1:
            registerVolunteer();
            break;
        case 2:
            displayVolunteers();
            break;
        case 3:
            remaining_budget();
            
            break;
        case 4:
            registerSponsor();
            
            break;
        case 5:
            displaySponsors();
        
            break;
        
        case 6:
            displayTickets();
        
            break;
        
        case 7:
            displayparticipants();
    
            break;
        case 8:
            generateBudgetReport();
            break;
        case 9:
            display_budget();
            break;
        case 10:
            invitation();
            break;
        case 11:
            add_events();
            break;
        case 12:
            edit_events();
            break;
        case 13:
            deleteEvent();
            break;
        case 14:
            display_events();
            break;
        case 15:
            displayRooms();
            break;
        case 16:
            bookRoom();
            break;
        case 17:
            unbookRoom();
            break;
        case 18:
            return 0;
        default:
            printf("Invalid task number. Please try again.\n");
            printf("Press \"Enter\" to continue");
            fflush(stdin);
            getchar();
            break;
        }
    }

    return 0;
}
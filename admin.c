#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
float budget = 10000;
float total_expenses = 0;
char host_name[100] = "Japneet Singh";
char fest_name[100] = "Ignus";
char customer_care[15] ="+918837856693"; 
char venue[100] = "IIT";
char start_date[100] = "19-04-2024";
char end_date[100] = "22-04-2024";
int event_count=0;
struct Participant {
    char name[100];
    char email[100];
    char event_name[100];
};
struct Participant participants[100];
int participants_count =0;
struct Sponsor {
    char company[100];
    char contactPerson[15];
    char email[50];
    float paymentAmount;
   
};
struct Sponsor sponsors[100];
int sponsor_count = 0;
struct Expense {
    char category[50];
    float amount;
};
struct Expense expenses[100];
int expense_count =0;
struct Event {
    char name[100];
    char date[20];
    char time[20];
    char performer[100];
};
 struct Event events[100];
 struct LHC_rooms{
    int room_no;
    bool in_use;
 };
 struct LHC_rooms rooms[10];
 int LHC_rooms[10];
int room_count =0;

struct Ticket {
    int ticketID;
    float price;
     char eventName[100];
    int quantityAvailable;
    int quantitySold;
};

struct Ticket tickets[100];
int ticket_count = 0;
struct Volunteer {
    char name[50];
    char email[50];
    char phone[15];    
    char preferredRole[100];
};
struct Volunteer volunteers[100];
int volunteer_count = 0;
void registerVolunteer() {
    char c;
    if (volunteer_count < 100) { 
        printf("      Enter volunteer details:      \n");
        printf("Name of the volunteer : ");
        fgets(volunteers[volunteer_count].name,100,stdin);
        printf("Email of the volunteer: ");
        scanf("%s", volunteers[volunteer_count].email);
        printf("Phone no of the volunteer: ");
        scanf("%s", volunteers[volunteer_count].phone);
        printf("Preferred Role : ");
         while ((c = getchar()) != '\n' && c != EOF);
        fgets(volunteers[volunteer_count].preferredRole,100,stdin);
        volunteer_count++;
        printf("Volunteer registered successfully.\n");
    } else {
        printf("Maximum number of volunteers reached.\n");
    }
}

void displayVolunteers() {
    printf("          Registered Volunteers:-          \n");
    for (int i = 0; i < volunteer_count; i++) {
        printf("Name: %s", volunteers[i].name);
        printf("Email: %s\n", volunteers[i].email);
        printf("Phone: %s\n", volunteers[i].phone);
        printf("Preferred Role: %s\n", volunteers[i].preferredRole);
        printf("\n");
    }
}

void saveVolunteersToFile() {
    FILE *file;
     file = fopen("volunteers.txt", "a");
    
    fprintf(file, "          Registered Volunteers           \n");
    for (int i = 0; i < volunteer_count; i++) {
        fprintf(file, "Name: %s", volunteers[i].name);
        fprintf(file, "Email: %s\n", volunteers[i].email);
        fprintf(file, "Phone: %s\n", volunteers[i].phone);
        fprintf(file, "Preferred Role: %s\n", volunteers[i].preferredRole);
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Volunteers Saved To file successfully\n");
}


void remaining_budget(){
 printf("Budget of the fest :%f",budget);
}

void registerSponsor( ) {
   
    if (sponsor_count < 100) { 
        printf("Enter the Company name :");
        fgets(sponsors[sponsor_count].company,100,stdin);
        printf("Enter the phone no of person in conatct :");
        fgets(sponsors[sponsor_count].contactPerson,100,stdin);
        printf("Enter the email :");
        scanf("%s",sponsors[sponsor_count].email);
        printf("Enter the amount provided :");
        scanf("%f",&sponsors[sponsor_count].paymentAmount);
        sponsor_count++;
        printf("Sponsor registered successfully\n");
    } else {
        printf("Maximum number of sponsors reached\n");
    }
}
void displaySponsors() {
  FILE *file;
  file =fopen("sponsors.txt","a");
    fprintf(file,"     The sponsors for the fest are as follows :-     ");
    for (int i = 0; i < sponsor_count; i++) {
        fprintf(file, "Company: %s", sponsors[i].company);
        fprintf(file, "Contact Person: %s\n", sponsors[i].contactPerson);
        fprintf(file, "Email: %s\n", sponsors[i].email);
        fprintf(file, "Payment Amount: %f\n", sponsors[i].paymentAmount);
        fprintf(file, "\n\n");
    }
}
void createticket(){
    char c;
    if (ticket_count < 100) { 
        printf("Enter the Ticket Id :");
        scanf("%d",&tickets[ticket_count].ticketID) ;
        printf("Enter the event name : ");
         while ((c = getchar()) != '\n' && c != EOF);
        fgets(tickets[ticket_count].eventName,100,stdin);
       printf("Enter the Price :");
       scanf("%f",&tickets[ticket_count].price);
       printf("Number Of tickets available :");
       scanf("%d",&tickets[ticket_count].quantityAvailable);
        tickets[ticket_count].quantitySold = 0;
        ticket_count++;
        printf("Ticket created successfully.\n");
    } else {
        printf("Maximum number of tickets reached.\n");
    }
}
void sellTicket(int ticketID, int quantity) {
    for (int i = 0; i < ticket_count; i++) {
        if (tickets[i].ticketID == ticketID) {
            if (tickets[i].quantityAvailable >= quantity) {
                tickets[i].quantityAvailable -= quantity;
                tickets[i].quantitySold += quantity;
                printf("%d tickets sold for '%s'.\n", quantity, tickets[i].eventName);
            } else {
                printf("Insufficient quantity of tickets available for '%s'.\n", tickets[i].eventName);
            }
            return;
        }
    }
    printf("Ticket ID %d does not exists \n", ticketID);
}
void displayTickets() {
    printf("          Available Tickets          \n");
    for (int i = 0; i < ticket_count; i++) {
        printf("Ticket ID: %d\n", tickets[i].ticketID);
        printf("Event Name: %s", tickets[i].eventName);
        printf("Price: %f\n", tickets[i].price);
        printf("Quantity Available: %d\n", tickets[i].quantityAvailable);
        printf("Quantity Sold: %d\n", tickets[i].quantitySold);
        printf("\n\n");
    }
}
void saveTicketsToFile() {
    FILE *file = fopen("tickets", "a");
        fprintf(file,"          Available Tickets          \n");
    for (int i = 0; i < ticket_count; i++) {
        fprintf(file, "Ticket Id :%d\n", tickets[i].ticketID);
        fprintf(file, "Name of the Event :%s", tickets[i].eventName);
        fprintf(file, " Price :%f\n", tickets[i].price);
        fprintf(file, " Quantity available :%d\n", tickets[i].quantityAvailable);
        fprintf(file, " Qunatity Sold: %d\n", tickets[i].quantitySold);
        fprintf(file, "\n\n"); 
    }
     fclose(file);
     printf("Tickets Saved Successfully\n");
}

void registerparticipant(){
   int i;
   char c;
    printf("Please Enter the Event name :");
    fgets(participants[participants_count].event_name,100,stdin);
     for (i = 0; i < event_count; i++) {
        if (strcmp(events[i].name, participants[participants_count].event_name) == 0) {
              break;
                }
          }

    
    if(i== event_count){
        printf("The event Entered does not exists.");
        return;
    }
      printf("Please Enter your Email Id :");
    scanf("%s", participants[participants_count].email);
      printf("Please Enter your name :");
       while ((c = getchar()) != '\n' && c != EOF);
    fgets( participants[participants_count].name,100,stdin);
      participants_count++;

}
void displayparticipants(){
    printf("       Registered  Participants       \n");
    for(int i=0;i<participants_count;i++){
        printf("Name of the participant : %s",participants[participants_count].name);
          printf("Email Id of the participant : %s\n",participants[participants_count].email);
            printf("Event chosen by the participant : %s",participants[participants_count].event_name);
              printf("\n\n");
    }
}
void saveparticipantstofile(){
    FILE *ptr;
    ptr =fopen("participants.txt","a");
    fprintf(ptr,"       Registered  Participants       \n");
     for(int i=0;i<participants_count;i++){
        
        fprintf(ptr, "Name of the participant : %s",participants[participants_count].name);
          fprintf(ptr ,"Email Id of the participant : %s\n",participants[participants_count].email);
            fprintf(ptr ,"Event chosen by the participant : %s",participants[participants_count].event_name);
            fprintf(ptr ,"\n");
    }
    fclose(ptr);
    printf("Participants Saved Successfully \n");
}
void trackExpense() {
    if (expense_count < 100) { 
        char str[100];
        printf("\nEnter the category of expense : ");
        scanf("%s",str);
        int amount;
        printf("Enter the  amount of expense :");
        scanf("%d",&amount);
        strcpy(expenses[expense_count].category,str);
        expenses[expense_count].amount = amount;
        expense_count++;
        budget = budget -amount; 
        printf("Expense tracked successfully.\n");
    } else {
        printf("No more expenses can be added.\n");
        return; 
    }
}


void generateBudgetReport() {
    printf("               Budget Report               \n");
    printf("Initial Fest Budget: %f\n",budget); 

    
    for (int i = 0; i < expense_count; i++) {
        printf("Expense -%d: Category: %s \n Amount: %f\n", i + 1, expenses[i].category, expenses[i].amount);
        total_expenses =  total_expenses + expenses[i].amount;
    }

    printf("Total Expenses: %f\n", total_expenses);
    printf("Remaining Budget: %f\n", budget - total_expenses);
    budget = budget - total_expenses;
}
void SaveBudgetToFile(){
    FILE *ptr;
    ptr =fopen("BUDGET.txt","w");
     fprintf(ptr,"               Budget Report               \n");
    for(int i=0;i<expense_count;i++){
        fprintf(ptr, "Category of the expense : %s\n",expenses[i].category);
         fprintf(ptr ,"amount of the expense : %f\n\n",expenses[i].amount);
   
    }
    fprintf(ptr,"Total Expenses :%f\n",total_expenses);
    fprintf(ptr,"Remainig Budget : %f\n",budget - total_expenses);
    fclose(ptr);
    printf("Budget Saved Successfully\n");
}

void invitation(){
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
void add_events(){
    char c;
    printf("     Enter Event Details :     ");
    printf("\nEnter name of the event : ");
   fgets(events[event_count].name,100,stdin);
    printf("Enter date of the event : ");
    scanf("%s" ,events[event_count].date);
    printf("Enter the timings of the event : ");
     scanf("%s" ,events[event_count].time);
    printf("Enter performer of the event : " );
     while ((c = getchar()) != '\n' && c != EOF);
    fgets(events[event_count].performer,100,stdin);
    event_count++;
     printf("Event added Successfully.");

}

void edit_events(){
    printf("Enter name of the event to edit :");
    char str[100];
    scanf("%s",str);
    int y=-1;
    for(int i=0;i<event_count;i++){
        if(strcmp(str,events[i].name)==0){
             y=i;
             break;
        }
    }
    if(y==-1){
        printf("No such event exists.");
        return;
    }
    char str1[100],str2[100],str3[100],str4[100];
    printf("Enter the New details : ");
    printf("\nEnter new name of the event : ");

     scanf("%s" ,str1);
     strcpy(events[y].name,str1);
    printf("Enter new date of the event : ");

     scanf("%s" ,str2);
      strcpy(events[y].date,str2);
    printf("Enter the new timings of the event : " );

     scanf("%s" ,str3);
      strcpy(events[y].time,str3);
    printf("Enter the new performer of the event : " );
     scanf("%s" ,str4);
      strcpy(events[y].performer,str4);

   printf("Event Edited Successfully");
}
void deleteEvent() {
    char str[100];
    int y=-1;
    for(int i=0;i<event_count;i++){
        if(strcmp(str,events[i].name)==0){
             y=i;
             break;
        }
    }
    if(y==-1){
        printf("No such event name.");
        return;
    }


          for (int i = y; i < event_count - 1; i++) {
            strcpy(events[i].name, events[i + 1].name);
            strcpy(events[i].date, events[i + 1].date);
            strcpy(events[i].time, events[i + 1].time);
            strcpy(events[i].performer, events[i + 1].performer);
        }

        event_count--; 
        printf("Event %s deleted successfully.\n", str);
    } 
void SaveEventsToFile(){
    FILE * ptr;
    ptr= fopen("event.txt","a");
    fprintf(ptr,"     Events in the Fest     ");
    for(int i=0;i<event_count;i++){
    fprintf(ptr,"Name of the event :%s",events[event_count].name);
    fprintf(ptr,"Date of the event :%s\n",events[event_count].date);
    fprintf(ptr,"The timings of the event :%s\n",events[event_count].time);
    fprintf(ptr,"Performer of the event :%s\n",events[event_count].performer);
     fprintf(ptr,"/n");
    }
    fclose(ptr);
    printf("Events saved Successfully.");
}

void display_events(){
  printf("          Events in The Fest          \n\n");
  for(int i=0;i<event_count;i++){
        printf("Event %d:\n", i + 1);
        printf("Name: %s", events[i].name);
        printf("Date: %s\n", events[i].date);
        printf("Time: %s\n\n", events[i].time);
        printf("Performance By: %s\n", events[i].performer);

  }
}
void initializeRooms() {
        printf("Enter the room number :");
        scanf("%d",&rooms[room_count].room_no);
        rooms[room_count].in_use = false;
         room_count++;
    
}
void displayAvailableRooms() {
    printf("           Available Rooms:          \n");
    
    for (int i = 0; i < room_count; i++) {
        if (rooms[i].in_use == false) {
            printf("Room %d \n", rooms[i].room_no);
        }
    }
}
void bookRoom() {
    int room_number;
    int y;
    printf("\nPlease enter the required Room number:");
    scanf("%d",&room_number);
    int count=0;
   for(int i=0;i<room_count;i++){
    if(rooms[i].room_no == room_number){
        y=i;
        count++;
    }
   }
   if(count>0){
    if (rooms[y].in_use == true) {
        printf("Room %d is already booked.\n", room_number);
    } else {
        rooms[y].in_use = true;
        printf("Room %d booked successfully.\n", room_number);
    }
   }else{
    printf("Please Enter A valid room number.\n");
    return;
   }
}
void unbookRoom() {
    int room_number;
    printf("\nPlease enter the Room number you want to unbook:");
    scanf("%d",&room_number);

    for (int i = 0; i < room_count; i++) {
        if (rooms[i].room_no == room_number) {
            if (rooms[i].in_use == false) {
                printf("Room %d is not booked.\n", room_number);
            } else {
                rooms[i].in_use = false;
                printf("Room %d has been unbooked.\n", room_number);
            }
            return;
        }
    }

    printf("Room %d not found.\n", room_number);
}
void saveBookingsToFile() {
    FILE *file = fopen("booking", "a");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < room_count; i++) {
        fprintf(file, "Room no : %d , Status : %d\n", rooms[i].room_no, rooms[i].in_use ? 1 : 0);
    }

    fclose(file);
    printf("Room bookings saved to %s.\n", "booking");
}
int main(){
    int y;
    int task = 0;
    int PIN=1;    
    int try =3;

    while(PIN!=1234){
        printf("Please enter the four digit PIN :- ");
        scanf("%d",&PIN);
       if(PIN!=1234){
        try--;
         printf("\nWrong PIN !!!! Please Try Again\n%d tries left\n",try);
       }
       if(try==0){
        printf("Sorry you cannot access the admin section");
        return 0;
       }
       if(PIN==1234){
        printf("\n        Welcome To Fest Management Admin Portal:-        \n");
       }
    }

    printf("                    Select Your Task:                     \n");
    printf("1. Register Volunteer\n");
    printf("2. Display Volunteers\n");
    printf("3. Save Volunteers to File\n");
    printf("4. View Remaining Budget \n");
    printf("5. Register Sponsor\n");
    printf("6. Display Sponsors(On file)\n");
    printf("7. Create Ticket\n");
    printf("8. Sell Ticket\n");
    printf("9. Display Tickets\n");
    printf("10. Save Tickets to File\n");
    printf("11. Register Participant\n");
    printf("12. Display Participants\n");
    printf("13. Save Participants to File\n");
    printf("14. Track Expense\n");
    printf("15. Generate Budget Report\n");
    printf("16. Save Budget to File\n");
    printf("17. Create Invitation\n");
    printf("18. Add Event\n");
    printf("19. Edit Event\n");
    printf("20. Delete Event\n");
    printf("21. Save Events to File\n");
    printf("22. Display Events\n");
    printf("23. Initialize Rooms\n");
    printf("24. Display Available Rooms\n");
    printf("25. Book Room\n");
    printf("26. Save Bookings to File\n");
    printf("27. Unbook Room\n");
    printf("28. Exit\n");

    while (task != 28) {
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
                saveVolunteersToFile();
                break;
            case 4:
                remaining_budget();
                break;
            case 5:
                registerSponsor();
                break;
            case 6:
                displaySponsors();
                break;
            case 7:
                createticket();
                break;
            case 8:
               
             printf("\nPlease enter the ticket ID :");
             scanf("%d",&y);
             int x;
             printf("\nEnter the quantity of tickets :");
             scanf("%d",&x);
                sellTicket(y, x);
                break;
            case 9:
                displayTickets();
                break;
            case 10:
                saveTicketsToFile();
                break;
            case 11:
                registerparticipant();
                break;
            case 12:
                displayparticipants();
                break;
            case 13:
                saveparticipantstofile();
                break;
            case 14:
                trackExpense();
                break;
            case 15:
                generateBudgetReport();
                break;
            case 16:
                SaveBudgetToFile();
                break;
            case 17:
                invitation();
                break;
            case 18:
                add_events();
                break;
            case 19:
                edit_events();
                break;
            case 20:
                deleteEvent();
                break;
            case 21:
                SaveEventsToFile();
                break;
            case 22:
                display_events();
                break;
            case 23:
                initializeRooms();
                break;
            case 24:
                displayAvailableRooms();
                break;
            case 25:
                bookRoom();
                break;
            case 26:
                saveBookingsToFile();
                break;
            case 27:
                printf("Exiting!!! Thank u for  Visiting\n");
                break;
            default:
                printf("Invalid task number. Please try again.\n");
                break;
        }
    }

    return 0;
}

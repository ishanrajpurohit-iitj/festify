#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include "b23cs1024_b23cs1022_b23ph1029_b23ch1019_user.c"
#include "b23cs1024_b23cs1022_b23ph1029_b23ch1019_vendor.c"
#include "b23cs1024_b23cs1022_b23ph1029_b23ch1019_admin.c"
// void pattern();

int main(){
    system("cls");
    // pattern();
    printf("\033[1;35m");
    int choice;
    printf("\nPlease choose from the following:\n1. To access User Portal\n2. To access Vendor Portal\n3. To access Admin Portal\n4. To exit\nPlease select the corresssponding number: ");
    scanf("%d",&choice);
    int pass;
    char admin_name[15];
    switch(choice){
        case 1:
            user_main();
            main();
            break;
        case 2:
            vendor_main();
            main();
            break;
        case 3:
            printf("Enter UserName : ");
            scanf("%s",admin_name);
            printf("Enter Password:");
            scanf("%d",&pass);
            if(pass == 1234 && strcmp(admin_name,"GoodMarks")==0){
                admin_main();
                main();
            }
            else{
                printf("\nInvalid Credentials\n");
                main();
            }
            break;
        case 4:
            return 0;
        default :
            printf("Invalid Input\nPlease press \"Enter\" to continue.");
            fflush(stdin);
            getchar();
            main();        
    }
}
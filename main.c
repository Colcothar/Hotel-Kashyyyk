/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>


//**** GLOBAL VARIABLE DECLERATION ****
int roomInt[5][9]={ {0,0,0,0,0,0,0,0,0} , {0,100,0,0,0,0,0,0,0}, {0,85,0,0,0,0,0,0,0}, {1,75,0,0,0,0,0,0,0},{1,50,4,3,1,3,1,2,0}}; 
char roomStr[5][4][100];
int loop =1, arrayCollums=0; 
int inputRm=0, r=0;

//*************************************

int roomState(array){
    if(array==0){
        return "vacant";
    }
    else{
        return "taken";
    }
}

int getIntInput(print){
    int error=0,input=1;
    while (error != 1 || input<0) {
        printf("%s", print);
        fflush(stdin);
        error = scanf("%d", &input);
        if(error!=1){
            printf("Input is not an integer! please try again.\n");
        }
        else if(input<0){
            printf("Number is negative! Please try again.\n");
        }
    }
    return input;
}

int roomSelect(){
    int error=0;
    inputRm=0;
    while (error != 1 || inputRm<0 || inputRm>4 || roomInt[inputRm][0]==1) { //forces user to choose a real vacant room
        printf("\n");
        for(int i =1; i<5; i++){
            printf("%d - Room%d costs £%d and is %s\n", i,i, roomInt[i][1], roomState(roomInt[i][0]));
        }
        printf("Please select room number: ");
        fflush(stdin);
        error = scanf("%d", &inputRm);
        //printf("%d", error);
        if(error!=1){
            printf("\nInput must be a room number. Please try again.\n");
        }
        else if(inputRm<0 || inputRm>4){
            printf("\nRoom number must be between 1 and 4. Please try again.\n");
        }
        else if(roomInt[inputRm][0]==1){
            printf("Room is not vacant. Please select a vacant room.");
        }
    }
    roomInt[inputRm][0]=1;
}

int detailFill(){
    char buffer;
    
    srand(time(NULL));   // Initialization, should only be called once.
    int r = rand()%999;      // Returns a pseudo-random integer between 0 and RAND_MAX.
    
    printf("\nEnter firstname : ");
    fflush(stdin);
    scanf("%s", roomStr[inputRm][0]);    // Read and store
    
    printf("Enter surname: ");
    fflush(stdin);
    scanf("%s",  roomStr[inputRm][1]);    // Read and store

    printf("Enter date of birth: ");
    fflush(stdin);
    scanf("%s",  roomStr[inputRm][2]);    // Read and store

    roomInt[inputRm][8] = (r+1000);
    printf("Booking ID: %s%d\n", roomStr[inputRm][1],roomInt[inputRm][8]);

    int error=0,input1=1,input2;
    while (error != 2 || input1<0 || input2<0 || (input1+input2)>4) {
        printf("Enter the number of adults and children seperated by commas (max of 4 total per room): ");
        fflush(stdin);
        error = scanf("%d,%d", &input1,&input2);
        if(error!=2){
            printf("Input is not an integer! please try again.\n");
        }
        else if(input1<0 || input2<0){
            printf("Number is negative! Please try again.\n");
        }
        else if(input1+input2>4){
            printf("There is a max of 4 people per room. Please try again.");
        }
    }
    roomInt[inputRm][2]=input1+input2;
    roomInt[inputRm][4]=input1;
    roomInt[inputRm][3]=input2;
    
    error =0;
    printf("\n****Board Types****\n1 - Full Board\n2 - Half Board\n3 - B&B\n*******************\n");
    while (error != 1 || input1<0 || input1>3) {
        printf("Enter your board type: ");
        fflush(stdin);
        error = scanf("%d", &input1);
        if(error!=1){
            printf("Input is not an integer! please try again.\n");
        }
        else if(input1<0 || input1>3 ){
            printf("Please choose a valid option.\n");
        }
        
    }
    roomInt[inputRm][7]=(input1-1);
    
    error=0;
    while (error != 1 || input1<0) {
        printf("Enter the length of your stay: ");
        fflush(stdin);
        error = scanf("%d", &input1);
        if(error!=1){
            printf("Input is not an integer! please try again.\n");
        }
        else if(input1<0 ){
            printf("Number is negative! Please try again.\n");
        }
    }
    roomInt[inputRm][5]=input1;
    
    error =0;
    printf("\n****Newspaper****\n0 - No Daily Newspaper\n1 - Daily Newspaper\n*******************\n");
    while (error != 1 || input1<0 || input1>2) {
        printf("Enter your newspaper choice: ");
        fflush(stdin);
        error = scanf("%d", &input1);
        if(error!=1){
            printf("Input is not an integer! please try again.\n");
        }
        else if(input1<0 || input1>3 ){
            printf("Please choose a valid option.\n");
        }
    }
    roomInt[inputRm][6]=input1;
    
    return 0;
}

  


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main(){
int y=0;int x=0;int i=0;
int roomInt[5][9] = { {0,0,0,0,0,0,0,0,0} , {0,100,0,0,0,0,0,0,1234}, {1,85,4,0,0,0,0,0,3451}, {0,75,0,0,0,0,0,0,0},{0,50,0,0,0,0,0,0,0}};
char roomStr[5][4][256] = {{"NULL","NULL","NULL","NULL"},
                         {"John","Smith","0102003","Smith1234"},
                         {"Joe","Blogs","01081993","Bloggs3451"},
                         {"NULL","NULL","NULL","NULL"},
                         {"NULL","NULL","NULL","NULL"}};
int LastDigits=0;
int TablesAvailable[2][5]= {{0,0,0,0},{0,0,0,0}};
int TimeIndex=0;
int ChoosenTime=0;
int Seven=0;
int Nine=0;

printf("******Booking dinner******\n");
printf("\nEnter the last four digits of your booking ID:\n");
scanf("%d", &LastDigits);

for(i=1;i<5;i++){   
    if(LastDigits == roomInt[i][8]){            /*Checks if the booking ID is assioated with a room*/
        
        if(roomInt[i][7] == 0 || roomInt[i][7] == 1){    /*Checks if the user is full or half board*/
            
            printf("Hello %s %s\n",roomStr[i][0],roomStr[i][1]);
            
            for(y=0;y<1;y++){
                for(x=0;x<3;x++){
                    if(TablesAvailable[y][x] == 0){
                        Seven++;}}}
            printf("There are %d tables available at 7\n", Seven);      /*Checks how any tables there are available*/
            
            for(y=1;y<2;y++){
                for(x=0;x<3;x++){
                    if(TablesAvailable[y][x] == 0){
                        Nine++;}}}
            printf("There are %d tables available at 9\n", Nine);
                    
            printf("\nChoose a time, 9pm or 7pm\n");
            scanf("%d", &ChoosenTime);
                if(ChoosenTime == 7){
                    TimeIndex = 0;}              /*Determines the time the guest wants to eat*/
                else if(ChoosenTime == 9){
                    TimeIndex = 1;}
                else{
                    printf("Invalid time");}
                
            if(TablesAvailable[TimeIndex][0] == 0){
                printf("You have booked the table Endor for %dpm for %d people",ChoosenTime, roomInt[i][2]);
                TablesAvailable[TimeIndex][0] = 1;
                break;}
            
            else if(TablesAvailable[TimeIndex][1] == 0){
                printf("You have booked the table Naboo for %dpm for %d people",ChoosenTime, roomInt[i][2]);    /*Changes the table name*/ 
                TablesAvailable[TimeIndex][1] = 1;
                break;}
            
            else if(TablesAvailable[TimeIndex][2] == 0){
                printf("You have booked the table Tatoonie for %dpm for %d people",ChoosenTime, roomInt[i][2]);
                TablesAvailable[TimeIndex][2] = 1;}
        }
        else{ 
            printf("Sorry, you aren't booked as half or full board");}         /*Printed if the person is B&B*/
    }
    else{
        printf("Sorry, we couldn't find your booking ID");}     /*Printed if the booking isn't recognised*/
}
}



int main()
{
    arrayCollums = sizeof(roomInt)/sizeof(roomInt[0]);
    
    while(loop==1){
        switch(getIntInput("\n1 - Check In\n2 - Book a Dinner Table\n3 - Check Out\n4 - Quit\nChoose an option:")){
            
            case 1:
                if((roomInt[1][0]+roomInt[2][0]+roomInt[3][0]+roomInt[4][0])!=4){
                    roomSelect();
                    detailFill();
                
                    printf("vacancy: %d cost: %d guestNum: %d childrenNum: %d adultNum: %d length: %d newspaper: %d boardType: %d IDNumber: %d \n", roomInt[inputRm][0], roomInt[inputRm][1], roomInt[inputRm][2], roomInt[inputRm][3], roomInt[inputRm][4], roomInt[inputRm][5], roomInt[inputRm][6], roomInt[inputRm][7], roomInt[inputRm][8]);
                    printf("firstname: %s Surname: %s DOB: %s BookingID: %s%d", roomStr[inputRm][0],roomStr[inputRm][1],roomStr[inputRm][2],roomStr[inputRm][1],roomInt[inputRm][8]);
                }
                else{
                    printf("The hotel is currently full.\n");
                }
                break;
                
            case 2:
                break;
            
            case 3:
                break;
            
            case 4:
                break;    
                
            default:
                printf("Please enter a valid option.");
                break;
                
        }
    }   
    return(0);
} 


 

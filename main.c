#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <string.h>



//**** GLOBAL VARIABLE DECLERATION ****
int roomInt[5][9]={ {0,0,0,0,0,0,0,0,0} , {0,100,0,0,0,0,0,0,0}, {0,85,0,0,0,0,0,0,0}, {0,75,0,0,0,0,0,0,0},{0,50,0,0,0,0,0,00}}; //main array to store integer room info
int ageInt[5][9]={ {0,0,0,0,0,0,0,0,0} , {0,100,0,0,0,0,0,0,0}, {0,85,0,0,0,0,0,0,0}, {1,75,0,0,0,0,0,0,0},{1,50,4,3,1,3,1,2,0}};
int costInt[5][9]={ {0,0,0,0,0,0,0,0,0} , {0,100,0,0,0,0,0,0,0}, {0,85,0,0,0,0,0,0,0}, {1,75,0,0,0,0,0,0,0},{1,50,4,3,1,3,1,2,0}};
char roomStr[5][5][100];//main array to store room string info

int loop =1, arrayCollums=0;//loop keeps the main program running, array collums is currently unused
int inputRm=0, r=0;//input room is the room the user has currently selected

//*************************************

const char* roomState(array){//function to determin the state of a room. Takes int returns string
    if(array==0){
        return "vacant";
    }
    else{
        return "taken";
    }
}

int getIntInput(print){//function to take a positive integer input only
    int error=0,input=1;
    while (error != 1 || input<0) {
        printf("%s", print);
        fflush(stdin);
        error = scanf("%d", &input);
        if(error!=1){//tells the user if input isnt an integer
            printf("Input is not an integer! please try again.\n");
        }
        else if(input<0){//tells the user if input is negative
            printf("Number is negative! Please try again.\n");
        }
    }
    return input;
}

int roomSelect(){//function to allow users to make a room selection
    int error=0;
    inputRm=0;//resets back to zero
    while (error != 1 || inputRm<1 || inputRm>4 || roomInt[inputRm][0]==1) { //forces user to choose a real vacant room. Loops if they fail to do so
        printf("\n");
        for(int i =1; i<5; i++){//loops for the four rooms
            printf("%d - Room%d costs \x9c %d and is %s\n", i,i, roomInt[i][1], roomState(roomInt[i][0]));//outputs room price, vancancy and room number
        }
        printf("Please select room number: ");
        fflush(stdin);
        error = scanf("%d", &inputRm);
        //printf("%d", error);
        if(error!=1){
            printf("\nInput must be a room number. Please try again.\n");
        }
        else if(inputRm<1 || inputRm>4){//makes sure users input is between 1 and 4. Makes sure its an actual room
            printf("\nRoom number must be between 1 and 4. Please try again.\n");
        }
        else if(roomInt[inputRm][0]==1){//tells the user if the room isnt vacant
            printf("Room is not vacant. Please select a vacant room.");
        }
    }
    roomInt[inputRm][0]=1;
}

int detailFill(){
    char buffer;
    char str[256];

    srand(time(NULL));   // Initialization, should only be called once.
    int r = 1000+(rand()%999);      // Returns a pseudo-random integer between 0 and 999.

    int error=0,input1=1,input2;

    printf("\nEnter firstname : ");
    fflush(stdin);
    scanf("%s", roomStr[inputRm][0]);    // Read and store firstname

    printf("Enter surname: ");
    fflush(stdin);
    scanf("%s",  roomStr[inputRm][1]);    // Read and store surname

    printf("Enter date of birth in the format DD/MM/YYYY: ");
    fflush(stdin);
    scanf("%s",  roomStr[inputRm][2]);    // Read and store date of birth

    sprintf(str, "%d", r);

    strcpy(roomStr[inputRm][3], roomStr[inputRm][1]);
    strcat(roomStr[inputRm][3], str);

    roomInt[inputRm][8] = r;//creates random booking id number, 4 digits
    roomInt[inputRm][8] = r;//creates random booking id number, 4 digits
    printf("Booking ID: %s%d\n", roomStr[inputRm][1],roomInt[inputRm][8]);//outputs booking id


    while (error != 2 || input1<0 || input2<0 || (input1+input2)==0 || (input1+input2)>4) {//forces user to input number of guests. There can only be a max of 4
        printf("Enter the number of adults and children seperated by commas (max of 4 total per room): ");
        fflush(stdin);
        error = scanf("%d,%d", &input1,&input2);
        if(error!=2){
            printf("Input is not an integer! please try again.\n");
        }
        else if(input1<0 || input2<0){
            printf("Number is negative! Please try again.\n");
        }
        else if(input1+input2>4 || (input1+input2)==0){
            printf("There is a max of 4 people per room and a min of 1. Please try again.");
        }
    }
    roomInt[inputRm][2]=input1+input2;//stores total number of guests in the array
    roomInt[inputRm][4]=input1;//stores the number of adults in the array
    roomInt[inputRm][3]=input2;//stores the number of children in the array

    error =0;//resets the error variable. Used to check if input is of correct type.
    printf("\n****Board Types****\n1 - Full Board - \x9c 20 \n2 - Half Board - \x9c 15 \n3 - B&B - \x9c 5 \n*******************\n");//outputs board types
    while (error != 1 || input1<1 || input1>3) {//forces the user to choose an existing board type
        printf("Enter your board type: ");
        fflush(stdin);
        error = scanf("%d", &input1);
        if(error!=1){
            printf("Input is not an integer! please try again.\n");
        }
        else if(input1<1 || input1>3 ){
            printf("Please choose a valid option.\n");
        }

    }
    roomInt[inputRm][7]=(input1-1);//stores the board type in the array

    error=0;//resets the error variable. Used to check if input is of correct type.
    while (error != 1 || input1<1) {
        printf("Enter the length of your stay: ");
        fflush(stdin);
        error = scanf("%d", &input1);
        if(error!=1){
            printf("Input is not an integer! please try again.\n");
        }
        else if(input1<1 ){
            printf("Number is negative! Please try again.\n");
        }
    }
    roomInt[inputRm][5]=input1;

    error =0;//resets the error variable. Used to check if input is of correct type.
    printf("\n****Newspaper****\n0 - No Daily Newspaper\n1 - Daily Newspaper - \x9c5.50 \n*******************\n");//outputs newspaper options
    while (error != 1 || input1<0 || input1>1) {//forces user to choose a newspaper option
        printf("Enter your newspaper choice: ");
        fflush(stdin);
        error = scanf("%d", &input1);
        if(error!=1){
            printf("Input is not an integer! please try again.\n");
        }
        else if(input1<0 || input1>1 ){
            printf("Please choose a valid option.\n");
        }
    }
    roomInt[inputRm][6]=input1;//stores the newspaper option to the array

    return 0;
}


int totalCostOfRoom(){
    printf("\n**********The total of the room is £%d**********\n",roomInt[inputRm][5]*roomInt[inputRm][1]);
}

int totalCostOfBoard(){
    printf("\n**********The coast of all the party's board is %d**********\n",roomInt[inputRm][7]*roomInt[inputRm][2]);
}

int newspaper() {
    if (roomInt[inputRm][6] == 1) {
        printf("\n**********The price of your daily newspapers is %d**********\n", roomInt[inputRm][5] * 5.50);
    } else if (roomInt[inputRm][6] == 0) {
        printf("\n**********You didnt have a daily newspaper so know payment is needed.**********\n");
    }
}

int Total() {
    if (roomInt[inputRm][6] == 1) {
        printf("\n**********So the total cost of your stay %s %s is : %d**********\n", roomStr[inputRm][0], roomStr[inputRm][1],
               (roomInt[inputRm][5] * roomInt[inputRm][1]) + (roomInt[inputRm][7] * roomInt[inputRm][2]) +
               (roomInt[inputRm][5] * 5.50));
    } else if (roomInt[inputRm][6] == 0) {
        printf("\n**********So the total cost of your stay %s %s is %d**********\n", roomStr[inputRm][0], roomStr[inputRm][1],
               (roomInt[inputRm][5] * roomInt[inputRm][1]) + (roomInt[inputRm][7] * roomInt[inputRm][2]));
    }
}


int bill() {
    int children = 0, over65s,  initial, onePerson, totalChild, totalRoom;
    int totalBoard,totalCost, newspaperCost = 0;

    int error=0,input1=1,input2;
    printf("\n****Is the user over 65?****\n0 - Over 65.\n1 - Under 65.\n*******************\n");
    while (error != 1 || input1<0 || input1>2) {
        printf("Please enter if your over 65 or not?");
        fflush(stdin);
        error = scanf("%d", &input1);
        if(error!=1){
            printf("Input is not an integer! please try again.\n");
        }
        else if(input1<0 || input1>3 ){
            printf("Please choose a valid option.\n");
        }
    }
    ageInt[inputRm][1]=input1;

//board cost calculator
    error=0;
    if (roomInt[inputRm][7] == 1){
        costInt[inputRm][1] = 20;
    }
    else if(roomInt[inputRm][7] == 2){
        roomInt[inputRm][1] = 15;
    }
    else if(roomInt[inputRm][7] == 3){
        costInt[inputRm][1] = 5;
    }
    else
    {
        //error
    }

    error=0;
    // calculating the final room cost, including seperate discounts for children/over65s
    onePerson = roomInt[inputRm][1] / roomInt[inputRm][2];
    if(roomInt[inputRm][3] != 0 && ageInt[inputRm][1] != 0){
        totalChild = ((onePerson * 0.5) * children) + (roomInt[inputRm][1] * (roomInt[inputRm][2] - children));
        totalRoom = totalChild * 0.9;
    }
    else if(roomInt[inputRm][9] != 0 && roomInt[inputRm][3] == 0){
        totalRoom = roomInt[inputRm][1] * 0.9;
    }
    else if(roomInt[inputRm][3] != 0 && roomInt[inputRm][9] == 0){
        totalRoom = ((onePerson * 0.5) * children) + (roomInt[inputRm][1] * (roomInt[inputRm][2] - 1));
    }
    else {
        totalRoom = roomInt[inputRm][1];
    }

    // calculating total board cost
    totalBoard = roomInt[inputRm][5] * costInt[inputRm][1];
    // calculating total cost of stay
    totalCost = totalBoard + totalRoom;
    if(roomInt[inputRm][6] != 0){
        totalCost + 5.50;
        newspaperCost = 5.50;
    }

    //outputting the user's bill
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nYour name: %s\nYour booking ID: %s%d\nPrice of room: %d\nPrice of board: %d", roomStr[inputRm][0], roomStr[inputRm][1],roomInt[inputRm][8], totalRoom, totalBoard);
    //only printing newspaper if the cost is not zero
    if(newspaperCost != 0){
        printf("\nPrice of newspapers: %d", newspaperCost);
    }
    printf("\nOverall total: %d\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~", totalCost);
    /*OUTPUT: full name, bookingID, total room cost, total board cost, newspaper cost (if price>0), overall total*/
    //return totalCost
}

int main()
{
    char LastDigits[256];

    int TablesAvailable[2][5]= {{0,0,0,0},{0,0,0,0}};
    int TimeIndex=0;
    int ChoosenTime=0;
    int Seven=0;
    int Nine=0;
    int y=0;int x=0;int i=0;
    arrayCollums = sizeof(roomInt)/sizeof(roomInt[0]);//unused

    printf("NOTE: If a decimal is entered, everything after the decimal point will be ignored!");

    while(loop==1){

        switch(getIntInput("\n*****Welcome to the Kashyyk Hotel*****\n1 - Check In\n2 - Book a Dinner Table\n3 - Check Out\n4 - Quit\n*********************\nChoose an option:")){



            case 1:

                if((roomInt[1][0]+roomInt[2][0]+roomInt[3][0]+roomInt[4][0])!=4){//makes sure there is rooms free in the hotel

                    roomSelect();//calls the function to select a room
                    detailFill();//calls the function to fill the array with user details

                    //printf("vacancy: %d cost: %d guestNum: %d childrenNum: %d adultNum: %d length: %d newspaper: %d boardType: %d IDNumber: %d \n", roomInt[inputRm][0], roomInt[inputRm][1], roomInt[inputRm][2], roomInt[inputRm][3], roomInt[inputRm][4], roomInt[inputRm][5], roomInt[inputRm][6], roomInt[inputRm][7], roomInt[inputRm][8]);
                    //printf("firstname: %s Surname: %s DOB: %s BookingID: %s%d", roomStr[inputRm][0],roomStr[inputRm][1],roomStr[inputRm][2],roomStr[inputRm][1],roomInt[inputRm][8]);
                }
                else{//if there are no free rooms
                    printf("The hotel is currently full.\n");
                }
                break;

            case 2:

                printf("******Booking dinner******\n");
                printf("\nEnter the booking ID:\n");
                scanf("%s", &LastDigits);



                for(i=1;i<5;i++){
                    printf("%s %s %d",LastDigits,roomStr[i][3],strcmp(LastDigits,roomStr[i][3]));
                    if(strcmp(LastDigits,roomStr[i][3])==0){            /*Checks if the booking ID is assioated with a room*/

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

                    break;

                }



                break;

            case 3:
                printf("******Checkout******\n");
                printf("\n**********Hello and wellcome to the best reception in the world.**********\n**********Please,Enter the booking ID:**********\n");
                scanf("%s", &LastDigits);

                for (i = 1; i < 5; i++) {
                    if (strcmp(LastDigits,roomStr[i][3])==0) {

                        bill();
                    }
                    else {
                        printf("Your Booking ID doesn't show up.\n");
                    }
                    break;
                }

            case 4:
                break;

            default:
                printf("Please enter a valid option.");
                break;

        }
    }
    return(0);
}

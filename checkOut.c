void checkOut();
double boardCost(int room);
double newspaperCost(int room);
double AgeDiscount(int room);
double roomCost(int room);

int booking = 0;
char BookingID1[32], surname1[16], forename1[16];
int DOB1[3], adults1 = 0, children1 = 0, boardtype1 = 0, lengthofstay1 = 0, newspaper1 = 0;

char BookingID2[32], surname2[16], forename2[16];
int DOB2[3], adults2 = 0, children2 = 0, boardtype2 = 0, lengthofstay2 = 0, newspaper2 = 0;

char BookingID3[32], surname3[16], forename3[16];
int DOB3[3], adults3 = 0, children3 = 0, boardtype3 = 0, lengthofstay3 = 0, newspaper3 = 0;

char BookingID4[32], surname4[16], forename4[16];
int DOB4[3], adults4 = 0, children4 = 0, boardtype4 = 0, lengthofstay4 = 0, newspaper4 = 0;

char BookingID[32];
char BookingID1[32];
char BookingID2[32];
char BookingID3[32];
char BookingID4[32];

int rooms[4] = {0,0,0,0};
int available_table[3] = {0,0,0};
int available_table1[3] = {0,0,0};


void checkOut() {
    char room[32];
    double boardTotal;
    double newspaperTotal;
    double discount;
    double totalRoomCost;
    double total;
    double discountCalc;

    printf("\n==================================Check Out===============================\nThank you for staying at the Kashyyk Hotel.\nPlease enter your BookingID\nEnter:");
    fflush(stdin);
    gets(room);
    //printf("%s", room);
    if(strcmp(room,BookingID1) == 0){
        boardTotal = boardCost(1);
        newspaperTotal = newspaperCost(1);
        discount = AgeDiscount(1);
        totalRoomCost = roomCost(1);
        if(discount == 0){
            discountCalc = 1;
        }
        else{
            discountCalc = 1.1;
        }
        total = (totalRoomCost + boardTotal + newspaperTotal)/(discountCalc);
        printf("\n======================\n\tBill\t\n======================\nRoom cost:\t%.2f\nBoard Cost:\t%.2f\nNewsPaper:\t%.2f\nDiscount:\t%.0f%%\n======================\nTotal:\t\t%.2f\n======================\n",totalRoomCost, boardTotal,newspaperTotal,discount,total);
        rooms[0] = 0;

    }
    else if(strcmp(room,BookingID2) == 0){
        boardTotal = boardCost(2);
        newspaperTotal = newspaperCost(2);
        discount = AgeDiscount(2);
        totalRoomCost = roomCost(2);
        if(discount == 0){
            discountCalc = 1;
        }
        else{
            discountCalc = 1.1;
        }
        total = (totalRoomCost + boardTotal + newspaperTotal)/(discountCalc);
        printf("\n======================\n\tBill\t\n======================\nRoom cost:\t%.2f\nBoard Cost:\t%.2f\nNewsPaper:\t%.2f\nDiscount:\t%.0f%%\n======================\nTotal:\t\t%.2f\n======================\n",totalRoomCost, boardTotal,newspaperTotal,discount,total);
        rooms[1] = 0;

    }
    else if(strcmp(room,BookingID3) == 0){
        boardTotal = boardCost(3);
        newspaperTotal = newspaperCost(3);
        discount = AgeDiscount(3);
        totalRoomCost = roomCost(3);
        if(discount == 0){
            discountCalc = 1;
        }
        else{
            discountCalc = 1.1;
        }
        total = (totalRoomCost + boardTotal + newspaperTotal)/(discountCalc);
        printf("\n======================\n\tBill\t\n======================\nRoom cost:\t%.2f\nBoard Cost:\t%.2f\nNewsPaper:\t%.2f\nDiscount:\t%.0f%%\n======================\nTotal:\t\t%.2f\n======================\n",totalRoomCost, boardTotal,newspaperTotal,discount,total);
        rooms[2] = 0;

    }
    else if(strcmp(room,BookingID4) == 0){
        boardTotal = boardCost(4);
        newspaperTotal = newspaperCost(4);
        discount = AgeDiscount(4);
        totalRoomCost = roomCost(4);
        if(discount == 0){
            discountCalc = 1;
        }
        else{
            discountCalc = 1.1;
        }
        total = (totalRoomCost + boardTotal + newspaperTotal)/(discountCalc);
        printf("\n======================\n\tBill\t\n======================\nRoom cost:\t%.2f\nBoard Cost:\t%.2f\nNewsPaper:\t%.2f\nDiscount:\t%.0f%%\n======================\nTotal:\t\t%.2f\n======================\n",totalRoomCost, boardTotal,newspaperTotal,discount,total);
        rooms[3] = 0;
    }
    else{
        printf("\nThat's not a valid input\n\n Returning to main manu...\n");
    }
}

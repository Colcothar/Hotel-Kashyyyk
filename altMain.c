int main(){
    int usr = 12984, _ = 1;
    while(_) {
        printf("\n===============================\n Welcome to the Kashyyk Hotel!\n===============================\n\tMenu:\n===============================\n\t1.Check in\n\t2.Book a table\n\t3.Check out\n\n\tEnter: ");
        fflush(stdin);
        scanf("%d", &usr);
        if(usr == 12984){
            printf("\nYou entered a non-digit, please enter a valid input.\n");
            fflush(stdin);
        }
        else if(usr == 1){
            checkIn();
        }
        else if( usr == 2){
            dining();
        }
        else if (usr == 3){
            checkOut();
        }
        else{
            printf("\nThat's not a valid input\n\n");
        }
    }
}

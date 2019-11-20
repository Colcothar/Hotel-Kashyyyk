#include <stdio.h>

int roomState(array){
    if(array==0){
        return "vacant";
    }
    else{
        return "taken";
    }
}
int main() {
    //                null   room1   room2   room3 room4
    int room[5][100]={{0,0}, {0,100},{0,85},{0,75},{0,50} } ;
    char* user[3][2]= {{"Barney", "Morris", "Bmorris3281"}};
    int userInfo[3][6]= {{4,2,2,3,0,3}};


    printf("%s wants to be in room%d\n", user[0][0], userInfo[0][5]);

    printf("Room 3 is %s and costs %d", roomState(room[userInfo[0][5]][0]), room[userInfo[0][5]][1]);
    
    
}

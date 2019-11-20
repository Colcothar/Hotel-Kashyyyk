double roomCost(int room){
    if(room == 1){
        double totalcost = lengthofstay1 * 100;
        return  totalcost;
    }

    else if(room == 2){
        double totalcost = lengthofstay2 * 85;
        return  totalcost;
    }
    else if(room == 3){
        double totalcost = lengthofstay3 * 75;
        return  totalcost;
    }
    else if(room == 4){
        double totalcost = lengthofstay4 * 50;
        return  totalcost;
    }
}

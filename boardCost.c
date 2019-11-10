double boardCost(int room) {
    double totalBoardCost;
    int boardPrice;
    if (room == 1) {
        if (boardtype1 == 1) {
            boardPrice = 20;
        } else if (boardtype1 == 2) {
            boardPrice = 15;
        } else {
            boardPrice = 5;
        }
        totalBoardCost = ((adults1 * boardPrice) + (0.5 * children1 * boardPrice)) * lengthofstay1;
        return totalBoardCost;
    } else if (room == 2) {
        if (boardtype2 == 1) {
            boardPrice = 20;
        } else if (boardtype2 == 2) {
            boardPrice = 15;
        } else {
            boardPrice = 5;
        }
        totalBoardCost = ((adults2 * boardPrice) + (0.5 * children2 * boardPrice)) * lengthofstay2;
        return totalBoardCost;
    } else if (room == 3) {
        if (boardtype3 == 1) {
            boardPrice = 20;
        } else if (boardtype3 == 2) {
            boardPrice = 15;
        } else {
            boardPrice = 5;
        }
        totalBoardCost = ((adults3 * boardPrice) + (0.5 * children3 * boardPrice)) * lengthofstay3;
        return totalBoardCost;
    } else if (room == 4) {
        if (boardtype4 == 1) {
            boardPrice = 20;
        } else if (boardtype4 == 2) {
            boardPrice = 15;
        } else {
            boardPrice = 5;
        }
        totalBoardCost = ((adults4 * boardPrice) + (0.5 * children4 * boardPrice)) * lengthofstay4;
        return totalBoardCost;
    }
}

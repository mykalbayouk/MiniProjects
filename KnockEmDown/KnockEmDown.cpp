#include <iostream>
#include <ctime>

void play(std::string *board);
void printBoard(std::string board);
int rollDice();
int checkInput(std::string input, int diceSum, std::string board);
bool isLoser(int diff, int diceSum, std::string board);
bool isWinner(std::string board);

/**
 * Main function used to start the game up.
 * 
 * @return 0 once game complete
*/
int main() {
    std::string board = "1 2 3 4 5 6 7 8 9";
    std::cout << "\nWelcome to Knock Em Down!" << std::endl;
    std::cout << "In this game the goal is to knock down #'s (1 - 9)" << std::endl;
    play(&board);
    std::cout << "Thanks for Playing!!!!" << std::endl;
    return 0;
} // main 
/** 
 * Function run recursively to allow the player to roll and knock down the numbers.
 * 
 * @param board pointing to the memory address of the board created in {@code main}
*/
void play(std::string *board) {
    if (isWinner(*board)) {
        std::cout << "You won!" << std::endl;
        return;
    } // if the board is empty, then the player has won
    std::string boar = *board;      
    std::cout << "Press Enter to roll the dice" << std::endl;
    std::cin.get();
    int diceSum1= rollDice();
    srand(time(0));
    int diceSum2 = rollDice();
    int diceSum = diceSum1 + diceSum2;
    std::cout << "You rolled a " << diceSum1 << " and a " << diceSum2 << std::endl;  
    std::cout << "The current board is: " << boar << std::endl;  
    if (isLoser(0, diceSum, boar)) {
        std::cout << "You have lost!" << std::endl;
        return;
    } // if the player has lost, then end the game
    std::string input;
    int check;
    do {
    std::cout << "What combination of numbers would you like to knock down? (Seperate by ' ')" << std::endl;
    std::getline(std::cin, input);
    check = checkInput(input, diceSum, boar);
    if (check == 0) {
        std::cout << input << " is an improper input, try again." << std::endl;
    } // Gives user a message letting them know input is invalid
    } while (check == 0);
    if (check == 1) {
        std::cout << "You knocked down " << input << std::endl;
        for (int i = 0; i < boar.length(); i++) {
            if (boar[i] == ' ') {
                continue;
            } // if the character is a space, then skip it
            if (input.find(boar[i]) != std::string::npos) {
                boar.erase(i, 1);
            } // if the input contains the number, then remove it from the board
        } // for loop to remove the knocked down numbers from the board
        std::cout << "The new board is: " << boar << std::endl;
        play(&boar);
    } // if the input is valid, then knock down the numbers
} // play 

/**
 * Checks to see if the board is empty.
 * 
 * @param board the current board
 * @return true if the board is empty, false if not
*/ 
bool isWinner(std::string board) {
    int sum = 0;
    for(int i = 1; i < 10; i++) {
        if (board.find(std::to_string(i)) == std::string::npos) {
            sum++;
        } // if the board contains the number, then add 1 to the sum
    } // for loop to check if the board is empty
    if (sum == 9) {
        return true;
    } else {
        return false;
    } // if the board is empty, then the player has won
} // isWinner

/**
 * Checks to see if the current dicesum and the current board have possible combinations.
 * 
 * @param diff used recurisevly 
 * @param diceSum the current rolled value
 * @param board the current string of the board
 * @return true if Lost, false if not 
*/
bool isLoser(int diff, int diceSum, std::string board) {
    if (diceSum == 0 || diff == 9 || diceSum == diff) {
        return true;
    } else {
        if ((board.find(std::to_string(diceSum)) != std::string::npos) && (board.find(std::to_string(diff)) != std::string::npos)) {
            return false;                 
        } else if (board.find(std::to_string(diceSum)) != std::string::npos && diff == 0) {
            return false;
        } else {
            return isLoser(diff + 1, diceSum - 1, board);
        } // if the board contains the dice sum or the difference, then the player has not lost
    } // if the dice sum is 0 or the difference is 9, then the player has lost
} // isLoser 

/**
 * Takes user input and determines if it is present on the board as well as it totals, 
 * the total sum of the dice roll.
 * 
 * @param input of the user in string format
 * @param diceSum total sum of the two dice
 * @param board the current board
 * 
 * @return 0 if improper input, 1 if correct input. 
*/
int checkInput(std::string input, int diceSum, std::string board) {
    int sum = 0;
        for (int i = 0; i < input.length(); i++) {
        if (input[i] == ' ') {
            continue;
        } // if whitespace continue
        if (input[i] < '1' || input[i] > '9') {
            return 0;
        } // if out of range return 0
        sum += input[i] - '0';
    } // for loop to add up the sum of the input
    if (sum == diceSum) {
        return 1;
    } else {
        return 0;
    } // if the sum of the input is equal to the dice sum return 1
}

/**
 * Generates a random value between 1 - 6.
 * 
 * @return value between 1 - 6
*/
int rollDice() {
    int dice = rand() % 6 + 1;
    return dice;
} // rollDice



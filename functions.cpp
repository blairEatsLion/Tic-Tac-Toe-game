#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
using namespace std;

// global variables
char checkboard[27];  // store 'X', 'O'
vector<string> theBoard; // store numbers, 'X', 'O', for printing

void greetAndInstruct(){
	cout << "Hello and welcome to the Tic-Tac-Toe challenge: Player against Computer."<< endl;
	cout << "The board is numbered from 1 to 27 as per the following: \n"<< endl;

	// fill number board with numbers
	for (int i = 1; i < 28; i++){
		theBoard.push_back(to_string(i));  // vector array
	}

	// display number board
	string result;
	string dash = "\n----------  ------------   ------------ \n";
	string blankSpace = "   ";

	result += theBoard[0] +" | "+ theBoard[1]+" | "+ theBoard[2] + blankSpace
				+ theBoard[9] +" | "+ theBoard[10]+" | "+ theBoard[11] + blankSpace
				+ theBoard[18] +" | "+ theBoard[19]+" | "+ theBoard[20] + dash;
    result += theBoard[3] +" | "+ theBoard[4]+" | "+ theBoard[5] + blankSpace
				+ theBoard[12] +" | "+ theBoard[13]+" | "+ theBoard[14] + blankSpace
				+ theBoard[21] +" | "+ theBoard[22]+" | "+ theBoard[23] + dash;
    result += theBoard[6] +" | "+ theBoard[7]+" | "+ theBoard[8] + blankSpace
				+ theBoard[15] +" | "+ theBoard[16]+" | "+ theBoard[17] + blankSpace
				+ theBoard[24] +" | "+ theBoard[25]+" | "+ theBoard[26];

	// display message and ask for user input
	cout << result << endl;
	cout << "Player starts first. Simply input the number of the cell you want to occupy. Player’s move is marked with X. Computer’s move is marked with O.\n" << endl;
	cout << "Start? (y/n):" << endl;

	char userIn;
	cin >> userIn;
	if (userIn == 'y'){
		cout << "Your choice is: " << userIn << "\nLet's start the game! \n";
	}else{
		cout << "Your choice is: " << userIn << "\n";
        exit(0); // end the program
	}
}

void displayBoard (char board[]){
	// print contents of the board

	string result;
	string dash = "\n----------  ------------   ------------ \n";
	string blankSpace = "   ";

	result += theBoard[0] +" | "+ theBoard[1]+" | "+ theBoard[2] + blankSpace
				+ theBoard[9] +" | "+ theBoard[10]+" | "+ theBoard[11] + blankSpace
				+ theBoard[18] +" | "+ theBoard[19]+" | "+ theBoard[20] + dash;
    result += theBoard[3] +" | "+ theBoard[4]+" | "+ theBoard[5] + blankSpace
				+ theBoard[12] +" | "+ theBoard[13]+" | "+ theBoard[14] + blankSpace
				+ theBoard[21] +" | "+ theBoard[22]+" | "+ theBoard[23] + dash;
    result += theBoard[6] +" | "+ theBoard[7]+" | "+ theBoard[8] + blankSpace
				+ theBoard[15] +" | "+ theBoard[16]+" | "+ theBoard[17] + blankSpace
				+ theBoard[24] +" | "+ theBoard[25]+" | "+ theBoard[26];
                
	cout << result << endl;
}


bool checkIfLegal (int cellNbre, char board[]){
	// mark legal if number in range and cell not occupied
	// else display warning and ask for user input

	if(cellNbre<28 && cellNbre>0){
        	
        if(!checkboard[cellNbre-1]){   // empty cell
//			cout << "This move is legal." << endl;
			return true;           
		}else{
			cout << "This cell is already taken, please input a different cell number." << endl;
		}    
	}else{ 	
		cout << "This move is beyond number range, please input a different cell number." << endl;
    }	 
    return false;
}

// helper function going through all cases to check whether there is a winner
bool helper_checkWinner(char board[],char player){
	int testcase = -1;  // for testing
	
	// row in same table
	for (int i = 0; i < 25; i+=3){
		if (board[i] == player && board[i+1] == player && board[i+2] == player) {
			testcase = 1;
			return true;
		}
	}        	
	
	// row across tables, modified
	for (int i = 0; i < 7; i+=3){
		if (board[i] == player && board[i+10] == player && board[i+20] == player){
			testcase = 2; // case 4 14 24
			return true;
		}
	}
	for (int i = 2; i < 9; i+=3){
		if (board[i] == player && board[i+8] == player && board[i+16] == player){
			testcase = 2; // case 3 11 19
			return true;
		}	
	}
	
	// column in same table, modified
	for (int j = 0; j < 20; j+=9){  // 3 tables in total
		for (int i = 0; i < 3; i++){		
			if (board[i+j] == player && board[i+j+3] == player && board[i+j+6] == player) {
				testcase = 3;
				return true;
			}
		}
	}
	
	// column across tables, modified
	for (int i = 0; i < 3; i++){
		if (board[i] == player && board[i+12] == player && board[i+24] == player) {
			testcase = 4; // case 3 15 27
			return true;
		}
		if (board[8-i] == player && board[8-i+6] == player && board[8-i+12] == player) {
			testcase = 4; // case 9 15 21
			return true;
		}
	}		
	
	// diagonal in same table
	for (int i = 0; i < 19; i+=9){	
		if (board[i+0] == player && board[i+4] == player && board[i+8] == player){
			testcase = 5; // case 19 23 27
			return true;
		}
			
		if (board[i+2] == player && board[i+4] == player && board[i+6] == player){
			testcase = 6; // case 12 14 16
			return true;
		}	
	}
	
	// diagonal across tables, modified - 4 cases
	if (board[0] == player && board[13] == player && board[26] == player){
		testcase = 7; // case 1 14 27
		return true;
	}	
	if (board[2] == player && board[13] == player && board[24] == player){
		testcase = 7; // case 3 14 25
		return true;
	}
	if (board[8] == player && board[13] == player && board[18] == player){
		testcase = 7; // case 9 14 19
		return true;
	}
	if (board[6] == player && board[13] == player && board[20] == player){
		testcase = 7; // case 7 14 21
		return true;
	}	
		
	// same cell across tables
	for (int i = 0; i < 9; i++){
		if (board[i] == player && board[i+9] == player && board[i+18] == player) {
			testcase = 9; // case 3 12 21
			return true;
		}
	}

	return false;  
}

bool checkWinner(char board[]){
// check tie as board is full
	int countEmpty = 0; // count number of empty cells
	for (int i = 0; i < 27; i++){	
		if (!board[i]){ // empty cell
			countEmpty += 1;
		}
	}
	if(countEmpty == 0){
		cout << "The board is full. We have a tie!   Game is over."  << endl;
		return true;
	}	
	// use helper function to check whether and who is winner	
	// when winner identified, display message and return	
	char player = 'X';
	char computer = 'O';
	if(helper_checkWinner(board, player)){
		cout << "Player wins the game!   Game is over."  << endl;
		return true; 
	}else if(helper_checkWinner(board, computer)){
		cout << "Computer wins the game.   Game is over."  << endl;
		return true; 
	}else{
		return false;
	}	
}

// helper function for update of player move
void movePlayer(int ind){
    checkboard[ind-1] = 'X';
    theBoard[ind-1] = "X";
}

// helper function for update of computer move
void moveComputer(int ind){
    checkboard[ind] = 'O';
    theBoard[ind] = "O";
    cout << "computer made the move: "<< ind+1  << endl;
}


void computerMove(char board[]){
	
	// exit function when computer makes a move
	bool moved = false;
	
	// check a move for computer to win
	// for each empty cell, simulate the scenario that computer takes the cell
	
	for(int i = 0; i < 27; i++){
		if (!board[i]){	
			char copyBoard[27];

			// make a copy of current board for simulation
			for(int j=0; j<27; j++){
				copyBoard[j] = board[j];
			}
			// simulation
			copyBoard[i] = 'O';			
			bool activate = helper_checkWinner(copyBoard,'O');
			
			if (activate){  // case when computer wins the game
				moveComputer(i);  // computer takes the move
				cout << "Computer has taken the move to win."  << endl;
				moved = true;
				break;
			}
		}
	}
	
	// then, check a move to block player from winning
	
	if(!moved){		
		for(int i = 0; i < 27; i++){
			if (!board[i]){	
				char copyBoard[27];

				for(int j=0; j<27; j++){
					copyBoard[j] = board[j];
				}
				// simulation
				copyBoard[i] = 'X';				
				bool activate = helper_checkWinner(copyBoard,'X');
				
				if (activate){  // case when player wins the game
					moveComputer(i); 
					cout << "Computer has taken the move to block player from winning."  << endl;
					moved = true;
					break;
				}
			}
		}
	}	
	
	// make a random move if neither of the above
	
	if(!moved){
		int countEmpty = 0; // number of available cells
		int cellNumbre [27]; // array of available cell index
		
		for(int i = 0; i < 27; i++){
			if (!board[i]){  // empty cell
				cellNumbre[countEmpty] = i;
				countEmpty += 1;
			}
		}
		
		// randomly choose one from available cell indices
		int iRand = rand() % countEmpty; 
		moveComputer(cellNumbre[iRand]);
		cout << "Computer has made a random move."  << endl;
		moved = true;
	}
	
}



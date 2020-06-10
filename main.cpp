#include <iostream>
#include <string>
#include <vector>
#include "functions.cpp" 

// Xiaohui Wang 260719359
// Comp322 Assignment 1, Feb 11, 2019

int main() { 		

    greetAndInstruct();

    // loop until there is winner
    while(true){
    	displayBoard(checkboard);
    	cout << "Now it's your turn." << endl;
    	
    	// try catch to ensure user input is integer  
		bool k = false;
		int input;
		while(!k){
			
			string str;
			try {
				cin >> str;
				str+="\0"; //
				input = std::stoi(str, 0, 10);		
				// check whether user input is legal
				k = checkIfLegal(input, checkboard);	
			}
			catch (const std::invalid_argument& e) {
				cout << "The input is not integer. Please enter a valid number."  << endl;
			}
			
		}	
		// move of player				
		movePlayer(input);  
		if(checkWinner(checkboard)){
			exit(0);
		}
		
		// move of computer
		computerMove(checkboard);
		if(checkWinner(checkboard)){
			exit(0);
		}
	}	    
    
    return 0;
}

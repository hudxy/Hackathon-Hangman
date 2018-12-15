#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;

void printMan(int);

int main() {
	srand((unsigned)time(0));	//seed for random number generator
	int counter; //variable to keep track of 
	string targetWord;
	fstream wordFile;

	wordFile.open("hangman.txt");
	if(!wordFile.is_open()) {	//Checks if file is open
		cout << "Sorry, file could not be found... aborting program." << endl;
		return 0;
	}
	
	int randomNum = ((rand() % 10)+1); //random number generator for selecting word
	for(int i=0; i < randomNum; i++) {	
		std::getline(wordFile, targetWord);	//get selected word
	}
	
	cout << targetWord;	//debugging (can delete later)


	printMan(counter);
	

  wordFile.close();
}

/*************************************************************************************************************
function takes in the game counter as a parameter
prints corresponding hangman
**************************************************************************************************************/
void printMan(int counter) {
	switch(counter) {
		case 0: {
			cout << endl;
			cout << "   ------  \n";
			cout << "   |     | \n";
			cout << "         | \n";
			cout << "         | \n";
			cout << "         | \n";
			cout << "        ---\n";
			cout << endl;
			break;
		}
		case 1: {
			cout << endl;
			cout << "   ------  \n";
			cout << "   |     | \n";
			cout << "   O     | \n";
			cout << "         | \n";
			cout << "         | \n";
			cout << "        ---\n";
			cout << endl;
			break;
		}
		case 2: {
			cout << endl;
			cout << "   ------  \n";
			cout << "   |     | \n";
			cout << "   O     | \n";
			cout << "   X     | \n";
			cout << "         | \n";
			cout << "        ---\n";
			cout << endl;
			break;
		}
		case 3: {
			cout << endl;
			cout << "   ------  \n";
			cout << "   |     | \n";
			cout << "   O     | \n";
			cout << "   X     | \n";
			cout << "    \\    | \n";
			cout << "        ---\n";
			cout << endl;
			break;
		}
		case 4: {
			cout << endl;
			cout << "   ------  \n";
			cout << "   |     | \n";
			cout << "   O     | \n";
			cout << "   X     | \n";
			cout << "  / \\    | \n";
			cout << "        ---\n";
			cout << endl;
			break;
		}
		case 5: {
			cout << endl;
			cout << "   ------  \n";
			cout << "   |     | \n";
			cout << "   O /   | \n";
			cout << "   X     | \n";
			cout << "  / \\    | \n";
			cout << "        ---\n";
			cout << endl;
			break;
		}
		case 6: {
			cout << endl;
			cout << "   ------  \n";
			cout << "   |     | \n";
			cout << " \\ O /   | \n";
			cout << "   X     | \n";
			cout << "  / \\    | \n";
			cout << "        ---\n";
			cout << endl;
			break;
		}
	}
}

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;

int main() {
	srand((unsigned)time(0));	//seed for random number generator
	string targetWord;
	fstream wordFile;

	wordFile.open("hangman.txt");
	if(!wordFile.is_open()) {	//Checks if file is open
		cout << "Sorry, file could not be found... aborting program." << endl;
		return 0;
	}
	
	int randomNum = ((rand() % 3)+1); //random number generator for selecting word
	for(int i=0; i < randomNum; i++) {	
		std::getline(wordFile, targetWord);	//get selected word
	}
	
	cout << targetWord;	//debugging (can delete later)


  wordFile.close();
}

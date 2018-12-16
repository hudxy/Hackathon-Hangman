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
	int counter; //variable to keep track of 
	string targetWord;
		
	cout << targetWord;	//debugging (can delete later)


	printMan(counter);
	

  	return 0;
}

/***********************************************************************************************************
Chooses word from txt file using random number generator. 
***********************************************************************************************************/
string wordSelect()
{
  string targetWord;
  int count = 0;
  srand((unsigned)time(0));	//seed for random number generator
	fstream wordFile;

	wordFile.open("hangman.txt");
	if(!wordFile.is_open()) {	//Checks if file is open
		cout << "Sorry, file could not be found... aborting program." << endl;
		exit(0);
	}
	
  while (wordFile >> targetValue) //counts how many words are in the file
    count++;
    
	int randomNum = ((rand() % count)+1); //random number generator for selecting word
	   
  wordFile.clear(); 
  wordFile.seekg(0, std::ios::beg); //clears failure flag for wordFile
  
  for(int i=0; i < randomNum; i++) 
  {	
		std::getline(wordFile, targetWord);	//get selected word
	}

  wordFile.close();
  return targetWord;
} 


//function takes in the game counter as a parameter
//prints corresponding hangman
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
		}
	}
}

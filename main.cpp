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
string wordSelect();
void input(string);


int main() {
	int counter=0; //variable to keep track of 
	string targetWord;
  char play = ' ';
  bool gameState = true;
  
  while (gameState)
  {
    cout << "HANGMAN" << endl;
    
    targetWord = wordSelect();

    cout << "Enter a letter to guess the word!" << endl;

    for (int i=6; i>-1; i--)
      {
        printMan(i);

        


        //system("CLS")
        
      }

    cout << "Would you like to play again? (y/n)" << endl;
    cin >> play;
    if(play == 'n')
      gameState = false;
  } 
	

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
	
  while (wordFile >> targetWord) //counts how many words are in the file
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


/*******************************************************************************************************
Loops to validate input and compare input to correct answer
*******************************************************************************************************/
void input(string word)
{
	char first;
	cout << "Please enter a character to guess... (A-Z)" << endl;
	cin >> first;
	char input = tolower(first);
	
	for(int i =0; i< word.length(); i++) {
		if(input == word[i]) {
			cout << word[i];
		}
		else {
			cout << "_" << " ";
		}
	}
	cout << endl;
}

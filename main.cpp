#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;
using std::vector;

void printMan(int);
string wordSelect();
bool input(string, vector<char>&, char);
bool validInput(char);
char charInputVal(char &);
bool letterInWord(char, vector<char>);
void printArray(vector<char>);
char getUserInput(vector<char>);
bool gameOver(vector<char>, string);


int main() {
	int counter=0; //variable to keep track of 
	srand((unsigned)time(0));	//seed for random number generator
	string targetWord;
  char play = ' ';
  bool gameState = true;	//intialize the start of the game
  vector<char> guess;
  while (gameState)
  {
    cout << "HANGMAN" << endl;
    
    targetWord = wordSelect();	//variable for random word

   
		while(counter < 7)
      {
        printMan(counter);
				char temp = getUserInput(guess);
        if(input(targetWord,guess, temp)) {
					//if user guesses correctly; do nothing
				}
				else {	//if user enters incorrectly; inc counter
					counter++;
				}
      }
//Block to restart game if user chooses to play again
    cout << "Would you like to play again? (y/n)" << endl;
    cin >> play;
		charInputVal(play);	//validate user input to play again
    if(play == 'n' || play == 'N') {
			cout << endl;
			cout << "Thanks for playing!" << endl;
      gameState = false;
		}
		else {
			counter = 0; //reset counter
		}
  } 
	

}

/***********************************************************************************************************
Chooses word from txt file using random number generator. 
***********************************************************************************************************/
string wordSelect()
{
  string targetWord;
  int count = 0;
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
			cout << "   ------- \n";
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
			cout << "   ------- \n";
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
			cout << "   ------- \n";
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
			cout << "   ------- \n";
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
			cout << "   ------- \n";
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
			cout << "   ------- \n";
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
			cout << "   ------- \n";
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
bool input(string word, vector<char>& guesses, char input)
{
	bool guessRight = false;
	/*char input;
	cout << "Please enter a character to guess... (A-Z)" << endl;	//prompt user
	cin >> input;
	while(!validInput(input)) {	//validation block
		cout << endl << "Sorry, that input was not an acceptable character.\n";
		cout << "Please enter a character (A-Z)" << endl;
		cin >> input;	
	}
	while(letterInWord(input, guesses)) {
			cout << endl << "You have already guessed this chracter, Please choose another." << endl;
			cin >> input;
	}*/
	char lowerCase = tolower(input);	//accounts for lowercase
	char upperCase = toupper(input);	//accounts for uppercase
	guesses.push_back(lowerCase);
	guesses.push_back(upperCase);			//adds upper and lower case to vector array


	for(int i =0; i< word.length(); i++) {
			if(word[i] == lowerCase || word[i] == upperCase) {
				cout << word[i] << " ";
				guessRight = true;
			}
			else if(letterInWord(word[i], guesses)) {
				cout << word[i] << " ";
			}
			else {
				cout << "_" << " ";
			}
		}
	cout << endl;
	return guessRight;
}

/*******************************************************************************************************
checks if a given letter is in an array (vector)
*******************************************************************************************************/
bool letterInWord(char letter, vector<char> guesses) {
	for(int i =0; i < guesses.size(); i++) {
		if(letter == guesses[i]) {
			return true;
		}
	}
	return false;
}

/*******************************************************************************************************
loops to validate input
*******************************************************************************************************/
bool validInput(char guess)
{
  if((guess >= 65 && guess <= 90) || (guess >= 97 && guess <= 122))
    return true;
  else 
    return false;
}


/******************************************************************************************************
validate input of "Do you want to play again"
*******************************************************************************************************/
char charInputVal(char &input)
{
	//input validation loop
 while(input != 'Y' && input !='N' && input != 'y' && input !='n') {
  cout << "Sorry that input is invalid; Please try again" << endl;
  cin >> input;
	}

	return input;
}

char getUserInput(vector<char> guess) {
	char userInput;
		cout << "Please enter a character to guess... (A-Z)" << endl;	//prompt user
		cin >> userInput;
		bool resume = true;
		while(resume) {
			if(letterInWord(userInput, guess)) {
			cout << endl << "You have already guessed this chracter, Please choose another." << endl;
			cin >> userInput;
		}
		else if (!validInput(userInput)){
			cout << endl << "Sorry, that input was not an acceptable character.\n";
			cout << "Please enter a character (A-Z)" << endl;
			cin >> userInput;	
		}
		else if((!letterInWord(userInput, guess)) && validInput(userInput)) {
			resume = false;
		}
	}
	return userInput;
}


/*********************************************************************************************************
checks for game ending condition
**********************************************************************************************************/
bool gameOver(vector<char> guess, string word)
{
  int chCount = 0;
  for(int i=0; i<word.length(); i++) {
    if(letterInWord(word[i], guess))
      chCount++;
  }

  if(chCount == word.length())
    return true;
  else
    return false;

}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int ROWS = 4;
const int COLS = 4;

///////// --------- Function Prototypes -------- //////////

void populateArray(ifstream&, char array[ROWS][COLS]);
void outputBoard(char charArray[ROWS][COLS], bool boolArray[ROWS][COLS]);
bool makeAMatch(char char_array[ROWS][COLS], bool bool_array[ROWS][COLS]);

int main() {

	ifstream inFile;
	char charArr[ROWS][COLS];
	bool boolArr[ROWS][COLS] = {{false}};
	int matches = 0;
	int moves = 0;
	bool result;
	
	populateArray(inFile, charArr);


	while(matches < 8) {

		cout << "Moves Made: " << moves << endl;
		cout << endl;

		result = makeAMatch(charArr, boolArr);

		if(result == true) {
			matches++;

			moves++;
			
			

		} else {

			moves++;
			
		}
	}

	return 0;
}

/*

FUNCTION NAME: makeAMatch

PARAMETERS: the char 2darray from the file input stream, an 2darray of bool values;

RETURN TYPE: bool - if the characters are equal returns true; if characters are not equal returns false;

DESCRIPTION: this function will loop through and error check the inputs for x y coordinate system and make assignments to 2d bool array
if there is isn't a match or not a match and passing those values into outputBoard() which will output the matches or non matches;

*/

bool makeAMatch(char _char[ROWS][COLS], bool _bool[ROWS][COLS]) {

	int x, y, x2, y2;
	bool isInvalid = false;
	bool result; 
	int move = 0;

	outputBoard(_char, _bool);

		cout << endl;
		cout << "Part 1 Enter row and column index (1-4): ";
		cin >> x >> y;
		cout << endl;

		x = x - 1;
		y = y - 1;
		isInvalid = false;

		while(!isInvalid) {

		if (_bool[x][y] == true) {

				cin.clear();
				cin.ignore(100, '\n');

				cerr << "Invalid: (YA ALREADY PICKED IT!)" << endl;

				cout << "Part 1 Enter row and column index (1-4): ";
				cin >> x >> y;
				cout << endl;

				x = x - 1;
				y = y - 1;
		}

		else if(x < 0 || y < 0) {

				cin.clear();
				cin.ignore(100, '\n');

				cerr << "Invalid: (Enter Positive Integers)" << endl;

				cout << "Part 1 Enter row and column index (1-4): ";
				cin >> x >> y;
				cout << endl;

				x = x - 1;
				y = y - 1;

		} else if(cin.fail()) {

				cin.clear();
				cin.ignore(100, '\n');

				cerr << "Invalid: (Enter Positive Integers)" << endl;

				cout << "Part 1 Enter row and column index (1-4): ";
				cin >> x >> y;
				cout << endl;

				x = x - 1;
				y = y - 1;

			} else if(x > 3 || y > 3) {

				cin.clear();
				cin.ignore(100, '\n');

				cerr << "Invalid: (Number Out of Range)" << endl;

				cout << "Part 1 Enter row and column index (1-4): ";
				cout << endl;
				cin >> x >> y;

				x = x - 1;
				y = y - 1;

			} else if(x == x2 && y == y2) {

				cin.clear();
				cin.ignore(100, '\n');

				cerr << "Invalid: Already Entered" << endl;

				cout << "Part 1 Enter row and column index (1-4): ";
				cin >> x >> y;
				cout << endl;

				x = x - 1;
				y = y - 1;
			}

			else {

				_bool[x][y] = true;

				isInvalid = true;
			}
		}

		outputBoard(_char, _bool);

		cout << endl;
		cout << "Part 2 Enter row and column index (1-4): ";
		cin >> x2 >> y2;
		cout << endl;

		x2 = x2 - 1;
		y2 = y2 - 1;

		isInvalid = false;

		while(!isInvalid) {

			if (_bool[x2][y2] == true) {

				cin.clear();
				cin.ignore(100, '\n');

				cerr << "Invalid: (YA ALREADY PICKED IT!)" << endl;

				cout << "Part 2 Enter row and column index (1-4): ";
				cin >> x2 >> y2;
				cout << endl;

				x2 = x2 - 1;
				y2 = y2 - 1;

		} else if(x2 < 0 || y2 < 0) {

				cin.clear();
				cin.ignore(100, '\n');

				cerr << "Invalid: (Enter Positive Integers)" << endl;

				cout << "Part 2 Enter row and column index (1-4): ";
				cin >> x2 >> y2;
				cout << endl;

				x2 = x2 - 1;
				y2 = y2 - 1;


		} else if(cin.fail()) {

				cin.clear();
				cin.ignore(100, '\n');

				cerr << "Invalid: (Enter Positive Integers)" << endl;

				cout << "Part 2 Enter row and column index (1-4): ";
				cin >> x2 >> y2;
				cout << endl;

				x2 = x2 - 1;
				y2 = y2 - 1;

			} else if (x2 > 3 || y2 > 3) {

				cin.clear();
				cin.ignore(100, '\n');

				cerr << "Invalid: (Number Out of Range)" << endl;

				cout << "Part 2 Enter row and column index (1-4): ";
				cin >> x2 >> y2;
				cout << endl;

				x2 = x2 - 1;
				y2 = y2 - 1;

			} else if(x == x2 && y == y2) {

				cin.clear();
				cin.ignore(100, '\n');

				cerr << "Invalid: Already Entered" << endl;

				cout << "Part 2 Enter row and column index (1-4): ";
				cin >> x >> y;
				cout << endl;

				x = x - 1;
				y = y - 1;
			}

			else {

				_bool[x2][y2] = true;

				isInvalid = true;
			}
		}

		if (_char[x][y] == _char[x2][y2]) {

			_bool[x][y] = true;
			_bool[x2][y2] = true;

			outputBoard(_char, _bool);
			
			cout << endl;
			cout << "Match found!" << endl;

			result = true;

			


		} else if(_char[x][y] != _char[x2][y2]) {

			_bool[x][y] = true;
			_bool[x2][y2] = true;

			outputBoard(_char, _bool);

			cout << endl;
			cout << "No match found!" << endl;

			_bool[x][y] = false;
			_bool[x2][y2] = false;

			result = false;
			

		}

		return result;

	}

/*

FUNCTION NAME: populateArray

PARAMETERS: ifstream variable containing txt file, an array of char values;

RETURN TYPE: void;

DESCRIPTION: this function will take in the .txt file stream and check for errors in case the file doesn't exist
if the file exists it recursivley call the function and loop through the txt file and assign into char array;
*/

void populateArray(ifstream&, char ARR[ROWS][COLS]) {

	ifstream inFile;
	string inputFile;

	cout << "Enter input file: ";
	cin >> inputFile;

	inFile.open(inputFile);

	while(!inFile.eof()) {

		if(inFile.fail()) {

			cin.clear();
			cin.ignore(100, '\n');
			inFile.clear();
			inFile.ignore(100, '\n');

			cerr << "File not found"<< endl;

			populateArray(inFile, ARR);

		} else {

				for(int i = 0; i < ROWS; i++) {
					for(int j = 0; j < COLS; j++) {
						inFile >> ARR[i][j];
					}
				}
		}

	}
	inFile.close();
	return;
}


/*

FUNCTION NAME: outputBoard

PARAMETERS: the char array from the file input stream, an array of bool values

RETURN TYPE: void - used in makeAMatch function;

DESCRIPTION: this function will loop and output the contents of the char array and do a check with a 
bool value in the bool array. If the bool val is false return an "_", otherwise return the character if true;

*/

void outputBoard(char charARR[ROWS][COLS], bool boolARR[ROWS][COLS]) {
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				if (boolARR[i][j] == false) {
					cout << "_" << " ";
				} else if (boolARR[i][j] == true) {
					cout << charARR[i][j] << " ";
				}
			}
			cout << endl;
		}
		return;
}
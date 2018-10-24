// problem 8.7 from the textbook

#include <iostream>
using namespace std;
const int MATRIX_SIZE = 100;

void fillMatrix(int matrix[][MATRIX_SIZE],int dimension,int minVal,int maxVal) {
	for (int row = 0; row < dimension; row++) {
		for (int col = 0; col < dimension; col++) {
			matrix[row][col] = minVal + rand() % (maxVal - minVal + 1);
		}
	}
}
void displayMatrix(const int matrix[][MATRIX_SIZE], int dimension) {
	for (int row = 0; row < dimension; row++) {
		for (int col = 0; col < dimension; col++) {
			cout << matrix[row][col];
		}
		cout << endl;
	}
	cout << endl;
}

int findRowAlltheSame(int matrix[][MATRIX_SIZE], int dimension, int seekValue, int rowsFound[]) {
	int foundRowNum=0;
	int counter=0;
	int foundCounter=0;


	for (int row = 0; row < dimension; row++) {
		for (int col = 0; col < dimension && matrix[row][col] == seekValue; col++) {
			if (matrix[row][col] == seekValue)
				counter++;
		}
		if (counter == dimension) {
			foundRowNum++;
			rowsFound[foundCounter] = row;   // we can use foundRowNum variable as our index. in this case foundRowNum++; has to be moved after this line.
			foundCounter++;
		}
		counter = 0;
	}
	return foundRowNum;
}

int findColAlltheSame(int matrix[][MATRIX_SIZE], int dimension, int seekValue, int colsFound[]) {
	int foundColNum=0;
	int counter = 0;
	int foundCol = 0;

	for (int col = 0; col < dimension; col++) {
		int row = 0;
		while (row < dimension && matrix[row][col] == seekValue) {
			if (matrix[row][col] == seekValue)
				counter++;
			row++;
		}
		if (counter==dimension) {
			foundColNum++;
			colsFound[foundCol++] = col;
		}
		counter = 0;
	}
	
	return foundColNum;
}

int main()
{
	
	int matrix[MATRIX_SIZE][MATRIX_SIZE];
	int dimension;
	int rowsFound[MATRIX_SIZE];
	int colsFound[MATRIX_SIZE];
	int foundRowNum, foundColNum;

	do {
		cout << "Please enter the dimension of your matrix: ";
		cin >> dimension;
		if (dimension < 2)
			cout << "Enter a value greater than 1" << endl;
	} while (dimension < 2); // The matrix can be at least 2 x 2.
	

	fillMatrix(matrix,dimension,0,1); // fills the matrix with random 0 or 1.

	displayMatrix(matrix, dimension); // displays in the console the randomly filled matrix.
	
	foundRowNum=findRowAlltheSame(matrix, dimension, 0, rowsFound); //finds all rows in matrix with all 0's. This function returns the number of rows that is found also the indexs of those rows are returned in the array rowsFound.
	if (foundRowNum == 0)
		cout << "No row of all 0\'s was found." << endl;
	else if (foundRowNum == 1) // my message is different if 1 row is found
		cout << foundRowNum << " row of all 0\'s was found. It is row #" << rowsFound[0] + 1 << endl;
	else {  // the following message in case several rows are found
		cout << foundRowNum << " rows of all 0\'s were found. They are rows #" << rowsFound[0] + 1;
		for (int rows = 1; rows <= foundRowNum; rows++)
			cout << ", #" << rowsFound[rows] + 1;
		cout << endl;
	}
		
	foundRowNum = findRowAlltheSame(matrix, dimension, 1, rowsFound); //finds all rows in matrix with all 1's. This function returns the number of rows that is found also the indexs of those rows are returned in the array rowsFound.
	if (foundRowNum == 0)
		cout << "No row of all 1\'s was found." << endl;
	else if (foundRowNum == 1) // my message is different if 1 row is found
		cout << foundRowNum << " row of all 1\'s was found. It is row #" << rowsFound[0]+1 << endl;
	else {  // the following message in case several rows are found
		cout << foundRowNum << " rows of all 1\'s were found. They are rows #" << rowsFound[0] + 1;
		for (int rows = 1; rows <= foundRowNum; rows++)
			cout << ", #" << rowsFound[rows] + 1;
		cout << endl;
	}
	// I did not write extra code to display columns as I did above for rows.
	// It can be a good idea to write a function that gets as input rowsFound or colsFound array
	foundColNum =findColAlltheSame(matrix,dimension,0,colsFound);
	cout << foundColNum << " col(s) found all 0\'s" << endl;
	
	foundColNum = findColAlltheSame(matrix, dimension, 1, colsFound);
	cout << foundColNum << " col(s) found all 1\'s" << endl;

	return 0;
}


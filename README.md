# JaggedArray
Create a jagged array (an array of arrays) with emphasis on Dynamic Memory Allocation, Data Parsing and Memory Cleanup

README for Jagged Array Program
Overview
This program allows users to create a jagged array (an array of arrays) in C++. The jagged array can be populated in two ways:

From a file: The program reads data from a text file and stores it in a jagged array.
From terminal input: The user manually enters the array data through the terminal.

Key Features:
Dynamic Memory Allocation: The program dynamically allocates memory for each row and column of the jagged array.
Data Parsing: It reads numbers either from a file or terminal input and stores them as integer elements in the jagged array.
Memory Cleanup: The program ensures that memory is properly deallocated after use to avoid memory leaks.

How to Run
Compilation: To compile the program, use a C++ compiler like g++.
g++ -o main main.cpp

Run the Program: Once compiled, you can run the program with:
./main


Populating the Array:
From File: The program reads from a file named input.txt. Ensure that the file is in the same directory as the executable, or provide the absolute path in the populateFromFile() function.
From Terminal: If you'd like to input data from the terminal, comment out the populateFromFile() function and uncomment the populateFromTerminal() function.
View the Array: Once the array is populated, you can view it using the printArr() function.

Functions
clearArray(int*** array, int** Cols, int Rows)
Frees the dynamically allocated memory for the jagged array.
Prints a message when memory is cleared.
populateFromFile(std::string filename)
Reads a text file and parses the data to fill the jagged array. Each row can have a different number of columns.
The file should contain rows of numbers, where each row represents a new row in the jagged array.
populateFromTerminal()
Allows the user to manually input data for the jagged array.
The user is prompted to input the number of rows and columns, and then enter values for each row.
printArr()
Prints the jagged array in a human-readable format.
Each row is printed on a new line, and the elements in a row are separated by commas.
printArrStructure()
Prints the structure of the jagged array, showing the number of rows and the number of columns for each row.
main()
The main function, where the user can choose whether to populate the array from a file or from terminal input.
Currently, the program is set to populate the array from a file (specified as "input.txt").

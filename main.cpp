#include <fstream>
#include <iostream>
#include <sstream>

int*** myArr = NULL;
int** numCols = NULL;
int numRows = 0;

void clearArray(int*** array, int** Cols, int Rows) 
{
    for (int i = 0;i < Rows; i++) // iterates each element in row
    {
        for (int j = 0; j < (*Cols[i]) ; j++) //iterate each element in column of the current row
        {
            delete [] array[i][j]; // deletes each element in column of the current row
        }
    }

    for (int i = 0;i < Rows; i++)
    {
        delete [] array[i]; //deletes each element in the rows
    }

    delete [] array;

    delete [] Cols;

    std::cout << "Deleted array with "<< Rows <<" rows" << std::endl;
}

void populateFromFile(std::string filename) 
{
    std::fstream file (filename.c_str());

    if (file.is_open())
    {
        std:: string line;
        // get the number of rows
        while(getline(file, line))
            {
                std::cout << line << std::endl;
                numRows++;
            }
        // alocate memory for number of rowa
        numCols = new int *[numRows];
        myArr= new int **[numRows];

        file.clear();
        file.seekg(0); // takes you back to the top of the file

        int i=0;
        int numCount =0;
        int counter=0; 

        // get number of columns for each row
        while(getline(file, line)) 
        {   
            {   
                while (i<line.length())
                {
                    if (isdigit(line[i]))
                    {
                        if (i== 0 || !isdigit(line[i-1]))
                        {
                            numCount++;
                            
                        }
                    }
                    i++;
                }
                
                //alocate memory for each colums
                //std :: cout << "Row has "<< numCount << std:: endl;
                numCols[counter]= new int (numCount);
                myArr[counter]= new int *[numCount];
         
            }
            counter++;
            i=0;
            numCount=0;
        }

        file.clear();
        file.seekg(0); // takes you back to the top of the file

        //fill the array you created 
        
        for (int row = 0; row < numRows; row++)
        {
            for ( int col=0; col < *numCols[col]; col++)
            {
                while(getline(file ,line) && row < numRows)
                {     
                    std::stringstream read(line);
                    std::string firstword;
                    int word;
                    read << firstword;
                    std::cout << firstword << std::endl;
                    read >> word;
                    std::cout<< word <<std::endl;
                    int col=0;
                    myArr[row][col] = new int (word);
                    line.erase (i, 1);
                    
                }
            }
        
            file.close();
        }
    }
        
    else 
    {
        std:: cout << "ERROR OPENING FILE"<< std::endl;
    }
        
    std::cout << "Created array from textfile with "<< numRows <<" rows"<< std::endl;
}

void populateFromTerminal() 
{
    // get the number of rows
    std::cout << "Enter the number of rows for the jagged array" << std :: endl;
    std ::cin >> numRows;

    std::cin.ignore();

    // allocate memory for the number of rows
    numCols = new int *[numRows];
    myArr= new int **[numRows];

    //get the number of columns
    std::string line;
    int counter =0;
    int numcount =0;
    
    for (int i=0; i< numRows; i++)
    {
        std::cout << "Enter values for row "<< i+1 << " seperated by comma" << std::endl;
        getline(std::cin ,line);
    
        for (int j=0; j< line.length(); j++)
        {
            if ( isdigit(line[j]) && !isdigit(line[j-1]))
            {
                numcount ++;
            }
        }

        //alocate memory for the number of columns
        std::cout << numcount << std::endl;
        numCols[counter]= new int (numcount);
        myArr[counter]= new int *[numcount];
        numcount=0;
        counter++;
    }

    //fill the array created 
    for (int i=0; i< numRows ; i++)
        {
            for (int j=0; j< line.length(); j++)
                {
                    getline (std::cin, line);
                    std::stringstream read(line);
                    std::string firstword;
                    int word;
                    read << firstword;
                    read >> word;
                    myArr[i][j]= new int (word);
                    line.erase (i, 1);
                    firstword[j]++;
                }   
            
        }

    std::cout << "Created array from terminal with "<< numRows<< " rows"<< std:: endl;
}

void printArr()
{
    if (myArr==NULL)
    {
        std:: cout << "Array is empty "<< std:: endl;
    }

    else 
    {
        for (int i=0; i < numRows;i++)
        {
            if (numCols[i] == 0)
            {
                std::cout << std:: endl;
            }
            else 
            {
                for (int j=0; j< *numCols[i];j++)
                {
                    std :: cout << *myArr[i][j] ;
                    if (j< *numCols[i]-1)
                    {
                        std::cout<< ",";
                    }
                }

                std :: cout <<std :: endl;
            }
        } 
    }
}

void printArrStructure() 
{
    if (myArr =NULL)
    {
        std::cout << " Array is empty" << std :: endl;
    }

    else 
    {
        std :: cout << numRows << " : [" ;
        for (int i=0;i <numRows; i++)
        {
            std::cout << *(numCols[i]);
            if (i < numRows-1)
            {
                std::cout << ",";
            }
        }
        std::cout<< "]"<< std::endl;
    }

}

int main() 
{   
    //printArrStructure();
   // clearArray(myArr, numCols, numRows);
    

    populateFromFile("input.txt");
    //populateFromTerminal();
    std::cout<<"chickens"<< std::endl; 
    printArr();
    return 0;
}
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
  string line, chr;
  int file_length = 5, file_width = 10;

  int grid[file_length+2][file_width+2];
  int i, j;
  int risk = 0;


  ifstream myfile;
  myfile.open("test_input.txt");

    for (i=0; i<file_length+2; i++)
    {
     
      for (j=0; j<file_width+2; j++)
	{
	  grid[i][j] = 9;
	}
    }


  for (i=1; i<file_length+1; i++)
    {
      getline(myfile, line);
      for (j=1; j<file_width+1; j++)
	{
	  chr = line[j-1];
	  grid[i][j] = stoi(chr);
	  
	}
      
    }

  myfile.close();
  for (i=1; i<file_length+1; i++)
    {
      
      for (j=1; j<file_width+1; j++)
	{
	  if ((grid[i][j+1]>grid[i][j])&&(grid[i][j-1]>grid[i][j])&&(grid[i+1][j]>grid[i][j])&&(grid[i-1][j]>grid[i][j]))
	    {
	      risk += grid[i][j]+1;
	    }
				  
	}
    }
  printf("%d\n", risk);
}

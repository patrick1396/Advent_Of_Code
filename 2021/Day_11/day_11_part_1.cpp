#include <iostream>
#include <fstream>
using namespace std;


int increment(int octo_grid[10][10], int i, int j)
{
  if (((i>=0)&&(i<=9))&&((j>=0)&&(j<=9)))
    {
      if (octo_grid[i][j] < 10)
	{
	  octo_grid[i][j]++;
	  if (octo_grid[i][j]==10)
	    {
	      increment(octo_grid,i, j+1);
	      increment(octo_grid,i, j-1);
	      increment(octo_grid,i+1, j);
	      increment(octo_grid,i-1, j);
	      increment(octo_grid,i+1, j+1);
	      increment(octo_grid,i-1, j+1);
	      increment(octo_grid,i+1, j-1);
	      increment(octo_grid,i-1, j-1);
	    }
	}
    }
  return 0;
}


int main()
{
  string line, chr;
  int file_length = 10, file_width = 10;
  int octo_grid[10][10];
  int i, j, step, flashes = 0;
  
  ifstream myfile;
  myfile.open("input.txt");
  
  
  for (i=0; i<file_length; i++)
    {
      getline(myfile, line);
      for (j=0; j<file_width; j++)
	{
	  chr = line[j];
	  octo_grid[i][j] = stoi(chr);
	  printf("%d", octo_grid[i][j]);
	}
      printf("\n");

    }
  myfile.close();

  for (step=0; step<100; step++)
    {
      printf("%d\n", step+1);
      //Increment values
      for (i=0; i<file_length; i++)
	{
	  getline(myfile, line);
	  for (j=0; j<file_width; j++)
	    {
	      increment(octo_grid, i, j);
	    }
	}
      //Count flashes and set to 0
      for (i=0; i<file_length; i++)
	{
	  getline(myfile, line);
	  for (j=0; j<file_width; j++)
	    {
	      if (octo_grid[i][j]>9)
		{
		  octo_grid[i][j] = 0;
		  flashes++;
		}
	      printf("%d", octo_grid[i][j]);
	    }
	  printf("\n");
	}
      printf("\n");
    }

  printf("%d\n", flashes);

}

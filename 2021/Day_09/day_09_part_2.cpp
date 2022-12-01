#include <iostream>
#include <fstream>
using namespace std;


int main()
{
  string line, chr;
  int file_length = 100, file_width = 100;

  int grid[2][file_length+2][file_width+2];
  int* min;
  int i, j, x, y, x_low, y_low;
  int risk = 0;
  int max_1 = 0, max_2 = 0, max_3 = 0;
  bool min_found;


  ifstream myfile;
  myfile.open("input.txt");

    for (i=0; i<file_length+2; i++)
    {
     
      for (j=0; j<file_width+2; j++)
	{
	  grid[0][i][j] = 9;
	  grid[1][i][j] = -1;
	}
    }


  for (i=1; i<file_length+1; i++)
    {
      getline(myfile, line);
      for (j=1; j<file_width+1; j++)
	{
	  chr = line[j-1];
	  grid[0][i][j] = stoi(chr);
	  
	}
      
    }

  myfile.close();
  for (i=1; i<file_length+1; i++)
    {
      
      for (j=1; j<file_width+1; j++)
	{
	  if ((grid[0][i][j+1]>grid[0][i][j])&&(grid[0][i][j-1]>grid[0][i][j])&&(grid[0][i+1][j]>grid[0][i][j])&&(grid[0][i-1][j]>grid[0][i][j]))
	    {
	      grid[1][i][j] = risk;
	      risk++;
	    }
				  
	}
    }

  min = new int[risk];

  for (i=0; i<risk; i++)
    {
      min[i] = 0;
    }
  

  for (i=1; i<file_length+1; i++)
    {
      for (j=1; j<file_width+1; j++)
	{
	  if (grid[0][i][j]!=9)
	    {
	      x = j;
	      y = i;

	      min_found = false;
	      while(min_found==false)
		{
		  
		  if (grid[1][y][x]>-1)
		    {
		      grid[1][i][j] = grid[1][y][x];
		      min[grid[1][y][x]]++;
		      min_found = true;
		    }
		  else
		    {
		      x_low = x;
		      y_low = y;

		      if(grid[0][y][x+1]<grid[0][y_low][x_low])
			{
			  y_low = y;
			  x_low = x+1;
			}

		      if(grid[0][y][x-1]<grid[0][y_low][x_low])
			{
			  y_low = y;
			  x_low = x-1;
			}

		      if(grid[0][y+1][x]<grid[0][y_low][x_low])
			{
			  y_low = y+1;
			  x_low = x;
			}

		      if(grid[0][y-1][x]<grid[0][y_low][x_low])
			{
			  y_low = y-1;
			  x_low = x;
			}

		      x = x_low;
		      y = y_low;
		    }
		}
	    }
	}
    }

  for (i=0; i<risk; i++)
    {
      if (min[i]>max_1)
	{
	  max_3 = max_2;
	  max_2 = max_1;
	  max_1 = min[i];
	}
      else if (min[i]>max_2)
	{
	  max_3 = max_2;
	  max_2 = min[i];
	}
      else if (min[i]>max_3)
	{
	  max_3 = min[i];
	}
    }


  printf("%d\n", max_1*max_2*max_3);
}

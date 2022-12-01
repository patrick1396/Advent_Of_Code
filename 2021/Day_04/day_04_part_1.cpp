#include <iostream>
#include <fstream>
using namespace std;


int main()
{
  string line, frst_line;
  int file_length = 601;
  int file_read = (file_length-1)/6;
  int search_num;
  int grid [file_read][2][5][5];
  int width = -1, grid_width;
  int len;
  int comma_pos = 0, space_pos;
  int i, j, k, l;
  int counter = 0;
  int row_sum, col_sum, un_mrk_sum = 0;
  bool found, bingo = false;
  
  ifstream myfile;
  myfile.open("input.txt");
  
  getline(myfile, frst_line);
  //  in_int = stoi(line);
  cout << frst_line << "\n" << "\n";

  for (i=0; i<file_read; i++)
    {

      getline(myfile, line);
      for (j=0; j<5; j++)
	{

	  getline(myfile, line);
	  grid_width = -1;

	  
	  for (k=0; k<5; k++)
	    {
	      grid_width++;

	      space_pos = line.find(" ", grid_width+1);

	      search_num  = stoi(line.substr(grid_width, space_pos-grid_width));
	      grid_width = space_pos;

	      grid[i][0][j][k] = search_num;
	      grid[i][1][j][k] = 0;
		
	    }
	  
	}
    }
  myfile.close();



  
  len = frst_line.length();
  while ((width<len)&&(bingo==false))
    {
      width++;
      counter++;
      comma_pos = frst_line.find(",", width+1);
      if (comma_pos<0)
      	{
      	  search_num = stoi(frst_line.substr(width, string::npos));
  	  width = len;
      	}
      else
      	{
  	  search_num  = stoi(frst_line.substr(width, comma_pos-width));
  	  width = comma_pos;
  	}


      for (i=0; i<file_read; i++)
	{
	  found = false;
	  for (j=0; j<5; j++)
	    {
	      for (k=0; k<5; k++)
		{
		  if (grid[i][0][j][k] == search_num)
		    {
		      grid[i][1][j][k] = 1;
		      found = true;
		    }

		  if (counter>4)
		    {
		      row_sum = 0;
		      col_sum = 0;
		      for (l=0; l<5; l++)
			{
			  row_sum += grid[i][1][j][l];
			  col_sum += grid[i][1][l][k];
			}
		      if ((row_sum==5)||(col_sum==5))
			{
			  bingo = true;
			}
		    }
		  
		  if (found==true)
		    {
		      break;
		    }
		}
	      if (found==true)
		{
		  break;
		}
	    }
	  if (bingo==true)
	    {
	      break;
	    }
	}
    }





  for (j=0; j<5; j++)
    {
      for (k=0; k<5; k++)
	{
	  if (grid[i][1][j][k]==0)
	    {
	      un_mrk_sum += grid[i][0][j][k];
	    }
	}
    }
  printf("%d, %d, %d\n", un_mrk_sum, search_num, un_mrk_sum*search_num);
}






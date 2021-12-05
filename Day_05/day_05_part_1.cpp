#include <iostream>
#include <fstream>
using namespace std;


int main()
{
  string line, number;
  int file_length = 10;
  int coords[file_length][4];
  int *grid;
  int f_com=0, s_com=0, f_spc=0, s_spc=0;
  int i, j;
  int y_max = 0, x_max = 0;
  int start, end, con;
  
  ifstream myfile;
  myfile.open("test_input.txt");
  
  
  for (i=0; i<file_length; i++)
    {
      f_com=0;
      s_com=0;
      f_spc=0;
      s_spc=0;

      getline(myfile, line);
      f_com = line.find(",", 0);
      s_com = line.find(",", f_com+1);
      f_spc = line.find(" ", 0);
      s_spc = line.find(" ", f_spc+1);

      coords[i][0] = stoi(line.substr(0, f_com));
      if (coords[i][0] > x_max)
	{
	  x_max = coords[i][0];
	}
      coords[i][1] = stoi(line.substr(f_com+1, f_spc-f_com));
      if (coords[i][1] > y_max)
	{
	  y_max = coords[i][1];
	}
      coords[i][2] = stoi(line.substr(s_spc+1, s_com-s_spc-1));
      if (coords[i][2] > x_max)
	{
	  x_max = coords[i][2];
	}
      coords[i][3] = stoi(line.substr(s_com+1, string::npos));
      if (coords[i][3] > y_max)
	{
	  y_max = coords[i][3];
	}
      printf("%d %d %d %d\n", coords[i][0], coords[i][1], coords[i][2], coords[i][3]);
    }

  grid = new int[x_max*y_max];

  for (i=0; i<x_max*y_max; i++)
    {
      grid[i] = 0;
    }

  for (i=0; i<file_length; i++)
    {
      if (coords[i][0]==coords[i][2])
  	{
	  con = coords[i][0];
	  if (coords[i][1]<coords[i][3])
	    {
	      start = coords[i][1];
	      end = coords[i][3];
	    }
	  else
	    {
	      start = coords[i][3];
	      end = coords[i][1];
	    }


  	}
      else if (coords[i][1]==coords[i][3])
  	{
	  con = coords[i][1];
	  if (coords[i][0]<coords[i][2])
	    {
	      start = coords[i][0];
	      end = coords[i][2];
	    }
	  else
	    {
	      start = coords[i][2];
	      end = coords[i][0];
	    }


	  
  	}
    }

  cout << "\n";
  for (i=0; i<x_max*y_max; i++)
    {
      cout << grid[i] << " ";
      if (i%x_max==x_max-1)
	{
	  cout << "\n";
	}
    }
  
  myfile.close();

}

#include <iostream>
#include <fstream>
using namespace std;


int main()
{
  string line, sub, axis;
  int coords_length = 983;
  int i, j, chr_pos, pos, dim;
  int coords[coords_length][3], hold[3];
  int num_dots = 0, prev = -1;
  
  ifstream myfile;
  myfile.open("input.txt");
  
  
  for (i=0; i<coords_length; i++)
    {
      getline(myfile, line);

      chr_pos = line.find(",", 0);

      sub = line.substr(0,chr_pos);

      coords[i][0] = stoi(sub);
      sub = line.substr(chr_pos+1);
      coords[i][1] = stoi(sub);
      coords[i][2] = 0;
    }

  getline(myfile, line);
  getline(myfile, line);

  chr_pos = line.find("=", 0);
  axis = line[chr_pos-1];
  sub = line.substr(chr_pos+1);
  pos = stoi(sub);

  myfile.close();

  if (axis=="x")
    {
      dim = 0;
    }
  else if (axis=="y")
    {
      dim = 1;
    }
    
  
  for (i=0; i<coords_length; i++)
    {
      if (coords[i][dim]>pos)
	{
	  coords[i][dim] -= 2*(coords[i][dim]-pos);
	}
      coords[i][2] = ((coords[i][0]+coords[i][1])*(coords[i][0]+coords[i][1]+1)+coords[i][1])/2;
    }


  
  for (i=0; i<coords_length-1; i++)
    {
      for (j = 0; j<coords_length-1-i; j++)
	{
	  if (coords[j][2]>coords[j+1][2])
	    {
	      hold[0] = coords[j][0];
	      hold[1] = coords[j][1];
	      hold[2] = coords[j][2];
	      
	      coords[j][0] = coords[j+1][0];
	      coords[j][1] = coords[j+1][1];
	      coords[j][2] = coords[j+1][2];
	      
	      coords[j+1][0] = hold[0];
	      coords[j+1][1] = hold[1];
	      coords[j+1][2] = hold[2];
	    }
	}
    }

  for (i=0; i<coords_length; i++)
    {
      if (coords[i][2]!=prev)
	{
	  num_dots++;
	  prev = coords[i][2];
	}
    }

  printf("%d\n", num_dots);
  
}

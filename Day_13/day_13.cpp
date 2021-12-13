#include <iostream>
#include <fstream>
using namespace std;


int main()
{
  string line, sub, axis;
  int coords_length = 983, fold_length = 996;
  int i, j, k, chr_pos, pos, dim;
  int coords[coords_length][3], hold[3];
  int search_item;
  int max_x = 0, max_y = 0;
  bool found;
  
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


  for (k = 0; k<fold_length-coords_length-1; k++)
    {
      getline(myfile, line);

      chr_pos = line.find("=", 0);
      axis = line[chr_pos-1];
      sub = line.substr(chr_pos+1);
      pos = stoi(sub);
      cout << axis << " " << pos << "\n";

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
	  coords[i][2] = (coords[i][0]+coords[i][1])*(coords[i][0]+coords[i][1]+1)/2+coords[i][1];
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

    }
  
  myfile.close();

  
  
  for (i=0; i<coords_length; i++)
    {
      //cout << coords[i][0] << " " << coords[i][1] << " " << coords[i][2] << "\n";
      if (coords[i][0] > max_x)
	{
	  max_x = coords[i][0];
	}
      if (coords[i][1] > max_y)
	{
	  max_y = coords[i][1];
	} 
    }

  cout << max_x << " " << max_y << "\n";
  for (i=0; i<max_y+1; i++)
    {
      for (j=0; j<max_x+1; j++)
	{

	  search_item = (j+i)*(j+i+1)/2+i;
	  found = false;
	  
	  for (k = 0; k<coords_length; k++)
	    {
	      if (search_item == coords[k][2])
		{
		  found = true;
		  //cout << search_item << " " << coords[k][2] << "\n";
		  break;
		}
	      else if (search_item < coords[k][2])
		{
		  found = false;
		  break;
		}
	    }

	  if (found == true)
	    {
	      cout << "#";
	    }
	  else
	    {
	      cout << ".";
	    }
      
	}
      cout << "\n";
    }

  
}

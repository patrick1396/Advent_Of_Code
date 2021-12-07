#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int quick_sort(int* sort_array, int min_indx, int max_indx)
{
  int swap_hold;
  int swap_indx;
  int i;

  if (min_indx<max_indx)
    {
      swap_indx = min_indx;
      for (i=min_indx; i<max_indx; i++)
	{
	  if (sort_array[i]<sort_array[max_indx])
	    {
	      swap_hold = sort_array[i];
	      sort_array[i] = sort_array[swap_indx];
	      sort_array[swap_indx]=swap_hold;
	      swap_indx += 1;
	    }
	}
      swap_hold = sort_array[max_indx];
      sort_array[max_indx] = sort_array[swap_indx];
      sort_array[swap_indx] = swap_hold;

      quick_sort(sort_array, min_indx, swap_indx-1);
      quick_sort(sort_array, swap_indx+1, max_indx);
    }
  return 0;
}


int main()
{
  string line;
  int width, len, com_pos;
  int num_comma = 0;
  int* pos;
  
  int i, j, k;
  int diff;
  long long int fuel = 0;
  int contr;
  double mean = 0.0;
  
  ifstream myfile;
  myfile.open("input.txt");
  
  getline(myfile, line);
  //cout << line << "\n" << "\n";

  myfile.close();

  width = -1;
  len = line.length();
  while(width<len)
    {
      width++;
      com_pos = line.find(",", width+1);
      if (com_pos<0)
      	{
  	  width = len;
      	}
      else
      	{
  	  width = com_pos;
	  
  	}
      num_comma++;
    }

  pos = new int[num_comma];
  for (i=0; i<num_comma; i++)
    {
      pos[i] = -1;
    }

  width = -1;
  i = 0;
  for (i=0; i<num_comma; i++)
    {
      width++;
      com_pos = line.find(",", width+1);
      
      pos[i] = stoi(line.substr(width, com_pos-width));
      width = com_pos;
      mean += pos[i];
    }
  mean /= num_comma;
  cout << mean << "\n";
  mean--;

  // for (i=0; i<pos[num_comma-1]; i++)
  //   {
  fuel = 0;
      for (j=0; j<num_comma; j++)
	{
	  diff = abs(pos[j]-int(round(mean)));
	  contr = 0;
	  for (k=1; k<=diff; k++)
	    {
	      contr += k;
	    }
	  //cout << pos[j] << " " << contr << "\n";
	  fuel += contr;
	}
      //cout << pos[i] << " " << fuel << "\n";
    // if (fuel<min_fuel)
    //   {
    //    min_fuel = fuel;
    //    mean = i;
    //   }
    // }
  
  
      cout << fuel << " " << int(round(mean)) << "\n";

  
  
}

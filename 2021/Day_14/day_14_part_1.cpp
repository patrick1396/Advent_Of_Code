#include <iostream>
#include <fstream>
using namespace std;


int quick_sort(string sort_array[], int min_indx, int max_indx)
{
  string swap_hold;
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
  int file_length = 16, len;
  string line, poly, poly_next, pair, hold;
  string insrt[file_length][2];
  string *poly_complete;
  int i, j, k, space_pos;
  long long int most_com, least_com, count;
  
  ifstream myfile;
  myfile.open("test_input.txt");
  
  getline(myfile, poly);
  cout << poly << "\n";
  getline(myfile, line);
  
  for (i=0; i<file_length; i++)
    {
      getline(myfile, line);
      
      space_pos = line.find(" ", 0);
      insrt[i][0] = line.substr(0, space_pos);

      space_pos = line.find(" ", space_pos+1);
      insrt[i][1] = line.substr(space_pos+1);

      
    }
  myfile.close();

  for (i=0; i<40; i++)
    {
      poly_next = "";
      len = poly.length();
      for (j=0; j<len-1; j++)
	{
	  pair = "";
	  poly_next += poly[j];
	  pair += poly[j];
	  pair += poly[j+1];
	  for (k=0; k<file_length; k++)
	    {
	      if (pair==insrt[k][0])
		{
		  poly_next += insrt[k][1];
		  break;
		}
	    }
	}
      poly_next += poly[len-1];
      poly = poly_next;
      //cout << poly << "\n";
    }

  cout << "insert done\n";
  len = poly.length();
  poly_complete = new string [len];

  for (i = 0; i<len; i++)
    {
      poly_complete[i] = poly[i];
    }

  // for (i=0; i<len-1; i++)
  //   {
  //     for (j = 0; j<len-1-i; j++)
  // 	{
  // 	  if (poly_complete[j]>poly_complete[j+1])
  // 	    {
  // 	      hold = poly_complete[j];
	      
  // 	      poly_complete[j] = poly_complete[j+1];
	      
  // 	      poly_complete[j+1] = hold;

  // 	    }
  // 	}
  //   }
  quick_sort(poly_complete, 0, len-1);
  cout << "sort done\n";
  
  most_com = 0;
  least_com = len;
  hold = poly_complete[0];
  count = 0;
  for (i = 0; i<len; i++)
    {
      if (poly_complete[i]!=hold)
	{
	  if (count>most_com)
	    {
	      most_com = count;
	    }
	  else if(count<least_com)
	    {
	      least_com = count;
	    }
	  cout << hold << " " << count << "\n";
	  count = 0;
	  hold = poly_complete[i];
	}
      count++;
    }
  cout << hold << " " << count << "\n";

  cout << most_com-least_com << "\n";
  cout << "count done\n";
}

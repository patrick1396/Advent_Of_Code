#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;


int main()
{
  string line, sub_str;
  string pre_bar[10], post_bar[4], numbers[10], other[6];
  string hold4, hold7;
  int len4, len7;
  int file_length = 200;
  int width, bar, len, spc_pos, sub_len, char_pos;
  int tot_num = 0, num = 0;
  int i, j, f, s, file;
  bool found;
  
  ifstream myfile;
  myfile.open("input.txt");

  for (file=0; file<file_length; file++)
    {
      cout << file << "\n";
      getline(myfile, line);
      
      spc_pos = 0;
      width = -1;
      bar = line.find("|", 0);
      j = 0;
      while(width<bar-1)
	{
	  width++;
	  spc_pos = line.find(" ", width+1);
	  sub_str  = line.substr(width, spc_pos-width);
	  width = spc_pos;
	  sub_len = sub_str.length();
	  pre_bar[j] = sub_str;

	  j++;
	}

      len = line.length();
      width++;
      width++;
      j = 0;
      while(width<len)
	{
	  width++;
	  spc_pos = line.find(" ", width+1);
	  if (spc_pos<0)
	    {
	      sub_str = line.substr(width, string::npos);
	      width = len;
	    }
	  else
	    {
	      sub_str  = line.substr(width, spc_pos-width);
	      width = spc_pos;
	    }
	  post_bar[j] = sub_str;

	  j++;
	}

      f = 0;
      s = 0;
      for (j=0; j<10; j++)
	{
	  sub_len = pre_bar[j].length();
	  
	  if (sub_len==2)
	    {
	      numbers[1] = pre_bar[j];
	    }
	  else if (sub_len==3)
	    {
	      numbers[7] = pre_bar[j];
	    }
	  else if (sub_len==4)
	    {
	      numbers[4] = pre_bar[j];
	    }
	  else if (sub_len==7)
	    {
	      numbers[8] = pre_bar[j];
	    }
	  else if ((sub_len == 5)||(sub_len == 6))
	    {
	      other[f] = pre_bar[j];
	      f++;
	    }

	}
      cout << "<>\n";

      for (f=0; f<6; f++)
	{
	  hold4 = other[f];
	  hold7 = other[f];

	  for (j=0; j<4; j++)
	    {
	      char_pos = hold4.find(numbers[4][j], 0);
	      
	      if (char_pos!=-1)
		{
		  hold4.erase(char_pos, 1);
		}
	    }
	      

	  for (j=0; j<3; j++)
	    {
	      char_pos = hold7.find(numbers[7][j], 0);
	      
	      if (char_pos!=-1)
		{
		  hold7.erase(char_pos, 1);
		}
	    }
	  cout << other[f] << " " << hold4 << " " << hold7 << "\n"; 
	  
	  len4 = hold4.length();
	  len7 = hold7.length();
	  len = other[f].length();
	  if ((len4==2)&&(len==6))
	    {
	      numbers[9] = other[f];
	    }
	  else if ((len7==2)&&(len==5))
	    {
	      numbers[3] = other[f];
	    }
	  else if ((len4==3)&&(len7==4))
	    {
	      numbers[6] = other[f];
	    }
	  else if ((len4==2)&&(len7==3))
	    {
	      numbers[5] = other[f];
	    }
	  else if ((len4==3)&&(len7==3)&&(len==6))
	    {
	      numbers[0] = other[f];
	    }
	  else if ((len4==3)&&(len7==3)&&(len==5))
	    {
	      numbers[2] = other[f];
	    }
	}
      cout << "<>\n";

      for (j=0; j<10; j++)
	{
	  cout << j << " " << numbers[j] << "\n";
	}


      num = 0;
      for (i = 0; i<4; i++)
	{
	  sub_len = post_bar[i].length();
	  found = false;
	  j=-1;
	  while (found==false)
	    {
	      j++;
	      found = true;
	      len = numbers[j].length();
	      if (sub_len == len)
		{
		  for(s=0; s<sub_len; s++)
		    {
		      char_pos = numbers[j].find(post_bar[i][s], 0);
		      if (char_pos==-1)
			{
			  found = false;
			  break;
			}
		    }
		}
	      else
		{
		  found = false;
		}
	    }
	  num += j*pow(10, 3-i);
	  tot_num += j*pow(10, 3-i);

	  
	}
      printf("%d %d %d\n", file+1, num, tot_num);
      cout << "\n";
      
      
    }
  
  myfile.close();

  printf("%d\n", tot_num);
  
}






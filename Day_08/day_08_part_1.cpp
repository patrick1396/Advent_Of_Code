#include <iostream>
#include <fstream>
using namespace std;


int main()
{
  string line, sub_str;
  int file_length = 200;
  int width, len, spc_pos, sub_len;
  int tot_num = 0;
  int i;
  
  ifstream myfile;
  myfile.open("input.txt");

  for (i=0; i<file_length; i++)
    {
      getline(myfile, line);
      
      spc_pos = 0;
      width = line.find("|", 0);
      width++;
      len = line.length();
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
	  sub_len = sub_str.length();
	  if ((sub_len==2)||(sub_len==3)||(sub_len==4)||(sub_len==7))
	    {
	      tot_num++;
	    }
	}

    }
  
  myfile.close();


  printf("%d\n", tot_num);
}






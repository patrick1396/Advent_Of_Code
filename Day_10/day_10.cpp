#include <iostream>
#include <fstream>
using namespace std;


int main()
{
  string line, sub, add, end;
  int file_length = 90, len, sub_len;
  int i, j;
  int err_tot = 0;
  bool corrupt;
  
  ifstream myfile;
  myfile.open("input.txt");
  
  
  for (i=0; i<file_length; i++)
    {
      getline(myfile, line);
      len = line.length();
      sub = line[0];
      corrupt = false;
      for (j=1; j<len; j++)
	{
	  add = line[j];
	  sub_len = sub.length();
	  if ((add=="(")||(add=="[")||(add=="{")||(add=="<"))
	    {
	      sub += add;
	    }
	  else
	    {
	      end = sub[sub_len-1];
	      if (((end=="(")&&(add==")"))||((end=="[")&&(add=="]"))||((end=="{")&&(add=="}"))||((end=="<")&&(add==">")))
		{
		  sub.erase(sub_len-1,1);
		}
	      else
		{
		  corrupt = true;
		  break;
		}
	    }
	}
      if (corrupt==true)
	{
	  if (add == ")")
	    {
	      err_tot += 3;
	    }
	  else if (add == "]")
	    {
	      err_tot += 57;
	    }
	  else if (add == "}")
	    {
	      err_tot += 1197;
	    }
	  else if (add == ">")
	    {
	      err_tot += 25137;
	    }
	}
    }
  myfile.close();
  printf("Part 1: Total Syntax Error = %d\n", err_tot);
}

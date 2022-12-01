#include <iostream>
#include <fstream>
using namespace std;


int main()
{
  string line, sub, add, end, comp, chr;
  int file_length = 90, len, sub_len;
  int i, j;
  int num_incmplt = 0;
  int err_score = 0;
  long long int auto_score, hold;
  long long int auto_array[file_length];
  bool corrupt;
  
  ifstream myfile;
  myfile.open("input.txt");

  
  
  for (i=0; i<file_length; i++)
    {
      auto_array[i] = 0;
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
	      err_score += 3;
	    }
	  else if (add == "]")
	    {
	      err_score += 57;
	    }
	  else if (add == "}")
	    {
	      err_score += 1197;
	    }
	  else if (add == ">")
	    {
	      err_score += 25137;
	    }
	}
      else
	{
	  num_incmplt ++;
	  sub_len = sub.length();
	  comp = "";
	  for (j=sub_len-1; j>=0; j--)
	    {
	      chr = sub[j];
	      if (chr == "(")
		{
		  comp += ")";
		}
	      else if (chr == "[")
		{
		  comp += "]";
		}
	      else if (chr == "{")
		{
		  comp += "}";
		}
	      else if (chr == "<")
		{
		  comp += ">";
		}
	    }

	  for (j=0; j<sub_len; j++)
	    {
	      auto_array[i] *= 5;
	      
	      chr = comp[j];
	      
	      if (chr == ")")
		{
		  auto_array[i] += 1;
		}
	      else if (chr == "]")
		{
		  auto_array[i] += 2;
		}
	      else if (chr == "}")
		{
		  auto_array[i] += 3;
		}
	      else if (chr == ">")
		{
		  auto_array[i] += 4;
		}
	    }
	}
    }
  myfile.close();


  for (i=0; i<file_length-1; i++)
    {
      for (j = 0; j<file_length-1-i; j++)
	{
	  if (auto_array[j]>auto_array[j+1])
	    {
	      hold = auto_array[j];
	      auto_array[j] = auto_array[j+1];
	      auto_array[j+1] = hold;
	    }
	}
    }

  
  auto_score = auto_array[file_length-(num_incmplt+1)/2];
  
  printf("Part 1: Total Syntax Error = %d\n", err_score);
  printf("Part 2: Autocomplete Score = %lld\n", auto_score);
}



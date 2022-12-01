#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
using namespace std;


int main()
{
  string line, check_bit;
  list<string> o2_list, co2_list;
  list<string>::iterator iter;
  int file_length = 1000;
  int file_width = 12;
  int i, j;
  int check_sum;
  int o2_check, co2_check;
  int o2_list_len = file_length, co2_list_len = file_length;
  
  ifstream myfile;
  myfile.open("input.txt");
  

 
  
  for (i=0; i<file_length; i++)
    {
      getline(myfile, line);
      o2_list.push_back(line);
      co2_list.push_back(line);
      
    }
  myfile.close();
  
  i = 0;
  while (o2_list_len>1)
    {
      iter=o2_list.begin();
      check_sum = 0;
      while (iter != o2_list.end())
  	{
  	  line = *iter;
	  if (line[i]=='1')
	    {
	      check_sum++;
	    }
	  else
	    {
	      check_sum--;
	    }
	  iter++;
  	}

      
      if (check_sum<0)
  	{
  	  check_bit = '0';
  	}
      else
  	{
  	  check_bit = '1';
  	}
      
      iter=o2_list.begin();
      while (iter != o2_list.end())
  	{
  	  line = *iter;
  	  if (line[i]!=check_bit[0])
  	    {
  	      iter = o2_list.erase(iter);
  	      o2_list_len--;
  	    }
  	  else
  	    {
  	      iter++;
  	    }
	 
  	}
      i++;

    }
  
  iter=o2_list.begin();
  line = *iter;
  cout << line << "\n";
  
  for (j=0; j<file_width; j++)
    {
      if (line[j]=='1')
  	{
  	  o2_check+=pow(2, file_width-j-1);
  	}
    }
  
  printf("%d\n", o2_check);



  

  i = 0;
  while (co2_list_len>1)
    {
  
      iter=co2_list.begin();
      line = *iter;
  
      check_sum = 0;
      while (iter != co2_list.end())
  	{
  	  line = *iter;
	  if (line[i]=='1')
	    {
	      check_sum++;
	    }
	  else
	    {
	      check_sum--;
	    }
	  iter++;
  	}

  
      if (check_sum<0)
  	{
  	  check_bit = '1';
  	}
      else
  	{
  	  check_bit = '0';
  	}
      
      iter=co2_list.begin();
      while (iter != co2_list.end())
  	{
  	  line = *iter;
  	  if (line[i]!=check_bit[0])
  	    {
  	      iter = co2_list.erase(iter);
  	      co2_list_len--;
  	    }
  	  else
  	    {
  	      iter++;
  	    }
	 
  	}
      i++;

    }
  
  iter=co2_list.begin();
  line = *iter;
  cout << line << "\n";
  
  for (j=0; j<file_width; j++)
    {
      if (line[j]=='1')
  	{
  	  co2_check+=pow(2, file_width-j-1);
  	}
    }
  
  printf("%d\n", co2_check);


  printf("%d\n", co2_check*o2_check);
}

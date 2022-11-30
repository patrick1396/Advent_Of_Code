#include <iostream>
#include <fstream>
using namespace std;


int main()
{
  string line;
  int width, len, com_pos;
  unsigned long long int tot_num = 0;
  unsigned long long int num_fish[7];
  unsigned long long int yng_fish[7];
  
  int search_num;
  int counter, i, j;

  for(counter=0; counter<7; counter++)
    {
      num_fish[counter] = 0;
      yng_fish[counter] = 0;
    }

  
  ifstream myfile;
  myfile.open("input.txt");
  
  getline(myfile, line);
  cout << line << "\n" << "\n";

  myfile.close();

  width = -1;
  len = line.length();
  while(width<len)
    {
      width++;
      com_pos = line.find(",", width+1);
      if (com_pos<0)
      	{
      	  search_num = stoi(line.substr(width, string::npos));
  	  width = len;
      	}
      else
      	{
  	  search_num  = stoi(line.substr(width, com_pos-width));
  	  width = com_pos;
  	}

      num_fish[search_num]++;
    }

  
  for (counter=0; counter<256; counter++)
    {
      i = counter%7;
      yng_fish[(i+2)%7] = num_fish[i];
      num_fish[i] += yng_fish[i];
      yng_fish[i] = 0;

      tot_num = 0;
      for(j=0; j<7; j++)
	{
	  tot_num += num_fish[j];
	  tot_num += yng_fish[j];
	}
      
      printf("%d %llu\n", counter, tot_num);

    }

  tot_num = 0;
  for(counter=0; counter<7; counter++)
    {
      tot_num += num_fish[counter];
      tot_num += yng_fish[counter];
    }

  printf("%llu\n", tot_num);
}






#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


int main()
{
  string line;
  int file_length = 1000;
  int file_width = 12;
  int in_int;
  int i, j;
  int gamma_sum[file_width];
  int gamma, epsilon;
  
  ifstream myfile;
  myfile.open("input.txt");
  
  
  
  for (i=0; i<file_length; i++)
    {
      getline(myfile, line);
      for (j=0; j<file_width; j++)
	{
	  
	  if (line[j]=='1')
	    {
	      gamma_sum[j]++;
	    }
	  else
	    {
	      gamma_sum[j]--;
	    }
	  //in_int = stoi(line);
	}

    }
  myfile.close();

  for (j=0; j<file_width; j++)
    {
      cout << gamma_sum[j] << " ";
      if (gamma_sum[j]>0)
	{
	  gamma+=pow(2, file_width-j-1);
	}
      else
	{
	  epsilon+=pow(2, file_width-j-1);
	}
    }
  cout << "\n";
  printf("gamma %d, epsilon %d, gamma*epsilon %d\n", gamma, epsilon, gamma*epsilon);
  
  //  printf("%d\n", in_int[0]);
}
